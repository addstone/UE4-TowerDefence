// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BTTask/BTTask_AttackTarget.h"
#include "Character/AIController/MonsterAIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "Character/Core/RuleOfTheCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTask_AttackTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (AMonsterAIController* MonsterAIController = Cast<AMonsterAIController>(OwnerComp.GetOwner()))
	{
		if (UBlackboardComponent* BlackBoard = OwnerComp.GetBlackboardComponent())
		{
			if (Blackboard_Actor.SelectedKeyType == UBlackboardKeyType_Object::StaticClass())
			{			
				if (ARuleOfTheCharacter* MyPawn = Cast<ARuleOfTheCharacter>(MonsterAIController->GetPawn()))
				{
					if (ARuleOfTheCharacter* TargetTower = Cast<ARuleOfTheCharacter>(BlackBoard->GetValueAsObject(Blackboard_Actor.SelectedKeyName)))
					{
						MyPawn->bAttack = true;
						MonsterAIController->AttackTarget(TargetTower);
						return EBTNodeResult::Succeeded;
					}
					else
					{
						MyPawn->bAttack = false;
						return EBTNodeResult::Succeeded;
					}
				}
			}
		}
	}
	return EBTNodeResult::Failed;
}

void UBTTask_AttackTarget::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);
	
	if (UBlackboardData* BBAsset = GetBlackboardAsset())
	{
		Blackboard_Actor.ResolveSelectedKey(*BBAsset);
	}
	else
	{
		UE_LOG(LogBehaviorTree, Warning, TEXT("can't initialize task:%s"), *GetName());
	}
}
