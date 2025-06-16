// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/TZAbilitySystemComponent.h"

void UTZAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	AddDefaultAbilities();
}

void UTZAbilitySystemComponent::AddDefaultAbilities()
{
	for (const TSubclassOf<UGameplayAbility>& StartupAbility : DefaultAbilities)
	{
		GiveAbility(FGameplayAbilitySpec(StartupAbility));
	}
}