# Unreal Engine Multiplayer Plugin
> Designed for Unreal Engine 5.1

## Introduction
- This Plugin allow the user to:
    - Host a server using the Steam Platform, with the possibility of choosing the quantity of entity who can access.
    - Join a compatible server, in your same region using **Presence**. [https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/Online/PresenceInterface/]
    
 
***Steam must be open for the plugin to work!*** 

## Multiplayer Plugin API

  - MultiplayerSessionSubsystem.h/cpp
    - *Multiplayer session Subsystem internal delegate and custom delegate for MultiplayerMenu Class.*
    - *Session Functionality (Create, Find, Join, etc..) called by MultiplayerMenu.*
    
    <details>
	<summary>  Multiplayer Session Subsystem Implementation </summary>
	</details>

  - MultiplayerSession.h/cpp 
    - Start up and ShutDown Module.
  - MultiplayerMenu.h/cpp 
    - Manages the calling of the various functions of the Multiplayer Session Subsystem
 


## Multiplayer Session Subsystem
```C++
UCLASS()
class MULTIPLAYERSESSION_API UMultiplayerSessionSubsystem : public UGameInstanceSubsystem
```
### Include
```C++
//.h inclue
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MultiplayerSessionSubsystem.generated.h"

//.cpp include
#include "MultiplayerSessionSubsystem.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
```
<details>
	<summary>  Constructor </summary>
	

### Constructor
```C++
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
```
- Bind the various delegates
- Set up the Session Interface
</details>


### Public Members
--------------------------------------
***Custom Delegate for MultiplayerMenu Class***
```C++
//Blueprint Compatible (is UCLASS) -> Dynamic
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnCreateSessionComplete, bool, bWasSuccessful);
	FMultiplayerOnCreateSessionComplete MultiplayerOnCreateSessionComplete;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnDestroySessionComplete, bool, bWasSuccessful);
	FMultiplayerOnDestroySessionComplete MultiplayerOnDestroySessionComplete;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnStartSessionComplete, bool, bWasSuccessful);
	FMultiplayerOnStartSessionComplete MultiplayerOnStartSessionComplete;

//Not Blueptint Compatible (NOT UCLASS)
//Array of session found passed by ref for not copy it
DECLARE_MULTICAST_DELEGATE_TwoParams(FMultiplayerOnFindSessionComplete, const TArray<FOnlineSessionSearchResult>& SessionResult, bool bWasSuccessful);
	FMultiplayerOnFindSessionComplete MultiplayerOnFindSessionComplete;
DECLARE_MULTICAST_DELEGATE_OneParam(FMultiplayerOnJoinSessionComplete, EOnJoinSessionCompleteResult::Type Reuslt);
	FMultiplayerOnJoinSessionComplete MultiplayerOnJoinSessionComplete;
```
--------------------------------------
***Create Session Method*** 
```C++
void CreateSession(int32 NumPublicConnections, FString MatchType);
```
- Parameters:
  - int32 NumPublicConnections = Number of players that can connect.
  - FString MatchType = Set the MetchType so we'r sure to join only in the sessions we are interested in.
- Called when press the 'HostButton'
- Used to set the various Session Settings for the Session Creation
- Try to IOnlineSessionPtr->CreateSession(), if fail unbind the delegate *CreateSessionCompleteDelegateHandle* and cast the custom delegate ```MultiplayerOnCreateSessionComplete.Broadcast(false)```
--------------------------------------
***Find Session Method***
```C++
void FindSession(int32 MaxSearchResults);
```
- Parameters:
  - int32 MaxSearchResults = Max number of session searched, usually set to a high number because we're using the open steam ID 480 so there'll be a lot of possible session.
