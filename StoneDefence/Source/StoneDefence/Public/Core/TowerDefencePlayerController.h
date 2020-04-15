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
	//Controller�Ĺ��캯��
	ATowerDefencePlayerController();

	//Tick
	virtual void Tick(float DeltaSeconds)override;

    //��ʼ������
	virtual void BeginPlay()override;

	//����������ӿ���
	void SetInputModeGameAndUI();

	//������Ӧ
	virtual void SetupInputComponent()override;

	//�����ֵķ�ʽ
	void MouseWheelUp();
	void MouseWheelDown();
protected:
	FScreenMoveUnit ScreenMoveUnits;
};
