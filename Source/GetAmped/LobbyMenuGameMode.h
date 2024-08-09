// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "LobbyMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class GETAMPED_API ALobbyMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<APlayerController*> PlayerControllers;

protected:
	virtual void PostLogin(APlayerController* NewPlayer) override;
};
