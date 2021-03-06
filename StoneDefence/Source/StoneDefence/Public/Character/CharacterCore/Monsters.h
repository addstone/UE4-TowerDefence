// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Core/RuleOfTheCharacter.h"
#include "../StoneDefenceType.h"
#include "Monsters.generated.h"

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API AMonsters : public ARuleOfTheCharacter
{
	GENERATED_BODY()
public:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	virtual EGameCharacterType::Type GetType();
	virtual bool IsTeam();
};
