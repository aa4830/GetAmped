// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "PlayerNameWidget.generated.h"

/**
 * 
 */
UCLASS()
class GETAMPED_API UPlayerNameWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(meta = (BindWidget))
	UButton* Button_OK;

	UFUNCTION()
	void OnStartButtonClicked();

	UFUNCTION(BlueprintImplementableEvent, Category = "Custom")
	void OnClickedButton_OK();
};
