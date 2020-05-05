// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AIController/TowerAIController.h"
#include "Character/CharacterCore/Towers.h"
#include "EngineUtils.h"
#include "Character/CharacterCore/Monsters.h"
#include "../StoneDefenceUtils.h"
#include "Character/Core/RuleOfTheCharacter.h"

ATowerAIController::ATowerAIController()
{
	HeartbeatDiagnosis = 0.0f;
}

void ATowerAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	HeartbeatDiagnosis += DeltaTime;
	if (HeartbeatDiagnosis >= 0.5f)
	{
		BTService_FindTarget();
		HeartbeatDiagnosis = 0.0f;
	}
	
	if (TArrayMonsters.Num() > 0)
	{
		if (ATowers *Tower = GetPawn<ATowers>())
		{
			if (!Target.IsValid())
			{
				Target = Cast<ARuleOfTheCharacter>(FindTarget());
			}
			else
			{
				Tower->TowersRotator = FRotationMatrix::MakeFromX(Target->GetActorLocation() - GetPawn()->GetActorLocation()).Rotator();
				if (GetPawn() -> GetActorRotation() != FRotator::ZeroRotator)
				{
					Tower->TowersRotator -= GetPawn()->GetActorRotation();
				}
			}
		}
	}
}

AActor * ATowerAIController::FindTarget()
{
	if (TArrayMonsters.Num() > 0)
	{
		return StoneDefenceUtils::FindCloestTarget(TArrayMonsters, GetPawn()->GetActorLocation());
	}
	return nullptr;
}

void ATowerAIController::BTService_FindTarget()
{
	TArrayMonsters.Empty();
	if (ATowers *Tower = GetPawn<ATowers>())
	{
		if (Tower->IsActive())
		{
			for (TActorIterator<AMonsters>it(GetWorld(), AMonsters::StaticClass()); it; ++it)
			{
				if (AMonsters* TheCharacter = *it)
				{
					if (TheCharacter->IsActive())
					{
						FVector TDistance = TheCharacter->GetActorLocation() - GetPawn()->GetActorLocation();
						if (TDistance.Size() <= 1600)
						{
							TArrayMonsters.Add(TheCharacter);
						}
					}
				}
			}

			AttackTarget(Target.Get());
		}
	}
}

void ATowerAIController::AttackTarget(ARuleOfTheCharacter* Target1)
{
	if (ATowers* Tower = GetPawn<ATowers>())
	{
		if (TArrayMonsters.Num() > 0)
		{
			Tower->bAttack = true;
		}
		else
		{
			Tower->bAttack = false;
		}
	}
}
