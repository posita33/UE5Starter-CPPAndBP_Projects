// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h" // �ǉ�
#include "Components/PointLightComponent.h" // �ǉ�
#include "CPPComponent.generated.h"

UCLASS()
class CPP_BP_API ACPPComponent : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPPComponent();

	// Scene Component
	UPROPERTY(EditAnywhere)
		USceneComponent* DefaultSceneRoot;

	// StaticMesh Component
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMesh;

	// Arrow Component
	UPROPERTY(VisibleAnywhere)
		UArrowComponent* Arrow;

	// PointLightComponent Component
	UPROPERTY(EditAnywhere)
		UPointLightComponent* PointLight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// PrintString�֐���Duration�ɐݒ肷��ϐ�
	const float Duration = 10.0f;

	// PrintString�֐���TextColor�ɐݒ肷��ϐ�
	const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);

};