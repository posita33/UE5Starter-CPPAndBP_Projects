// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPAbstractParent.h"
#include "CPPAbstractChild.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API ACPPAbstractChild : public ACPPAbstractParent
{
	GENERATED_BODY()
public:
	// 挨拶する
	void Greeting(FString message);
};
