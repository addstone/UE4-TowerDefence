// Fill out your copyright notice in the Description page of Project Settings.


#include "HallCore/TowerDefenceHallGameMode.h"
#include "UI/HallUI/Core/TowerDefenceHallHUD.h"
#include "HallCore/TowerDefenceHallPawn.h"
#include "HallCore/TowerDefenceHallPlayerController.h"

ATowerDefenceHallGameMode::ATowerDefenceHallGameMode()
{
	HUDClass = ATowerDefenceHallHUD::StaticClass();
	DefaultPawnClass = ATowerDefenceHallPawn::StaticClass();
	PlayerControllerClass = ATowerDefenceHallPlayerController::StaticClass();
}
