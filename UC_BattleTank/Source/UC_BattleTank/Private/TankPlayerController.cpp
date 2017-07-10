// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	controlledTank = GetControlledTank();
	if (!controlledTank) 
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find a Tank to controll for PlayerController!"));
		return;
	}
	FString name;
	name = controlledTank->GetName();
	UE_LOG(LogTemp, Warning, TEXT("Player controller possesing Tank: %s"), *name);
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!controlledTank) { return; }

	FVector outHitLocation;
	if (GetSightRayHitLocation(outHitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Player aims at: %s"), *outHitLocation.ToString())
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("No Hitsolution found."))
	}
	
	
	//If a location was found aim at it
}

//Get location with raycast through crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector& outHitLocation) const
{
	outHitLocation = FVector(1.0);
	return true;
}
