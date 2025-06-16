// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "PatrolPath.generated.h"

UCLASS()
class TESTOVOE_API APatrolPath : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (MakeEditWidget = "true"))
	USplineComponent* PatrolRout;

public:
	APatrolPath(const FObjectInitializer& oI);

	UFUNCTION(BlueprintCallable)
	FVector GetPatrolPoint(int32 Index, bool PathDir, bool ignoreDirection) const;

	int32 PatrolPointsNum() const;
};
