// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Components/NPCHealthComponent.h"
#include "AI/NPC.h"
#include "GameFramework/DamageType.h"
#include "GameFramework/Controller.h"

UNPCHealthComponent::UNPCHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UNPCHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CachedOwner = Cast<ANPC>(GetOwner());
	CachedOwner->OnTakeAnyDamage.AddDynamic(this, &UNPCHealthComponent::OnTakeAnyDamageHandleee);
}

void UNPCHealthComponent::OnTakeAnyDamageHandleee(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0, MaxHealth);

	if (CurrentHealth <= 0)
	{
		CachedOwner->GetAbilitySystemComponent()->TryActivateAbilitiesByTag(FGameplayTagContainer(DeathTag));
		CachedOwner->OnTakeAnyDamage.Clear();
		OnNPCDeath.Broadcast();
	}
}