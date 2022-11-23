// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPAccessParent.generated.h"

UCLASS()
class CPP_BP_API ACPPAccessParent : public AActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	// 親クラスのメンバ関数(Public)
	void CallPublicFunc();

	// 親クラスのデータメンバ(Public)
	int VarPublicNum = 10;

protected:

	// 親クラスのメンバ関数(Protected)
	void CallProtectedFunc();

	// 親クラスのデータメンバ(Protected)
	int VarProtectedNum = 20;

private:

	// 親クラスのメンバ関数(Private)
	void CallPrivateFunc();

	// 親クラスのデータメンバ(Private)
	int VarPrivateNum = 30;
};
