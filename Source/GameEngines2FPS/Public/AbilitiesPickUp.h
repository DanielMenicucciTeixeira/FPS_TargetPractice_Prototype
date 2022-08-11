// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitiesPickUp.generated.h"

UCLASS()
class GAMEENGINES2FPS_API AAbilitiesPickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbilitiesPickUp();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities Pick Up")
	class UStaticMeshComponent* StaticMesh = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Abilities Pick Up")
	TSubclassOf<class UAbilities> Ability = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
