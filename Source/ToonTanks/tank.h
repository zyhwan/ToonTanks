// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API Atank : public ABasePawn
{
	GENERATED_BODY()
	
public:
	Atank();

	//이동 입력값을 처리해줄 함수.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 600.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate = 120.f;

	//전방 이동 매핑에 바인드할 함수.
	void Move(float Value);

	//객체 회전 매핑에 바인드할 함수.
	void Turn(float Value);

};
