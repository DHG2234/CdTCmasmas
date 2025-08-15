// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap.h"
#include "TimerManager.h"
#include "PlayerPawn.h"

// Sets default values
ATrap::ATrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATrap::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(timerHandle, this, &ATrap::ChangeDirection, changeTime, true);
	OnActorBeginOverlap.AddDynamic(this, &ATrap::OnOverlap);
}

// Called every frame
void ATrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector move(0, 0, 0);
	move.Z = speed * DeltaTime;
	AddActorLocalOffset(move, true);

}

void ATrap::ChangeDirection()
{
	speed *= -1;
}

void ATrap::OnOverlap(AActor* me, AActor* other)
{
	APlayerPawn* pP = Cast<APlayerPawn>(other);
	if (pP != nullptr)
	{
		pP->health -= damage;
	}
}

