// Fill out your copyright notice in the Description page of Project Settings.


#include "NichProjectile.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
ANichProjectile::ANichProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->SetCollisionProfileName("Projectile");
	RootComponent = SphereComponent;

	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComponent");
	EffectComp->SetupAttachment(SphereComponent);

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComponent");
	MovementComponent->InitialSpeed = 1000.f;
	MovementComponent->bRotationFollowsVelocity = true;
	MovementComponent->bInitialVelocityInLocalSpace = true;
	
}

// Called when the game starts or when spawned
void ANichProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANichProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

