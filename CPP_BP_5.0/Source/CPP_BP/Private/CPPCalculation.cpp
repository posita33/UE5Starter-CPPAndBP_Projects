// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPCalculation.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPCalculation::BeginPlay()
{
	FString Message = "C++ Hello World!";

	// PrintStringƒm[ƒh‚Æ“¯‚¶ˆ—
	// UKismetSystemLibraryƒNƒ‰ƒX‚ÌPrintStringŠÖ”‚ðŒÄ‚Ño‚·
	UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
	
	// Add(‘«‚µŽZ)‚Ìˆ—
	int32 ResultAdd = CalcVarA + CalcVarB;
	FString StrResultAdd = FString::Printf(TEXT("%d"), ResultAdd);
	UKismetSystemLibrary::PrintString(
		this
		, StrResultAdd
		, true
		, true
		, FColor::Red
		, Duration);

	// Subtract(ˆø‚«ŽZ)‚Ìˆ—
	int32 ResultSubtract = CalcVarA - CalcVarB;
	FString StrResultSubtract = FString::Printf(TEXT("%d"), ResultSubtract);
	UKismetSystemLibrary::PrintString(
		this
		, StrResultSubtract
		, true
		, true
		, FColor::Yellow
		, Duration);

	// Multiply(Š|‚¯ŽZ)‚Ìˆ—
	int32 ResultMultiply = CalcVarA * CalcVarB;
	FString StrResultMultiply = FString::Printf(TEXT("%d"), ResultMultiply);
	UKismetSystemLibrary::PrintString(
		this
		, StrResultMultiply
		, true
		, true
		, FColor::Green
		, Duration);

	// Divide(Š„‚èŽZ)‚Ìˆ—(int > float)
	float ResultDivide = (float)CalcVarA / (float)CalcVarB;
	FString StrResultDivide = FString::Printf(TEXT("%f"), ResultDivide);
	UKismetSystemLibrary::PrintString(
		this
		, StrResultDivide
		, true
		, true
		, FColor::Blue
		, Duration);
}