- Called when press the 'JoinButton'
- Set some search sarameters taken from ```TSharedPtr<FOnlineSessionSearch> LastSessionSearch```
- Try to IOnlineSessionPtr->FindSession(), if fail unbind the delegate *FindSessionsCompleteDelegateHandle* and cast the custom delegate ```MultiplayerOnFindSessionComplete.Broadcast(TArray<FOnlineSessionSearchResult>(), false);```
--------------------------------------
***Join Session Method***
```
void JoinSession(const FOnlineSessionSearchResult& SessionResult);
```
- Parameters:
  - const FOnlineSessionSearchResult& SessionResult = The desired session to join
- Called when Menu find a session (UMultiplayerMenu::OnFindSession)
- Try to IOnlineSessionPtr->JoinSession(), if fail unbind the delegate *JoinSessionCompleteDelegateHandle* and cast the custom delegate ```MultiplayerOnJoinSessionComplete.Broadcast(EOnJoinSessionCompleteResult::UnknownError);```
--------------------------------------
***Destroy Session Method***
```
void DestroySession();
```
- Called in CreateSession When can't create a session
- Try to IOnlineSessionPtr->DestroySession(), if fail unbind the delegate *DestroySessionCompleteDelegateHandle* and cast the custom delegate ```MultiplayerOnDestroySessionComplete.Broadcast(false);```
--------------------------------------
***Start Session Method***
```
void StartSession();
```
- Not yet implemented
- Teorically called inside OnCreateSessionComplete().




### Protected Members
Internal callbacks for the delegate we'll add to the online session interface delegate list, don't need to be called outside this class.
	
--------------------------------------
***On Create Session Complete Method*** 
```C++
void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
```
- Remove *CreateSessionCompleteDelegateHandle* once the session is succesfully complete.
- Broadcast our own custom delegate for success of the creation ```MultiplayerOnCreateSessionComplete.Broadcast(bWasSuccessful);```
--------------------------------------
***On Find Session Complete Method*** 
```C++
void OnFindSessionComplete(bool bWasSuccessful);
```
- Broadcast our own custom delegate for Finding session, passing the array of SearchResult ```MultiplayerOnFindSessionComplete.Broadcast(LastSessionSearch->SearchResults, bWasSuccessful);```
- Remove *FindSessionsCompleteDelegateHandle* once the session is succesfully Found.
- In case the array of SeachResult is empty ```MultiplayerOnFindSessionComplete.Broadcast(TArray<FOnlineSessionSearchResult>(), false);```
--------------------------------------
***On Join Session Complete Method*** 
```C++
void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
```
- Remove *JoinSessionCompleteDelegateHandle*
- Broadcast our own custom delegate ```MultiplayerOnJoinSessionComplete.Broadcast(Result);```
--------------------------------------
***On Destroy Session Complete Method*** 
```C++
void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);
```
- Remove *DestroySessionCompleteDelegateHandle*
- If the session was successfully destroyed but we are still trying to create a session we call the *Create Session Method* again, used if the session is destroyed by mistake.
- Broadcast our own custom delegate ```MultiplayerOnDestroySessionComplete.Broadcast(bWasSuccessful);```
--------------------------------------
***On Start Session Complete Method*** 
```C++
void OnStartSessionComplete(FName SessionName, bool bWasSuccessful);
```
- Not yet implemented





### Private Members 

 - bool bCreateSessionOnDestroy{ false } = check this when a session has been destroyes, if true we'll create a new session.
 - int32 LastNumPublicConnections = Used by the *Create Session Method* called by *On Destroy Session Complete Method*.
 - FString LastMathType = Used by the *Create Session Method* called by *On Destroy Session Complete Method*.
 - IOnlineSessionPtr SessionInterface = Interface for accessing the session management service. 
 - TSharedPtr<FOnlineSessionSearch> LastSessionSearch = Parameter for the session search.
 - TSharedPtr<FOnlineSessionSettings> LastSessionSettings = Setting for the creation of a session.
 - A bunch of delegate and delegate handle used for internal callbacks.
	```C++
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
	```
	
