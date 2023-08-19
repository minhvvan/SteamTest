// Fill out your copyright notice in the Description page of Project Settings.


#include "SG_PlayerProfile.h"
#include "SteamTestGameInstance.h"


void USG_PlayerProfile::SetPlayerName(FString name)
{
	PlayPfofile.PlayerName = name;

	score = 10;
}

void USG_PlayerProfile::Print()
{
	UE_LOG(LogTemp, Warning, TEXT("aa%s"), *(PlayPfofile.PlayerName));
	UE_LOG(LogTemp, Warning, TEXT("score: %d"), score);
}
