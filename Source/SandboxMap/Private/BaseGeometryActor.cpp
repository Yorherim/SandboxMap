// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All);

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();
	UE_LOG(LogBaseGeometry, Warning, TEXT("InitialLocation is: %s"), *InitialLocation.ToString());

	printTransform();
	printStrings();
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// движение по синусу
	// amplitude - насколько актор будет отклонятся от первоначальной точки
	// Frequency - частота колебания
	// формула: z = z0 + amplitude * sin(freq * t);

	FVector CurrentLocation = GetActorLocation();
	// получаем время в секундах с начала игры
	float time = GetWorld()->GetTimeSeconds();
	CurrentLocation.Z = InitialLocation.Z + Amplitude * FMath::Sin(Frequency * time);
	SetActorLocation(CurrentLocation);
}

void ABaseGeometryActor::printStrings()
{
	FString Name = "Jonh Connor";
	UE_LOG(LogBaseGeometry, Display, TEXT("My name is: %s"), *Name);

	FString WeaponsCountStr = "Weapons count: " + FString::FromInt(WeaponsCount);
	FString IsDeadStr = "Is dead: " + FString(IsDead ? "true" : "false");
	FString HealthStr = "Health: " + FString::SanitizeFloat(Health, 2);

	FString Stats = FString::Printf(
		TEXT(" \n== All stats == \n%s \n%s \n%s"), *WeaponsCountStr, *IsDeadStr, *HealthStr
	);
	UE_LOG(LogBaseGeometry, Warning, TEXT("%s"), *Stats);

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, Name);
	GEngine->AddOnScreenDebugMessage(
	-1, 3.0f, FColor::Green, Stats, true, FVector2D(1.5f, 1.5f)
	);
	
}

// получаем информацию о нахождение в пространстве actor в логи
void ABaseGeometryActor::printTransform()
{
	FTransform Transform = GetActorTransform();
	FVector3d Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	FVector Scale = Transform.GetScale3D();

	UE_LOG(LogBaseGeometry, Warning, TEXT("Transform is: %s"), *Transform.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Location is: %s"), *Location.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Rotator is: %s"), *Rotation.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Scale is: %s"), *Scale.ToString());

	UE_LOG(LogBaseGeometry, Error, TEXT("Human Transform is: %s"), *Transform.ToHumanReadableString());
}



