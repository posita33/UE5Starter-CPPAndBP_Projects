// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPClassBase.generated.h"

UCLASS()
class CPP_BP_API ACPPClassBase : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ACPPClassBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Scene Component
	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	// StaticMesh Component
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	// �e�N���X�̃����o�֐� 
	UFUNCTION(BlueprintCallable, Category = CPP_And_Blueprint)
	void CallParentFunc();

	// �e�N���X�̃f�[�^�����o
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	int VarParentNum = 10;
};
