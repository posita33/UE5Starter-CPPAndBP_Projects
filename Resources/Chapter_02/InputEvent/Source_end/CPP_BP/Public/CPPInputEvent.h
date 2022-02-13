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

	// 計算結果を出力する関数
	void PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration);

	// PrintString関数のDurationに設定する変数
	const float Duration = 10.0f;

	// PrintString関数のTextColorに設定する変数
	const FLinearColor TextColor = FColor(255, 255, 255);

	// 計算用の変数
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

	// Flow Control用の変数
	bool IsPrintHello = false;
	ECPPCalcType CalcType = ECPPCalcType::Add;

	// Input設定
	void SetupInput();

	// Input Event イベントハンドラー関数
	void PressedH();
	void ReleasedH();

	void PressedActionPrintCalcResult();
};