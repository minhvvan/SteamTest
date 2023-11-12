// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "GlobalEnum.h"
#include "GlobalStruct.generated.h"

USTRUCT(BlueprintType)
struct FTokenCount
{
	GENERATED_USTRUCT_BODY()

public:
	FTokenCount() : Key(ETokenColor::E_End), Value(0) {};

	FTokenCount(ETokenColor key, int value) : Key(key), Value(value) {};

	UPROPERTY(EditAnywhere)
	ETokenColor Key;

	UPROPERTY(EditAnywhere)
	int Value;
};

USTRUCT(BlueprintType)
struct FTokenCountList
{
	GENERATED_USTRUCT_BODY()

public:
	TCheckedPointerIterator<FTokenCount,int32> begin()
	{
		return TokenCnt.begin();
	}

	TCheckedPointerIterator<FTokenCount, int32> end()
	{
		return TokenCnt.end();
	}

	void Init()
	{
		for (ETokenColor color : TEnumRange<ETokenColor>())
		{
			TokenCnt.Add({ color, 0 });
		}
	}

	int& operator[] (ETokenColor color)
	{
		for (int i = 0; i < TokenCnt.Num(); i++)
		{
			if(this->TokenCnt[i].Key == color) return this->TokenCnt[i].Value;
		}

		return temp;
	}

	const int& operator[] (ETokenColor color) const
	{
		for (int i = 0; i < TokenCnt.Num(); i++)
		{
			if (this->TokenCnt[i].Key == color) return this->TokenCnt[i].Value;
		}

		return temp;
	}

	int Num()
	{
		int total = 0;
		for (auto token : TokenCnt)
		{
			total += token.Value;
		}

		return total;
	}

	const TArray<FTokenCount>& Get()
	{
		return TokenCnt;
	}

private:
	UPROPERTY()
	TArray<FTokenCount> TokenCnt;

	int temp;
};

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
	TArray<FTokenCount> cost;

	UPROPERTY(EditAnywhere, Category = "Info")
	TArray<EItem> item;
};

USTRUCT(BlueprintType)
struct FTokenIdxColor
{
	GENERATED_USTRUCT_BODY()

public:
	FTokenIdxColor() : Idx(0), Color(ETokenColor::E_End) {};

	FTokenIdxColor(int idx, ETokenColor color) : Idx(idx), Color(color) {};

	UPROPERTY(EditAnywhere)
	int Idx;
	
	UPROPERTY(EditAnywhere)
	ETokenColor Color;

	bool operator== (const FTokenIdxColor& rhs)
	{
		return this->Idx == rhs.Idx && this->Color == rhs.Color;
	}

	bool operator< (const FTokenIdxColor& rhs) const
	{
		return this->Idx < rhs.Idx;
	}
};


UCLASS()
class STEAMTEST_API UGlobalStruct : public UObject
{
	GENERATED_BODY()
	
};
