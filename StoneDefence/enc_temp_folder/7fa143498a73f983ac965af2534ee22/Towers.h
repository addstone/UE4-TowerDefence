// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Core/RuleOfTheCharacter.h"
#include "../StoneDefenceType.h"
#include "Towers.generated.h"

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API ATowers : public ARuleOfTheCharacter
{
	GENERATED_BODY()

	//塔本身是一个粒子特效
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	class UParticleSystemComponent* ParticleMesh;

	//可建造的范围
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	class UStaticMeshComponent* StaticMeshBuilding;

	//摧毁后的MESH
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	class UDestructibleComponent* DestructibleMeshBuilding;

public:
	ATowers();

	//旋转变量
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute")
	FRotator TowersRotator;

	virtual EGameCharacterType::Type GetType();

protected:
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
};
