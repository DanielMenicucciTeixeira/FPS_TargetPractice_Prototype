 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbilitySuperJump.h"
#include "GameEngines2FPS/GameEngines2FPSCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UAbilitySuperJump::ActivateAbility_Implementation(ACharacter* Player)
 {
    if (UCharacterMovementComponent* CharacterMovement = Cast<UCharacterMovementComponent>(Player->GetCharacterMovement()))
    {
        CharacterMovement->JumpZVelocity = CharacterMovement->JumpZVelocity * JumpMultiplier;
    }
 }
