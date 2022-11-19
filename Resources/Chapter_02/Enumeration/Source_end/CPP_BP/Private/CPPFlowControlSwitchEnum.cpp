// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFlowControlSwitchEnum.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Called when the game starts or when spawned
void ACPPFlowControlSwitchEnum::BeginPlay()
{
	Super::BeginPlay();

	// 変数を作成する
	FString Message = "C++ Hello World!";

	if (IsPrintHello)
	{
		// PrintStringノードと同じ処理
		// UKismetSystemLibraryクラスのPrintString関数を呼び出す
		UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
	}
	else
	{
		switch (CalcType)
		{
			case ECPPCalcType::Add:
			{
				// Add(足し算)の処理
				int32 ResultAdd = UKismetMathLibrary::Add_IntInt(CalcVarA, CalcVarB);
				FString StrResultAdd = FString::Printf(TEXT("%d"), ResultAdd);
				UKismetSystemLibrary::PrintString(
					this
					, StrResultAdd
					, true
					, true
					, FColor::Red
					, Duration
					, TEXT("None"));
				break;
			}
			case ECPPCalcType::Subtract:
			{
				// Subtract(引き算)の処理
				int32 ResultSubtract = CalcVarA - CalcVarB;
				FString StrResultSubtract = FString::Printf(TEXT("%d"), ResultSubtract);
				UKismetSystemLibrary::PrintString(
					this
					, StrResultSubtract
					, true
					, true
					, FColor::Yellow
					, Duration
					, TEXT("None"));
				break;
			}
			case ECPPCalcType::Multiply:
			{
				// Multiply(掛け算)の処理
				int32 ResultMultiply = CalcVarA * CalcVarB;
				FString StrResultMultiply = FString::Printf(TEXT("%d"), ResultMultiply);
				UKismetSystemLibrary::PrintString(
					this
					, StrResultMultiply
					, true
					, true
					, FColor::Green
					, Duration
					, TEXT("None"));
				break;
			}
			case ECPPCalcType::Divide:
			{
				// Divide(割り算)の処理
				float ResultDivide = (float)CalcVarA / (float)CalcVarB;
				FString StrResultDivide = FString::Printf(TEXT("%f"), ResultDivide);
				UKismetSystemLibrary::PrintString(
					this
					, StrResultDivide
					, true
					, true
					, FColor::Blue
					, Duration
					, TEXT("None"));
				break;
			}
		}
	}
}
