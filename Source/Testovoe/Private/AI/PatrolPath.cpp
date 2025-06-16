// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/PatrolPath.h"

APatrolPath::APatrolPath(const FObjectInitializer& oI)
	: Super(oI)
{
	PrimaryActorTick.bCanEverTick = false;

	PatrolRout = CreateDefaultSubobject<USplineComponent>(TEXT("PatrolRoute"), true);
}

FVector APatrolPath::GetPatrolPoint(int32 Index, bool PathDir, bool ignoreDirection) const
{
	if (ignoreDirection)
		return PatrolRout->GetLocationAtSplinePoint(Index, ESplineCoordinateSpace::Type::World);

	if (PathDir)
		return PatrolRout->GetLocationAtSplinePoint(Index, ESplineCoordinateSpace::Type::World);
	else
		return PatrolRout->GetLocationAtSplinePoint(PatrolPointsNum() - 1 - Index, ESplineCoordinateSpace::Type::World);
}

int32 APatrolPath::PatrolPointsNum() const
{
	return PatrolRout->GetNumberOfSplinePoints();
}

