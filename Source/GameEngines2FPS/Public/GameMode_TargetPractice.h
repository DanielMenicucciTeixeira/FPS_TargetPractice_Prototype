// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameMode_TargetPractice.generated.h"

/**
 * 
 */
UCLASS()
class GAMEENGINES2FPS_API AGameMode_TargetPractice : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameMode_TargetPractice();

	UPROPERTY(BlueprintReadWrite, Category = "Timer")
	float TimeRemaining = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Timer")
	float InitialTime = 5.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Timer")
	float MaxTime = 5.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Timer")
	float TotalTime = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Targets")
	int TotalTargets = 0;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Targets")
	int TargetsHit = 0;

	UFUNCTION(BlueprintCallable)
	void HitTarget();

	UFUNCTION(BlueprintNativeEvent)
	void GameOver();

	void GameOver_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void Victory();

	void Victory_Implementation();

	UFUNCTION(BlueprintCallable)
	void AddTime(float ExtraTime);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void InitialSetUp();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
