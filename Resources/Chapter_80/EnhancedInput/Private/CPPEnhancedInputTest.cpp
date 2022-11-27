// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPEnhancedInputTest.h"
#include "Kismet/KismetSystemLibrary.h" // 追加
#include "Kismet/GameplayStatics.h" // 追加
#include "Components/InputComponent.h" // 追加
#include "EnhancedInputComponent.h" // 追加
#include "EnhancedInputSubsystems.h" // 追加

class UInputMappingContext;

// Sets default values
ACPPEnhancedInputTest::ACPPEnhancedInputTest()
{
	// Input Actionを読込
	ActionInput = LoadObject<UInputAction>(NULL, TEXT("/Game/EnhancedInputTest/Input/Actions/IA_Action"), NULL, LOAD_None, NULL);
	AxisInput = LoadObject<UInputAction>(NULL, TEXT("/Game/EnhancedInputTest/Input/Actions/IA_Axis"), NULL, LOAD_None, NULL);

	// Input Mapping Contextを読込
	DefaultMappingContext = LoadObject<UInputMappingContext>(NULL, TEXT("/Game/EnhancedInputTest/Input/IMC_Default"), NULL, LOAD_None, NULL);
}

// Called when the game starts or when spawned
void ACPPEnhancedInputTest::BeginPlay()
{
	Super::BeginPlay();

	// Input設定を行う
	SetupInput();
}

void ACPPEnhancedInputTest::SetupInput()
{
	// PlayerControllerを取得する
	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	// 入力を有効にする
	EnableInput(controller);

	if (InputComponent)
	{
		// Set up action bindings
		if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent)) {

			// Input Action
			EnhancedInputComponent->BindAction(ActionInput, ETriggerEvent::Triggered, this, &ACPPEnhancedInputTest::PressedAction);
			EnhancedInputComponent->BindAction(ActionInput, ETriggerEvent::Completed, this, &ACPPEnhancedInputTest::ReleasedAction);

			// Input Axis
			EnhancedInputComponent->BindAction(AxisInput, ETriggerEvent::Triggered, this, &ACPPEnhancedInputTest::PressedAxis);
		}

		// Input Mapping Contextを登録する
		if (APlayerController* PlayerController = Cast<APlayerController>(controller))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
}

void ACPPEnhancedInputTest::PressedAction()
{
	if (!IsPressed)
	{
		// Pressed
		UKismetSystemLibrary::PrintString(this, TEXT("Pressed"), true, true, FColor::Cyan, 10.0f, TEXT("None"));

		// Press状態に設定
		IsPressed = true;
	}
}

void ACPPEnhancedInputTest::ReleasedAction()
{
	// Released
	UKismetSystemLibrary::PrintString(this, TEXT("Released"), true, true, FColor::Cyan, 10.0f, TEXT("None"));

	// Press状態を解除
	IsPressed = false;
}

void ACPPEnhancedInputTest::PressedAxis(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D v = Value.Get<FVector2D>();

	// Axis Input Value
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("X:%f Y:%f"), v.X, v.Y), true, true, FColor::Cyan, 10.0f, TEXT("None"));
}
