// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "UI/Core/UI_RuleOfTheWidget.h"
#include "UI_HallMenuSystem.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_HallMenuSystem : public UUI_RuleOfTheWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UButton* GameStartButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SecretTerritoryButton;

	UPROPERTY(meta = (BindWidget))
	UButton* HistoryButton;

	UPROPERTY(meta = (BindWidget))
	UButton* GameSettingsButton;

	UPROPERTY(meta = (BindWidget))
	UButton* TutorialWebsiteButton;

	UPROPERTY(meta = (BindWidget))
	UButton* BrowserButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SpecialContentButton;

	UPROPERTY(meta = (BindWidget))
	UButton* GameQuitButton;

public:

	virtual void NativeConstruct()override;

	void BindGameStart(FOnButtonClickedEvent ClickEvent);
	void BindSecretTerritory(FOnButtonClickedEvent ClickEvent);
	void BindHistory(FOnButtonClickedEvent ClickEvent);
	void BindGameSettings(FOnButtonClickedEvent ClickEvent);
	void BindTutorialWebsite(FOnButtonClickedEvent ClickEvent);
	void BindBrowser(FOnButtonClickedEvent ClickEvent);
	void BindSpecialContent(FOnButtonClickedEvent ClickEvent);
	void BindQuit(FOnButtonClickedEvent ClickEvent);
};
