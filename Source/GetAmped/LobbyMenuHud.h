// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "LobbyMenuPlayerState.h"
#include "LobbyWidget.h"
#include "LobbyMenuHud.generated.h"

/**
 * 
 */
UCLASS()
class GETAMPED_API ALobbyMenuHud : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	ULobbyWidget* LobbyWidgetInstance;

	UFUNCTION(BlueprintCallable)
	void SetVisibleStartBoard();

	UFUNCTION(BlueprintCallable)
	void SetInVisibleStartBoard();

	UFUNCTION(BlueprintCallable)
	void GetLobbyWidgetInstanceAndAddViewPort();

	UFUNCTION()
	void BindPlayerState(ALobbyMenuPlayerState* PlayerState);

	UFUNCTION()
	void SaveUserName(FString NewUserName);

	UFUNCTION()
	void IsAllReady();

	UFUNCTION()
	void HandleEventDispatcher();

	UPROPERTY()
	bool IsAllRD;

protected:
	virtual void BeginPlay() override;
};
