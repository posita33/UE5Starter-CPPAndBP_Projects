// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAccessParent.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPAccessParent::BeginPlay()
{
	Super::BeginPlay();

	// Public�֐��̌Ăяo��
	// CallPublicFunc();

	// Protected�֐��̌Ăяo��
	// CallProtectedFunc();

	// Private�֐��̌Ăяo��
	// CallPrivateFunc();
}

void ACPPAccessParent::CallPublicFunc()
{
	// Viewport�ɔz�u����Actor�̕\�������擾����
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	// PrintString��Actor�\����,�����o�֐�,�f�[�^�����o���o��
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s : CallPublicFunc %d"), *name, VarPublicNum), true, true, FColor::Cyan, 10.f, TEXT("None"));
}

void ACPPAccessParent::CallProtectedFunc()
{
	// Viewport�ɔz�u����Actor�̕\�������擾����
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	// PrintString��Actor�\����,�����o�֐�,�f�[�^�����o���o��
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s : CallProtectedFunc %d"), *name, VarProtectedNum), true, true, FColor::Cyan, 10.f, TEXT("None"));
}

void ACPPAccessParent::CallPrivateFunc()
{
	// Viewport�ɔz�u����Actor�̕\�������擾����
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	// PrintString��Actor�\����,�����o�֐�,�f�[�^�����o���o��
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s : CallPrivateFunc %d"), *name, VarPrivateNum), true, true, FColor::Cyan, 10.f, TEXT("None"));
}
