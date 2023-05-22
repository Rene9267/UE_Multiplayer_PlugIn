// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MultiplayerMenu.generated.h"

/**
 *
 */
UCLASS()
class MULTIPLAYERSESSION_API UMultiplayerMenu : public UUserWidget
{
	GENERATED_BODY()

#pragma region Variables
private:
	//this is used for link the button widget to our button variable in c++ the variable has to have the exact same name of the button
	UPROPERTY(meta = (BindWidjet))
		class UButton* HostButton;
	UPROPERTY(meta = (BindWidjet))
		UButton* JoinButton;

	//the susbsystem designed to handle all online session
	class UMultiplayerSessionSubsystem* MultiplayerSessionSubsystem;

	int32 NumConnection = 4;
	FString MatchType = TEXT("FreeForAll");
#pragma endregion


#pragma region Functions
public:
	UFUNCTION(BlueprintCallable)
		void MenuSetUp(); //for setting visibility or things like that

protected:
	//we'll bind the button callback on this fuction
	//this is kinda like the constructor and is too early to set the parameter that we saw in the MenuSetUp funcition
	virtual bool Initialize() override;

private:
	//because this is bind to ad on click event or delegate that exit in new button class we have to use UFUNCTION
	UFUNCTION()
		void HostButtonClicked();
	UFUNCTION()
		void JoinButtonClicked();
#pragma endregion

};
