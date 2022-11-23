// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPParentRedefinition.h"
#include "CPPChildRedefinition.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API ACPPChildRedefinition : public ACPPParentRedefinition
{
	GENERATED_BODY()
	
public:
	void SetPoint(int myPoint);

};
