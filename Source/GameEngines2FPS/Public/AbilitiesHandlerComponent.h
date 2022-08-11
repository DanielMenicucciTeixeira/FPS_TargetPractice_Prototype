// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilitiesHandlerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEENGINES2FPS_API UAbilitiesHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbilitiesHandlerComponent();

	UFUNCTION()
		void OnPlayerColliderBeginOverlap
		(
			UPrimitiveComponent* OverllapedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComponent,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult
		);

	void ActivatePower();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UAbilities* CurrentAbility = nullptr;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Abilities Handler")
	class UAbilities* GetCurrentAbility();

		
};
