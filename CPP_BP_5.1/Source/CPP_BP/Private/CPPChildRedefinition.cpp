// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPChildRedefinition.h"

void ACPPChildRedefinition::SetPoint(int myPoint)
{
	// 基底クラスのSetPointをmyPointの値を変更して呼び出す
	ACPPParentRedefinition::SetPoint(myPoint - 30);
}
