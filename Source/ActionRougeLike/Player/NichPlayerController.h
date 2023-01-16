// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NichPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROUGELIKE_API ANichPlayerController : public APlayerController
{
	GENERATED_BODY()
	ANichPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;
protected:
	virtual void SetupInputComponent() override;
};
