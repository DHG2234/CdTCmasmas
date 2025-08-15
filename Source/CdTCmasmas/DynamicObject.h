// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DynamicObject.generated.h"

UCLASS()
class CDTCMASMAS_API ADynamicObject : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere)
	FVector speed;

	UPROPERTY(EditAnywhere)
	float health;

	// Sets default values for this actor's properties
	ADynamicObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
