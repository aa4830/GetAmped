// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidget.h"
#include "Engine/World.h"
#include "ChatMessage.h"
#include "Components/Button.h"
#include "Components/TileView.h"
#include "GameFramework/PlayerController.h"
#include "LobbyMenuPlayerController.h"
#include "Components/EditableText.h"
#include "LobbyPlayerWidget.h"
#include "LobbyMenuPlayerState.h"
#include "Kismet/GameplayStatics.h"

MyFlipFlop FlipFlopInstance;

void ULobbyWidget::NativeConstruct()
{
    Super::NativeConstruct();
    StartBoard->SetVisibility(ESlateVisibility::Collapsed);
    if (Start_Button != nullptr)
    {
        Start_Button->OnClicked.AddDynamic(this, &ULobbyWidget::OnStartButtonClicked);
    }
    if (Ready_Button != nullptr)
    {
        Ready_Button->OnClicked.AddDynamic(this, &ULobbyWidget::OnReadyButtonClicked);
    }
    if (Chat_EditableText != nullptr)
    {
        Chat_EditableText->OnTextCommitted.AddDynamic(this, &ULobbyWidget::OnChatTextCommitted);
    }

}

void ULobbyWidget::OnStartButtonClicked()
{
    FString Command = TEXT("servertravel GetAmped_Level");
    ExecuteConsoleCommand(Command);

}

void ULobbyWidget::OnReadyButtonClicked()
{
    if (FlipFlopInstance.FlipFlop())
    {
        Ready_Image->SetVisibility(ESlateVisibility::Collapsed);
        UWorld* World = GetWorld();
        APlayerController* PlayerController = World->GetFirstPlayerController();
        ALobbyMenuPlayerController* MyPlayerController = Cast<ALobbyMenuPlayerController>(PlayerController);
        MyPlayerController->ReqUpdateReady(PlayerController, true);
    }
    else
    {
        Ready_Image->SetVisibility(ESlateVisibility::Visible);
        UWorld* World = GetWorld();
        APlayerController* PlayerController = World->GetFirstPlayerController();
        ALobbyMenuPlayerController* MyPlayerController = Cast<ALobbyMenuPlayerController>(PlayerController);
        MyPlayerController->ReqUpdateReady(PlayerController, false);
    }
}

void ULobbyWidget::ExecuteConsoleCommand(const FString& Command)
{
    if (UWorld* World = GetWorld())
    {
        if (APlayerController* PlayerController = World->GetFirstPlayerController())
        {
            PlayerController->ConsoleCommand(Command);
        }
    }
}
void ULobbyWidget::OnChatTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
    if (CommitMethod == ETextCommit::OnEnter)
    {
        UWorld* World = GetWorld();
        APlayerController* PlayerController = World->GetFirstPlayerController();
        ALobbyMenuPlayerController* MyPlayerController = Cast<ALobbyMenuPlayerController>(PlayerController);
        FString MyUserName = MyPlayerController->UserName;
        MyPlayerController->ReqUpdateChat(Text, MyUserName);
    }
}
void ULobbyWidget::UpdateChat(FText Text, FString MyUserName)
{
    UE_LOG(LogTemp, Warning, TEXT("Hello, Unreal Engine!"));
}
void ULobbyWidget::AddWidgetToScrollBox(FText Text, FString MyUserName)
{
    if (MyWidgetClass && Chat_ScrollBox != nullptr)
    {
        UWorld* World = GetWorld();
        if (World != nullptr)
        {
            UChatMessage* NewWidget = CreateWidget<UChatMessage>(World, MyWidgetClass);

            if (NewWidget != nullptr)
            {
                NewWidget->MyText = Text;
                NewWidget->MyUserName = MyUserName;

                Chat_ScrollBox->AddChild(NewWidget);
            }
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