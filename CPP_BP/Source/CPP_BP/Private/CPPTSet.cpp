// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPTSet.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPTSet::BeginPlay()
{
	Super::BeginPlay();

	// ’Ç‰Á‚·‚é
	FruitSet.Add(TEXT("Orange"));

	// íœ‚·‚é
	FruitSet.Remove(TEXT("Apple"));

	// TSet‚Ì’†g‚ğo—Í‚·‚é
	for (FString Elem : FruitSet)
	{
		UKismetSystemLibrary::PrintString(
			this
			, FString::Printf(TEXT("Value : %s"), *Elem)
			, true
			, true
			, FColor::Cyan
			, 10.0f
			, TEXT("None"));
	}
}
