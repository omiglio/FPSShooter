// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSShooterGameMode.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyController.h"

void AFPSShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AFPSShooterGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GameTimer += DeltaTime;
	EnemyTimer -= DeltaTime;

	if (EnemyTimer <= 0.0f)
	{
		float difficultyPercentage = FMath::Min(GameTimer / TIME_TO_MINIMUM_INTERVAL
			, 1.0f);
		EnemyTimer = MAXIUM_INTERVAL - (MAXIUM_INTERVAL - MINIMUM_INTEVAL) *
			difficultyPercentage;

		UWorld* World = GetWorld();

		if (World)
		{
			float distance = 800.0f;
			float randomAngle = FMath::RandRange(0.0f
				, 360.0f);

			FVector playerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
			FVector enemyLocation = playerLocation;

			enemyLocation.X += FMath::Cos(randomAngle * 3.14f / 180.0f) * distance;
			enemyLocation.Y += FMath::Sin(randomAngle * 3.14 / 180.0f) * distance;
			enemyLocation.Z = 202.231216;

			AEnemyController* enemy = World->SpawnActor<AEnemyController>
				(EnemyBlueprint, enemyLocation, FRotator::ZeroRotator);
			enemy->Direction = (playerLocation - enemyLocation).
				GetSafeNormal();
		}
	}
}

void AFPSShooterGameMode::IncrementScore()
{

}

void AFPSShooterGameMode::OnGameOver()
{

}

void AFPSShooterGameMode::OnRestart()
{

}


