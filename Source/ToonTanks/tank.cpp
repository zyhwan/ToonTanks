// Fill out your copyright notice in the Description page of Project Settings.


#include "tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"


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
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &Atank::Turn);
}

void Atank::BeginPlay()
{
	Super::BeginPlay();

	//캐스팅
	PlayerControllerRef = Cast<APlayerController>(GetController());

}

void Atank::Move(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Value : %f"), Value);

	//델타 타임으로 프레임별 이동 속도 맞춰주기
	// X(위치 이동값) = Value * Deltatime * Speed
	// UGameplayStatics::GetWorldDeltaSeconds() : 델타 타임을 반환하는 함수, 인자로 World Context object(this 포인터를 받음)를 받는데 이는 월드 객체에 어떤것이든 인자로 넣으면 해당 월드의 델타 타임을 반환해준다.

	FVector DeltaLocation = FVector::ZeroVector; 
	DeltaLocation.X = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);

	AddActorLocalOffset(DeltaLocation, true);

}

void Atank::Turn(float Value)
{
	// Yaw = Value * Deltatime * TurnRate 
	
	FRotator DeltaRotation = FRotator::ZeroRotator;
	DeltaRotation.Yaw = Value * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
	
	AddActorLocalRotation(DeltaRotation, true);



}