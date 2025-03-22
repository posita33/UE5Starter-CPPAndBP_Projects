// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPRotatingComponent.h"

// Called when the game starts
void UCPPRotatingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	// Owner��Rotation���擾����
	OwnerRotation = GetOwner()->GetRootComponent()->GetComponentRotation();

	// Timer���Z�b�g����
	FTimerHandle handle;
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(handle, this, &UCPPRotatingComponent::RotateLoop, Interval, true);
}

void UCPPRotatingComponent::RotateLoop()
{
	// Owner��Rotation���X�V����
	OwnerRotation = FRotator(OwnerRotation.Pitch + RotY, OwnerRotation.Yaw + RotZ, OwnerRotation.Roll + RotX);
	GetOwner()->GetRootComponent()->SetWorldRotation(OwnerRotation);
}