// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "StoneDefenceGameModeBase.h"
#include "Core/TowerDefenceGameState.h"
#include "Core/TowerDefencePlayerController.h"
#include "Core/TowerDefenceGameCamera.h"
#include "Core/TowerDefencePlayerState.h"
#include "UI/GameUI/Core/RuleOfTheHUD.h"

AStoneDefenceGameModeBase::AStoneDefenceGameModeBase()
{
	//加载GameState
	GameStateClass = ATowerDefenceGameState::StaticClass();
	//加载PlayerController
	PlayerControllerClass = ATowerDefencePlayerController::StaticClass();
	//加载ControllerPawn
	DefaultPawnClass = ATowerDefenceGameCamera::StaticClass();
	//加载PlayerState
	PlayerStateClass = ATowerDefencePlayerState::StaticClass();
	//加载HUD
	HUDClass = ARuleOfTheHUD::StaticClass();
}
