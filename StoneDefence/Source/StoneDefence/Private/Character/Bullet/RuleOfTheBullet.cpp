// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Bullet/RuleOfTheBullet.h"
#include "Components/SphereComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "../StoneDefenceType.h"
#include "Character/Core/RuleOfTheCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"
#include "Character/AIController/RuleOfTheAIController.h"
#include "EngineUtils.h"

// Sets default values
ARuleOfTheBullet::ARuleOfTheBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxDamage = CreateDefaultSubobject<USphereComponent>(TEXT("BulletBoxDamage"));
	RootBullet = CreateDefaultSubobject<USceneComponent>(TEXT("BulletRootBullet"));
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("BulletProjectileMovement"));

	RootComponent = RootBullet;
	BoxDamage->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ProjectileMovement->MaxSpeed = 2000.f;
	ProjectileMovement->InitialSpeed = 1600.f;
	ProjectileMovement->ProjectileGravityScale = 0.f;
	ProjectileMovement->UpdatedComponent = BoxDamage;

	InitialLifeSpan = 4.0f;

	BulletType = EBulletType::BULLET_DIRECT_LINE;
}

// Called when the game starts or when spawned
void ARuleOfTheBullet::BeginPlay()
{
	Super::BeginPlay();

	switch (BulletType)
	{
	case EBulletType::BULLET_DIRECT_LINE:
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OpenFireParticle, GetActorLocation());
		break;
	case EBulletType::BULLET_LINE:
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OpenFireParticle, GetActorLocation());
		break;
	case EBulletType::BULLET_TRACK_LINE:
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OpenFireParticle, GetActorLocation());
		ProjectileMovement->bIsHomingProjectile = true;
		ProjectileMovement->bRotationFollowsVelocity = true;
		if (ARuleOfTheCharacter* InstigatorCharacter = Cast<ARuleOfTheCharacter>(Instigator))
		{
			if (ARuleOfTheAIController* InstigatorController = Cast<ARuleOfTheAIController>(InstigatorCharacter->GetController()))
			{
				if (ARuleOfTheCharacter* TargetCharacter = InstigatorController->Target.Get())
				{
					ProjectileMovement->HomingAccelerationMagnitude = 4000.0f;
					ProjectileMovement->HomingTargetComponent = TargetCharacter->GetHomingPoint();
				}
			}
		}
		break;
	}
	case EBulletType::BULLET_RANGE_LINE:
		break;
	case EBulletType::BULLET_RANGE:
	{
		ProjectileMovement->StopMovementImmediately();
		if (ARuleOfTheCharacter* InstigatorCharacter = Cast<ARuleOfTheCharacter>(Instigator))
		{
			TArray<AActor*> IgnoreActors;
			//TArray<AActor*> TargetActors;
			for (TActorIterator<ARuleOfTheCharacter> it(GetWorld(), ARuleOfTheCharacter::StaticClass()); it; ++it)
			{
				if (ARuleOfTheCharacter* TheCharacter = *it)
				{
					FVector VDistance = TheCharacter->GetActorLocation() - InstigatorCharacter->GetActorLocation();
					if (VDistance.Size() <= 1400.f)
					{
						if (TheCharacter->IsTeam() == InstigatorCharacter->IsTeam())
						{
							IgnoreActors.Add(TheCharacter);
						}
						else
						{
							UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DamageParticle, TheCharacter->GetActorLocation());
							//TargetActors.Add(TheCharacter);
						}
					}
				}	
			}
			UGameplayStatics::ApplyRadialDamageWithFalloff(GetWorld(), 100.f, 10.f, GetActorLocation(), 400.f, 1000.f, 0.5f, UDamageType::StaticClass(), IgnoreActors, Instigator);
		}
		break;
	}		
	case EBulletType::BULLET_CHAIN:
		ProjectileMovement->StopMovementImmediately();
		BoxDamage->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
	}

	BoxDamage->OnComponentBeginOverlap.AddUniqueDynamic(this, &ARuleOfTheBullet::BeginOverlap);
}

void ARuleOfTheBullet::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (ARuleOfTheCharacter* InstigatorCharacter = Cast<ARuleOfTheCharacter>(Instigator))
	{
		if (ARuleOfTheCharacter* OtherCharacter = Cast<ARuleOfTheCharacter>(OtherActor))
		{
			if (InstigatorCharacter->IsTeam() != OtherCharacter->IsTeam())
			{
				if (OtherCharacter->IsActive())
				{
					//生成伤害特效
					UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DamageParticle, SweepResult.Location);
				
					UGameplayStatics::ApplyDamage(OtherCharacter, 100.0f, InstigatorCharacter->GetController(), InstigatorCharacter, UDamageType::StaticClass());
				}
				switch (BulletType)
				{
				case EBulletType::BULLET_LINE:
				case EBulletType::BULLET_TRACK_LINE:
					Destroy();
					break;
				}
			}
		}
	}
}

// Called every frame
void ARuleOfTheBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

