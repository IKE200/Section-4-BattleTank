// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	controlledTank = GetControlledTank();
	playerTank = GetPlayerTank();

	if (!controlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankAIController could not find a Tank to controll!"));
		return;
	}

	if (!playerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController %s could not find a player tank!"), *GetPawn()->GetName());
	}
	
	FString name = controlledTank->GetName();
	UE_LOG(LogTemp, Warning, TEXT("TankAIController controlling Tank: %s"), *name);
	UE_LOG(LogTemp, Warning, TEXT("TankAIController %s found player %s"), *name, *playerTank->GetName());
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APawn* player = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!player)
	{
		return nullptr;
	}
	return Cast<ATank>(player);
}


