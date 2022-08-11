// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitiesHandlerComponent.h"
#include "GameFramework/Character.h"
#include "AbilitiesPickUp.h"
#include "Abilities.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameEngines2FPS/GameEngines2FPSCharacter.h"

// Sets default values for this component's properties
UAbilitiesHandlerComponent::UAbilitiesHandlerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UAbilitiesHandlerComponent::OnPlayerColliderBeginOverlap(UPrimitiveComponent* OverllapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AAbilitiesPickUp* NewPickUp = Cast<AAbilitiesPickUp>(OtherActor))
	{
		CurrentAbility = NewObject<UAbilities>(this, NewPickUp->Ability);
	}
}

void UAbilitiesHandlerComponent::ActivatePower()
{
	if (CurrentAbility)
	{
		CurrentAbility->ActivateAbility(Cast<ACharacter>(GetOwner()));
	}
}

// Called when the game starts
void UAbilitiesHandlerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (AGameEngines2FPSCharacter* Player = Cast<AGameEngines2FPSCharacter>(GetOwner()))
	{
		FScriptDelegate Delegate;
		Delegate.BindUFunction(this, "OnPlayerColliderBeginOverlap");
		Player->GetCapsuleComponent()->OnComponentBeginOverlap.Add(Delegate);
	}

	// ...
	
}


// Called every frame
void UAbilitiesHandlerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UAbilities* UAbilitiesHandlerComponent::GetCurrentAbility()
{
	return CurrentAbility;
}

