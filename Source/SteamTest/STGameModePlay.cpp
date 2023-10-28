// Fill out your copyright notice in the Description page of Project Settings.


#include "STGameModePlay.h"
#include "PSPlayerInfo.h"
#include "GSPlay.h"
#include "TileManager.h"
#include "TokenManager.h"
#include "Kismet/GameplayStatics.h"
#include "TurnManager.h"
#include "PCPlay.h"

ASTGameModePlay::ASTGameModePlay()
{
	bUseSeamlessTravel = true;
}

void ASTGameModePlay::SwapPlayerControllers(APlayerController* OldPC, APlayerController* NewPC)
{
	Super::SwapPlayerControllers(OldPC, NewPC);
}

void ASTGameModePlay::InitPlayerTurn(APlayerController* Player, bool bFirst)
{
	if (TurnManager)
	{
		auto GS = GetGameState<AGSPlay>();
		
		if (GS)
		{
			for (auto PS : GS->PlayerArray)
			{
				TurnManager->InitPlayerTurn(PS->GetPlayerController(), Cast<APSPlayerInfo>(PS)->GetMyTurn());
			}
		}
	}
}

void ASTGameModePlay::StartPlay()
{
	Super::StartPlay();
}

void ASTGameModePlay::StartMatch()
{
	Super::StartMatch();

	TileManager = GetWorld()->SpawnActor<ATileManager>();
	TokenManager = GetWorld()->SpawnActor<ATokenManager>();
	TurnManager = GetWorld()->SpawnActor<ATurnManager>();
}

void ASTGameModePlay::SetTokenSpawnLoc(TArray<class AToken*>& Tokens)
{
	if (TileManager)
	{
		TileManager->SetTokenLocs(Tokens);
	}
}

void ASTGameModePlay::TokenClicked(AToken* ClickedToken, int cnt, bool bAble)
{
	if (ClickedToken)
	{
		int boardIdx = ClickedToken->GetIndex();

		if (TileManager)
		{
			TileManager->Clicked(boardIdx, cnt, bAble);
		}

		if (TokenManager)
		{
			TokenManager->SelectedToken(ClickedToken, bAble);
		}

		ClickedToken->Clicked();
	}
}

void ASTGameModePlay::PossessTokens(APlayerController* PC)
{
	if (TokenManager)
	{
		TokenManager->PossessTokens(PC);
	}

	if (TileManager)
	{
		TileManager->ClearSeletedTiles();
	}

	//�� ����
	if (TurnManager)
	{
		TurnManager->EndCurrentTurn();
	}
}

void ASTGameModePlay::HandleSeamlessTravelPlayer(AController*& C)
{
	Super::HandleSeamlessTravelPlayer(C);

	Cast<APCPlay>(C)->SRSetTurn();
}