// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/Anim/RuleOfAnimInstance.h"
#include "Character/Core/RuleOfTheCharacter.h"

URuleOfAnimInstance::URuleOfAnimInstance() : bDeath(false),bAttack(false),Speed(0.0f)
{

}

void URuleOfAnimInstance::NativeInitializeAnimation()
{

}

void URuleOfAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	ARuleOfTheCharacter* RuleOfTheCharacter = Cast<ARuleOfTheCharacter>(TryGetPawnOwner());
	if (RuleOfTheCharacter)
	{
		bAttack = RuleOfTheCharacter->bAttack;
		Speed = RuleOfTheCharacter->GetVelocity().Size();
		bDeath = !RuleOfTheCharacter->IsActive();
	}
}


