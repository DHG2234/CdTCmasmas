// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticObject.h"
#include "DynamicObject.h"


// Sets default values
AStaticObject::AStaticObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStaticObject::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AStaticObject::OnOverlap);
	
}

// Called every frame
void AStaticObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStaticObject::OnOverlap(AActor* me, AActor* other)
{
	ADynamicObject* dynamicObj = Cast<ADynamicObject>(other);
	dynamicObj->health -= damage;
}

