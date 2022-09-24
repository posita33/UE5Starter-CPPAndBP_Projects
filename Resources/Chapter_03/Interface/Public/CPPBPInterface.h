// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPPBPInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UCPPBPInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CPP_BP_API ICPPBPInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// �����Ɩ߂�l���Ȃ������o�֐�
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InterfaceTest")
	void PrintHello();

	// �����Ɩ߂�l�����郁���o�֐�
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InterfaceTest")
	int Add(int A, int B);
};
