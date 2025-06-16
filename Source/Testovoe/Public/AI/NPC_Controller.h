// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "NPC_Controller.generated.h"

class UBehaviorTree;
class ANPC;

UCLASS()
class TESTOVOE_API ANPC_Controller : public AAIController
{
	GENERATED_BODY()
	
private:
	class UAISenseConfig_Sight* sightConfig;
	float StandartSightRaduis;
	float StandartLoseSightRaduis;
	TWeakObjectPtr<AActor> CurrentPerceivedActor;
	TWeakObjectPtr<ANPC> CachedOwnerNPC;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UBehaviorTree* BehaviorTree;

private:
	void SightConfigInit();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* inPawn) override;

	void SetupPerceptionSystem();
	void SetupLightManagerSettings();

	UFUNCTION()
	void OnTargetDetection(AActor* Target, const FAIStimulus Stimulus);

public:
	ANPC_Controller(const FObjectInitializer& oI);

	UAISenseConfig_Sight* GetSightConfig() { return sightConfig; }
	AActor* GetCurrentPerceivedActor() const { return CurrentPerceivedActor.Get(); }
};
