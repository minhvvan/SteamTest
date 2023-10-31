// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUDCardHolder.h"
#include "HUDDesk.generated.h"

/**
 * 
 */
UCLASS()
class STEAMTEST_API UHUDDesk : public UUserWidget
{
	GENERATED_BODY()
	

protected:
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UButton* BtnGetToken;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UButton* BtnFillToken;

	UPROPERTY(VisibleAnywhere, meta = (BindWidgetOptional))
	class UHUDCardHolder* CDHRed;	
	
	UPROPERTY(VisibleAnywhere, meta = (BindWidgetOptional))
	class UHUDPopUpPannel* PUPannel;

	//UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	//class UHUDCardHolder* CDHGreen;

	//UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	//class UHUDCardHolder* CDHBlue;

	//UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	//class UHUDCardHolder* CDHWhite;

	//UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	//class UHUDCardHolder* CDHBlack;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UHUDTokenHolder* TokenHolder;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* TxtScore;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* TxtCrown;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* TxtScroll;	
	
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* TxtTurn;	
	
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* TxtMessage;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
	class UWidgetAnimation* FailedGetAnim;

	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
	class UWidgetAnimation* MessageAnim;

	virtual void NativeOnInitialized();
public:
	void SetScoreTxt(int score);
	void SetCrownTxt(int crown);

	UFUNCTION()
	void SetScrollTxt(int scroll);
	void SetTurnTxt(FString turn);

	UFUNCTION()
	void BindState(class APSPlayerInfo* ps);

	UFUNCTION()
	void ChangedScroll();

	UFUNCTION()
	void NotifyOverToken();

	UFUNCTION()
	void ChangedToken();

	void RenderMessage(FString message);
private:
	UFUNCTION(BlueprintCallable)
	void GetTokenClicked();

	UFUNCTION(BlueprintCallable)
	void FilTokenClicked();	

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	USoundBase* FailSound;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> OverTokenClass;

	UPROPERTY()
	TWeakObjectPtr<APSPlayerInfo> CurrentState;
};
