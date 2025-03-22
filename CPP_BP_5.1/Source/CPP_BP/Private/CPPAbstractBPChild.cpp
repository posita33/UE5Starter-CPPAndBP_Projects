// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAbstractBPChild.h"
#include "Kismet/KismetSystemLibrary.h"

void ACPPAbstractBPChild::Greeting_Implementation()
{
	UKismetSystemLibrary::PrintString(this, GreetingMessage, true, true, FColor::Cyan, 10.f, TEXT("None"));
}
