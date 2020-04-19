// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/TowerDefenceGameInstance.h"
#include "Modules/ModuleManager.h"
#include "SimpleScreenLoading.h"

void UTowerDefenceGameInstance::Init()
{
	Super::Init();

	FSimpleScreenLoadingModule &SimpleScreenLoadingModule = FModuleManager::LoadModuleChecked<FSimpleScreenLoadingModule>("SimpleScreenLoading");
	SimpleScreenLoadingModule.SetupScreenLoading();
}
