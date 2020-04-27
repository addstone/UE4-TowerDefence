// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Core/RuleOfTheCharacter.h"
#include "Components/SceneComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ARuleOfTheCharacter::ARuleOfTheCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HomingPoint = CreateDefaultSubobject<USceneComponent>(TEXT("HomingPoint"));
	Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	FirePoint = CreateDefaultSubobject<UArrowComponent>(TEXT("SpawnPoint"));
	TraceShowCharacterInformation = CreateDefaultSubobject<UBoxComponent>(TEXT("TranceBox"));

	HomingPoint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Widget->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	FirePoint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	TraceShowCharacterInformation->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	//设置碰撞为Scanning
	TraceShowCharacterInformation->SetCollisionProfileName("Scanning");
	//设置检测盒子的碰撞大小
	TraceShowCharacterInformation->SetBoxExtent(FVector(38, 38, 100));
}

// Called when the game starts or when spawned
void ARuleOfTheCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

float ARuleOfTheCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	return 0;
}

bool ARuleOfTheCharacter::IsDeath()
{
	return false;
}

float ARuleOfTheCharacter::GetHealth()
{
	return 0;
}

float ARuleOfTheCharacter::GetMaxHealth()
{
	return 0;
}

bool ARuleOfTheCharacter::IsTeam()
{
	return false;
}

// Called every frame
void ARuleOfTheCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


