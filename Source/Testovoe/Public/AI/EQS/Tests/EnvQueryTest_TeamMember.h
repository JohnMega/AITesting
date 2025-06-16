// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_TeamMember.generated.h"

/**
 * 
 */
UCLASS()
class TESTOVOE_API UEnvQueryTest_TeamMember : public UEnvQueryTest
{
	GENERATED_BODY()
	
public:
	UEnvQueryTest_TeamMember(const FObjectInitializer& ObjectInitializer);

	virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;
};
