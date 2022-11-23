// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPRedefinitionTest.h"
#include "CPPParentRedefinition.h"
#include "CPPChildRedefinition.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPRedefinitionTest::BeginPlay()
{
	Super::BeginPlay();

	// �e�N���X�𐶐�����
	ACPPParentRedefinition* parentActor = GetWorld()->SpawnActor<ACPPParentRedefinition>(ACPPParentRedefinition::StaticClass());
	// SetPoint���Ăяo��
	parentActor->SetPoint(100);
	// GetPoint�̒l���o�͂���
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Parent Point : %d"), parentActor->GetPoint()), true, true, FColor::Cyan, 10.f, TEXT("None"));

	// �q�N���X�𐶐�����
	ACPPChildRedefinition* childActor = GetWorld()->SpawnActor<ACPPChildRedefinition>(ACPPChildRedefinition::StaticClass());
	// SetPoint���Ăяo��
	childActor->SetPoint(100);
	// GetPoint�̒l���o�͂���
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Child Point : %d"), childActor->GetPoint()), true, true, FColor::Red, 10.f, TEXT("None"));

}
