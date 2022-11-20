// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFunction.h"
#include "Kismet/KismetSystemLibrary.h"

int32 ACPPFunction::Sum(int32 A, int32 B)
{
	return A + B;
}

int32 ACPPFunction::SumRef(int32& A, int32& B)
{
	return A + B;
}

void ACPPFunction::PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration)
{
	switch (Type)
	{
		case ECPPCalcType::Add:
		{
			// Add(‘«‚µZ)‚Ìˆ—
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
			// Subtract(ˆø‚«Z)‚Ìˆ—
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
			// Multiply(Š|‚¯Z)‚Ìˆ—
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
			// Divide(Š„‚èZ)‚Ìˆ—
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

// Called when the game starts or when spawned
void ACPPFunction::BeginPlay()
{
	Super::BeginPlay();

	// •Ï”‚ğì¬‚·‚é
	FString Message = "C++ Hello World!";

	if (IsPrintHello)
	{
		// PrintStringƒm[ƒh‚Æ“¯‚¶ˆ—
		// UKismetSystemLibraryƒNƒ‰ƒX‚ÌPrintStringŠÖ”‚ğŒÄ‚Ño‚·
		UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration, TEXT("None"));
	}
	else
	{
		// ŒvZŒ‹‰Ê‚ğo—Í‚·‚éˆ—
		PrintCalcResult(CalcType, CalcVarA, CalcVarB, Duration);
	}
}
