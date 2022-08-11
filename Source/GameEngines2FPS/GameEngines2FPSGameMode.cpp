// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameEngines2FPSGameMode.h"
#include "GameEngines2FPSHUD.h"
#include "GameEngines2FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameEngines2FPSGameMode::AGameEngines2FPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGameEngines2FPSHUD::StaticClass();
}
