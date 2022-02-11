// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPComponent::BeginPlay()
{
	FString Message = "C++ Hello World!";

	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
}