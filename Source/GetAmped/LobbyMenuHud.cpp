// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyMenuHud.h"
#include "Blueprint/UserWidget.h"
#include "LobbyWidget.h"
#include "LobbyMenuPlayerController.h"

void ALobbyMenuHud::BeginPlay()
{
    Super::BeginPlay();
    GetLobbyWidgetInstanceAndAddViewPort();
}

void ALobbyMenuHud::SetVisibleStartBoard()
{
    if (LobbyWidgetInstance != nullptr)
    {
        ULobbyWidget* LobbyWidget = Cast<ULobbyWidget>(LobbyWidgetInstance);
        LobbyWidget->SetStartBoardVisibility(ESlateVisibility::Visible);
    }
}

void ALobbyMenuHud::GetLobbyWidgetInstanceAndAddViewPort()
{
    APlayerController* PlayerController = GetOwningPlayerController();
    if (PlayerController != nullptr)
    {
        ALobbyMenuPlayerController* MyPlayerController = Cast<ALobbyMenuPlayerController>(PlayerController);
        if (MyPlayerController != nullptr)
        {
            LobbyWidgetInstance = MyPlayerController->CurrentWidgetInstance;
            LobbyWidgetInstance->AddToViewport();
        }
    }
}