// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightSenseManager.generated.h"

USTRUCT(BlueprintType)
struct FSightSenseSettings
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SightRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float LoseSightRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float PeripheralVisionAngleDegrees;
};

UENUM(BlueprintType)
enum class ELightLevel : uint8
{
	Bright UMETA(DisplayName = "Bright"),
	PartialShade UMETA(DisplayName = "PartialShade"),
	FullShadow UMETA(DisplayName = "FullShadow")
};

UCLASS()
class TESTOVOE_API ALightSenseManager : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Light Level")
	ELightLevel CurrentLightLevel = ELightLevel::Bright;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	TMap<ELightLevel, FSightSenseSettings> SightSenseSettings;

public:	
	ALightSenseManager();
};
