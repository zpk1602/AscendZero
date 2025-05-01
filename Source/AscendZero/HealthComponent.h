// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASCENDZERO_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	/** Health value, which can be viewed in a Blueprint */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
	float BaseMaxHealth = 100.0f;	// Defaults to 100, can be changed

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Health variable
	UPROPERTY(BlueprintReadOnly)
	float CurrentHealth = 100.0;

	// Max Health variable
	UPROPERTY(BlueprintReadOnly)
	float MaxHealth;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	void InitializeHealth(float HealthMultiplier);
	float GetHealth() const;
	void SetHealth(float DamageTaken);
	void Death();

private:
		
};
