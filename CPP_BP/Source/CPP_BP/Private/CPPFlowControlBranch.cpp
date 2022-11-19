// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFlowControlBranch.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h" // �ǉ�

// Called when the game starts or when spawned
void ACPPFlowControlBranch::BeginPlay()
{
	Super::BeginPlay();

	// �ϐ����쐬����
	FString Message = "C++ Hello World!";

	if (IsPrintHello)
	{
		// PrintString�m�[�h�Ɠ�������
		// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
		UKismetSystemLibrary::PrintString(
			this
			, Message
			, true
			, true
			, TextColor// Text�̃J���[���ɕϐ�TextColor��ݒ�
			, Duration
			, TEXT("None"));
	}
	else
	{
		if (CalcType == 0)
		{
			// Add(�����Z)�̏���
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
		}
		else if (CalcType == 1)
		{
			// Subtract(�����Z)�̏���
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
		}
		else if (CalcType == 2)
		{
			// Multiply(�|���Z)�̏���
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
		}
		else
		{
			// Divide(����Z)�̏���
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
		}
	}
}

