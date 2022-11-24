// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPPInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCPPInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CPP_BP_API ICPPInterface
{
	GENERATED_BODY()

		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// 引数と戻り値がないメンバ関数
	virtual void PrintHello();

	// 引数と戻り値があるメンバ関数
	virtual int Add(int A, int B);
};
