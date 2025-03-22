// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbstractSampleActor.generated.h"

// 抽象クラスを示す abstract キーワードを追加
UCLASS(Abstract, Blueprintable)
class CPP_BP_API AAbstractSampleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbstractSampleActor();
	
	// 戻り値：なし
	// 引数：なし
	// Blueprint：必ず実装が必要
	// C++:実装なし
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Abstract Sample")
	void DoLogging();

	// 戻り値：なし
	// 引数：あり
	// Blueprint：必ず実装が必要
	// C++:実装なし
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Abstract Sample")
	void DoLoggingWithArg(const FString& Message);

	// 戻り値：あり
	// 引数：なし
	// Blueprint：必ず実装が必要
	// C++:実装なし
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Abstract Sample")
	int32 Calculation();

	// 戻り値：あり
	// 引数：あり
	// Blueprint：必ず実装が必要
	// C++:実装なし
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Abstract Sample")
	int32 CalculationWithArg(int32 A, int32 B);

	// 戻り値：なし
	// 引数：なし
	// Blueprint：上書き可能
	// C++:デフォルト実装（任意）
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Abstract Sample")
	void FuncOverridable();
	virtual void FuncOverridable_Implementation();

	// 戻り値：あり
	// 引数：あり
	// Blueprint：上書き可能
	// C++:デフォルト実装（任意）
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Abstract Sample")
	int32 FuncOverridableWithArg(int32 Value);
	virtual int32 FuncOverridableWithArg_Implementation(int32 Value);
};
