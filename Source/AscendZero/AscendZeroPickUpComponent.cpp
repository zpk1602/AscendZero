// Copyright Epic Games, Inc. All Rights Reserved.

#include "AscendZeroPickUpComponent.h"

UAscendZeroPickUpComponent::UAscendZeroPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UAscendZeroPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UAscendZeroPickUpComponent::OnSphereBeginOverlap);
}

void UAscendZeroPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AAscendZeroCharacter* Character = Cast<AAscendZeroCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
