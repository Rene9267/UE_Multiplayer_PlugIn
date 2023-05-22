// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerMenu.h"

void UMultiplayerMenu::MenuSetUp()
{
	//add widjet to viewport
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
			InputModeData.SetWidgetToFocus(TakeWidget()); //this'll take the current widjet and set the focus
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); //for lock the mouse
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(true);
		}
	}
}
