// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyMenuPlayerController.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "GameFramework/GameStateBase.h"
#include "LobbyMenuPlayerState.h"
#include "LobbyMenuHud.h"
#include "MyGameInstance.h"
#include "GetAmped/LobbyWidget.h"

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

void ALobbyMenuPlayerController::OnPossess(APawn* PossessedPawn)
{
    Super::OnPossess(PossessedPawn);
    if (PossessedPawn != nullptr)
    {
        ReqOnPossessClient(PossessedPawn);
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
        CurrentWidgetInstance = CreateWidget<ULobbyWidget>(GetWorld(), CurrentWidget);
        if (CurrentWidgetInstance != nullptr)
        {
            CurrentWidgetInstance->AddToViewport();
        }
    }
}

void ALobbyMenuPlayerController::ReqUpdateReady_Implementation(APlayerController* PlayerController, bool IsReady)
{
    APlayerState* NewPlayerState = PlayerController->GetPlayerState<APlayerState>();
    ALobbyMenuPlayerState* MyPlayerState = Cast<ALobbyMenuPlayerState>(NewPlayerState);
    MyPlayerState->UpdateReady(IsReady);
}

bool ALobbyMenuPlayerController::ReqUpdateReady_Validate(APlayerController* PlayerController, bool IsReady)
{
    return true;
}

void ALobbyMenuPlayerController::ReqUpdateChat_Implementation(const FText& Text, const FString& MyUserName)
{
    AGameStateBase* MyGameState = GetWorld()->GetGameState<AGameStateBase>();
    if (MyGameState != nullptr)
    {
        const TArray<APlayerState*>& PlayerArray = MyGameState->PlayerArray;

        for (APlayerState* MyPlayerState : PlayerArray)
        {
            if (MyPlayerState != nullptr)
            {
                UWorld* World = GetWorld();
                APlayerController* PlayerController = MyPlayerState->GetOwner<APlayerController>();
                ALobbyMenuPlayerController* MyPlayerController = Cast<ALobbyMenuPlayerController>(PlayerController);
                MyPlayerController->ResUpdateChat(Text, MyUserName);
            }
        }
    }
}

bool ALobbyMenuPlayerController::ReqUpdateChat_Validate(const FText& Text, const FString& MyUserName)
{
    return true;
}

void ALobbyMenuPlayerController::ResUpdateChat_Implementation(const FText& Text, const FString& MyUserName)
{
    if (CurrentWidgetInstance != nullptr)
    {
        CurrentWidgetInstance->UpdateChat(Text, MyUserName);
    }
}

void ALobbyMenuPlayerController::ReqOnPossessClient_Implementation(APawn* PossessedPawn)
{
    UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
    if (GameInstance != nullptr)
    {
        UserName = GameInstance->NewUserName;
    }
    ReqSavePlayerName(UserName);
}

void ALobbyMenuPlayerController::ReqSavePlayerName_Implementation(const FString& NewUserName)
{
    APlayerState* NewPlayerState = GetPlayerState<APlayerState>();
    ALobbyMenuPlayerState* MyPlayerState = Cast<ALobbyMenuPlayerState>(NewPlayerState);
    MyPlayerState->SavePlayerName(NewUserName);
}

bool ALobbyMenuPlayerController::ReqSavePlayerName_Validate(const FString& NewUserName)
{
    return true;
}

void ALobbyMenuPlayerController::ReqSetVisibleStartBoard_Implementation()
{
    UWorld* World = GetWorld();
    APlayerController* PlayerController = World->GetFirstPlayerController();
    AHUD* IsHUD = PlayerController->GetHUD();
    ALobbyMenuHud* LobbyHUD = Cast<ALobbyMenuHud>(IsHUD);
    LobbyHUD->SetVisibleStartBoard();
}

bool ALobbyMenuPlayerController::ReqSetVisibleStartBoard_Validate()
{
    return true;
}

void ALobbyMenuPlayerController::ReqSetInVisibleStartBoard_Implementation()
{
    UWorld* World = GetWorld();
    APlayerController* PlayerController = World->GetFirstPlayerController();
    AHUD* IsHUD = PlayerController->GetHUD();
    ALobbyMenuHud* LobbyHUD = Cast<ALobbyMenuHud>(IsHUD);
    LobbyHUD->SetInVisibleStartBoard();
}

bool ALobbyMenuPlayerController::ReqSetInVisibleStartBoard_Validate()
{
    return true;
}
