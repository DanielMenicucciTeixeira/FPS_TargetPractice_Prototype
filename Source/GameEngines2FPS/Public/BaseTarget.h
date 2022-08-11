// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTarget.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAMEENGINES2FPS_API ABaseTarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	class AGameMode_TargetPractice* GameMode = nullptr;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Target | Mesh")
	class USceneComponent* TargetRootComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Target | Mesh")
	class UStaticMeshComponent* TargetMesh = nullptr;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Target | Mesh")
	class UMaterialInstance* NotHitMaterial = nullptr;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Target | Mesh")
	class UMaterialInstance* HitMaterial = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Target | Default")
	bool WasHit = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Target | Timer")
	float ExtraTime = 2.0f;

	UFUNCTION()
	void OnTargetHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintCallable)
	void AwardHit();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void ResetTarget();

};
