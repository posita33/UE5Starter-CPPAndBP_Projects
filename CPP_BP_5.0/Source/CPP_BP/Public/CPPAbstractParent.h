// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPAbstractParent.generated.h"

UCLASS(Abstract)
class CPP_BP_API ACPPAbstractParent : public AActor
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 派生クラスで値を設定する
	UPROPERTY(EditAnywhere, Category = Default)
	FString GreetingMessage;

public:
	// 挨拶する
	virtual void Greeting(FString message) PURE_VIRTUAL (ACPPAbstractParent::Greeting, );
};
