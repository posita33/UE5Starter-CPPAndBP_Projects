// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPConstructor.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPConstructor::ACPPConstructor()
{
    // ƒƒ“ƒo•Ï”‚ğ‰Šú‰»‚·‚é
	hp = 100;

	// SceneComponent‚ğRootComponent‚Éİ’è‚·‚éB
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	// SceneComponent‚ğRootComponent‚Éİ’è‚·‚é
	RootComponent = DefaultSceneRoot;

	// StaticMeshComponent‚ğì¬‚·‚é
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	// StaticMesh‚ğLaod‚µ‚ÄStaticMeshComponent‚ÌStaticMesh‚Éİ’è‚·‚é
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/CPP_BP/Meshes/SM_SampleCube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);

	// StaticMeshComponent‚ğRootComponent‚ÉAttach‚·‚é
	StaticMesh->SetupAttachment(RootComponent);
}

ACPPConstructor::~ACPPConstructor()
{
	// Destructor‚ÅPrintString
	UKismetSystemLibrary::PrintString(this, TEXT("Destructor Class destroyed"), true, true, FColor::Cyan, 2.f);
}

// Called when the game starts or when spawned
void ACPPConstructor::BeginPlay()
{
	Super::BeginPlay();

	// Constructor‚Å‰Šú‰»‚µ‚½•Ï”‚ğPrintString‚Åo—Í‚·‚é
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%d"), hp), true, true, FColor::Cyan, 2.f);
}

void ACPPConstructor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// EndPlay‚ÅPrintString
	UKismetSystemLibrary::PrintString(this, TEXT("EndPlay Class destroyed"), true, true, FColor::Cyan, 2.f);

}

