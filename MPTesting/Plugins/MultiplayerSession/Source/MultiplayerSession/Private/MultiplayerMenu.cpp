// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerMenu.h"
#include "Components/Button.h"
#include "MultiplayerSessionSubsystem.h"
#include "OnlineSubsystem.h"



void UMultiplayerMenu::MenuSetUp(int32 NumConnections, FString TypeOfMatch, FString LobbyPath)
{
	this->PathToLobby = FString::Printf(TEXT("%s?Listen"), *LobbyPath);
	NumConnection = NumConnections;
	MatchType = TypeOfMatch;

	//add widget to viewport
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	bIsFocusable = true;
	UWorld* World = GetWorld();
	//for setting input mode on UI
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController)
		{
			FInputModeUIOnly InputModeData;
			InputModeData.SetWidgetToFocus(TakeWidget()); //this'll take the current widget and set the focus
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); //for lock the mouse
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(true);
		}
	}

	//access game instance for get the subsystem
	UGameInstance* GameInstance = GetGameInstance();
	if (GameInstance)
	{
		MultiplayerSessionSubsystem = GameInstance->GetSubsystem<UMultiplayerSessionSubsystem>();
	}

	//Bind the callback for the delegate
	if (MultiplayerSessionSubsystem)
	{
		//every time we broadcast that delegate the callback OnCreateSession'll response
		MultiplayerSessionSubsystem->MultiplayerOnCreateSessionComplete.AddDynamic(this, &ThisClass::OnCreateSession);
		MultiplayerSessionSubsystem->MultiplayerOnStartSessionComplete.AddDynamic(this, &ThisClass::OnStartSession);
		MultiplayerSessionSubsystem->MultiplayerOnDestroySessionComplete.AddDynamic(this, &ThisClass::OnDestroySession);

		MultiplayerSessionSubsystem->MultiplayerOnFindSessionComplete.AddUObject(this, &ThisClass::OnFindSession);
		MultiplayerSessionSubsystem->MultiplayerOnJoinSessionComplete.AddUObject(this, &ThisClass::OnJoinSession);

	}
}

bool UMultiplayerMenu::Initialize()
{
	//check if the base initialize return false
	if (!Super::Initialize())
	{
		return false;
	}

	if (HostButton)
	{
		//bind the custom host button function to the delegate event
		HostButton->OnClicked.AddDynamic(this, &ThisClass::HostButtonClicked);
	}
	if (JoinButton)
	{
		//bind the custom join button function to the delegate event
		JoinButton->OnClicked.AddDynamic(this, &ThisClass::JoinButtonClicked);
	}

	return true;
}

void UMultiplayerMenu::NativeDestruct()
{
	MenuTearDown();
	Super::NativeDestruct();
}

void UMultiplayerMenu::OnCreateSession(bool bWasSuccesful)
{
	if (bWasSuccesful)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, FString(TEXT("Session Created Successfully")));
		}
		//if all ok we can travel to the lobby level
		UWorld* World = GetWorld();
		if (World)
		{
			World->ServerTravel(PathToLobby);
		}
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, FString(TEXT("FAIL TO CREATE")));
		}
	}
}

void UMultiplayerMenu::OnFindSession(const TArray<FOnlineSessionSearchResult>& SessionResult, bool bWasSuccesful)
{
	if (MultiplayerSessionSubsystem == nullptr)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, FString(TEXT("MultiplayerSessionSubsystem Null")));
		}
		return;
	}
	//check trow the array if there is a valid session
	for (FOnlineSessionSearchResult Result : SessionResult)
	{
		FString ID = Result.GetSessionIdStr();
		FString User = Result.Session.OwningUserName;
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("ID: %s, User: %s"), *ID, *User));
		}
		FString MatchSettingValue;
		Result.Session.SessionSettings.Get(FName("MatchType"), MatchSettingValue); //if the session have the correct FName he'll set the Match Type value
		if (MatchSettingValue == MatchType)
		{
			//call join session for joining
			MultiplayerSessionSubsystem->JoinSession(Result);
			return;
		}
	}
}

void UMultiplayerMenu::OnJoinSession(EOnJoinSessionCompleteResult::Type Reuslt)
{
	//Get the IP address
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, FString(TEXT("Travelling")));
		}
		IOnlineSessionPtr SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			FString Address;
			bool ConnectionResolved = SessionInterface->GetResolvedConnectString(NAME_GameSession, Address);// the address'll be automatically filled

			//very important to take from the game instance because in the Menu we dont have other way yo access the player controller
			APlayerController* PlayerController = GetGameInstance()->GetFirstLocalPlayerController();
			if (PlayerController)
			{
				PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
			}
		}
	}
}

void UMultiplayerMenu::OnDestroySession(bool bWasSuccesful)
{
}

void UMultiplayerMenu::OnStartSession(bool bWasSuccesful)
{
}

void UMultiplayerMenu::HostButtonClicked()
{
	//Call MultiplayerSessionSubsystem Functions
	if (MultiplayerSessionSubsystem)
	{
		MultiplayerSessionSubsystem->CreateSession(NumConnection, MatchType);
	}
}

void UMultiplayerMenu::JoinButtonClicked()
{
	if (MultiplayerSessionSubsystem)
	{
		MultiplayerSessionSubsystem->FindSession(/*MaxSessionResult*/10000);
	}
}

void UMultiplayerMenu::MenuTearDown()
{
	RemoveFromParent();
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController)
		{
			//Add again input to the player
			FInputModeGameOnly InputModeData;
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(false);
		}
	}
}
