// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPChildVirtual.h"

void ACPPChildVirtual::SetPoint(int myPoint)
{
	// ���N���X��SetPoint��myPoint�̒l��ύX���ČĂяo��
	ACPPParentVirtual::SetPoint(myPoint - 30);
}
