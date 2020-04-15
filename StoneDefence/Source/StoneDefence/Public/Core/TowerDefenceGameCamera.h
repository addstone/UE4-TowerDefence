// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TowerDefenceGameCamera.generated.h"

UCLASS()
class STONEDEFENCE_API ATowerDefenceGameCamera : public APawn
{
	GENERATED_BODY()

	//������������볡���ľ���
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "True"))
		class USpringArmComponent* CameraBoom;

	//�������
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "True"))
		class UCameraComponent* MainCamera;

	//���������ײ��ʶ
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "True"))
		class UBoxComponent* MarkBox;

public:
	// Sets default values for this pawn's properties
	ATowerDefenceGameCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Zoom(bool bDirection, const float &ZoomSpeed);

};
