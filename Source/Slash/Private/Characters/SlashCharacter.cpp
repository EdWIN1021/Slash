// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SlashCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ASlashCharacter::ASlashCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationRoll = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 300.0f;
	
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(CameraBoom);
}

void ASlashCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ASlashCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASlashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ASlashCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ASlashCharacter::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ASlashCharacter::LookUp);
}

void ASlashCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0.f)
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, Value);
	}
}

void ASlashCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ASlashCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}