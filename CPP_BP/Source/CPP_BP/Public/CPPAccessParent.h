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
	
	// �e�N���X�̃����o�֐�(Public)
	void CallPublicFunc();

	// �e�N���X�̃f�[�^�����o(Public)
	int VarPublicNum = 10;

protected:

	// �e�N���X�̃����o�֐�(Protected)
	void CallProtectedFunc();

	// �e�N���X�̃f�[�^�����o(Protected)
	int VarProtectedNum = 20;

private:

	// �e�N���X�̃����o�֐�(Private)
	void CallPrivateFunc();

	// �e�N���X�̃f�[�^�����o(Private)
	int VarPrivateNum = 30;
};
