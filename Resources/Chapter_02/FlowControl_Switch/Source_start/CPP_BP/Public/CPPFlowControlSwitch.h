// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPFlowControlSwitch.generated.h"

UCLASS()
class CPP_BP_API ACPPFlowControlSwitch : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// PrintStringŠÖ”‚ÌDuration‚Éİ’è‚·‚é•Ï”
	const float Duration = 10.0f;

	// PrintStringŠÖ”‚ÌTextColor‚Éİ’è‚·‚é•Ï”
	const FLinearColor TextColor = FColor(255, 255, 255);

	// ŒvZ—p‚Ì•Ï”
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

	// Flow Control—p‚Ì•Ï”
	bool IsPrintHello = false;
	int32 CalcType = 1;
};
