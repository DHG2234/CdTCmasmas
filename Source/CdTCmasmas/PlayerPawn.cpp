// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	health = 100;
	respawn = 5;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	initialPosition = GetActorLocation();
	initialRotation = GetActorRotation();
	initialHealth = health;
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (health <= 0) 
	{
		if (respawn > 0)
		{
			SetActorLocation(initialPosition);
			SetActorRotation(initialRotation);
			health = initialHealth;
			respawn--;
		}
		else 
		{
			Destroy();
		}
	}
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &APlayerPawn::ForwardAxis);
	PlayerInputComponent->BindAxis("Side", this, &APlayerPawn::SideAxis);

}

void APlayerPawn::ForwardAxis(float axis)
{
	FVector move(0, 0, 0);
	move.X = axis * speed * GetWorld()->GetDeltaSeconds();
	AddActorLocalOffset(move, true);
}

void APlayerPawn::SideAxis(float axis)
{
	FRotator rotator(0, 0, 0);
	rotator.Yaw = axis * rotationSpeed * GetWorld()->GetDeltaSeconds();
	AddActorLocalRotation(rotator, true);
}

