// Fill out your copyright notice in the Description page of Project Settings.


#include "Test.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
ATest::ATest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	health = 100;
	damage = 10;
	maxBall = 4;

}

// Called when the game starts or when spawned
void ATest::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(timerStopHandle, this, &ATest::StopTimer, timerStopSpawner);

	GetWorldTimerManager().SetTimer(timerHandle, this, &ATest::Timer, timerSpawner, true);
}

// Called every frame
void ATest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(Speed);
	AddActorLocalRotation(rotationSpeed);

	health -= damage * DeltaTime;
	if (health <= 0) 
	{
		Destroy();
	}

}

void ATest::Timer() 
{

	FVector pos = GetActorLocation() + offsetPos;
	FRotator rot = GetActorRotation();

	currentBall++;
	// currentBall = currentBall + 1;
	// currentBall +=;
	if (currentBall < maxBall)
	{
		GetWorld()->SpawnActor<AActor>(blueprintObject, pos, rot);
	}
}

void ATest::StopTimer()
{
	GetWorldTimerManager().ClearTimer(timerStopHandle);
	Destroy();
}