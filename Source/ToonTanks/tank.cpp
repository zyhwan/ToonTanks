// Fill out your copyright notice in the Description page of Project Settings.


#include "tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

Atank::Atank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Sprint Arm"));
	SpringArm->SetupAttachment(RootComponent);


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void Atank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &Atank::Move);
}

void Atank::Move(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Value : %f"), Value);

	FVector DeltaLocation = FVector::ZeroVector; 

	DeltaLocation.X = Value;

	AddActorLocalOffset(DeltaLocation);

}
