// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPComponent::BeginPlay()
{
	Super::BeginPlay();

	// 変数を作成する
	FString Message = "C++ Hello World!";

	// PrintStringノードと同じ処理
	// UKismetSystemLibraryクラスのPrintString関数を呼び出す
	UKismetSystemLibrary::PrintString(
		this
		, Message
		, true
		, true
		, TextColor// Textのカラー情報に変数TextColorを設定
		, Duration
		, TEXT("None"));
}