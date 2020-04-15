// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RuleOfTheWidget.h"
#include "UI_PlaySkillSystem.generated.h"

class UUI_SkillSlot;

UCLASS()
class STONEDEFENCE_API UUI_PlaySkillSystem : public UUI_RuleOfTheWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UUI_SkillSlot* FreezeSkill;

	UPROPERTY(meta = (BindWidget))
	UUI_SkillSlot* ExplosionSkill;

	UPROPERTY(meta = (BindWidget))
	UUI_SkillSlot* RecoverySkill;

	UPROPERTY(meta = (BindWidget))
	UUI_SkillSlot* RecoveryMainTowerSkill;

public:
	virtual void NativeConstruct();

private:
	/*FKey FreezeSkillKey;
	FKey ExplosionSkillKey;
	FKey RecoverySkillKey;
	FKey RecoveryMainTowerSkillKey;
*/
};
