// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	controlledTank = GetControlledTank();
	if (!controlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankAIController could not find a Tank to controll!"));
		return;
	}
	FString name = controlledTank->GetName();
	UE_LOG(LogTemp, Warning, TEXT("TankAIController controlling Tank: %s"), *name);
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


