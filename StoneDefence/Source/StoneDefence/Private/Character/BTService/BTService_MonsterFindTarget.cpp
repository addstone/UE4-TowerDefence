// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BTService/BTService_MonsterFindTarget.h"
#include "Character/AIController/MonsterAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "Character/Core/RuleOfTheCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBTService_MonsterFindTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	ARuleOfTheAIController* MonsterAIController = Cast<ARuleOfTheAIController>(OwnerComp.GetOwner());
	UBlackboardComponent* BlackBoard = OwnerComp.GetBlackboardComponent();

	if (MonsterAIController)
	{
		if (BlackBoard)
		{
			ARuleOfTheCharacter* NewTarget = Cast<ARuleOfTheCharacter>(MonsterAIController->FindTarget());
			if (NewTarget)
			{
				if (MonsterAIController->Target != NewTarget)
				{
					ARuleOfTheCharacter* MonsterSelf = Cast<ARuleOfTheCharacter>(MonsterAIController->GetPawn());
					if (MonsterSelf)
					{
						MonsterSelf->GetCharacterMovement()->StopMovementImmediately();
					}
					MonsterAIController->Target = NewTarget;
				}
				if (MonsterAIController->Target.IsValid())
				{
					if (MonsterAIController->Target->IsActive())
					{
						FVector NewTargetV = MonsterAIController->GetPawn()->GetActorLocation() - MonsterAIController->Target.Get()->GetActorLocation();
						NewTargetV.Normalize();
						FVector NextLocation = NewTargetV * 800.f + MonsterAIController->Target.Get()->GetActorLocation();
						BlackBoard->SetValueAsObject(BlackBoardKey_Target.SelectedKeyName, MonsterAIController->Target.Get());
						BlackBoard->SetValueAsVector(BlackBoardKey_TargetLocation.SelectedKeyName, NextLocation);
					}
					else
					{
						BlackBoard->SetValueAsObject(BlackBoardKey_Target.SelectedKeyName, NULL);
						BlackBoard->SetValueAsVector(BlackBoardKey_TargetLocation.SelectedKeyName, FVector::ZeroVector);
					}
				}
				else
				{
					BlackBoard->SetValueAsObject(BlackBoardKey_Target.SelectedKeyName, NULL);
					BlackBoard->SetValueAsVector(BlackBoardKey_TargetLocation.SelectedKeyName, FVector::ZeroVector);
				}
			}

			if (MonsterAIController->Target.IsValid())
			{
				FVector MonsterLocation = MonsterAIController->GetPawn()->GetActorLocation();
				FVector TMDistance = MonsterLocation - MonsterAIController->Target->GetActorLocation();
				if (TMDistance.Size() > 2200)
				{
					ARuleOfTheCharacter* Monster = Cast<ARuleOfTheCharacter>(MonsterAIController->GetPawn());
					if (Monster)
					{
						Monster->bAttack = false;
					}
				}
				BlackBoard->SetValueAsFloat(BlackBoardKey_Distance.SelectedKeyName, TMDistance.Size());
			}
			else
			{
				BlackBoard->SetValueAsFloat(BlackBoardKey_Distance.SelectedKeyName, 0.0f);
			}
		}
	}
}
