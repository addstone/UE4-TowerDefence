// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HallUI/UMG/UI_HallMenuSystem.h"
#include "Kismet/GameplayStatics.h"

void UUI_HallMenuSystem::NativeConstruct()
{
	Super::NativeConstruct();
}

void UUI_HallMenuSystem::BindGameStart(FOnButtonClickedEvent ClickEvent)
{
	GameStartButton->OnClicked = ClickEvent;
}

void UUI_HallMenuSystem::BindSecretTerritory(FOnButtonClickedEvent ClickEvent)
{
	SecretTerritoryButton->OnClicked = ClickEvent;
}

void UUI_HallMenuSystem::BindHistory(FOnButtonClickedEvent ClickEvent)
{
	HistoryButton->OnClicked = ClickEvent;
}

void UUI_HallMenuSystem::BindGameSettings(FOnButtonClickedEvent ClickEvent)
{
	GameSettingsButton->OnClicked = ClickEvent;
}

void UUI_HallMenuSystem::BindTutorialWebsite(FOnButtonClickedEvent ClickEvent)
{
	TutorialWebsiteButton->OnClicked = ClickEvent;
}

void UUI_HallMenuSystem::BindBrowser(FOnButtonClickedEvent ClickEvent)
{
	BrowserButton->OnClicked = ClickEvent;
}

void UUI_HallMenuSystem::BindSpecialContent(FOnButtonClickedEvent ClickEvent)
{
	SpecialContentButton->OnClicked = ClickEvent;
}

void UUI_HallMenuSystem::BindQuit(FOnButtonClickedEvent ClickEvent)
{
	GameQuitButton->OnClicked = ClickEvent;
}

