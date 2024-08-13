// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "Components/TileView.h"
#include "Components/ScrollBox.h"
#include <Components/SlateWrapperTypes.h>
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/EditableText.h"
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

    UFUNCTION()
    void OnReadyButtonClicked();

    UFUNCTION(BlueprintCallable)
    void ExecuteConsoleCommand(const FString& Command);

    UFUNCTION()
    void OnChatTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<UUserWidget> MyWidgetClass;

    UFUNCTION(BlueprintCallable)
    void AddWidgetToScrollBox(FText Text, FString MyUserName);

public:
    UPROPERTY(meta = (BindWidget))
    UBorder* StartBoard;

    UPROPERTY(meta = (BindWidget))
    UButton* Start_Button;

    UPROPERTY(meta = (BindWidget))
    UButton* Ready_Button;

    UPROPERTY(meta = (BindWidget))
    UImage* Ready_Image;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTileView* Player_Tile;

    UPROPERTY(meta = (BindWidget))
    UEditableText* Chat_EditableText;

    UPROPERTY(meta = (BindWidget))
    UScrollBox* Chat_ScrollBox;

    UFUNCTION(BlueprintCallable, Category = "UI")
    void SetStartBoardVisibility(ESlateVisibility isVisible);

    UFUNCTION(BlueprintImplementableEvent, Category = "Custom")
    void UpdateTextAndImage();

    UFUNCTION()
    void UpdateChat(FText Text, FString MyUserName);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
    TSubclassOf<class ULobbyPlayerWidget> LobbyPlayerWidgetClass;
};

class MyFlipFlop
{
private:
    bool bIsATurn;

public:
    MyFlipFlop() : bIsATurn(true) {}

    bool FlipFlop()
    {
        bool CurrentState = bIsATurn;
        bIsATurn = !bIsATurn;
        return CurrentState;
    }
};
