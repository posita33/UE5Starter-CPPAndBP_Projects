// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFlowControlLoop.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

ACPPFlowControlLoop::ACPPFlowControlLoop()
{
	// Event Dispathcer[OnPrintHello]にCustom Event[PrintHello]をバインドする
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
		// Hello World!を出力する処理
		PrintHello();
	}
	else
	{
		// 計算結果を出力する処理
		PressedActionPrintCalcResult();
	}
}

void ACPPFlowControlLoop::PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration)
{
	switch (Type)
	{
		case ECPPCalcType::Add:
		{
			// Add(足し算)の処理
			// 値渡し
			int32 ResultAdd = Sum(A, B);
			FString StrResultAdd = FString::Printf(TEXT("%d"), ResultAdd);
			UKismetSystemLibrary::PrintString(this, StrResultAdd, true, true, FColor::Red, PrintDuration);
			break;
		}
		case ECPPCalcType::Subtract:
		{
			// Subtract(引き算)の処理
			int32 ResultSubtract = A - B;
			FString StrResultSubtract = FString::Printf(TEXT("%d"), ResultSubtract);
			UKismetSystemLibrary::PrintString(this, StrResultSubtract, true, true, FColor::Yellow, PrintDuration);
			break;
		}
		case ECPPCalcType::Multiply:
		{
			// Multiply(掛け算)の処理
			int32 ResultMultiply = A * B;
			FString StrResultMultiply = FString::Printf(TEXT("%d"), ResultMultiply);
			UKismetSystemLibrary::PrintString(this, StrResultMultiply, true, true, FColor::Green, PrintDuration);
			break;
		}
		case ECPPCalcType::Divide:
		{
			// Divide(割り算)の処理(int > float)
			float ResultDivide = (float)A / (float)B;
			FString StrResultDivide = FString::Printf(TEXT("%f"), ResultDivide);
			UKismetSystemLibrary::PrintString(this, StrResultDivide, true, true, FColor::Blue, PrintDuration);
			break;
		}
	}
}

void ACPPFlowControlLoop::SetupInput()
{
	// 入力を有効にする
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	// HキーのPressedとReleasedをバインドする
	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPFlowControlLoop::PressedH);

	// ActionMappingsに設定したActionをバインドする
	InputComponent->BindAction("ActionPrintCalcResult", IE_Pressed, this, &ACPPFlowControlLoop::PressedActionPrintCalcResult);
}

void ACPPFlowControlLoop::PressedH()
{
	// Event Dispathcer[OnPrintHello]をコールする
	OnPrintHello.Broadcast();
}

void ACPPFlowControlLoop::PressedActionPrintCalcResult()
{
	// 計算結果を出力する処理
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
		// 文字列に"Bonjour"が含まれているか
		if (Messages[HelloIndex].Contains(TEXT("Bonjour")))
		{
			// While Loopの条件をfalseに設定する
			NotBonjour = false;
		}
		else
		{
			// Messagesの値を出力する
			UKismetSystemLibrary::PrintString(this, Messages[HelloIndex], true, true, TextColor, Duration);
		}
		// HelloIndexをインクリメント
		HelloIndex++;
	}

	// CompletedをPrintStringで出力する
	UKismetSystemLibrary::PrintString(this, TEXT("Completed"), true, true, FColor::Cyan, Duration);
}
