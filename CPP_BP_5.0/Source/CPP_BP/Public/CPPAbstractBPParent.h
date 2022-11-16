// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPAbstractBPParent.generated.h"

UCLASS(BlueprintType, Blueprintable, Abstract)
class CPP_BP_API ACPPAbstractBPParent : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// îhê∂ÉNÉâÉXÇ≈ílÇê›íËÇ∑ÇÈ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		FString GreetingMessage;

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Greeting();
};
