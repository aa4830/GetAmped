// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h" 
#include "MyGameInstance.h"
#include "LobbyMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GETAMPED_API ALobbyMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> CurrentWidget;

	UPROPERTY(BlueprintReadOnly)
	class ULobbyWidget* CurrentWidgetInstance;

	UFUNCTION(BlueprintCallable)
	void CreateLobbyWidget();

	UFUNCTION(Server, Reliable, WithValidation)
	void ReqUpdateReady(APlayerController* PlayerController, bool IsReady);
	void ReqUpdateReady_Implementation(APlayerController* PlayerController, bool IsReady);
	bool ReqUpdateReady_Validate(APlayerController* PlayerController, bool IsReady);

	UFUNCTION(Server, Reliable, WithValidation)
	void ReqUpdateChat(const FText& Text, const FString& MyUserName);
	void ReqUpdateChat_Implementation(const FText& Text, const FString& MyUserName);
	bool ReqUpdateChat_Validate(const FText& Text, const FString& MyUserName);

	UFUNCTION(Client, Reliable)
	void ResUpdateChat(const FText& Text, const FString& MyUserName);
	void ResUpdateChat_Implementation(const FText& Text, const FString& MyUserName);

	UFUNCTION(Client, Reliable)
	void ReqOnPossessClient(APawn* PossessedPawn);
	void ReqOnPossessClient_Implementation(APawn* PossessedPawn);

	UFUNCTION(Server, Reliable, WithValidation)
	void ReqSavePlayerName(const FString& NewUserName);
	void ReqSavePlayerName_Implementation(const FString& NewUserName);
	bool ReqSavePlayerName_Validate(const FString& NewUserName);

	UFUNCTION(Server, Reliable, WithValidation)
	void ReqSetVisibleStartBoard();
	void ReqSetVisibleStartBoard_Implementation();
	bool ReqSetVisibleStartBoard_Validate();

	UFUNCTION(Server, Reliable, WithValidation)
	void ReqSetInVisibleStartBoard();
	void ReqSetInVisibleStartBoard_Implementation();
	bool ReqSetInVisibleStartBoard_Validate();

	FString UserName;

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* PossessedPawn) override;

private:

	void SetInputModeUIOnly();
};
