// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPCalculation.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h" // ’Ç‰Á
#include "Kismet/KismetMathLibrary.h" // ’Ç‰Á

// Called when the game starts or when spawned
void ACPPCalculation::BeginPlay()
{
	Super::BeginPlay();

	// •Ï”‚ğì¬‚·‚é
	FString Message = "C++ Hello World!";

	// PrintStringƒm[ƒh‚Æ“¯‚¶ˆ—
	// UKismetSystemLibraryƒNƒ‰ƒX‚ÌPrintStringŠÖ”‚ğŒÄ‚Ño‚·
	UKismetSystemLibrary::PrintString(
		this
		, Message
		, true
		, true
		, TextColor// Text‚ÌƒJƒ‰[î•ñ‚É•Ï”TextColor‚ğİ’è
		, Duration
		, TEXT("None"));

	// Add(‘«‚µZ)‚Ìˆ—
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

}

