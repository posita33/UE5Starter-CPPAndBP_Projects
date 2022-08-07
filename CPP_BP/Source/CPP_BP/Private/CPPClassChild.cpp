// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPClassChild.h"
#include "Kismet/KismetSystemLibrary.h"

ACPPClassChild::ACPPClassChild()
{
	// Sphere��Laod����StaticMeshComponent��StaticMesh�ɐݒ肷��
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/BasicShapes/Sphere"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);

	// Material�����[�h����StaticMesh�ɐݒ肷��
	UMaterial* Material = LoadObject<UMaterial>(NULL, TEXT("/Game/CPP_BP/Materials/M_SampleMaterial"), NULL, LOAD_None, NULL);
	StaticMesh->SetMaterial(0, Material);
}

void ACPPClassChild::BeginPlay()
{
	// �e�N���X�̃f�[�^�����o��ύX����
	VarParentNum = 1000;

	// �e�N���X�̃����o�֐����Ăяo��
	CallParentFunc();

	// �����������Ă��郁���o�֐����Ăяo��
	CallChildFunc();
}

void ACPPClassChild::CallChildFunc()
{
	// Viewport�ɔz�u����Actor�̕\�������擾����
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	// PrintString��Actor�\�����Ɗ֐������o��
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s : CallChildFunc %d"), *name, VarChildNum), true, true, FColor::Blue, 10.f);
}
