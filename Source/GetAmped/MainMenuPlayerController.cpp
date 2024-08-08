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
            SetInputModeUIOnly(); // 입력 모드 설정 호출
        }
    }
}

void AMainMenuPlayerController::SetInputModeUIOnly()
{
    if (CurrentWidget)
    {
        FInputModeUIOnly InputMode; // 입력 모드를 UI 전용으로 설정
        InputMode.SetWidgetToFocus(CurrentWidget->TakeWidget()); // 사용자가 UI와 상호작용 가능
        SetInputMode(InputMode); // 플레이어 컨트롤러의 입력 모드 설정
        bShowMouseCursor = true; // 마우스 커서를 보이게 설정
    }
}