// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
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

	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FName SocketName = Barrel->GetAllSocketNames()[0];
	FVector StartLocation = Barrel->GetSocketLocation(FName(SocketName));
	bool bFoundAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, TargetLocation, LaunchSpeed, ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bFoundAimSolution)
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}

	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// get barrel direction
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotation;
	Barrel->ElevateBarrel(5);
}

