// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AIController/RuleOfTheAIController.h"
#include "TowerAIController.generated.h"

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API ATowerAIController : public ARuleOfTheAIController
{
	GENERATED_BODY()

public:

	virtual AActor *FindTarget() { return nullptr; };
};
