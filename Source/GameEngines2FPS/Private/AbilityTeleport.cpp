// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityTeleport.h"
#include "GameEngines2FPS/GameEngines2FPSCharacter.h"
#include "GameFramework/Character.h"

void UAbilityTeleport::ActivateAbility_Implementation(ACharacter* Player)
{
	if (Player)
	{
		FVector Direction = Player->GetTransform().GetRotation().Vector();
		Player->SetActorLocation(Player->GetTransform().GetLocation() + Direction * TeleportationDistance);
	}
}