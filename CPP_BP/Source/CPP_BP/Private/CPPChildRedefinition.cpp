// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPChildRedefinition.h"

void ACPPChildRedefinition::SetPoint(int myPoint)
{
	// ���N���X��SetPoint��myPoint�̒l��ύX���ČĂяo��
	ACPPParentRedefinition::SetPoint(myPoint - 30);
}
