// Fill out your copyright notice in the Description page of Project Settings.


#include "BetterProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ABetterProjectile::ABetterProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileRootComponent = CreateDefaultSubobject<USceneComponent>("ProjectileRoot");
	SetRootComponent(ProjectileRootComponent);

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("ProjectileMesh");
	ProjectileMesh->SetSimulatePhysics(true);
	ProjectileMesh->SetNotifyRigidBodyCollision(true);
	ProjectileMesh->SetCollisionProfileName("Projectile");
	ProjectileMesh->SetupAttachment(ProjectileRootComponent);
}

void ABetterProjectile::AddNewProjectileVelocity(FVector NewVelocity)
{
	if (ProjectileMesh && ProjectileMesh->IsSimulatingPhysics())
	{
		ProjectileMesh->AddForce(NewVelocity, NAME_None, true);
	}
}

void ABetterProjectile::DestroyProjectile()
{
	this->Destroy();
}

void ABetterProjectile::OnProjectileColliderHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	BumpUp();
	if(!UKismetSystemLibrary::K2_IsTimerActive(this, "DestroyProjectile")) UKismetSystemLibrary::K2_SetTimer(this, "DestroyProjectile", 0.0016f, false, 0.5f);
}

void ABetterProjectile::StickToSurface(AActor* Suface)
{
	ProjectileMesh->SetCollisionProfileName("NoCollision");
	ProjectileMesh->ComponentVelocity = FVector(0);
}

void ABetterProjectile::BumpUp()
{
	FVector NewVelocity = GetActorUpVector() * (BumpUpwardSpeed - ProjectileMesh->GetComponentVelocity().Z);
	AddNewProjectileVelocity(NewVelocity);
}

// Called when the game starts or when spawned
void ABetterProjectile::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMesh->AddForce(GetActorTransform().GetRotation().Vector() * ProjectileSpeed);

	FScriptDelegate Delegate;
	Delegate.BindUFunction(this, "OnProjectileColliderHit");
	ProjectileMesh->OnComponentHit.Add(Delegate);
}

// Called every frame
void ABetterProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

