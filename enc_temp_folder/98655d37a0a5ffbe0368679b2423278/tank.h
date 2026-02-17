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
private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;


};
