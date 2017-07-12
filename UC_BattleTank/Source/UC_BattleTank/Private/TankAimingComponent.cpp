// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/SceneComponent.h"


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::AimAt(FVector TargetLocation, float LaunchSpeed)
{
	FString Name = GetOwner()->GetName();
	FVector BarrelLocation = Barrel->GetComponentLocation();

	UE_LOG(LogTemp, Warning, TEXT("%s Aiming at: %s from %s"), *Name, *TargetLocation.ToString(), *BarrelLocation.ToString());
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

