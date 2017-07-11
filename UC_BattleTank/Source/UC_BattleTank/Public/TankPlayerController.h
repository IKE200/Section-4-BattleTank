// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UC_BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation;

	UPROPERTY(EditAnywhere)
		float CrossHairYLocation;
	
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;

	ATank* controlledTank;

	ATank* GetControlledTank() const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	// Aim tank, so that a shot will hit, where the crosshair points to
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& outHitLocation) const;
	bool GetLookVectorHitLocation(FVector& OutHitLocation, FVector LookDirection) const;

};
