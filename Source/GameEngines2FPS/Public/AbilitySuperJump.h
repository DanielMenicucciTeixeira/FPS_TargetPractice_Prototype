// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities.h"
#include "AbilitySuperJump.generated.h"

/**
 * 
 */

UCLASS()
class GAMEENGINES2FPS_API UAbilitySuperJump : public UAbilities
{
	GENERATED_BODY()
	
public:
	void ActivateAbility_Implementation(class ACharacter* Player) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float JumpMultiplier = 3.0f;
};
