// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;

// Component to find Hitsolutions for a Tank
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UC_BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	void AimAt(FVector TargetLocation, float LaunchSpeed);

	void SetBarrelReference(UTankBarrel* BarrelToSet);

private:

	// Sets default values for this component's properties
	UTankAimingComponent();

	void MoveBarrelTowards(FVector AimDirection);

	UTankBarrel* Barrel = nullptr;

		
	
};
