// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPCalculation.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPCalculation::BeginPlay()
{
	FString Message = "C++ Hello World!";

	// PrintStringノードと同じ処理
	// UKismetSystemLibraryクラスのPrintString関数を呼び出す
	UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
}
