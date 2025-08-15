// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorC.h"
#include "Components/BoxComponent.h"
#include "PlayerPawn.h"

// Sets default values
ADoorC::ADoorC()
{
	PrimaryActorTick.bCanEverTick = true;

	//Create our Default Components
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrameMesh"));
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorTimelineComp = CreateDefaultSubobject<UTimelineComponent>(TEXT("DoorTimelineComp"));
	DoorProxVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("DoorProximityVolume"));

	//Setup our Attachments
	DoorFrame->SetupAttachment(RootComponent);
	Door->AttachToComponent(DoorFrame, FAttachmentTransformRules::KeepRelativeTransform);
	DoorProxVolume->AttachToComponent(DoorFrame, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ADoorC::BeginPlay()
{
	Super::BeginPlay();

	//Binding our float track to our UpdateTimelineComp Function's output
	UpdateFunctionFloat.BindDynamic(this, &ADoorC::UpdateTimelineComp);

	//If we have a float curve, bind it's graph to our update function
	if (DoorTimelineFloatCurve)
	{
		DoorTimelineComp->AddInterpFloat(DoorTimelineFloatCurve, UpdateFunctionFloat);
	}
	//Binding our Proximity Box Component to our Overlap Functions
	DoorProxVolume->OnComponentBeginOverlap.AddDynamic(this, &ADoorC::OnOverlapBegin);
	DoorProxVolume->OnComponentEndOverlap.AddDynamic(this, &ADoorC::OnOverlapEnd);
}

// Called every frame
void ADoorC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorC::UpdateTimelineComp(float Output)
{
	// Create and set our Door's new relative location based on the output from our Timeline Curve
	FRotator DoorNewRotation = FRotator(0.0f, Output, 0.f);
	Door->SetRelativeRotation(DoorNewRotation);
}

void ADoorC::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayerPawn* pP = Cast<APlayerPawn>(OtherActor);
	if (pP != nullptr && pP->keys > 0)
	{
		pP->keys--;
		DoorTimelineComp->Play();
	}
}

void ADoorC::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	DoorTimelineComp->Reverse();
}