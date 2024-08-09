// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include <Components/SlateWrapperTypes.h>
#include "SlateCore.h"
#include "Components/Button.h"
#include "LobbyWidget.generated.h"
/**
 * 
 */
UCLASS()
class GETAMPED_API ULobbyWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;
    
    UFUNCTION()
    void OnStartButtonClicked();

    UFUNCTION(BlueprintCallable, Category = "Console")
    void ExecuteConsoleCommand(const FString& Command);

public:
    UPROPERTY(meta = (BindWidget))
    UBorder* StartBoard;

    UPROPERTY(meta = (BindWidget))
    UButton* Start_Button;

    UFUNCTION(BlueprintCallable, Category = "UI")
    void SetStartBoardVisibility(ESlateVisibility isVisible);
};
