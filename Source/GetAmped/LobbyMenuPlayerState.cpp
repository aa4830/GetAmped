// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyMenuPlayerState.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Hud.h"
#include "LobbyMenuPlayerController.h"
#include "LobbyMenuHud.h"
#include "Engine/World.h"

void ALobbyMenuPlayerState::UpdateReady(bool IsReady)
{
	AmIReady = IsReady;
}

void ALobbyMenuPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALobbyMenuPlayerState, AmIReady);
	DOREPLIFETIME(ALobbyMenuPlayerState, UserName);
}

void ALobbyMenuPlayerState::SavePlayerName(const FString& NewUserName)
{
	UserName = NewUserName;
}

void ALobbyMenuPlayerState::BeginPlay()
{
	UWorld* World = GetWorld();
	APlayerController* PlayerController = World->GetFirstPlayerController();
	AHUD* NewHUD = PlayerController->GetHUD();
	ALobbyMenuHud* MyHUD = Cast<ALobbyMenuHud>(NewHUD);
	MyHUD->BindPlayerState(this);
}

void ALobbyMenuPlayerState::OnRep_IsReady()
{
	OnIsReadyChanged();
}
void ALobbyMenuPlayerState::OnIsReadyChanged()
{
	CallEventDispatcherToWgLobby.Broadcast();
}

void ALobbyMenuPlayerState::OnRep_UserName()
{
	OnUserNameChanged();
}

void ALobbyMenuPlayerState::OnUserNameChanged()
{
	CallEventDispatcherSaveUserName.Broadcast();
}
