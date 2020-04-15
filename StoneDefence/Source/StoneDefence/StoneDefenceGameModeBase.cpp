// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "StoneDefenceGameModeBase.h"
#include "Core/TowerDefenceGameState.h"
#include "Core/TowerDefencePlayerController.h"
#include "Core/TowerDefenceGameCamera.h"
#include "Core/TowerDefencePlayerState.h"
#include "UI/GameUI/Core/RuleOfTheHUD.h"

AStoneDefenceGameModeBase::AStoneDefenceGameModeBase()
{
	//����GameState
	GameStateClass = ATowerDefenceGameState::StaticClass();
	//����PlayerController
	PlayerControllerClass = ATowerDefencePlayerController::StaticClass();
	//����ControllerPawn
	DefaultPawnClass = ATowerDefenceGameCamera::StaticClass();
	//����PlayerState
	PlayerStateClass = ATowerDefencePlayerState::StaticClass();
	//����HUD
	HUDClass = ARuleOfTheHUD::StaticClass();
}
