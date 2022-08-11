// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities.h"
#include "AbilityTeleport.generated.h"

/**
 * 
 */

UCLASS()
class GAMEENGINES2FPS_API UAbilityTeleport : public UAbilities
{
	GENERATED_BODY()

public:
	void ActivateAbility_Implementation(class ACharacter* Player) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TeleportationDistance = 1000.0f;
};
