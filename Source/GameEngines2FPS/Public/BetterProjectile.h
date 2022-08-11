// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BetterProjectile.generated.h"

class UStaticMeshComponent;

UCLASS(Blueprintable, BlueprintType)
class GAMEENGINES2FPS_API ABetterProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABetterProjectile();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "BetterProjectile | Default")
	UStaticMeshComponent* ProjectileMesh = nullptr;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "BetterProjectile | Default")
	USceneComponent* ProjectileRootComponent = nullptr;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "BetterProjectile | Default")
	float ProjectileSpeed = 5000000.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "BetterProjectile | Default")
	float BumpUpwardSpeed = 50000.0f;

	UFUNCTION(BlueprintCallable, Category = "BetterProjectile | Default")
	void AddNewProjectileVelocity(FVector NewVelocity);

	UFUNCTION(BlueprintCallable)
	void DestroyProjectile();

	UFUNCTION()
	void OnProjectileColliderHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintCallable)
	void StickToSurface(AActor* Suface);

	UFUNCTION(BlueprintCallable)
	void BumpUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
