// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyMenuGameMode.h"
#include "GameFramework/PlayerController.h"

void ALobbyMenuGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

    if (NewPlayer)
    {
        PlayerControllers.Add(NewPlayer);

        UE_LOG(LogTemp, Warning, TEXT("Player Controller Added. Total Count: %d"), PlayerControllers.Num());
        for (APlayerController* PC : PlayerControllers)
        {
            if (PC)
            {
                UE_LOG(LogTemp, Warning, TEXT("PlayerController: %s"), *PC->GetName());
            }
        }
    }
}
