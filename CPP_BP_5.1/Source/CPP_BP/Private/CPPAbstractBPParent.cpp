// Fill out your copyright notice in the Description page of Project Settings.

#include "CPPAbstractBPParent.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPAbstractBPParent::BeginPlay()
{
	Super::BeginPlay();

	// ���A����
	Greeting();
}

void ACPPAbstractBPParent::Greeting_Implementation()
{
}
