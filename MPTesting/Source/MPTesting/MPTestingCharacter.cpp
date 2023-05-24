// Copyright Epic Games, Inc. All Rights Reserved.

#include "MPTestingCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "Kismet/GameplayStatics.h"

//Online Connection
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"

//////////////////////////////////////////////////////////////////////////
// AMPTestingCharacter

AMPTestingCharacter::AMPTestingCharacter() :
	CreateSessionCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnCreateSessionComplete)), //deleate for the session creation
	FindSessionCompleteDelegate(FOnFindSessionsCompleteDelegate::CreateUObject(this, &ThisClass::OnFindSessionComplete)), //deleate for finding the session complete
	JoinSessionCompleteDelegate(FOnJoinSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnJoinSessionComplete))
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	//Online Subsystem
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();
	if (OnlineSubsystem)
	{
		//access th session interface
		OnlineSssionInterface = OnlineSubsystem->GetSessionInterface();

		//if (GEngine)
		//{
		//	//print a screen message for onlyne subystm information
		//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("Found Subsystem %s"), *OnlineSubsystem->GetSubsystemName().ToString()));
		//}
	}
}

void AMPTestingCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AMPTestingCharacter::OpenLobby()
{
	UWorld* World = GetWorld();
	if (World)
	{
		//travel to the lobby level open as listen server
		World->ServerTravel("/Game/ThirdPerson/Maps/MAP_Lobby?listen");
	}
}

void AMPTestingCharacter::CallOpenLevl(const FString& Address)
{
	//Enter in the opened lobby in lan conneection
	UGameplayStatics::OpenLevel(this, *Address);
}

void AMPTestingCharacter::CallClientTravel(const FString& Address)
{
	//Enter in the opened lobby in lan conneection using PlayerController
	APlayerController* PlayerController = GetGameInstance()->GetFirstLocalPlayerController();
	if (PlayerController)
	{
		PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
	}
}

void AMPTestingCharacter::CreateGameSession()
{
	//called when pressing the 1 key
	//check if the pointer is valid
	if (!OnlineSssionInterface.IsValid())
	{
		return;
	}
	//check to see if a session alrady exist
	FNamedOnlineSession* ExistingSession = OnlineSssionInterface->GetNamedSession(NAME_GameSession /*global variable*/);
	//if already exist destroy the session so we can generate a new one
	if (ExistingSession != nullptr)
	{
		OnlineSssionInterface->DestroySession(NAME_GameSession);
	}

	OnlineSssionInterface->AddOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteDelegate);

	TSharedPtr<FOnlineSessionSettings> SessionSettings = MakeShareable(new FOnlineSessionSettings);
	SessionSettings->bIsLANMatch = false;
	//number player that can connect
	SessionSettings->NumPublicConnections = 4;
	//if session is running other player can join 
	SessionSettings->bAllowJoinInProgress = true;
	//search from region player
	SessionSettings->bAllowJoinViaPresence = true;
	//allows steam to advertise so other player can find and join
	SessionSettings->bShouldAdvertise = true;
	//find session going on in our region of the world
	SessionSettings->bUsesPresence = true;
	SessionSettings->bUseLobbiesIfAvailable = true;
	//usefull for chech the type when join. so we'r sure to join only in sessions with the correct match type
	SessionSettings->Set(FName("MatchType"), FString("FreeForAll"), EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);


	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	OnlineSssionInterface->CreateSession(*LocalPlayer->GetPreferredUniqueNetId(), NAME_GameSession, *SessionSettings);
}

void AMPTestingCharacter::JoinGameSession()
{
	//find game session
	if (!OnlineSssionInterface.IsValid())
	{
		return;
	}

	//add the delegate to the delegate list
	OnlineSssionInterface->AddOnFindSessionsCompleteDelegate_Handle(FindSessionCompleteDelegate);

	//create a pointer we use a shared pointer and not a ref because we plan on making there varibales on this class to access information
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	//settings session
	SessionSearch->MaxSearchResults = 10000; //hight number because we'r using the open steam ID 480 so there'll be a lot of possibile session
	SessionSearch->bIsLanQuery = false; // for lan using
	SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals); //query to use for finding matching servers
	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController(); // for get the net id
	OnlineSssionInterface->FindSessions(*LocalPlayer->GetPreferredUniqueNetId(), SessionSearch.ToSharedRef());
}

void AMPTestingCharacter::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		//print a screen message if success create session
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("Create session %s"), *SessionName.ToString()));
		}
		//travel in the server world
		UWorld* CurrentWorld = GetWorld();
		if (CurrentWorld)
		{
			if (CurrentWorld->ServerTravel(FString("/Game/ThirdPerson/Maps/LobbyMap?listen")))//?listen => open the level as listen server
			{
				if (GEngine)
				{
					GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Enter in this map: %s"), *CurrentWorld->GetFName().ToString()));
				}
			}

		}
	}
	else
	{
		//print a screen message if fail create session
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Failed to create session!")));
		}
	}
}

void AMPTestingCharacter::OnFindSessionComplete(bool bWasSuccessful)
{
	if (!OnlineSssionInterface.IsValid())
	{
		return;
	}

	for (FOnlineSessionSearchResult Result : SessionSearch->SearchResults)
	{
		FString ID = Result.GetSessionIdStr();
		FString User = Result.Session.OwningUserName;

		FString MatchType;
		Result.Session.SessionSettings.Get(FName("MatchType"), MatchType); //if the session have the correct FName he'll set the Match Type value

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("ID: %s, User: %s"), *ID, *User));
		}

		//check if MatchType is correct
		if (MatchType == FString("FreeForAll"))
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("Jopin Match Type: %s"), *MatchType));
			}
			OnlineSssionInterface->AddOnJoinSessionCompleteDelegate_Handle(JoinSessionCompleteDelegate);
			const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController(); // for get the net id
			OnlineSssionInterface->JoinSession(*LocalPlayer->GetPreferredUniqueNetId(), NAME_GameSession, Result);
		}
	}
}

//called when join complete
void AMPTestingCharacter::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	if (!OnlineSssionInterface.IsValid())
	{
		return;
	}

	//Get the IP address
	FString Address;
	bool ConnectionResolved = OnlineSssionInterface->GetResolvedConnectString(NAME_GameSession, Address);// the address'll be automatically filled
	if (ConnectionResolved)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Connect string: %s"), *Address));
	}

	APlayerController* PlayerController = GetGameInstance()->GetFirstLocalPlayerController();
	if (PlayerController)
	{
		PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void AMPTestingCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMPTestingCharacter::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMPTestingCharacter::Look);

	}

}

void AMPTestingCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AMPTestingCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}




