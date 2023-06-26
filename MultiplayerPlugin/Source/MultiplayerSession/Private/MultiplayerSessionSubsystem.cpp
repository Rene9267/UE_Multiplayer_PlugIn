// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerSessionSubsystem.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"

UMultiplayerSessionSubsystem::UMultiplayerSessionSubsystem() :
	CreateSessionCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this, &UMultiplayerSessionSubsystem::OnCreateSessionComplete)),
	FindSessionsCompleteDelegate(FOnFindSessionsCompleteDelegate::CreateUObject(this, &ThisClass::OnFindSessionComplete)),
	JoinSessionCompleteDelegate(FOnJoinSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnJoinSessionComplete)),
	DestroySessionCompleteDelegate(FOnDestroySessionCompleteDelegate::CreateUObject(this, &ThisClass::OnDestroySessionComplete)),
	StartSessionCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnStartSessionComplete))

{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem)
	{
		SessionInterface = Subsystem->GetSessionInterface();
	}
}

//Called when press the HostButton
void UMultiplayerSessionSubsystem::CreateSession(int32 NumPublicConnections, FString MatchType)
{
#pragma region Checks
	if (!SessionInterface.IsValid())
	{
		return;
	} //return

	FNamedOnlineSession* ExistsingSession = SessionInterface->GetNamedSession(NAME_GameSession);
	//check if already exixst a session with the name and destroy in case
	if (ExistsingSession != nullptr)
	{
		//"Session Already Exist, can't create a new one" Debug
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, FString(TEXT("Session Already Exist, can't create a new one")));
		}

		//if can't create session store the previous value for retry creation
		bCreateSessionOnDestroy = true;
		LastNumPublicConnections = NumPublicConnections;
		LastMathType = MatchType;
		DestroySession();
	}
#pragma endregion

	//store the delegate in a FDelegateHandle so we can later remove from the delegate list
	CreateSessionCompleteDelegateHandle = SessionInterface->AddOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteDelegate);

	//Set some SessionSetting for the Session Creation
	LastSessionSettings = MakeShareable(new FOnlineSessionSettings());
	LastSessionSettings->bIsLANMatch = IOnlineSubsystem::Get()->GetSubsystemName() == "NULL" ? true : false; // this'll return null if we'r useing null subsystem or steam if we'r using steam subsystem
	LastSessionSettings->NumPublicConnections = NumPublicConnections;	//number player that can connect
	LastSessionSettings->bAllowJoinInProgress = true;					//if session is running other player can join 
	LastSessionSettings->bAllowJoinViaPresence = true;					//search from region player
	LastSessionSettings->bShouldAdvertise = true;						//allows steam to advertise so other player can find and join
	LastSessionSettings->bUsesPresence = true;							//find session going on in our region of the world
	LastSessionSettings->bUseLobbiesIfAvailable = true;
	LastSessionSettings->BuildUniqueId = 1;								//We can have multiple user launching their own builds and hosting otherwise we'll join in the first one session hosted
	LastSessionSettings->Set(FName("MatchType"), MatchType, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing); //usefull for chech the type when join. so we'r sure to join only in sessions with the correct match type


	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	//if the creation of the session didnt work, remember to unbind the delegate
	if (!SessionInterface->CreateSession(*LocalPlayer->GetPreferredUniqueNetId(), NAME_GameSession, *LastSessionSettings))
	{
		//"Can't create session with this Settings" Debug
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 50, FColor::Red, FString(TEXT("Can't create session with this Settings")));
		}

		SessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteDelegateHandle);

		//Broadcast our own custom delegate for the fail
		MultiplayerOnCreateSessionComplete.Broadcast(false);
	}
}

//Called when press the Join Button
void UMultiplayerSessionSubsystem::FindSession(int32 MaxSearchResults)
{
	if (!SessionInterface.IsValid())
	{
		//"Session Interface Not Valid" Debug
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, FString(TEXT("Find Session -> Session Interface Not Valid")));
		}
		return;
	}

	FindSessionsCompleteDelegateHandle = SessionInterface->AddOnFindSessionsCompleteDelegate_Handle(FindSessionsCompleteDelegate);

	//create a pointer we use a shared pointer and not a ref because we plan on making there varibales on this class to access information
	LastSessionSearch = MakeShareable(new FOnlineSessionSearch());
	LastSessionSearch->MaxSearchResults = MaxSearchResults;		//hight number because we'r using the open steam ID 480 so there'll be a lot of possibile session
	LastSessionSearch->bIsLanQuery = IOnlineSubsystem::Get()->GetSubsystemName() == "NULL" ? true : false;		// for lan using
	LastSessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals); //query to use for finding matching servers

	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController(); // for get the net id
	//if the creation of the session didnt work if good to unbind the delegate

	if (!SessionInterface->FindSessions(*LocalPlayer->GetPreferredUniqueNetId(), LastSessionSearch.ToSharedRef()))
	{
		SessionInterface->ClearOnFindSessionsCompleteDelegate_Handle(FindSessionsCompleteDelegateHandle);
		//"Can't find Session with this Search" Debug
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, FString(TEXT("Can't find Session with this Search")));
		}

		//faliure case, send an empty array
		MultiplayerOnFindSessionComplete.Broadcast(TArray<FOnlineSessionSearchResult>(), false);
	}
}

