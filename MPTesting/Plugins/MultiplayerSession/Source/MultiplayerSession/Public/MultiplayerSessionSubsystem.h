// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"


#include "MultiplayerSessionSubsystem.generated.h"

//Delegate for the menu class to bind callbacks
//The multicast means that once casted multiple classes can bind to him
//Dynamic means the delegate can be serialized and saved or loaded from a blueprint graph (Event Dispatchers)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnCreateSessionComplete, bool, bWasSuccessful);

/**
 *
 */
UCLASS()
class MULTIPLAYERSESSION_API UMultiplayerSessionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

#pragma region Variables
public:

	//CustomDelegate for Menu class
	FMultiplayerOnCreateSessionComplete MultiplayerOnCreateSessionComplete;

private:

	IOnlineSessionPtr SessionInterface;
	TSharedPtr<FOnlineSessionSettings> LastSessionSettings;

	//Delegates, we'll bind our multilayer seession susbsystem internal callbacks to these
	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
	FDelegateHandle CreateSessionCompleteDelegateHandle;

	FOnFindSessionsCompleteDelegate FindSessionsCompleteDelegate;
	FDelegateHandle FindSessionsCompleteDelegateHandle;

	FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;
	FDelegateHandle JoinSessionCompleteDelegateHandle;

	FOnDestroySessionCompleteDelegate DestroySessionCompleteDelegate;
	FDelegateHandle DestroySessionCompleteDelegateHandle;

	FOnStartSessionCompleteDelegate StartSessionCompleteDelegate;
	FDelegateHandle StartSessionCompleteDelegateHandle;

#pragma endregion


#pragma region Functions
public:
	UMultiplayerSessionSubsystem(); //default constructor
	// to handle session functionality, the menu class can call these
	void CreateSession(int32 NumPublicConnections, FString MatchType); //wanna pass the number of player (NumPublic..)
	void FindSession(int32 MaxSearchResults);
	void JoinSession(const FOnlineSessionSearchResult& SessionResult);
	void DestroySession();
	void StartSession();

protected:
	//Internal callbacks for the deleggate we'll add to the online session interface delegate list, don't need to be called outside this class.
	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void OnFindSessionComplete(bool bWasSuccessful);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);
	void OnStartSessionComplete(FName SessionName, bool bWasSuccessful);
#pragma endregion


};
