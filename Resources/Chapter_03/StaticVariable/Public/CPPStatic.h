// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPStatic.generated.h"

UCLASS()
class CPP_BP_API ACPPStatic : public AActor
{
	GENERATED_BODY()
	
public:
	// staticメンバ変数
	static int staticPoint;

	// 通常のメンバ変数
	int normalPoint;
};
