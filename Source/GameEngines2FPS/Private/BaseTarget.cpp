// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTarget.h"
#include "Materials/MaterialInstance.h"
#include "Components/StaticMeshComponent.h"
#include "GameMode_TargetPractice.h"
#include "Kismet/GameplayStatics.h"
#include "BetterProjectile.h"

// Sets default values
ABaseTarget::ABaseTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TargetRootComponent = CreateDefaultSubobject<USceneComponent>("TargetRoot");
	SetRootComponent(TargetRootComponent);

	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>("TargetMesh");
	TargetMesh->SetSimulatePhysics(false);
	TargetMesh->SetNotifyRigidBodyCollision(true);
	TargetMesh->SetCollisionProfileName("BlockAll");
	TargetMesh->SetupAttachment(TargetRootComponent);
}

// Called when the game starts or when spawned
void ABaseTarget::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<AGameMode_TargetPractice>(UGameplayStatics::GetGameMode(GetWorld()));

	TargetMesh->SetMaterial(0, NotHitMaterial);

	FScriptDelegate Delegate;
	Delegate.BindUFunction(this, "OnTargetHit");
	TargetMesh->OnComponentHit.Add(Delegate);
}

void ABaseTarget::OnTargetHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if(Cast<ABetterProjectile>(OtherActor) && !WasHit)
	{
		TargetMesh->SetMaterial(0, HitMaterial);
		AwardHit();
		WasHit = true;
	}
}

void ABaseTarget::AwardHit()
{
	if (GameMode)
	{
		GameMode->AddTime(ExtraTime);
		GameMode->HitTarget();
	}
}

void ABaseTarget::ResetTarget()
{
	TargetMesh->SetMaterial(0, NotHitMaterial);
	WasHit = false;
}

// Called every frame
void ABaseTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

