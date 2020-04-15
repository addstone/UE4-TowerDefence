// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectLevel/TowerDefenceSelectLevelGameMode.h"
#include "UI/SelectLevelUI/Core/SelectLevelHUD.h"

ATowerDefenceSelectLevelGameMode::ATowerDefenceSelectLevelGameMode()
{
	HUDClass = ASelectLevelHUD::StaticClass();
}

void ATowerDefenceSelectLevelGameMode::BeginPlay()
{

}
