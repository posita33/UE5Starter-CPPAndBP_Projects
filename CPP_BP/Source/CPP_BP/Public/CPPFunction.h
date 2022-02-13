// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPCalcType.h"
#include "CPPFunction.generated.h"

UCLASS()
class CPP_BP_API ACPPFunction : public AActor
{
	GENERATED_BODY()

public:
	int32 Sum(int32 A, int32 B);

	int32 SumRef(const int32& A, const int32& B);

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
	ECPPCalcType CalcType = ECPPCalcType::Add;

	void PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration);

};
