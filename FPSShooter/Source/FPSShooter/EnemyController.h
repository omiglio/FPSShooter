// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyController.generated.h"

UCLASS()
class FPSSHOOTER_API AEnemyController : public AActor
{
	GENERATED_BODY()


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AEnemyController();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UShapeComponent* RootBox;

	UPROPERTY(EditAnywhere)
	float Speed = 200.0f;

	FVector Direction;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent*
	OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32
	OtherBodyIndex, bool bFromSweep, const
	FHitResult& SweepResult);
};
