// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPVirtualTest.h"
#include "CPPParentVirtual.h"
#include "CPPChildVirtual.h"
#include "CPPParentRedefinition.h"
#include "CPPChildRedefinition.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPVirtualTest::BeginPlay()
{
	Super::BeginPlay();

	// CPPChildRedefinition�𐶐�����
	ACPPParentRedefinition* redefinitionActor = GetWorld()->SpawnActor<ACPPChildRedefinition>(ACPPChildRedefinition::StaticClass());
	// SetPoint���Ăяo��
	redefinitionActor->SetPoint(100);
	// GetPoint�̒l���o�͂���
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Redefinition Point : %d"), redefinitionActor->GetPoint()), true, true, FColor::Cyan, 10.f, TEXT("None"));

	// CPPChildVirtual�𐶐�����
	ACPPParentVirtual* virautalActor = GetWorld()->SpawnActor<ACPPChildVirtual>(ACPPChildVirtual::StaticClass());
	// SetPoint���Ăяo��
	virautalActor->SetPoint(100);
	// GetPoint�̒l���o�͂���
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Virtual Point : %d"), virautalActor->GetPoint()), true, true, FColor::Red, 10.f, TEXT("None"));

}
