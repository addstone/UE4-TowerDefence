// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameUI/UMG/UI_PlaySkillSystem.h"
#include "GameFramework/InputSettings.h"

void UUI_PlaySkillSystem::NativeConstruct()
{
	Super::NativeConstruct();
	
	/*auto KeyMapping = GetDefault<UInputSettings>()->ActionMappings.FindByPredicate([&](FInputActionKeyMapping & EntryUI) { return (EntryUI.ActionName == "FreezeSkill"); });
	auto KeyMapping = GetDefault<UInputSettings>()->ActionMappings.FindByPredicate([&](FInputActionKeyMapping & EntryUI) { return (EntryUI.ActionName == "ExplosionSkill"); });
	auto KeyMapping = GetDefault<UInputSettings>()->ActionMappings.FindByPredicate([&](FInputActionKeyMapping & EntryUI) { return (EntryUI.ActionName == "RecoverySkill"); });
	auto KeyMapping = GetDefault<UInputSettings>()->ActionMappings.FindByPredicate([&](FInputActionKeyMapping & EntryUI) { return (EntryUI.ActionName == "RecoveryMainTowerSkill"); });*/
}
