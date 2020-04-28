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
	
	AMonsterAIController* MonsterAIController = Cast<AMonsterAIController>(OwnerComp.GetOwner());
	UBlackboardComponent* BlackBoard = OwnerComp.GetBlackboardComponent();

	if (MonsterAIController)
	{
		if (BlackBoard)
		{
			ARuleOfTheCharacter* NewTarget = Cast<ARuleOfTheCharacter>(MonsterAIController->FindTarget());
			if (NewTarget)
			{
				if (Target != NewTarget)
				{
					ARuleOfTheCharacter* MonsterSelf = Cast<ARuleOfTheCharacter>(MonsterAIController->GetPawn());
					if (MonsterSelf)
					{
						MonsterSelf->GetCharacterMovement()->StopMovementImmediately();
					}
					Target = NewTarget;
				}
				if (Target.IsValid())
				{
					if (Target.IsActive())
					{
						BlackBoard->SetValueAsObject(BlackBoardKey_Target.SelectedKeyName, Target.Get());
					}
					else
					{
						BlackBoard->SetValueAsObject(BlackBoardKey_Target.SelectedKeyName, NULL);
					}
				}
				else
				{
					BlackBoard->SetValueAsObject(BlackBoardKey_Target.SelectedKeyName, NULL);
				}
			}

			if (Target.IsValid())
			{
				FVector MonsterLocation = MonsterAIController->GetPawn()->GetActorLocation();
				FVector TMDidtance = MonsterLocation - Target->GetActorLocation();
				if (TMDidtance.Size() > 2200)
				{
					ARuleOfTheCharacter* Monster = Cast<ARuleOfTheCharacter>(MonsterAIController->GetPawn());
					if (Monster)
					{
						Monster->bAttack = false;
					}
				}
				BlackBoard->SetValueAsFloat(BlackBoardKey_Distance.SelectedKeyName, TMDidtance.Size());
			}
			else
			{
				BlackBoard->SetValueAsFloat(BlackBoardKey_Distance.SelectedKeyName, 0.0f);
			}
		}
	}
}
