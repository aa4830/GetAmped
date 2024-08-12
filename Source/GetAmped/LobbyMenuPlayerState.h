// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "EngineMinimal.h"
#include "LobbyMenuPlayerState.generated.h"


/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEventDispatcher);

UCLASS()
class GETAMPED_API ALobbyMenuPlayerState : public APlayerState
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
	void UpdateReady(bool IsReady);

	UPROPERTY(ReplicatedUsing = OnRep_IsReady)
	bool AmIReady;

	UFUNCTION(BlueprintCallable)
	void SavePlayerName(const FString& NewUserName);


	UPROPERTY(ReplicatedUsing = OnRep_UserName)
	FString UserName;

	UPROPERTY(BlueprintAssignable)
	FOnEventDispatcher CallEventDispatcherToWgLobby;

	UPROPERTY(BlueprintAssignable)
	FOnEventDispatcher CallEventDispatcherSaveUserName;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnRep_IsReady();

	UFUNCTION()
	void OnIsReadyChanged();

	UFUNCTION()
	void OnRep_UserName();

	UFUNCTION()
	void OnUserNameChanged();

};
