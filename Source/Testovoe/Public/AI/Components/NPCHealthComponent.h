// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "NPCHealthComponent.generated.h"

class ANPC;
struct FGameplayTag;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNPCDeathSignature);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTOVOE_API UNPCHealthComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	TWeakObjectPtr<ANPC> CachedOwner;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	float MaxHealth = 100;

	UPROPERTY(BlueprintReadWrite, Category = "Health")
	float CurrentHealth = MaxHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Death")
	FGameplayTag DeathTag;

public:
	UPROPERTY(BlueprintAssignable)
	FOnNPCDeathSignature OnNPCDeath;

protected:
	UFUNCTION()
	void OnTakeAnyDamageHandleee(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	virtual void BeginPlay() override;

public:	
	UNPCHealthComponent();
};
