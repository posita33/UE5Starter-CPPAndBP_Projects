// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPFlowControlBranch.generated.h"

UCLASS()
class CPP_BP_API ACPPFlowControlBranch : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// PrintString�֐���Duration�ɐݒ肷��ϐ�
	const float Duration = 10.0f;

	// PrintString�֐���TextColor�ɐݒ肷��ϐ�
	const FLinearColor TextColor = FColor(255, 255, 255);

	// �v�Z�p�̕ϐ�
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

	// Flow Control�p�̕ϐ�
	bool IsPrintHello = false;
	int32 CalcType = 1;
	int32 NumA = 1;
	int32 NumB = 2;
	int32 NumC = 15;
	bool IsBlueprint = true;
};