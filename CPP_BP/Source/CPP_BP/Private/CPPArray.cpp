// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPArray.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

ACPPArray::ACPPArray()
{
	// Event Dispathcer[OnPrintHello]��Custom Event[PrintHello]���o�C���h����
	OnPrintHello.AddDynamic(this, &ACPPArray::PrintHello);
}

int32 ACPPArray::Sum(int32 A, int32 B)
{
	return A + B;
}

// Called when the game starts or when spawned
void ACPPArray::BeginPlay()
{
	Super::BeginPlay();

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

void ACPPArray::PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration)
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
		}
	}
}

void ACPPArray::SetupInput()
{
	// ���͂�L���ɂ���
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	// H�L�[��Pressed��Released���o�C���h����
	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPArray::PressedH);

	// ActionMappings�ɐݒ肵��Action���o�C���h����
	InputComponent->BindAction("ActionPrintCalcResult", IE_Pressed, this, &ACPPArray::PressedActionPrintCalcResult);
}

void ACPPArray::PressedH()
{
	// Event Dispathcer[OnPrintHello]���R�[������
	OnPrintHello.Broadcast();
}

void ACPPArray::PressedActionPrintCalcResult()
{
	// �v�Z���ʂ��o�͂��鏈��
	PrintCalcResult(CalcTypes[TypeIndex], CalcVarA, CalcVarB, Duration);

	TypeIndex++;
	TypeIndex = TypeIndex % CalcTypes.Num();
}

void ACPPArray::PrintHello()
{
	int32 randomIndex = FMath::RandRange(0, Messages.Num() - 1);

	// 1�s�ŏ����Ȃ� 
	// Messages[FMath::RandRange(0, Messages.Num() - 1)]

	// Hello World!���o�͂��鏈��
	UKismetSystemLibrary::PrintString(this, Messages[randomIndex], true, true, TextColor, Duration);
}