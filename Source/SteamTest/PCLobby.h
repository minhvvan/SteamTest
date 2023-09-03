// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PCLobby.generated.h"

/**
 * 
 */
UCLASS()
class STEAMTEST_API APCLobby : public APlayerController
{
	GENERATED_BODY()
	
public:
	APCLobby();

	UFUNCTION()
	void BeginPlay() override;

	UFUNCTION(Server, Reliable)
	void SRSpawnPlayer();

	UFUNCTION()
	void ShowLobby();

	UFUNCTION()
	void FirstPlayerClicked();

	UFUNCTION()
	void SecondPlayerClicked();

	UFUNCTION(Server, Reliable)
	void SRFirstPlayerClicked();

	UFUNCTION(Server, Reliable)
	void SRSecondPlayerClicked();

	UFUNCTION(NetMulticast, Reliable)
	void MarkFirst(const FString& name);

	UFUNCTION(NetMulticast, Reliable)
	void MarkSecond(const FString& name);

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> LobbyClass;

	UPROPERTY(VisibleAnywhere)
	class UHUDLobby* WidgetLobby;
};
