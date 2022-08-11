// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Abilities.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class GAMEENGINES2FPS_API UAbilities : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Abilities")
	void ActivateAbility(class ACharacter* Player);
	virtual void ActivateAbility_Implementation(class ACharacter* Player) {};
	
};
