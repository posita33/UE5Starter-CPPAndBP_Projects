// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPStaticTest.h"
#include "CPPStatic.h"
#include "Kismet/KismetSystemLibrary.h"

int ACPPStatic::staticPoint = 400;

// Called when the game starts or when spawned
void ACPPStaticTest::BeginPlay()
{
	Super::BeginPlay();

	// CPPStatic‚ð¶¬‚·‚é
	ACPPStatic* staticActorA = GetWorld()->SpawnActor<ACPPStatic>(ACPPStatic::StaticClass());
	// ƒƒ“ƒo•Ï”‚ðÝ’è‚·‚é
	staticActorA->normalPoint = 100;

	// CPPStatic‚ð¶¬‚·‚é
	ACPPStatic* staticActorB = GetWorld()->SpawnActor<ACPPStatic>(ACPPStatic::StaticClass());
	// ƒƒ“ƒo•Ï”‚ðÝ’è‚·‚é
	staticActorB->normalPoint = 200;

	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("staticActorA staticPoint : %d, normalPoint : %d"), ACPPStatic::staticPoint, staticActorA->normalPoint), true, true, FColor::Cyan, 10.f);

	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("staticActorB staticPoint : %d, normalPoint : %d"), staticActorB->staticPoint, staticActorB->normalPoint), true, true, FColor::Red, 10.f);

}
