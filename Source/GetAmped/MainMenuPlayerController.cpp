#include "MainMenuPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"

void AMainMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (WidgetClass != nullptr)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
        if (CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
            SetInputModeUIOnly();
        }
    }
}

void AMainMenuPlayerController::SetInputModeUIOnly()
{
    if (CurrentWidget)
    {
        FInputModeUIOnly InputMode;
        InputMode.SetWidgetToFocus(CurrentWidget->TakeWidget()); 
        SetInputMode(InputMode); 
        bShowMouseCursor = true; 
    }
}