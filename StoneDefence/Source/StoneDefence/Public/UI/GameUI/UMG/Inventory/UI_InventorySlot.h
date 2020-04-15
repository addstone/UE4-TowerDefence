// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RuleOfTheWidget.h"
#include "UI_InventorySlot.generated.h"

class UImage;
class UTextBlock;
class UButton;

UCLASS()
class STONEDEFENCE_API UUI_InventorySlot : public UUI_RuleOfTheWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
	UImage* TowersIcon;

	UPROPERTY(meta = (BindWidget))
	UImage* TowersCD;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TPBNumber;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TCOCNumber;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TowersCDValue;

	UPROPERTY(meta = (BindWidget))
	UButton* TISButton;

public:
	virtual void NativeConstruct();

	UFUNCTION()
	void OnClickedWidget();
};
