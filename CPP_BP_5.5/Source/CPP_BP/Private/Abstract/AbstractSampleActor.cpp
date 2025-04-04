// Fill out your copyright notice in the Description page of Project Settings.


#include "Abstract/AbstractSampleActor.h"

// Sets default values
AAbstractSampleActor::AAbstractSampleActor()
{

}

void AAbstractSampleActor::FuncOverridable_Implementation()
{
	// Blueprintで上書き可能
	// 処理の実装は任意
	UE_LOG(LogTemp, Display, TEXT("FuncOverridable"));
}

int32 AAbstractSampleActor::FuncOverridableWithArg_Implementation(int32 Value)
{
	// Blueprintで上書き可能
	// 処理の実装は任意
	UE_LOG(LogTemp, Display, TEXT("FuncOverridableWithArg : %d"), Value);
	return Value;
}

void AAbstractSampleActor::FuncNonOverridableBP()
{
	UE_LOG(LogTemp, Log, TEXT("これはC++のみオーバーライドできる関数です。"));	
}

void AAbstractSampleActor::FuncNonOverridableBoth()
{
	UE_LOG(LogTemp, Log, TEXT("これはオーバーライド禁止のfinal関数です。"));
}
