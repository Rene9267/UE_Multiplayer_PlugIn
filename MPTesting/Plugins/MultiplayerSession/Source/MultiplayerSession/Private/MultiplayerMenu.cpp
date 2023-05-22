// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerMenu.h"
#include "Components/Button.h"
#include "MultiplayerSessionSubsystem.h"

void UMultiplayerMenu::MenuSetUp()
{
	//add widget to viewport
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	bIsFocusable = true;
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController)
		{
			//for setting input mode on UI
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

}

bool UMultiplayerMenu::Initialize()
{
	//check if the base initialize return false
	if (!Super::Initialize())
	{
		return false;
	}

	if (Host_Button)
	{
		//bind the custom host button function to the delegate event
		Host_Button->OnClicked.AddDynamic(this, &ThisClass::HostButtonClicked);
	}
	if (Join_Button)
	{
		//bind the custom join button function to the delegate event
		Join_Button->OnClicked.AddDynamic(this, &ThisClass::JoinButtonClicked);
	}

	return true;
}

void UMultiplayerMenu::HostButtonClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, FString(TEXT("Host Button Clicked")));
	}

	//Call MultiplayerSessionSubsystem Functions
	if (MultiplayerSessionSubsystem)
	{
		MultiplayerSessionSubsystem->CreateSession(NumConnection, MatchType);
	}
}

void UMultiplayerMenu::JoinButtonClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, FString(TEXT("Join Button Clicked")));
	}
}
