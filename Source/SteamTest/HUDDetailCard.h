// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GlobalStruct.h"
#include "HUDDetailCard.generated.h"

DECLARE_MULTICAST_DELEGATE(FBuyCard);

UCLASS()
class STEAMTEST_API UHUDDetailCard : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeOnInitialized();

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UButton* BtnBuy;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UButton* BtnBack;	
	
	UPROPERTY(VisibleAnywhere, meta = (BindWidgetOptional))
	class UHUDCard* CardInfo;

	//!---------OwnToken---------------
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* TxtOwnRed;
	
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* TxtOwnGreen;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* TxtOwnBlue;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* TxtOwnWhite;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* TxtOwnBlack;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* TxtOwnGold;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* TxtOwnPearl;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* TxtMessage;

	//!---------Anim-------------------
	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
	class UWidgetAnimation* FailedBuy;	
	
	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
	class UWidgetAnimation* MessageAnim;

public:
	//!-----Dele----------
	//FBuyCard OnBuyCard;

private:
	UPROPERTY()
	FCardInfo Info;

	//smartPtr 필요할수도
	UPROPERTY()
	FTokenCountList UseTokens;

public:
	UFUNCTION()
	void SetCardInfo(struct FCardInfo& info_);

	UFUNCTION()
	void BuyClicked();

	UFUNCTION()
	void BackClicked();

	UFUNCTION()
	bool CheckCanBuy();

	UFUNCTION()
	void RenderMessage(FString message);
};
