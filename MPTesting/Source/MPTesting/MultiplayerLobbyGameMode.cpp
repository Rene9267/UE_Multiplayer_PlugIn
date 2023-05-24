// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerLobbyGameMode.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"


void AMultiplayerLobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	//access to the game state
	if (GameState)
	{
		//return the game state base pointer
		int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num(); // now know the numb of player
		if (GEngine)
		{
			//Message for the number of player
			//the key one'll replace the old message avoiding spam
			GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Yellow, FString::Printf(TEXT("Players currentrly in game: %d"), NumberOfPlayers));

			//Message for every time someone join
			//the key one'll replace the old message avoiding spam
			//we can get the name from the player state accessible from APlayerController
			APlayerState* PlayerState = NewPlayer->GetPlayerState<APlayerState>();
			if (PlayerState)
			{
				FString PlayerName = PlayerState->GetPlayerName(); //return the name of a entering player
				GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Cyan, FString::Printf(TEXT("%s has joined the game"), *PlayerName));
			}
		}
	}
}

void AMultiplayerLobbyGameMode::Logout(AController* ExitingPlayer)
{
	Super::Logout(ExitingPlayer);

	if (GEngine)
	{
		APlayerState* PlayerState = ExitingPlayer->GetPlayerState<APlayerState>();
		if (PlayerState)
		{
			int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num(); // now know the numb of player
			GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Yellow, FString::Printf(TEXT("Players currentrly in game: %d"), NumberOfPlayers - 1));//-1 because the number is not ye updated

			FString PlayerName = PlayerState->GetPlayerName(); //return the name of a entering player
			GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Cyan, FString::Printf(TEXT("%s has exiting the game"), *PlayerName));
		}
	}

}
