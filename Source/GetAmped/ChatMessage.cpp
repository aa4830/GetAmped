// Fill out your copyright notice in the Description page of Project Settings.


#include "ChatMessage.h"

void UChatMessage::NativeConstruct()
{
	Super::NativeConstruct();
	Chat_Text->SetText(MyText);
	FText UserNameText = FText::FromString(MyUserName);
	PlayerName_Text->SetText(UserNameText);
}
