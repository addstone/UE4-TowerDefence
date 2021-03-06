// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../StoneDefenceType.h"
#include "RuleOfTheBullet.generated.h"

UCLASS()
class STONEDEFENCE_API ARuleOfTheBullet : public AActor
{
	GENERATED_BODY()

	//碰撞盒子
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = "True"))
	class USphereComponent* BoxDamage;

	//根组件
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = "True"))
	class USceneComponent* RootBullet;

	//具有移动属性的组件
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = "True"))
	class UProjectileMovementComponent* ProjectileMovement;
public:	
	// Sets default values for this actor's properties
	ARuleOfTheBullet();

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Bullet")
	TEnumAsByte<EBulletType> BulletType;

	//子弹伤害特效
	UPROPERTY(EditDefaultsOnly, Category = "Bullet")
	class UParticleSystem* DamageParticle;

	//开火特效
	UPROPERTY(EditDefaultsOnly, Category = "Bullet")
	class UParticleSystem* OpenFireParticle;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
