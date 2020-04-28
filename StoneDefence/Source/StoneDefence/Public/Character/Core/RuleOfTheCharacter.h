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
		
	//���߲�׽����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	class UBoxComponent* TraceShowCharacterInformation;

	//�����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	class UArrowComponent* FirePoint;

	//��ɫ��Ϣ��ʾ
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttribute", meta = (AllowPrivateAccess = true))
	class UWidgetComponent* Widget;

	//�ӵ����ٵ�
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

	//�����˺�
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	//�Ƿ�����
	virtual bool IsDeath();

	//��ȡ����ֵ
	virtual float GetHealth();

	//��ȡ�������ֵ
	virtual float GetMaxHealth();

	//�Ƿ�Ϊһ������
	virtual bool IsTeam();

public:
	UFUNCTION(Blueprintable, BlueprintPure, Category = "Towers|Attribute")
	bool IsActive() { return !IsDeath(); };

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//��ȡPlayerController
	FORCEINLINE ATowerDefencePlayerController* GetGameController() { return GetWorld() ? GetWorld()->GetFirstPlayerController<ATowerDefencePlayerController>() : NULL; }

	//��ȡGameState
	FORCEINLINE ATowerDefenceGameState* GetGameState() { return GetWorld() ? GetWorld()->GetGameState<ATowerDefenceGameState>() : NULL; }

	//��ȡ���ٵ�
	FORCEINLINE USceneComponent* GetHomingPoint() const { return HomingPoint; };

	//��ȡ�����
	FORCEINLINE UArrowComponent* GetFirePoint() const { return FirePoint; };
};
