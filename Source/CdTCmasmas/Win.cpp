// Fill out your copyright notice in the Description page of Project Settings.


#include "Win.h"
#include "Engine/World.h"
#include "PlayerPawn.h"
// Sets default values
AWin::AWin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWin::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AWin::OnOverlap);
	
}

// Called every frame
void AWin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWin::OnOverlap(AActor* me, AActor* other)
{
	APlayerPawn* pP = Cast<APlayerPawn>(other);
	if (pP != nullptr)
	{
		GetWorld()->ServerTravel("L_Test");
	}
}

