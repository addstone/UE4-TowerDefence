// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AIController/MonsterAIController.h"
#include "Character/CharacterCore/Towers.h"
#include "EngineUtils.h"

using namespace std;

AActor * AMonsterAIController::FindTarget()
{
	auto GetCloestTower = [&](const TArray<ATowers*> &MyTowers) -> ATowers*
	{
		if (MyTowers.Num() > 0)
		{
			float TowerTargetDistance = 99999999;
			int32 TowerIndex = INDEX_NONE;
			FVector MyLocation = GetPawn()->GetActorLocation();
			for (int32 i = 0 ; i < MyTowers.Num(); i++)
			{
				if (ATowers* TowerCharacter = MyTowers[i])
				{
					FVector TowerLoaction = TowerCharacter->GetActorLocation();
					FVector TMDistance = TowerLoaction - MyLocation;
					float TowerAndMonsterDistance = TMDistance.Size();

					if (TowerAndMonsterDistance < TowerTargetDistance)
					{
						TowerIndex = i;
						TowerTargetDistance = TowerAndMonsterDistance;
					}
				}
			}
			if (TowerIndex != INDEX_NONE)
			{
				return MyTowers[TowerIndex];
			}
		}
		return NULL;
	};

	TArray<ATowers*> TargetMainTowersArray;
	TArray<ATowers*> TargetTowersArray;

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

	ATowers* MainTower = GetCloestTower(TargetMainTowersArray);
	ATowers* NormalTower = GetCloestTower(TargetTowersArray);

	if (MainTower)
	{
		return MainTower;
	}

	return NormalTower;
}
