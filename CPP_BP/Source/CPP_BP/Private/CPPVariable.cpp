// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPVariable.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h" // �ǉ�

// Called when the game starts or when spawned
void ACPPVariable::BeginPlay()
{
	FString Message = "C++ Hello World!";

	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(
		this
		, Message // Message�ɖ߂�
		, true
		, true
		, TextColor// Text�̃J���[���ɕϐ�TextColor��ݒ�
		, Duration);
}
