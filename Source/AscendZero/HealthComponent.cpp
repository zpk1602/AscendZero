// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	UE_LOG(LogTemp, Warning, TEXT("%s has spawned with %f health."), *GetOwner()->GetName(), CurrentHealth);
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Method to initialize health, allowing for multiple customizable health values
void UHealthComponent::InitializeHealth(float HealthMultiplier)
{
	MaxHealth = BaseMaxHealth * HealthMultiplier;
	CurrentHealth = MaxHealth;
	UE_LOG(LogTemp, Warning, TEXT("Initial Health has been set to %f."), MaxHealth);
}

float UHealthComponent::GetHealth() const
{
	return CurrentHealth;
}

void UHealthComponent::SetHealth(float DamageTaken)
{
	UE_LOG(LogTemp, Warning, TEXT("%s has taken %f damage!"), *GetOwner()->GetName(), DamageTaken);

	// Ignore no damage or no health possible states
	if (DamageTaken <= 0.f || CurrentHealth <= 0.f) return;

	// Subtract damage from health
	CurrentHealth -= DamageTaken;

	// Kill the character if they have no health
	if (CurrentHealth <= 0) {
		Death();
	}
}

void UHealthComponent::Death()
{
	UE_LOG(LogTemp, Warning, TEXT("%s has died."), *GetOwner()->GetName());
}

