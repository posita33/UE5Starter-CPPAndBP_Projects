// Fill out your copyright notice in the Description page of Project Settings.


#include "Interface/InterfaceUser.h"

// Sets default values
AInterfaceUser::AInterfaceUser()
{
}

void AInterfaceUser::SetInterfaceActor(AActor* NewActor)
{
	if (NewActor && NewActor->GetClass()->ImplementsInterface(UMyInterface::StaticClass()))
	{
		InterfaceInstance.SetObject(NewActor);
		InterfaceInstance.SetInterface(Cast<IMyInterface>(NewActor));
        
		UE_LOG(LogTemp, Warning, TEXT("InterfaceInstance が正常にセットされました。"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("指定されたアクターはインターフェースを実装していません。"));
	}
}

void AInterfaceUser::ExecuteInterfaceFunction()
{
	if (InterfaceInstance)
	{
		IMyInterface::Execute_DoSomething(InterfaceInstance.GetObject());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("InterfaceInstance がセットされていないか、無効です。"));
	}
}
