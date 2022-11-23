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

	// CPPChildRedefinitionを生成する
	ACPPParentRedefinition* redefinitionActor = GetWorld()->SpawnActor<ACPPChildRedefinition>(ACPPChildRedefinition::StaticClass());
	// SetPointを呼び出す
	redefinitionActor->SetPoint(100);
	// GetPointの値を出力する
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Redefinition Point : %d"), redefinitionActor->GetPoint()), true, true, FColor::Cyan, 10.f, TEXT("None"));

	// CPPChildVirtualを生成する
	ACPPParentVirtual* virautalActor = GetWorld()->SpawnActor<ACPPChildVirtual>(ACPPChildVirtual::StaticClass());
	// SetPointを呼び出す
	virautalActor->SetPoint(100);
	// GetPointの値を出力する
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Virtual Point : %d"), virautalActor->GetPoint()), true, true, FColor::Red, 10.f, TEXT("None"));

}
