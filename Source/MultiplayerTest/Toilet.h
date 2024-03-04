// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PointLightComponent.h"
#include "Components/TimelineComponent.h"
#include "Toilet.generated.h"

UCLASS()
class MULTIPLAYERTEST_API AToilet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AToilet();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* doorMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPointLightComponent* toiletLight;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveFloat* toiletDoorCurve;

	bool bDoorOpened = false;

	UPROPERTY()
	UTimelineComponent* TimelineComponent;

	UFUNCTION()
	void DoorTimelineCallback(float val);

	FOnTimelineFloat DoorTimelineInterp{};

	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void DoorInteract();
};
