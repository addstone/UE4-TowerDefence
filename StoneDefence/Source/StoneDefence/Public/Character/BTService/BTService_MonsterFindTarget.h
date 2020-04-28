// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_MonsterFindTarget.generated.h"

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UBTService_MonsterFindTarget : public UBTService
{
	GENERATED_BODY()

public:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category = "BlackBoard")
	struct FBlackboardKeySelector BlackBoardKey_Target;

	UPROPERTY(EditAnywhere, Category = "BlackBoard")
	struct FBlackboardKeySelector BlackBoardKey_Distance;

public:
	virtual void OnGameplayTaskInitialized(UGameplayTask& Task) {}

	virtual void OnGameplayTaskActivated(UGameplayTask& Task) {}

	virtual void OnGameplayTaskDeactivated(UGameplayTask& Task) {}

private:
	TWeakObjectPtr<class ARuleOfTheCharacter> Target;
};
