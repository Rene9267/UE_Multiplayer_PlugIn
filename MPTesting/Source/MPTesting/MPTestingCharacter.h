// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"

#include "Interfaces/OnlineSessionInterface.h"

#include "MPTestingCharacter.generated.h"

UCLASS(config = Game)
class AMPTestingCharacter : public ACharacter
{
	GENERATED_BODY()

		/** Camera boom positioning the camera behind the character */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* LookAction;

public:
	AMPTestingCharacter();


protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);


protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }


	//Online Base function
public:

	//Pointer to the online session Interface
	IOnlineSessionPtr OnlineSssionInterface;

	// in this way we can avoid using the hader but we'll need the inlude there
	//TSharedPtr<class IOnlineSession, ESPMode::ThreadSafe> OnlineSssionInterface;


#pragma region Lan Connection function
	UFUNCTION(BlueprintCallable)
		void OpenLobby();

	UFUNCTION(BlueprintCallable)
		void CallOpenLevl(const FString& Address);

	UFUNCTION(BlueprintCallable)
		void CallClientTravel(const FString& Address);
#pragma endregion

protected:

	//all session create logic
	UFUNCTION(BlueprintCallable)
		void CreateGameSession();

	UFUNCTION(BlueprintCallable)
		void JoinGameSession();

#pragma region Callback Function
	//Callback Function for the delegate
	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);

	//callback for find session
	//this'll reflect the success or not for the find 
	//called in response to the delegate sent by the session interface once complete find the session
	void OnFindSessionComplete(bool bWasSuccessful);

	//callback for joining the session
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result); //will be passed the session name and the status of the join for inform us if we join the session or not
#pragma endregion

private:

#pragma region Delegates
	//delegate variable creation
	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
	//delegate for find session
	FOnFindSessionsCompleteDelegate FindSessionCompleteDelegate;
	FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;
#pragma endregion


	TSharedPtr<FOnlineSessionSearch> SessionSearch;
};

