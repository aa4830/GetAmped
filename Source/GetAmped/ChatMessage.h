// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "ChatMessage.generated.h"


/**
 * 
 */
UCLASS()
class GETAMPED_API UChatMessage : public UUserWidget
{
	GENERATED_BODY()
public:

    virtual void NativeConstruct() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = true))
    FText MyText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = true))
    FString MyUserName;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* Chat_Text;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* PlayerName_Text;
    
};
