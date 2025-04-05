// Fill out your copyright notice in the Description page of Project Settings.


#include "Interface/InterfaceImplementer.h"

// Sets default values
AInterfaceImplementer::AInterfaceImplementer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AInterfaceImplementer::DoSomething_Implementation()
{
	IMyInterface::DoSomething_Implementation();
	
	UE_LOG(LogTemp, Warning, TEXT("InterfaceImplementerがDoSomethingを実行しました！"));
}

