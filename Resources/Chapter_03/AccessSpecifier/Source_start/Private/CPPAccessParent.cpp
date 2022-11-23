// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAccessParent.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPAccessParent::BeginPlay()
{
	Super::BeginPlay();

	// Public関数の呼び出し
	CallPublicFunc();

	// Protected関数の呼び出し
	CallProtectedFunc();

	// Private関数の呼び出し
	CallPrivateFunc();
}

void ACPPAccessParent::CallPublicFunc()
{
	// Viewportに配置したActorの表示名を取得する
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	// PrintStringでActor表示名,メンバ関数,データメンバを出力
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s : CallPublicFunc %d"), *name, VarPublicNum), true, true, FColor::Cyan, 10.f, TEXT("None"));
}

void ACPPAccessParent::CallProtectedFunc()
{
	// Viewportに配置したActorの表示名を取得する
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	// PrintStringでActor表示名,メンバ関数,データメンバを出力
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s : CallProtectedFunc %d"), *name, VarProtectedNum), true, true, FColor::Cyan, 10.f, TEXT("None"));
}

void ACPPAccessParent::CallPrivateFunc()
{
	// Viewportに配置したActorの表示名を取得する
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	// PrintStringでActor表示名,メンバ関数,データメンバを出力
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s : CallPrivateFunc %d"), *name, VarPrivateNum), true, true, FColor::Cyan, 10.f, TEXT("None"));
}
