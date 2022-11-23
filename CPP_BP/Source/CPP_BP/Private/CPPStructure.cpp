// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPStructure.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

ACPPStructure::ACPPStructure()
{
	// Event Dispathcer[OnPrintHello]にCustom Event[PrintHello]をバインドする
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
		// Hello World!を出力する処理
		PrintHello();
	}
	else
	{
		// 計算結果を出力する処理
		PressedActionPrintCalcResult();
	}
}

void ACPPStructure::PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration)
{
	switch (Type)
	{
		case ECPPCalcType::Add:
		{
			// Add(足し算)の処理
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

void ACPPStructure::PrintCalcResultArgStructure(const FCPPCalcInfo& CalcInfo, const float PrintDuration)
{
	switch (CalcInfo.Type)
	{
		case ECPPCalcType::Add:
		{
			// Add(足し算)の処理
			// 値渡し
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
			// Subtract(引き算)の処理
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
			// Multiply(掛け算)の処理
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
			// Divide(割り算)の処理(int > float)
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
	// 入力を有効にする
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	// HキーのPressedとReleasedをバインドする
	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPStructure::PressedH);

	// ActionMappingsに設定したActionをバインドする
	InputComponent->BindAction("ActionPrintCalcResult", IE_Pressed, this, &ACPPStructure::PressedActionPrintCalcResult);
}

void ACPPStructure::PressedH()
{
	// Event Dispathcer[OnPrintHello]をコールする
	OnPrintHello.Broadcast();
}

void ACPPStructure::PressedActionPrintCalcResult()
{
	// 構造体を引数に持った計算結果を出力する処理
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
		// 文字列に"Bonjour"が含まれているか
		if (Messages[HelloIndex].Contains(TEXT("Bonjour")))
		{
			// While Loopの条件をfalseに設定する
			NotBonjour = false;
		}
		else
		{
			// Messagesの値を出力する
			UKismetSystemLibrary::PrintString(this, Messages[HelloIndex], true, true, TextColor, Duration, TEXT("None"));
		}
		// HelloIndexをインクリメント
		HelloIndex++;
	}

	// CompletedをPrintStringで出力する
	UKismetSystemLibrary::PrintString(this, TEXT("Completed"), true, true, FColor::Cyan, Duration, TEXT("None"));
}

