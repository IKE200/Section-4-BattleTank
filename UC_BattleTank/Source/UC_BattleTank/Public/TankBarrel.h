// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class UC_BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void ElevateBarrel(float DegreesPerSecond);

private:
	
	UPROPERTY(EditAnywhere, category = Setup)
		float MaxDegreePerSecond = 20;

	UPROPERTY(EditAnywhere, category = Setup)
		float MaxElevationInDeg = 45;

	UPROPERTY(EditAnywhere, category = Setup)
		float MinElevationInDeg= 0;
	
};
