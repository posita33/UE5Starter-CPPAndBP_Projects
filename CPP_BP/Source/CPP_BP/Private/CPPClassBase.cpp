// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPClassBase.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPClassBase::ACPPClassBase()
{
	// SceneComponent��RootComponent�ɐݒ肷��B
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	// SceneComponent��RootComponent�ɐݒ肷��
	RootComponent = DefaultSceneRoot;

	// StaticMeshComponent���쐬����
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	// StaticMesh��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/CPP_BP/Meshes/SM_SampleCube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);

	// StaticMeshComponent��RootComponent��Attach����
	StaticMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACPPClassBase::BeginPlay()
{
	Super::BeginPlay();
	
	// �����̃����o�֐����Ăяo��
	CallParentFunc();
}

void ACPPClassBase::CallParentFunc()
{
	// Viewport�ɔz�u����Actor�̕\�������擾����
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	// PrintString��Actor�\����,�����o�֐�,�f�[�^�����o���o��
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s : CallParentFunc %d"), *name, VarParentNum), true, true, FColor::Cyan, 10.f, TEXT("None"));
}
