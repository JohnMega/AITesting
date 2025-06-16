// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "TZAbilitySystemComponent.generated.h"

UCLASS()
class TESTOVOE_API UTZAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default property")
	TSet<TSubclassOf<UGameplayAbility>> DefaultAbilities;

private:
	void AddDefaultAbilities();

protected:
	virtual void BeginPlay() override;
};
