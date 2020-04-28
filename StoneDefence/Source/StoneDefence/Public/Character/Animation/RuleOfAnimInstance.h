// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RuleOfAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API URuleOfAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation();

	//�����ͼ��ı����仯
	virtual void NativeUpdateAnimation(float DeltaSeconds);

public:
	URuleOfAnimInstance();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
	bool bDeath;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
	bool bAttack;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
	float Speed;
};
