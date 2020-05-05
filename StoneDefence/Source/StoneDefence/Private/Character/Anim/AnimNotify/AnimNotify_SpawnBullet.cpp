// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/Anim/AnimNotify/AnimNotify_SpawnBullet.h"
#include "Character/Core/RuleOfTheCharacter.h"
#include "Character/Bullet/RuleOfTheBullet.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/ArrowComponent.h"

UAnimNotify_SpawnBullet::UAnimNotify_SpawnBullet()
	:Super()
{
	InSocketName = TEXT("OpenFire");
}

FString UAnimNotify_SpawnBullet::GetNotifyName_Implementation() const
{
	if (BulletClass)
	{
		return BulletClass->GetName();
	}
	else
	{
		return Super::GetNotifyName_Implementation();	
	}
}

void UAnimNotify_SpawnBullet::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
#if WITH_EDITOR
	FVector ComponentLocation = MeshComp->GetSocketLocation(InSocketName);
	FRotator ComponentRotation = MeshComp->GetSocketRotation(InSocketName);
	if (AActor* Character = Cast<AActor>(MeshComp->GetOuter()))
#else
	FVector ComponentLocation = Character->GetFirePoint()->GetComponentLocation();
	FRotator ComponentRotation = Character->GetFirePoint()->GetComponentRotation();
	if (ARuleOfTheCharacter* Character = Cast<ARuleOfTheCharacter>(MeshComp->GetOuter()))
#endif
	{
		if (ARuleOfTheBullet* Bullet = Character->GetWorld()->SpawnActor<ARuleOfTheBullet>(BulletClass, ComponentLocation, ComponentRotation))
		{

		}
	}
}
