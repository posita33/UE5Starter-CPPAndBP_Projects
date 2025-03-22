// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Components/PointLightComponent.h"
#include "CPPConstructionScript.generated.h"

UCLASS()
class CPP_BP_API ACPPConstructionScript : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPPConstructionScript();

	// Scene Component
	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	// StaticMesh Component
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	// Arrow Component
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UArrowComponent> Arrow;

	// PointLightComponent Component
	UPROPERTY(EditAnywhere)
	TObjectPtr<UPointLightComponent> PointLight;

	UPROPERTY(EditAnywhere, Category = "Point Light")
	bool bIsVisible = false;

	UPROPERTY(EditAnywhere, Category = "Point Light")
	float Intensity = 5000.0f;

	UPROPERTY(EditAnywhere, Category = "Point Light")
	FLinearColor LightColor = FLinearColor::White;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// ConstructionScript
	virtual void OnConstruction(const FTransform& Transform) override;

	// PrintString�֐���Duration�ɐݒ肷��ϐ�
	const float Duration = 10.0f;

	// PrintString�֐���TextColor�ɐݒ肷��ϐ�
	const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);

};
