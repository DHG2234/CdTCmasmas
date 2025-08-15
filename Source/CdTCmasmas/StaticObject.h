// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StaticObject.generated.h"

UCLASS()
class CDTCMASMAS_API AStaticObject : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere)
	int damage;

	// Sets default values for this actor's properties
	AStaticObject();

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
