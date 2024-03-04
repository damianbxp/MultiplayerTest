// Fill out your copyright notice in the Description page of Project Settings.


#include "Toilet.h"

// Sets default values
AToilet::AToilet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	RootComponent = mesh;

	doorMesh = CreateDefaultSubobject<UStaticMeshComponent>("Door Mesh");
	doorMesh->SetupAttachment(RootComponent);

	toiletLight = CreateDefaultSubobject<UPointLightComponent>("Toilet Light");
	toiletLight->SetupAttachment(RootComponent);

	TimelineComponent = CreateDefaultSubobject<UTimelineComponent>("Toilet Door Timeline");
	DoorTimelineInterp.BindUFunction(this, "DoorTimelineCallback");

}

void AToilet::DoorTimelineCallback(float val)
{
	doorMesh->SetRelativeRotation(FRotator(0, 0, val));
}

// Called when the game starts or when spawned
void AToilet::BeginPlay()
{
	Super::BeginPlay();
	TimelineComponent->AddInterpFloat(toiletDoorCurve, DoorTimelineInterp, "Floaty");

}


// Called every frame
void AToilet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AToilet::DoorInteract()
{
	if (bDoorOpened) {
		UE_LOG(LogTemp, Display, TEXT("Door Closing"));
		TimelineComponent->Reverse();
		bDoorOpened = false;
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Door Opening"));
		TimelineComponent->Play();
		bDoorOpened = true;
	}
}