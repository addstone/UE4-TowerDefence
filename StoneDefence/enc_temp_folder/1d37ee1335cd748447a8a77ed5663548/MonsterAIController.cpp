// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AIController/MonsterAIController.h"
#include "Character/CharacterCore/Towers.h"
#include "EngineUtils.h"
#include "../StoneDefenceUtils.h"

using namespace std;

AActor * AMonsterAIController::FindTarget()
{
	TArray<ARuleOfTheCharacter*> TargetMainTowersArray;
	TArray<ARuleOfTheCharacter*> TargetTowersArray;

	for (TActorIterator<ATowers> it(GetWorld(), ATowers::StaticClass()); it; ++it)
	{
		ATowers* TheCharacter = *it;
		if (TheCharacter && TheCharacter->IsActive())
		{
			if (TheCharacter->GetType() == EGameCharacterType::Type::TOWER)
			{
				TargetTowersArray.Add(TheCharacter);
			}
			else if (TheCharacter->GetType() == EGameCharacterType::Type::MAIN_TOWER)
			{
				TargetMainTowersArray.Add(TheCharacter);
			}
		}
	}

	ATowers* MainTower = Cast<ATowers>(StoneDefenceUtils::FindCloestTarget(TargetMainTowersArray, GetPawn()->GetActorLocation()));
	ATowers* NormalTower = Cast<ATowers>(StoneDefenceUtils::FindCloestTarget(TargetTowersArray, GetPawn()->GetActorLocation()));

	if (MainTower)
	{
		return MainTower;
	}

	return NormalTower;
}

void AMonsterAIController::AttackTarget(ARuleOfTheCharacter* Target)
{

}
