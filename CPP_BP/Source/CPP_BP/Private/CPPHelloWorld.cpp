// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPHelloWorld.h"
#include "Kismet/KismetSystemLibrary.h" //�ǉ�

// Sets default values
ACPPHelloWorld::ACPPHelloWorld()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPHelloWorld::BeginPlay()
{
	Super::BeginPlay();

	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(this, "C++ Hello World!", true, true, FColor::Cyan, 2.f);

	// Output Log�ɕ�������o�͂���}�N��
	UE_LOG(LogTemp, Display, TEXT("Display Message"));
	UE_LOG(LogTemp, Warning, TEXT("Warning Message"));
	UE_LOG(LogTemp, Error, TEXT("Error Message"));

	// Viewport�̍���ɕ�������o�͂���֐�
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White, "C++ Hello World!", true, FVector2D(2.0f, 2.0f));
}

// Called every frame
void ACPPHelloWorld::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