//Called when Menu find a session (UMultiplayerMenu::OnFindSession)
void UMultiplayerSessionSubsystem::JoinSession(const FOnlineSessionSearchResult& SessionResult)
{
	if (!SessionInterface.IsValid())
	{
		//"Session Interface Not Valid" Debug
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, FString(TEXT("Join Session -> Session Interface Not Valid")));
		}

		//send error in case we can't join
		MultiplayerOnJoinSessionComplete.Broadcast(EOnJoinSessionCompleteResult::UnknownError);
		return;
	}

	JoinSessionCompleteDelegateHandle = SessionInterface->AddOnJoinSessionCompleteDelegate_Handle(JoinSessionCompleteDelegate);

	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController(); // for get the controller
	if (!SessionInterface->JoinSession(*LocalPlayer->GetPreferredUniqueNetId(), NAME_GameSession, SessionResult))
	{
		//"Can't Join The session" Debug
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, FString(TEXT("Can't Join The session")));
		}
		SessionInterface->ClearOnJoinSessionCompleteDelegate_Handle(JoinSessionCompleteDelegateHandle);
		MultiplayerOnJoinSessionComplete.Broadcast(EOnJoinSessionCompleteResult::UnknownError);
	}
}

//Called in CreateSession When can't create a session
void UMultiplayerSessionSubsystem::DestroySession()
{
	if (!SessionInterface.IsValid())
	{
		MultiplayerOnDestroySessionComplete.Broadcast(false);
		return;
	}

	DestroySessionCompleteDelegateHandle = SessionInterface->AddOnDestroySessionCompleteDelegate_Handle(DestroySessionCompleteDelegate);

	if (!SessionInterface->DestroySession(NAME_GameSession))
	{
		SessionInterface->ClearOnDestroySessionCompleteDelegate_Handle(DestroySessionCompleteDelegateHandle);
		MultiplayerOnDestroySessionComplete.Broadcast(false);
	}
}

void UMultiplayerSessionSubsystem::StartSession()
{
}

void UMultiplayerSessionSubsystem::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
	//remove the delegate once the session is succesfully complete
	if (SessionInterface)
	{
		SessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteDelegateHandle);
	}

	//Broadcast our own custom delegate for success of the creation
	MultiplayerOnCreateSessionComplete.Broadcast(bWasSuccessful);
}

void UMultiplayerSessionSubsystem::OnFindSessionComplete(bool bWasSuccessful)
{
	if (SessionInterface)
	{
		SessionInterface->ClearOnFindSessionsCompleteDelegate_Handle(FindSessionsCompleteDelegateHandle);
	}

	//in case the array is empty
	if (LastSessionSearch->SearchResults.Num() <= 0)
	{
		//"LastSessionSearch SearchResults" Debug
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, FString(TEXT("LastSessionSearch SearchResults Null")));
		}
		MultiplayerOnFindSessionComplete.Broadcast(TArray<FOnlineSessionSearchResult>(), false);
		return;
	}

	//broadcast to menu
	MultiplayerOnFindSessionComplete.Broadcast(LastSessionSearch->SearchResults, bWasSuccessful);
}

void UMultiplayerSessionSubsystem::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	if (SessionInterface)
	{
		SessionInterface->ClearOnJoinSessionCompleteDelegate_Handle(JoinSessionCompleteDelegateHandle);
	}
	MultiplayerOnJoinSessionComplete.Broadcast(Result);
}

void UMultiplayerSessionSubsystem::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
	if (SessionInterface)
	{
		SessionInterface->ClearOnDestroySessionCompleteDelegate_Handle(DestroySessionCompleteDelegateHandle);
	}

	//if destroy succesfully the session
	//if bCreateSessionOnDestroy is true we'r trying to create a new session but a session already exist
	if (bWasSuccessful && bCreateSessionOnDestroy)
	{
		bCreateSessionOnDestroy = false;
		CreateSession(LastNumPublicConnections, LastMathType);
	}

	MultiplayerOnDestroySessionComplete.Broadcast(bWasSuccessful);
}

void UMultiplayerSessionSubsystem::OnStartSessionComplete(FName SessionName, bool bWasSuccessful)
{
}
