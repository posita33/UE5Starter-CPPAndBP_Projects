// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPTSet.generated.h"

UCLASS()
class CPP_BP_API ACPPTSet : public AActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	TSet<FString> FruitSet =
	{
		TEXT("Apple"),
		TEXT("Lemon"),
		TEXT("Banana"),
	};
};
