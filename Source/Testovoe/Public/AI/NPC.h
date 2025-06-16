// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/TZAbilitySystemComponent.h"
#include <AbilitySystemInterface.h>
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "NPC.generated.h"

class AMainCharacter;
class UNiagaraComponent;
class UBehaviorTree;
class APatrolPath;
class UNPCHealthComponent;
class UWidgetComponent;
class UAbilitySystemComponent;
class ALightSenseManager;

UENUM(BlueprintType)
enum class EBehaviorStateTypes : uint8
{
	Passive UMETA(DisplayName = "Passive"),
	Patrol UMETA(DisplayName = "Patrol"),
	Investigation UMETA(DisplayName = "Investigation"),
	Combat UMETA(DisplayName = "Combat"),
	Chase UMETA(DisplayName = "Chase"),
	Dead UMETA(DisplayName = "Dead")
};

UCLASS()
class TESTOVOE_API ANPC : public ACharacter, public IAbilitySystemInterface, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UTZAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UNPCHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UWidgetComponent* HealthWidgetComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	APatrolPath* patrolPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	ALightSenseManager* LightSenseManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Relatioship")
	FGenericTeamId TeamID = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior")
	EBehaviorStateTypes StartBehaviorState = EBehaviorStateTypes::Passive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior")
	float CombatSwitchRadius = 50;

protected:
	virtual void BeginPlay() override;

public:
	ANPC(const FObjectInitializer& Init);

	// IGenericTeamAgentInterface Interface
	virtual void SetGenericTeamId(const FGenericTeamId& NewTeamID) override { TeamID = NewTeamID; }
	virtual FGenericTeamId GetGenericTeamId() const override { return TeamID; }
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
	// End IGenericTeamAgentInterface Interface

	// IAbilitySystemInterface Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	// End IAbilitySystemInterface Interface

	virtual void Tick(float DeltaTime) override;

	APatrolPath* GetPatrolPath() const;
	ALightSenseManager* GetLightSenseManager() const;
};
