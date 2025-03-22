// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPAbstractBPParent.h"
#include "CPPAbstractBPChild.generated.h"

/**
 *
 */
UCLASS()
class CPP_BP_API ACPPAbstractBPChild : public ACPPAbstractBPParent
{
	GENERATED_BODY()

public:
	void Greeting();
	virtual void Greeting_Implementation() override;
};
