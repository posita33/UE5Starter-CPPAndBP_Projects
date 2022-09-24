// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPInterface.h"
#include "CPPInterfaceTest.generated.h"

UCLASS()
class CPP_BP_API ACPPInterfaceTest : public AActor, public ICPPInterface
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// 引数と戻り値がないメンバ関数
	virtual void PrintHello() override;

	// 引数と戻り値があるメンバ関数
	virtual int Add(int A, int B) override;

};
