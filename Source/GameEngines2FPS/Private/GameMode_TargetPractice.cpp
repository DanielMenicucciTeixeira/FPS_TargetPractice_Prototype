// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode_TargetPractice.h"
#include "GameEngines2FPS/GameEngines2FPSCharacter.h"
#include "BaseTarget.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

AGameMode_TargetPractice::AGameMode_TargetPractice()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AGameMode_TargetPractice::InitialSetUp()
{
	TimeRemaining = InitialTime;
	TotalTime = 0.0f;
	TotalTargets = 0;
	TargetsHit = 0;

	//RestAllTargets
	for (TActorIterator<ABaseTarget> TargetItr(GetWorld()); TargetItr; ++TargetItr)
	{
		TargetItr->ResetTarget();
		TotalTargets++;
	}
}

void AGameMode_TargetPractice::HitTarget()
{
	TargetsHit++;
	if (TargetsHit >= TotalTargets) Victory();
}

void AGameMode_TargetPractice::GameOver_Implementation()
{
}

void AGameMode_TargetPractice::Victory_Implementation()
{
}

void AGameMode_TargetPractice::AddTime(float ExtraTime)
{
	TimeRemaining += ExtraTime;
	if (TimeRemaining > MaxTime) TimeRemaining = MaxTime;
}

void AGameMode_TargetPractice::BeginPlay()
{
	Super::BeginPlay();

	InitialSetUp();
}

void AGameMode_TargetPractice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TimeRemaining < 0) GameOver();
	else TimeRemaining -= DeltaTime;

	TotalTime += DeltaTime;
}
