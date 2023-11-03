// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "GlobalEnum.h"
#include "GlobalStruct.generated.h"


USTRUCT(BlueprintType)
struct FCardInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	public:
	UPROPERTY(EditAnywhere, Category = "Info")
	ECardTier tier;

	UPROPERTY(EditAnywhere, Category = "Info")
	int score;

	UPROPERTY(EditAnywhere, Category = "Info")
	int bonus;

	UPROPERTY(EditAnywhere, Category = "Info")
	int crown;

	UPROPERTY(EditAnywhere, Category = "Info")
	ETokenColor color;

	UPROPERTY(EditAnywhere, Category = "Info")
	TMap<ETokenColor, int> cost;

	UPROPERTY(EditAnywhere, Category = "Info")
	TArray<EItem> item;
};

UCLASS()
class STEAMTEST_API UGlobalStruct : public UObject
{
	GENERATED_BODY()
	
};
