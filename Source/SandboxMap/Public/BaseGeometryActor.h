// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseGeometryActor.generated.h"

UCLASS()
class SANDBOXMAP_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGeometryActor();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BaseMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ��������� ����� ����� ���������� �� �������������� ����� ��� ��������
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Amplitude = 50.0f;

	// ������� ���������
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Frequency = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	int32 WeaponsCount = 4;

	UPROPERTY(EditDefaultsOnly, Category = "Stat")
	int32 KillsNum = 7;

	UPROPERTY(EditInstanceOnly, Category = "Health")
	float Health = 34.45f;

	UPROPERTY(EditAnywhere, Category = "Health")
	bool IsDead = false;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	bool HasWeapon = true;

	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	bool HasWeapon1 = true;

	UPROPERTY(VisibleInstanceOnly, Category = "Weapon")
	bool HasWeapon2 = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector InitialLocation;

	void printStrings();
	void printTransform();
};
