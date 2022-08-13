// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAccessOther.h"
#include "CPPAccessParent.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void ACPPAccessOther::BeginPlay()
{
	Super::BeginPlay();

	// ViewportにあるACPPAccessParentを探す
	AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(),ACPPAccessParent::StaticClass());

	// 取得したAActorからACPPAccessParentに変換する 
	ACPPAccessParent* CPPAccessParent = Cast<ACPPAccessParent>(FoundActor);

	// CPPAccessParentのデータメンバ(Public)を変更する
	CPPAccessParent->VarPublicNum = 1000;

	// CPPAccessParentのデータメンバ(Protected)を変更する
	// CPPAccessParent->VarProtectedNum = 2000;

	// CPPAccessParentのデータメンバ(Private)を変更する
	// CPPAccessParent->VarPrivateNum = 3000;

	// CPPAccessParentのメンバ関数(Public)を呼び出す
	CPPAccessParent->CallPublicFunc();

	// CPPAccessParentのメンバ関数(Protected)を呼び出す
	// CPPAccessParent->CallProtectedFunc();

	// CPPAccessParentのメンバ関数(Private)を呼び出す
	// CPPAccessParent->CallPrivateFunc();
}
