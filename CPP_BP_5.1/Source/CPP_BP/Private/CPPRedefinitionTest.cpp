// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPRedefinitionTest.h"
#include "CPPParentRedefinition.h"
#include "CPPChildRedefinition.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPRedefinitionTest::BeginPlay()
{
	Super::BeginPlay();

	// 親クラスを生成する
	ACPPParentRedefinition* parentActor = GetWorld()->SpawnActor<ACPPParentRedefinition>(ACPPParentRedefinition::StaticClass());
	// SetPointを呼び出す
	parentActor->SetPoint(100);
	// GetPointの値を出力する
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Parent Point : %d"), parentActor->GetPoint()), true, true, FColor::Cyan, 10.f, TEXT("None"));

	// 子クラスを生成する
	ACPPChildRedefinition* childActor = GetWorld()->SpawnActor<ACPPChildRedefinition>(ACPPChildRedefinition::StaticClass());
	// SetPointを呼び出す
	childActor->SetPoint(100);
	// GetPointの値を出力する
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Child Point : %d"), childActor->GetPoint()), true, true, FColor::Red, 10.f, TEXT("None"));

}
