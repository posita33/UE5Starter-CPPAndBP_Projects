// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAbstractParent.h"
#include "Kismet/KismetSystemLibrary.h"

void ACPPAbstractParent::BeginPlay()
{
	Super::BeginPlay();

	// 挨拶する
	Greeting(GreetingMessage);
}
