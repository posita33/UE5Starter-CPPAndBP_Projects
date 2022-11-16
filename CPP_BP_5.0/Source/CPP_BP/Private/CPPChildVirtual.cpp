// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPChildVirtual.h"

void ACPPChildVirtual::SetPoint(int myPoint)
{
	// 基底クラスのSetPointをmyPointの値を変更して呼び出す
	ACPPParentVirtual::SetPoint(myPoint - 30);
}
