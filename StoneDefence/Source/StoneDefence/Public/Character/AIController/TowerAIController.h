// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AIController/RuleOfTheAIController.h"
#include "TowerAIController.generated.h"

class ARuleOfTheCharacter;

UCLASS()
class STONEDEFENCE_API ATowerAIController : public ARuleOfTheAIController
{
	GENERATED_BODY()

public:
	ATowerAIController();

	virtual void Tick(float DeltaTime) override;

	virtual AActor *FindTarget();

protected:

	void BTService_FindTarget();

	virtual void AttackTarget(ARuleOfTheCharacter* Target);
	//¥Ê¥¢π÷ŒÔ
	UPROPERTY()
	TArray<ARuleOfTheCharacter*> TArrayMonsters;

	float HeartbeatDiagnosis;

	TWeakObjectPtr<ARuleOfTheCharacter> Target;
};
