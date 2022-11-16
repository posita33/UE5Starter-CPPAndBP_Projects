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

	// �h���N���X�Œl��ݒ肷��
	UPROPERTY(EditAnywhere, Category = Default)
	FString GreetingMessage;

public:
	// ���A����
	virtual void Greeting(FString message) PURE_VIRTUAL (ACPPAbstractParent::Greeting, );
};
