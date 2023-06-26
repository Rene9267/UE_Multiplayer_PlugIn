# Unreal Engine Multiplayer Plugin
> Designed for Unreal Engine 5.1

## Introduction
- This Plugin allow the user to:
    - Host a server using the Steam Platform, with the possibility of choosing the quantity of entity who can access.
    - Join a compatible server, in your same region using [**Presence**](https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/Online/PresenceInterface/). 
    
***Steam must be open for the plugin to work!*** 

## Multiplayer Plugin API

--------------------------------------
  - MultiplayerSessionSubsystem.h/cpp
    - *Multiplayer session Subsystem internal delegate and custom delegate for MultiplayerMenu Class.*
    - *Session Functionality (Create, Find, Join, etc..) called by MultiplayerMenu.*
    
<details><summary>  Multiplayer Session Subsystem Implementation </summary><blockquote>
	
## Multiplayer Session Subsystem
```C++
UCLASS()
class MULTIPLAYERSESSION_API UMultiplayerSessionSubsystem : public UGameInstanceSubsystem
```
<details><summary>  Include </summary><blockquote>

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

</blockquote></details>
<details><summary>  Constructor </summary><blockquote>


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
<details><summary>  Public Members </summary><blockquote>


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
- No default implementation
- Called inside OnCreateSessionComplete().

</blockquote></details>	
<details><summary>  Protected Members </summary><blockquote>	
	
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
- No default implementation
--------------------------------------
</blockquote></details>
<details><summary>  Private Members </summary><blockquote>	

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

</blockquote></details>	
</blockquote></details>

--------------------------------------

  - MultiplayerSession.h/cpp 
    - Start up and ShutDown Module.
--------------------------------------
  - MultiplayerMenu.h/cpp 
    - Manages the calling of the various functions of the Multiplayer Session Subsystem

<details><summary>  Multiplayer Menu Implementation </summary><blockquote>
	
 ## Multiplayer Menu
```C++
UCLASS()
class MULTIPLAYERSESSION_API UMultiplayerMenu : public UUserWidget
```
<details><summary>  Include </summary><blockquote>

### Include
```C++
//.h inclue
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MultiplayerMenu.generated.h"

//.cpp include
#include "MultiplayerMenu.h"
#include "Components/Button.h"
#include "MultiplayerSessionSubsystem.h"
#include "OnlineSubsystem.h"
```
</blockquote></details>
<details><summary>  Public Members </summary><blockquote>
	
### Public Members
--------------------------------------
***Menu Set Up Method***
```C++
UFUNCTION(BlueprintCallable)
		void MenuSetUp(int32 NumConnections = 4, FString TypeOfMatch = FString(TEXT("FreeForAll")), FString LobbyPath = FString(TEXT("/Game/ThirdPerson/Maps/LobbyMap"))); 
```
- Parameters:
  - int32 NumConnections = Number of players that can connect.
  - FString TypeOfMatch = Set the MetchType so we'r sure to join only in the sessions we are interested in, in this case is "FreeForAll"
  - FString LobbyPath = set the path to the lobby Map
- Call this in the level Blueprint of the first loaded Map
- Add the Menu widget to the viewport and set the input mode on UI
- Access the Game instance for setting the MultiplayerSessionSubsystem
- Bind the callbacks to the MultiplayerSessionSubsystem calls
--------------------------------------
</blockquote></details>
<details><summary>  Protected Members </summary><blockquote>	

### Protected Members 
--------------------------------------
***Initialize Method***
```C++
virtual bool Initialize() override;
```
- Bind the custom Host button function to the delegate event HostButtonClicked using AddDynamic
- bind the custom Join button function to the delegate event JoinButtonClicked using AddDynamic
--------------------------------------
***NativeDestruct Method***
```C++
virtual void NativeDestruct() override;
```
- Called by the user widget when travel to another Level
- Inside we call the Menu Tear Down for add again input to the player
--------------------------------------
***On Create Session Method***
```C++
UFUNCTION();
void OnCreateSession(bool bWasSuccesful);
```
- Parameters
  - bool bWasSuccesful = true if succesfuly create the session
- Callback for the castom delegate called on the Multiplayer Session Subsystem ```MultiplayerOnCreateSessionComplete```
- Handle the Server travel to the lobby path
--------------------------------------
***On Destroy Session Method***
```C++
UFUNCTION();
void OnDestroySession(bool bWasSuccesful);
```
- Parameters
  - bool bWasSuccesful = true if succesfuly destroy the session
- Called on ```MultiplayerOnDestroySessionComplete```
- No default implementation
--------------------------------------
***On Start Session Method***
```C++
UFUNCTION();
void OnStartSession(bool bWasSuccesful);
```
- Parameters
  - bool bWasSuccesful = true if succesfuly start the session
- Called on ```MultiplayerOnStartSessionComplete```
- No default implementation
--------------------------------------
***On Find Session Method***
```C++
void OnFindSession(const TArray<FOnlineSessionSearchResult>& SessionResult, bool bWasSuccesful);
```
- Parameters:
  - const TArray<FOnlineSessionSearchResult>& SessionResult = array sessions found.
  - bool bWasSuccesful.
- Called on ```MultiplayerOnFindSessionComplete```.
- Check if there is a valis session in the array based on "MatchType".
- If found call ```MultiplayerSessionSubsystem->JoinSession(Result);``` for the travel.
--------------------------------------
***On Join Session Method***
```C++
void OnJoinSession(EOnJoinSessionCompleteResult::Type Reuslt);
```
- Parameters:
  - EOnJoinSessionCompleteResult::Type Reuslt = enum that let you know the state of the joining process
- Get the IP Address and the Player controller (from the game instance) and call Client Travel
--------------------------------------
</blockquote></details>
<details><summary>  Private Members </summary><blockquote>	
	
### Private Members 
--------------------------------------
***Host Button Clicked Method***
```C++
UFUNCTION();
void HostButtonClicked();
```
- When Host button is clicked call ```MultiplayerSessionSubsystem->CreateSession(NumConnection, MatchType);```
--------------------------------------
***Join Button Clicked Method***
```C++
UFUNCTION();
void JoinButtonClicked();
```
- When Join button is clicked call ```MultiplayerSessionSubsystem->FindSession(MaxSessionResult);```
--------------------------------------
***Menu Tear Down Method***
```C++
void MenuTearDown();
```
- Add again input to the player
- Called when we have to destroy the menu widget
--------------------------------------
***Variables***
   
- UPROPERTY(meta = (BindWidget)) class UButton* HostButton; = used for link the button widget to our button variable in c++ the variable has to have the exact same name of the button
- UPROPERTY(meta = (BindWidget)) class UButton* JoinButton; = used for link the button widget to our button variable in c++ the variable has to have the exact same name of the button
- class UMultiplayerSessionSubsystem* MultiplayerSessionSubsystem; = the susbsystem designed to handle all online session
- int32 NumConnection{ 4 };
- int32 MaxSessionResult{ 10000 };
- FString MatchType{ TEXT("FreeForAll") };
- FString PathToLobby{ TEXT("") };
--------------------------------------

</blockquote></details>
</blockquote></details>

--------------------------------------
