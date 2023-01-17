// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NichItemChest.generated.h"

UCLASS()
class ACTIONROUGELIKE_API ANichItemChest : public AActor
{
	GENERATED_BODY()

	void Interact_Implementation(APawn* InstigatorPawn);
	
public:	
	// Sets default values for this actor's properties
	ANichItemChest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LidMesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
