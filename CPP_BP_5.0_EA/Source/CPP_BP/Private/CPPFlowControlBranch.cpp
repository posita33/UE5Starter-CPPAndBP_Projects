// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFlowControlBranch.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPFlowControlBranch::BeginPlay()
{
	FString Message = "C++ Hello World!";

	if (IsPrintHello)
	{
		// PrintString�m�[�h�Ɠ�������
		// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
		UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
	}
	else
	{
		if (CalcType == 0)
		{
			// Add(�����Z)�̏���
			int32 ResultAdd = CalcVarA + CalcVarB;
			FString StrResultAdd = FString::Printf(TEXT("%d"), ResultAdd);
			UKismetSystemLibrary::PrintString(this, StrResultAdd, true, true, FColor::Red, Duration);
		}
		else if (CalcType == 1)
		{
			// Subtract(�����Z)�̏���
			int32 ResultSubtract = CalcVarA - CalcVarB;
			FString StrResultSubtract = FString::Printf(TEXT("%d"), ResultSubtract);
			UKismetSystemLibrary::PrintString(this, StrResultSubtract, true, true, FColor::Yellow, Duration);
		}
		else if (CalcType == 2)
		{
			// Multiply(�|���Z)�̏���
			int32 ResultMultiply = CalcVarA * CalcVarB;
			FString StrResultMultiply = FString::Printf(TEXT("%d"), ResultMultiply);
			UKismetSystemLibrary::PrintString(this, StrResultMultiply, true, true, FColor::Green, Duration);
		}
		else
		{
			// Divide(����Z)�̏���(int > float)
			float ResultDivide = (float)CalcVarA / (float)CalcVarB;
			FString StrResultDivide = FString::Printf(TEXT("%f"), ResultDivide);
			UKismetSystemLibrary::PrintString(this, StrResultDivide, true, true, FColor::Blue, Duration);
		}
	}
}