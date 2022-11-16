// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPAccessParent.h"
#include "CPPAccessChild.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API ACPPAccessChild : public ACPPAccessParent
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
