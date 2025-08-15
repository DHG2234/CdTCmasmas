// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Win.generated.h"

UCLASS()
class CDTCMASMAS_API AWin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnOverlap(AActor* me, AActor* other);
};
