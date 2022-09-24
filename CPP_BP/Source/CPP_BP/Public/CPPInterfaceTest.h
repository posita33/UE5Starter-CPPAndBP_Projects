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
	// �����Ɩ߂�l���Ȃ������o�֐�
	virtual void PrintHello() override;

	// �����Ɩ߂�l�����郁���o�֐�
	virtual int Add(int A, int B) override;

};
