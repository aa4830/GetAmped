// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "LobbyMenuHud.generated.h"

/**
 * 
 */
UCLASS()
class GETAMPED_API ALobbyMenuHud : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	UUserWidget* LobbyWidgetInstance;

	UFUNCTION(BlueprintCallable, Category = "Widgets")
	void SetVisibleStartBoard();

	UFUNCTION(BlueprintCallable, Category = "Widgets")
	void GetLobbyWidgetInstanceAndAddViewPort();
protected:
	virtual void BeginPlay() override;
};
