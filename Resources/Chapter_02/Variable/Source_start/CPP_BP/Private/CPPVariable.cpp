// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPVariable.h"

// Called when the game starts or when spawned
void ACPPVariable::BeginPlay()
{
	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(this, "C++ Hello World!", true, true, FColor::Cyan, 2.f);
}
