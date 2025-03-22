// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPRotatingComponent.h"

// Called when the game starts
void UCPPRotatingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	// OwnerのRotationを取得する
	OwnerRotation = GetOwner()->GetRootComponent()->GetComponentRotation();

	// Timerをセットする
	FTimerHandle handle;
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(handle, this, &UCPPRotatingComponent::RotateLoop, Interval, true);
}

void UCPPRotatingComponent::RotateLoop()
{
	// OwnerのRotationを更新する
	OwnerRotation = FRotator(OwnerRotation.Pitch + RotY, OwnerRotation.Yaw + RotZ, OwnerRotation.Roll + RotX);
	GetOwner()->GetRootComponent()->SetWorldRotation(OwnerRotation);
}