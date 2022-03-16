// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyController::AEnemyController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootBox->SetGenerateOverlapEvents(true); // Changed from bGenerateoverlappEvents to SetGenerateOverlapEvents.
	RootBox->OnComponentBeginOverlap.AddDynamic(this, &AEnemyController::OnOverlap);

}

// Called when the game starts or when spawned
void AEnemyController::BeginPlay()
{
	Super::BeginPlay();

	this->SetLifeSpan(10);
}

// Called every frame
void AEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	NewLocation.X += Direction.X * Speed * DeltaTime;
	SetActorLocation(NewLocation);

}

void AEnemyController::OnOverlap (UPrimitiveComponent*
	OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32
	OtherBodyIndex, bool bFromSweep, const
	FHitResult& SweepResult)
{
	if (OtherActor == GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
	else if(OtherActor->GetName().Contains("Projectile"))
	{
		OtherActor->Destroy();
		this-> Destroy();
	}
}
