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
	
	// static�����o�֐�
	static void SetPoint(int myPoint);

	// static�����o�ϐ�
	static int staticPoint;

	// �ʏ�̃����o�ϐ�
	int normalPoint;
};
