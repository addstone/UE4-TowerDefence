// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RuleOfTheBullet.generated.h"

UCLASS()
class STONEDEFENCE_API ARuleOfTheBullet : public AActor
{
	GENERATED_BODY()

	//��ײ����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = "True"))
	class USphereComponent* BoxDamage;

	//�����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = "True"))
	class USceneComponent* RootBullet;

	//�����ƶ����Ե����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = "True"))
	class UProjectileMovementComponent* ProjectileMovement;
public:	
	// Sets default values for this actor's properties
	ARuleOfTheBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
