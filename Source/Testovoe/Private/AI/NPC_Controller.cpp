// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/NPC_Controller.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Kismet/GameplayStatics.h"
#include "AI/NPC.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AI/LightSenseManager.h"

ANPC_Controller::ANPC_Controller(const FObjectInitializer& oI)
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception component"));
	SetupPerceptionSystem();
}

void ANPC_Controller::BeginPlay()
{
	Super::BeginPlay();

	if (!sightConfig) SightConfigInit();

	GetPerceptionComponent()->Activate();
}

void ANPC_Controller::OnPossess(APawn* inPawn)
{
	Super::OnPossess(inPawn);

	if (!sightConfig) SightConfigInit();
	if (BehaviorTree)
	{
		UBlackboardComponent* blackboard;
		UseBlackboard(BehaviorTree->BlackboardAsset, blackboard);
		Blackboard = blackboard;
		Blackboard->SetValueAsEnum(TEXT("BehaviorState"), static_cast<uint8>(EBehaviorStateTypes::Patrol));

		RunBehaviorTree(BehaviorTree);

		CachedOwnerNPC = StaticCast<ANPC*>(inPawn);
		SetupLightManagerSettings();
	}
}

void ANPC_Controller::SetupLightManagerSettings()
{
	if (CachedOwnerNPC.IsValid())
	{
		auto LightSenseManager = CachedOwnerNPC->GetLightSenseManager();
		if (LightSenseManager)
		{
			auto SightSettings = *LightSenseManager->SightSenseSettings.Find(LightSenseManager->CurrentLightLevel);
			sightConfig->SightRadius = SightSettings.SightRadius;
			sightConfig->LoseSightRadius = SightSettings.LoseSightRadius;
			sightConfig->PeripheralVisionAngleDegrees = SightSettings.PeripheralVisionAngleDegrees;
			GetPerceptionComponent()->ConfigureSense(*sightConfig);
		}
	}
}

void ANPC_Controller::SetupPerceptionSystem()
{
	SetPerceptionComponent(*PerceptionComponent);
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ANPC_Controller::OnTargetDetection);
}

void ANPC_Controller::OnTargetDetection(AActor* Target, const FAIStimulus Stimulus)
{
	if (!GetPerceptionComponent()->IsActive() || CurrentPerceivedActor.IsValid()) return;

	auto NPC = Cast<ANPC>(Target);
	if (NPC && NPC->GetGenericTeamId() != CachedOwnerNPC->GetGenericTeamId())
	{
		CurrentPerceivedActor = Target;
		GetBlackboardComponent()->SetValueAsObject(TEXT("TargetCharacter"), Target);
		GetBlackboardComponent()->SetValueAsEnum(TEXT("BehaviorState"), static_cast<uint8>(EBehaviorStateTypes::Chase));
	}
}

void ANPC_Controller::SightConfigInit()
{
	sightConfig = GetPerceptionComponent()->GetSenseConfig<UAISenseConfig_Sight>();
}