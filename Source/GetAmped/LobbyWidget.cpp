// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidget.h"
#include "Engine/World.h"
#include "Components/Button.h"
#include "GameFramework/PlayerController.h"
#include "SlateCore.h"

void ULobbyWidget::NativeConstruct()
{
    Super::NativeConstruct();
    StartBoard->SetVisibility(ESlateVisibility::Collapsed);
}

void ULobbyWidget::OnStartButtonClicked()
{

}
void ULobbyWidget::ExecuteConsoleCommand(const FString& Command)
{
    if (UWorld* World = GetWorld())
    {
        if (APlayerController* PlayerController = World->GetFirstPlayerController())
        {
        }
    }
}
void ULobbyWidget::SetStartBoardVisibility(ESlateVisibility isVisible)
{
    if (StartBoard != nullptr)
    {
        StartBoard->SetVisibility(isVisible);
    }
}
