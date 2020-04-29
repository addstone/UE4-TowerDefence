#include "StoneDefenceUtils.h"
#include "Character/Core/RuleOfTheCharacter.h"

ARuleOfTheCharacter * StoneDefenceUtils::FindCloestTarget(const TArray<ARuleOfTheCharacter*> &InCharacters, const FVector &Location)
{
		if (InCharacters.Num() > 0)
		{
			float Distance = 99999999;
			int32 Index = INDEX_NONE;

			for (int32 i = 0; i < InCharacters.Num(); i++)
			{
				if (ARuleOfTheCharacter* Character = InCharacters[i])
				{
					FVector CharacterLoaction = Character->GetActorLocation();
					FVector TMDistance = CharacterLoaction - Location;
					float TowerAndMonsterDistance = TMDistance.Size();

					if (TowerAndMonsterDistance < Distance && Character->IsActive())
					{
						Index = i;
						Distance = TowerAndMonsterDistance;
					}
				}
			}
			if (Index != INDEX_NONE)
			{
				return InCharacters[Index];
			}
		}
		return NULL;
}

