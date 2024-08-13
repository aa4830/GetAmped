// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerNameWidget.h"
#include "Blueprint/UserWidget.h"

void UPlayerNameWidget::NativeConstruct()
{
	Super::NativeConstruct();
    if (Button_OK != nullptr)
    {
        Button_OK->OnClicked.AddDynamic(this, &UPlayerNameWidget::OnStartButtonClicked);
    }

}

void UPlayerNameWidget::OnStartButtonClicked()
{
    OnClickedButton_OK();
}
