// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPHelloWorld.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPHelloWorld::BeginPlay()
{
	Super::BeginPlay();

	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(this, "C++ Hello World!", true, true, FColor::Cyan, 2.f, TEXT("None"));

}
