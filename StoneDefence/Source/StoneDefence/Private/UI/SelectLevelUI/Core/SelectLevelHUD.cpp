// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SelectLevelUI/Core/SelectLevelHUD.h"
#include "UObject/ConstructorHelpers.h"
#include "UI/SelectLevelUI/UMG/UI_SelectLevelMain.h"

ASelectLevelHUD::ASelectLevelHUD()
{
	static ConstructorHelpers::FClassFinder<UUI_SelectLevelMain> SelectMain_BPClass(TEXT("/Game/UI/Select/SelectMain_BP"));
	SelectLevelMainClass = SelectMain_BPClass.Class;
}

void ASelectLevelHUD::BeginPlay()
{
	Super::BeginPlay();
	SelectLevelMain = CreateWidget<UUI_SelectLevelMain>(GetWorld(), SelectLevelMainClass);
	SelectLevelMain->AddToViewport();
}
