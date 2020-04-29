#pragma once

#include "CoreMinimal.h"

class ARuleOfTheCharacter;

namespace StoneDefenceUtils
{
	ARuleOfTheCharacter *FindCloestTarget(const TArray<ARuleOfTheCharacter*> &InCharacters, const FVector &Location);
}