// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "TZGameplayAbility_Base.generated.h"

UCLASS()
class TESTOVOE_API UTZGameplayAbility_Base : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite)
	TWeakObjectPtr<ACharacter> CachedInstigatorCharacter;

public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* OwnerInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};
