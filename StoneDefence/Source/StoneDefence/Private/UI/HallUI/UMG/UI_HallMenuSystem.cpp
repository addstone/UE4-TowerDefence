// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HallUI/UMG/UI_HallMenuSystem.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UUI_HallMenuSystem::NativeConstruct()
{
	Super::NativeConstruct();

	GameStartButton->OnClicked.AddDynamic(this, &UUI_HallMenuSystem::GameStart);
	SecretTerritoryButton->OnClicked.AddDynamic(this, &UUI_HallMenuSystem::SecretTerritory);
	HistoryButton->OnClicked.AddDynamic(this, &UUI_HallMenuSystem::History);
	GameSettingsButton->OnClicked.AddDynamic(this, &UUI_HallMenuSystem::GameSettings);
	TutorialWebsiteButton->OnClicked.AddDynamic(this, &UUI_HallMenuSystem::TutorialWebsite);
	BrowserButton->OnClicked.AddDynamic(this, &UUI_HallMenuSystem::Browser);
	SpecialContentButton->OnClicked.AddDynamic(this, &UUI_HallMenuSystem::SpecialContent);
	GameQuitButton->OnClicked.AddDynamic(this, &UUI_HallMenuSystem::QuitGame);
}

void UUI_HallMenuSystem::GameStart()
{
	UGameplayStatics::OpenLevel(GetWorld(), "SelectLevel");
}

void UUI_HallMenuSystem::SecretTerritory()
{

}

void UUI_HallMenuSystem::History()
{

}

void UUI_HallMenuSystem::GameSettings()
{

}

void UUI_HallMenuSystem::TutorialWebsite()
{

}

void UUI_HallMenuSystem::Browser()
{

}

void UUI_HallMenuSystem::SpecialContent()
{

}

void UUI_HallMenuSystem::QuitGame()
{

}
