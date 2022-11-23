// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPParentVirtual.h"

// Called when the game starts or when spawned
void ACPPParentVirtual::BeginPlay()
{
	Super::BeginPlay();

}

void ACPPParentVirtual::SetPoint(int myPoint)
{
	point = myPoint;
}

int ACPPParentVirtual::GetPoint()
{
	return point;
}
