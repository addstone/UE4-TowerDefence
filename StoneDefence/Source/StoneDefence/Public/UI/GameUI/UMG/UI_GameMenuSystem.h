// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RuleOfTheWidget.h"
#include "UI_GameMenuSystem.generated.h"

class UButton;

UCLASS()
class STONEDEFENCE_API UUI_GameMenuSystem : public UUI_RuleOfTheWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UButton* ReturnGameButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SaveGameButton;

	UPROPERTY(meta = (BindWidget))
	UButton* GameSettingsButton;

	UPROPERTY(meta = (BindWidget))
	UButton* GameQuitButton;

public:
	virtual void NativeConstruct();

	UFUNCTION()
	void ReturnGame();

	UFUNCTION()
	void SaveGame();

	UFUNCTION()
	void GameSettings();

	UFUNCTION()
	void QuitGame();
};
