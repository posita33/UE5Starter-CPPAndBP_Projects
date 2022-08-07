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
	USceneComponent* DefaultSceneRoot;

	// StaticMesh Component
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	// �e�N���X�̃����o�֐� 
	void CallParentFunc();

	// �e�N���X�̃f�[�^�����o
	int VarParentNum = 10;
};
