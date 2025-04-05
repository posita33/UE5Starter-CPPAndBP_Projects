// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/MyInterface.h"
#include "InterfaceUser.generated.h"

UCLASS()
class CPP_BP_API AInterfaceUser : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInterfaceUser();

protected:
	// InterfaceInstance をセットする関数
	UFUNCTION(BlueprintCallable, Category = "Interface")
	void SetInterfaceActor(AActor* NewActor);

	// InterfaceInstance に実装された関数を実行する
	UFUNCTION(BlueprintCallable, Category = "Interface")
	void ExecuteInterfaceFunction();

protected:
	// インターフェースを保持する変数
	TScriptInterface<IMyInterface> InterfaceInstance;
};
