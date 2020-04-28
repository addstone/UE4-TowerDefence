// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/Character/IRuleOfCharacter.h"
#include "Core/TowerDefencePlayerController.h"
#include "Core/TowerDefenceGameState.h"
#include "RuleOfTheCharacter.generated.h"

UCLASS()
class STONEDEFENCE_API ARuleOfTheCharacter : public ACharacter, public IRuleOfCharacter
{
	GENERATED_BODY()
		
	//射线捕捉对象
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	class UBoxComponent* TraceShowCharacterInformation;

	//开火点
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	class UArrowComponent* FirePoint;

	//角色信息显示
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	class UWidgetComponent* Widget;

	//子弹跟踪点
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	class USceneComponent* HomingPoint;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attribute")
	bool bAttack;

public:
	// Sets default values for this character's properties
	ARuleOfTheCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//接受伤害
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	//是否死亡
	virtual bool IsDeath();

	//获取生命值
	virtual float GetHealth();

	//获取最大生命值
	virtual float GetMaxHealth();

	//是否为一个队伍
	virtual bool IsTeam();

public:
	UFUNCTION(Blueprintable, BlueprintPure, Category = "Towers|Attribute")
	bool IsActive() { return !IsDeath(); };

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//获取PlayerController
	FORCEINLINE ATowerDefencePlayerController* GetGameController() { return GetWorld() ? GetWorld()->GetFirstPlayerController<ATowerDefencePlayerController>() : NULL; }

	//获取GameState
	FORCEINLINE ATowerDefenceGameState* GetGameState() { return GetWorld() ? GetWorld()->GetGameState<ATowerDefenceGameState>() : NULL; }

	//获取跟踪点
	FORCEINLINE USceneComponent* GetHomingPoint() const { return HomingPoint; };

	//获取开火点
	FORCEINLINE UArrowComponent* GetFirePoint() const { return FirePoint; };
};
