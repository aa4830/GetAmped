// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyMenuPlayerController.h"
#include "Engine/World.h"
#include "MyGameInstance.h"

void ALobbyMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    CreateLobbyWidget();

    UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
    if (GameInstance != nullptr)
    {
        UserName = GameInstance->NewUserName;
    }
}

void ALobbyMenuPlayerController::SetInputModeUIOnly()
{
    if (CurrentWidget != nullptr)
    {
        FInputModeUIOnly InputMode;
        InputMode.SetWidgetToFocus(CurrentWidgetInstance->TakeWidget());
        SetInputMode(InputMode);
        bShowMouseCursor = true; 
    }
}

void ALobbyMenuPlayerController::CreateLobbyWidget()
{
    if (CurrentWidget != nullptr)
    {
        CurrentWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), CurrentWidget);
        if (CurrentWidgetInstance != nullptr)
        {
            CurrentWidgetInstance->AddToViewport();
        }
    }
}
