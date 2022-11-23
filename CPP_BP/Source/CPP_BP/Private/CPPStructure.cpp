// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPStructure.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

ACPPStructure::ACPPStructure()
{
	// Event Dispathcer[OnPrintHello]��Custom Event[PrintHello]���o�C���h����
	OnPrintHello.AddDynamic(this, &ACPPStructure::PrintHello);
}

int32 ACPPStructure::Sum(int32 A, int32 B)
{
	return A + B;
}

// Called when the game starts or when spawned
void ACPPStructure::BeginPlay()
{
	SetupInput();

	if (IsPrintHello)
	{
		// Hello World!���o�͂��鏈��
		PrintHello();
	}
	else
	{
		// �v�Z���ʂ��o�͂��鏈��
		PressedActionPrintCalcResult();
	}
}

void ACPPStructure::PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration)
{
	switch (Type)
	{
		case ECPPCalcType::Add:
		{
			// Add(�����Z)�̏���
			int32 ResultAdd = Sum(CalcVarA, CalcVarB);
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
			break;
		}
		case ECPPCalcType::Multiply:
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
			break;
		}
		case ECPPCalcType::Divide:
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
			break;
		}
	}
}

void ACPPStructure::PrintCalcResultArgStructure(const FCPPCalcInfo& CalcInfo, const float PrintDuration)
{
	switch (CalcInfo.Type)
	{
		case ECPPCalcType::Add:
		{
			// Add(�����Z)�̏���
			// �l�n��
			int32 ResultAdd = Sum(CalcInfo.NumA, CalcInfo.NumB);
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
			// Subtract(�����Z)�̏���
			int32 ResultSubtract = CalcInfo.NumA - CalcInfo.NumB;
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
			// Multiply(�|���Z)�̏���
			int32 ResultMultiply = CalcInfo.NumA * CalcInfo.NumB;
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
			// Divide(����Z)�̏���(int > float)
			float ResultDivide = (float)CalcInfo.NumA / (float)CalcInfo.NumB;
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

void ACPPStructure::SetupInput()
{
	// ���͂�L���ɂ���
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	// H�L�[��Pressed��Released���o�C���h����
	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPStructure::PressedH);

	// ActionMappings�ɐݒ肵��Action���o�C���h����
	InputComponent->BindAction("ActionPrintCalcResult", IE_Pressed, this, &ACPPStructure::PressedActionPrintCalcResult);
}

void ACPPStructure::PressedH()
{
	// Event Dispathcer[OnPrintHello]���R�[������
	OnPrintHello.Broadcast();
}

void ACPPStructure::PressedActionPrintCalcResult()
{
	// �\���̂������Ɏ������v�Z���ʂ��o�͂��鏈��
	PrintCalcResultArgStructure(CalcInfos[TypeIndex], Duration);

	TypeIndex++;
	TypeIndex = TypeIndex % CalcTypes.Num();
}

void ACPPStructure::PrintHello()
{
	bool NotBonjour = true;
	int32 HelloIndex = 0;

	while (NotBonjour)
	{
		// �������"Bonjour"���܂܂�Ă��邩
		if (Messages[HelloIndex].Contains(TEXT("Bonjour")))
		{
			// While Loop�̏�����false�ɐݒ肷��
			NotBonjour = false;
		}
		else
		{
			// Messages�̒l���o�͂���
			UKismetSystemLibrary::PrintString(this, Messages[HelloIndex], true, true, TextColor, Duration, TEXT("None"));
		}
		// HelloIndex���C���N�������g
		HelloIndex++;
	}

	// Completed��PrintString�ŏo�͂���
	UKismetSystemLibrary::PrintString(this, TEXT("Completed"), true, true, FColor::Cyan, Duration, TEXT("None"));
}

