// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPHelloWorld.h"
#include "Kismet/KismetSystemLibrary.h" //追加

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

	// PrintStringノードと同じ処理
	// UKismetSystemLibraryクラスのPrintString関数を呼び出す
	UKismetSystemLibrary::PrintString(this, "C++ Hello World!", true, true, FColor::Cyan, 2.f);

	// Output Logに文字列を出力するマクロ
	UE_LOG(LogTemp, Display, TEXT("Display Message"));
	UE_LOG(LogTemp, Warning, TEXT("Warning Message"));
	UE_LOG(LogTemp, Error, TEXT("Error Message"));

	// Viewportの左上に文字列を出力する関数
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White, "C++ Hello World!", true, FVector2D(2.0f, 2.0f));
}

// Called every frame
void ACPPHelloWorld::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

