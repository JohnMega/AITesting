// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/NPC.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "AI/Components/NPCHealthComponent.h"
#include "Components/WidgetComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "AI/PatrolPath.h"
#include "AI/LightSenseManager.h"

ANPC::ANPC(const FObjectInitializer& Init)
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UTZAbilitySystemComponent>("AbilitySystemComponent");

	HealthComponent = CreateDefaultSubobject<UNPCHealthComponent>("HealthComponent");

	HealthWidgetComponent = CreateDefaultSubobject<UWidgetComponent>("HealthWidgetComponent");
	HealthWidgetComponent->SetupAttachment(GetRootComponent());
}

void ANPC::BeginPlay()
{
	Super::BeginPlay();
}

void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

ETeamAttitude::Type ANPC::GetTeamAttitudeTowards(const AActor& Other) const
{
	const IGenericTeamAgentInterface* OtherTeamAgent = Cast<const IGenericTeamAgentInterface>(&Other);
	if (!OtherTeamAgent) return ETeamAttitude::Neutral;

	return OtherTeamAgent->GetGenericTeamId().GetId() == GetGenericTeamId().GetId() ? ETeamAttitude::Friendly : ETeamAttitude::Hostile;
}

APatrolPath* ANPC::GetPatrolPath() const
{
	return patrolPath;
}

ALightSenseManager* ANPC::GetLightSenseManager() const
{
	return LightSenseManager;
}

UAbilitySystemComponent* ANPC::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}