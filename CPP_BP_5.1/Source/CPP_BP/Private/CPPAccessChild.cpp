// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAccessChild.h"

void ACPPAccessChild::BeginPlay()
{
	// Super::BeginPlay();

	// �f�[�^�����o(Public)��ύX����
	VarPublicNum = 100;

	// �f�[�^�����o(Protected)��ύX����
	VarProtectedNum = 200;

	// �f�[�^�����o(Private)��ύX����
	// VarPrivateNum = 300;

	// ���N���X�̃����o�֐�(Public)���Ăяo��
	CallPublicFunc();

	// ���N���X�̃����o�֐�(Protected)���Ăяo��
	CallProtectedFunc();

	// ���N���X�̃����o�֐�(Private)���Ăяo��
	// CallPrivateFunc();
}
