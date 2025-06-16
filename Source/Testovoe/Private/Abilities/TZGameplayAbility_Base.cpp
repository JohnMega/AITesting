// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/TZGameplayAbility_Base.h"
#include "GameFramework/Character.h"

void UTZGameplayAbility_Base::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* OwnerInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	CachedInstigatorCharacter = StaticCast<ACharacter*>(OwnerInfo->AvatarActor.Get());

	Super::ActivateAbility(Handle, OwnerInfo, ActivationInfo, TriggerEventData);
}