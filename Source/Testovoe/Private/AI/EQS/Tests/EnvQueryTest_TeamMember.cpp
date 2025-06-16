// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EQS/Tests/EnvQueryTest_TeamMember.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"
#include "AI/NPC.h"

UEnvQueryTest_TeamMember::UEnvQueryTest_TeamMember(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Cost = EEnvTestCost::Low;
	ValidItemType = UEnvQueryItemType_ActorBase::StaticClass();
	SetWorkOnFloatValues(false);
}

void UEnvQueryTest_TeamMember::RunTest(FEnvQueryInstance& QueryInstance) const
{
	auto OwnerNPC = Cast<ANPC>(QueryInstance.Owner.Get());
	if (!OwnerNPC)
		return;

	BoolValue.BindData(OwnerNPC, QueryInstance.QueryID);
	bool bWantsValid = BoolValue.GetValue();

	for (FEnvQueryInstance::ItemIterator It(this, QueryInstance); It; ++It)
	{
		auto NPC = StaticCast<ANPC*>(GetItemActor(QueryInstance, It.GetIndex()));
		if (NPC->GetGenericTeamId() == OwnerNPC->GetGenericTeamId())
		{
			It.SetScore(TestPurpose, FilterType, true, bWantsValid);
		}
		else
		{
			It.SetScore(TestPurpose, FilterType, false, bWantsValid);
		}
	}
}