// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPClassChild.h"
#include "Kismet/KismetSystemLibrary.h"

ACPPClassChild::ACPPClassChild()
{
	// SphereをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/BasicShapes/Sphere"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);

	// MaterialをロードしてStaticMeshに設定する
	UMaterial* Material = LoadObject<UMaterial>(NULL, TEXT("/Game/CPP_BP/Materials/M_SampleMaterial"), NULL, LOAD_None, NULL);
	StaticMesh->SetMaterial(0, Material);
}

void ACPPClassChild::BeginPlay()
{
	// 親クラスのデータメンバを変更する
	VarParentNum = 1000;

	// 親クラスのメンバ関数を呼び出す
	CallParentFunc();

	// 自分が持っているメンバ関数を呼び出す
	CallChildFunc();
}

void ACPPClassChild::CallChildFunc()
{
	// Viewportに配置したActorの表示名を取得する
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	// PrintStringでActor表示名と関数名を出力
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s : CallChildFunc %d"), *name, VarChildNum), true, true, FColor::Blue, 10.f);
}
