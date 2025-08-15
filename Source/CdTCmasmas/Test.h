// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test.generated.h"

UCLASS()
class CDTCMASMAS_API ATest : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(VisibleAnywhere)
	int currentHealth;

	UPROPERTY(EditAnywhere)
	FVector Speed;

	UPROPERTY(EditAnywhere)
	FRotator rotationSpeed;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> blueprintObject;

	UPROPERTY(EditAnywhere)
	FVector offsetPos;

	FTimerHandle timerHandle;

	UPROPERTY(EditAnywhere)
	float timerSpawner;

	FTimerHandle timerStopHandle;

	UPROPERTY(EditAnywhere)
	float timerStopSpawner;

	UPROPERTY(EditAnywhere)
	float health;

	UPROPERTY(EditAnywhere)
	float damage;

	UPROPERTY(EditAnywhere)
	int maxBall;

	UPROPERTY(EditAnywhere)
	int currentBall;

	// Sets default values for this actor's properties
	ATest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Timer();
	void StopTimer();
};