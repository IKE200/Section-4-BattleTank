// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

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
	UE_LOG(LogTemp, Warning, TEXT("Plaer controller possesing Tank: %s"), *name);
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}


