// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPComponent.h"
#include "Kismet/KismetSystemLibrary.h"

ACPPComponent::ACPPComponent()
{
	// SceneComponent���쐬����
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	// SceneComponent��RootComponent�ɐݒ肷��
	RootComponent = DefaultSceneRoot;

	// StaticMeshComponent���쐬����
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/CPP_BP/Meshes/SM_SampleCube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);

	// ArrowComponent���쐬����
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));

	// ArrowComponent�̈ʒu��ݒ肷��
	Arrow->SetRelativeLocation(FVector(30.0f, 0.0f, 0.0f));

	// ArrowComponent��StaticMeshComponent��Attach����
	Arrow->SetupAttachment(StaticMesh);

	// PointLightComponent���쐬����
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));

	// PointLightComponent�̈ʒu��ݒ肷��
	PointLight->SetRelativeLocation(FVector(130.0f, 0.0f, 0.0f));

	// PointLightComponent��StaticMeshComponent��Attach����
	PointLight->SetupAttachment(StaticMesh);
}

// Called when the game starts or when spawned
void ACPPComponent::BeginPlay()
{
	FString Message = "C++ Hello World!";

	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
}
