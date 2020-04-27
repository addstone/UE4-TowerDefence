// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RuleOfTheWidget.h"
#include "UI_MainHall.generated.h"

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_MainHall : public UUI_RuleOfTheWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
	class UUI_HallMenuSystem* HallMenuSystem;

	UPROPERTY(meta = (BindWidget))
	class UBorder* MainBorder;

	UPROPERTY(meta = (BindWidget))
	class USizeBox* BoxList;

	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UUI_SaveAndLoadSystem> SaveAndLoadSystemClass;

	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UUI_GameSettingsSystem> GameSettingsSystemClass;

	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UUI_TutoriaSystem> TutoriaSystemClass;


public:
	//UMG≥ı ºªØ
	virtual void NativeConstruct();

	UFUNCTION()
	void GameStart();

	UFUNCTION()
	void SecretTerritory();

	UFUNCTION()
	void History();

	UFUNCTION()
	void GameSettings();

	UFUNCTION()
	void TutorialWebsite();

	UFUNCTION()
	void Browser();

	UFUNCTION()
	void SpecialContent();

	UFUNCTION()
	void QuitGame();
};
