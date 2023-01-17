// Fill out your copyright notice in the Description page of Project Settings.


#include "NichItemChest.h"

// Sets default values
ANichItemChest::ANichItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	BaseMesh->SetupAttachment(RootComponent);
	
	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>("LidMesh");
	LidMesh->SetupAttachment(BaseMesh);
}

// Called when the game starts or when spawned
void ANichItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANichItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANichItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	LidMesh->SetRelativeRotation(FRotator(110,0,0));
}

