// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/MyInterface.h"
#include "InterfaceImplementer.generated.h"

UCLASS()
class CPP_BP_API AInterfaceImplementer : public AActor, public IMyInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInterfaceImplementer();

	virtual void DoSomething_Implementation() override;
};
