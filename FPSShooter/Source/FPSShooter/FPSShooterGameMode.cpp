// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSShooterGameMode.h"
#include "FPSShooterHUD.h"
#include "FPSShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPSShooterGameMode::AFPSShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSShooterHUD::StaticClass();
}
