// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPCalcType.h"
#include "CPPInputEvent.generated.h"

UCLASS()
class CPP_BP_API ACPPInputEvent : public AActor
{
	GENERATED_BODY()

public:
	int32 Sum(int32 A, int32 B);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FString Message = "C++ Hello World!";

	// �v�Z���ʂ��o�͂���֐�
	void PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration);

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

	// Input�ݒ�
	void SetupInput();

	// Input Event �C�x���g�n���h���[�֐�
	void PressedH();
	void ReleasedH();

	void PressedActionPrintCalcResult();
};