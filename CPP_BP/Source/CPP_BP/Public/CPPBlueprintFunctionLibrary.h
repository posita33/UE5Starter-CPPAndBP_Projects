// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CPPBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CPP_BP_API UCPPBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "CPPBlueprintFunctionLibrary")
	static void PrintHello();

	UFUNCTION(BlueprintCallable, Category = "CPPBlueprintFunctionLibrary", BlueprintPure)
	static int Sum(const int A, const int B);
};
