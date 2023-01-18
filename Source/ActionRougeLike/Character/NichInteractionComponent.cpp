// Fill out your copyright notice in the Description page of Project Settings.


#include "NichInteractionComponent.h"

#include "NichCharacter.h"
#include "ActionRougeLike/Interface/NichGameplayInterface.h"

// Sets default values for this component's properties
UNichInteractionComponent::UNichInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UNichInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UNichInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UNichInteractionComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	AActor* MyOwner = GetOwner();
	FVector EyeLocation;
	FRotator EyeRotation;
	MyOwner->GetActorEyesViewPoint(EyeLocation,EyeRotation);
	FVector End = EyeLocation + (1000 * EyeRotation.Vector());
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(Hit,EyeLocation,End,ObjectQueryParams);

	if(	AActor* HitActor = Hit.GetActor())
	{
		if(HitActor->Implements<UNichGameplayInterface>())
		{
			INichGameplayInterface::Execute_Interact(HitActor,Cast<APawn>(MyOwner));
		}
	}
	DrawDebugLine(GetWorld(),EyeLocation,End,FColor::Red,false,2.0f);
}


