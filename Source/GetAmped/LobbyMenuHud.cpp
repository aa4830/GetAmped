// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyMenuHud.h"
#include "Blueprint/UserWidget.h"
#include "LobbyWidget.h"
#include "LobbyMenuPlayerState.h"
#include "Delegates/Delegate.h"
#include "Kismet/GameplayStatics.h"
#include "LobbyMenuPlayerController.h"

void ALobbyMenuHud::BeginPlay()
{
    Super::BeginPlay();
    GetLobbyWidgetInstanceAndAddViewPort();
    if (LobbyWidgetInstance != nullptr)
    {
        LobbyWidgetInstance->UpdateTextAndImage();
    }
}

void ALobbyMenuHud::SetVisibleStartBoard()
{
    if (LobbyWidgetInstance != nullptr)
    {
        ULobbyWidget* LobbyWidget = Cast<ULobbyWidget>(LobbyWidgetInstance);
        LobbyWidget->SetStartBoardVisibility(ESlateVisibility::Visible);
    }
}

void ALobbyMenuHud::SetInVisibleStartBoard()
{
    if (LobbyWidgetInstance != nullptr)
    {
        ULobbyWidget* LobbyWidget = Cast<ULobbyWidget>(LobbyWidgetInstance);
        LobbyWidget->SetStartBoardVisibility(ESlateVisibility::Collapsed);
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

void ALobbyMenuHud::BindPlayerState(ALobbyMenuPlayerState* PlayerState)
{
    if (PlayerState != nullptr)
    {
        PlayerState->CallEventDispatcherToWgLobby.AddDynamic(this, &ALobbyMenuHud::HandleEventDispatcher);
    }
    SaveUserName(PlayerState->UserName);

    if (PlayerState != nullptr)
    {
        PlayerState->CallEventDispatcherSaveUserName.AddDynamic(this, &ALobbyMenuHud::HandleEventDispatcher);
    }
    IsAllReady();
}

void ALobbyMenuHud::SaveUserName(const FString NewUserName)
{
    if (LobbyWidgetInstance != nullptr)
    {
        ULobbyWidget* LobbyWidget = Cast<ULobbyWidget>(LobbyWidgetInstance);
        LobbyWidget->UpdateTextAndImage();
    }
}

void ALobbyMenuHud::IsAllReady()
{
    UWorld* World = GetWorld();
    if (World !=nullptr)
    {
        TArray<AActor*> PlayerStates;
        UGameplayStatics::GetAllActorsOfClass(World, ALobbyMenuPlayerState::StaticClass(), PlayerStates);

        for (AActor* Actor : PlayerStates)
        {
            ALobbyMenuPlayerState* PlayerState = Cast<ALobbyMenuPlayerState>(Actor);
            if (PlayerState !=nullptr)
            {
                if (PlayerState->AmIReady)
                {
                    IsAllRD = true;
                }
                else
                {
                    IsAllRD = false;
                    APlayerController* PlayerController = GetOwningPlayerController();
                    if (PlayerController != nullptr)
                    {
                        ALobbyMenuPlayerController* MyPlayerController = Cast<ALobbyMenuPlayerController>(PlayerController);
                        if (MyPlayerController != nullptr)
                        {
                            MyPlayerController->ReqSetInVisibleStartBoard();
                            break;
                        }
                    }
                }
            }
        }
        if (IsAllRD)
        {
            APlayerController* PlayerController = GetOwningPlayerController();
            if (PlayerController != nullptr)
            {
                ALobbyMenuPlayerController* MyPlayerController = Cast<ALobbyMenuPlayerController>(PlayerController);
                if (MyPlayerController != nullptr)
                {
                    MyPlayerController->ReqSetVisibleStartBoard();
                }
            }
        }
    }
}

void ALobbyMenuHud::HandleEventDispatcher()
{
}
