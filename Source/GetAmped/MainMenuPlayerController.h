#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h" // UUserWidget 헤더 파일 포함
#include "MainMenuPlayerController.generated.h"

/**
 *
 */
    UCLASS()
    class GETAMPED_API AMainMenuPlayerController : public APlayerController
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<UUserWidget> WidgetClass;

    UUserWidget* CurrentWidget;

    void SetInputModeUIOnly();
};