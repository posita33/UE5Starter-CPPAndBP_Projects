// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFlowControlLoop.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

ACPPFlowControlLoop::ACPPFlowControlLoop()
{
	// Event Dispathcer[OnPrintHello]��Custom Event[PrintHello]���o�C���h����
	OnPrintHello.AddDynamic(this, &ACPPFlowControlLoop::PrintHello);
}

int32 ACPPFlowControlLoop::Sum(int32 A, int32 B)
{
	return A + B;
}

// Called when the game starts or when spawned
void ACPPFlowControlLoop::BeginPlay()
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

void ACPPFlowControlLoop::PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration)
{
	switch (Type)
	{
		case ECPPCalcType::Add:
		{
			// Add(�����Z)�̏���
			// �l�n��
			int32 ResultAdd = Sum(A, B);
			FString StrResultAdd = FString::Printf(TEXT("%d"), ResultAdd);
			UKismetSystemLibrary::PrintString(this, StrResultAdd, true, true, FColor::Red, PrintDuration);
			break;
		}
		case ECPPCalcType::Subtract:
		{
			// Subtract(�����Z)�̏���
			int32 ResultSubtract = A - B;
			FString StrResultSubtract = FString::Printf(TEXT("%d"), ResultSubtract);
			UKismetSystemLibrary::PrintString(this, StrResultSubtract, true, true, FColor::Yellow, PrintDuration);
			break;
		}
		case ECPPCalcType::Multiply:
		{
			// Multiply(�|���Z)�̏���
			int32 ResultMultiply = A * B;
			FString StrResultMultiply = FString::Printf(TEXT("%d"), ResultMultiply);
			UKismetSystemLibrary::PrintString(this, StrResultMultiply, true, true, FColor::Green, PrintDuration);
			break;
		}
		case ECPPCalcType::Divide:
		{
			// Divide(����Z)�̏���(int > float)
			float ResultDivide = (float)A / (float)B;
			FString StrResultDivide = FString::Printf(TEXT("%f"), ResultDivide);
			UKismetSystemLibrary::PrintString(this, StrResultDivide, true, true, FColor::Blue, PrintDuration);
			break;
		}
	}
}

void ACPPFlowControlLoop::SetupInput()
{
	// ���͂�L���ɂ���
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	// H�L�[��Pressed��Released���o�C���h����
	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPFlowControlLoop::PressedH);

	// ActionMappings�ɐݒ肵��Action���o�C���h����
	InputComponent->BindAction("ActionPrintCalcResult", IE_Pressed, this, &ACPPFlowControlLoop::PressedActionPrintCalcResult);
}

void ACPPFlowControlLoop::PressedH()
{
	// Event Dispathcer[OnPrintHello]���R�[������
	OnPrintHello.Broadcast();
}

void ACPPFlowControlLoop::PressedActionPrintCalcResult()
{
	// �v�Z���ʂ��o�͂��鏈��
	PrintCalcResult(CalcTypes[TypeIndex], CalcVarA, CalcVarB, Duration);

	TypeIndex++;
	TypeIndex = TypeIndex % CalcTypes.Num();
}

void ACPPFlowControlLoop::PrintHello()
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
			UKismetSystemLibrary::PrintString(this, Messages[HelloIndex], true, true, TextColor, Duration);
		}
		// HelloIndex���C���N�������g
		HelloIndex++;
	}

	// Completed��PrintString�ŏo�͂���
	UKismetSystemLibrary::PrintString(this, TEXT("Completed"), true, true, FColor::Cyan, Duration);
}
