// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h" 
#include "MyGameInstance.h"
#include "LobbyMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GETAMPED_API ALobbyMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<UUserWidget> CurrentWidget;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	UUserWidget* CurrentWidgetInstance;

	UFUNCTION(BlueprintCallable, Category = "Widgets")
	void CreateLobbyWidget();

	FString UserName;

protected:
	virtual void BeginPlay() override;

private:

	void SetInputModeUIOnly();
};
