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
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MultiplayerSessionSubsystem.generated.h"
```

### Public Member
Custom Delegate for MultiplayerMenu Class
```C++
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnCreateSessionComplete, bool, bWasSuccessful);
	FMultiplayerOnCreateSessionComplete MultiplayerOnCreateSessionComplete;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnDestroySessionComplete, bool, bWasSuccessful);
	FMultiplayerOnDestroySessionComplete MultiplayerOnDestroySessionComplete;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnStartSessionComplete, bool, bWasSuccessful);
	FMultiplayerOnStartSessionComplete MultiplayerOnStartSessionComplete;

DECLARE_MULTICAST_DELEGATE_TwoParams(FMultiplayerOnFindSessionComplete, const TArray<FOnlineSessionSearchResult>& SessionResult, bool bWasSuccessful);
	FMultiplayerOnFindSessionComplete MultiplayerOnFindSessionComplete;
```
