// Fill out your copyright notice in the Description page of Project Settings.


#include "tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

Atank::Atank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Sprint Arm"));
	SpringArm->SetupAttachment(RootComponent);


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void Atank::Move(float Value)
{
}
