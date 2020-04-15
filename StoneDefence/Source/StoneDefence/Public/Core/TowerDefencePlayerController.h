// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tools/ScreenMove.h"
#include "TowerDefencePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API ATowerDefencePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	//Controller的构造函数
	ATowerDefencePlayerController();

	//Tick
	virtual void Tick(float DeltaSeconds)override;

    //初始化操作
	virtual void BeginPlay()override;

	//锁定鼠标在视口中
	void SetInputModeGameAndUI();

	//按键响应
	virtual void SetupInputComponent()override;

	//鼠标滚轮的方式
	void MouseWheelUp();
	void MouseWheelDown();
protected:
	FScreenMoveUnit ScreenMoveUnits;
};
