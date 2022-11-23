// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPParentRedefinition.h"

// Called when the game starts or when spawned
void ACPPParentRedefinition::BeginPlay()
{
	Super::BeginPlay();

}

void ACPPParentRedefinition::SetPoint(int myPoint)
{
	point = myPoint;
}

int ACPPParentRedefinition::GetPoint()
{
	return point;
}
