// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// PROPERTY()의 메크로 종류
	// VisibleAnywhere : 읽기만 가능. 편집x 
	// EditAnywhere : 읽기, 쓰기 모두 가능. 편집o
	// VisibleInstanceOnly : 읽기 가능. 디폴트 블루프린트에서는 확인할 수 없고 레벨에 인스턴스로 존재하는 디테일패널에서 읽기 가능.
	// VisibleDefaultsOnly : 디폴트 블루프린트에서만 읽기 가능.
	// EditDefaultsOnly : 디폴트 블루프린트에서만 읽기, 쓰기 가능.
	// EditInstanceOnly : 인스턴스에서만 읽기, 쓰기 가능.
	// BlueprintReadWrite : 이벤트 그래프에서 호출 및 편집 가능.
	// BlueprintReadOnly : 이벤트 그래프에서 호출 가능, 편집x.

	// PROPERTY()의 메크로 특징
	// 읽기 및 쓰기 액세스가 있고, private 섹션에서는 사용할 수 없다.
	// private 지정자에서 데이터를 읽거나 쓰고 싶은경우 인자로 meta = (AllowPrivateAccess = "true")를 넣으면 사용가능하다.
	// Category를 넣을 수 있는데 [Category = "Category Name"] 이런식으로 인자값을 넣어주면 블루프린트 에디터에서 해당 카테고리 이름으로 구분이 생긴다.


};
