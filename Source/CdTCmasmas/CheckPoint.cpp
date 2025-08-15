// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckPoint.h"
#include "PlayerPawn.h"

// Sets default values
ACheckPoint::ACheckPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACheckPoint::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &ACheckPoint::OnOverlap);
}

// Called every frame
void ACheckPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACheckPoint::OnOverlap(AActor* me, AActor* other)
{
	APlayerPawn* pP = Cast<APlayerPawn>(other);
	if (pP != nullptr)
	{
		pP->initialPosition = GetActorLocation();
		pP->initialRotation = GetActorRotation();
	}
}

