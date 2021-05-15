// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Paintball_LoGiudiceGameMode.h"
#include "Paintball_LoGiudiceHUD.h"
#include "Paintball_LoGiudiceCharacter.h"
#include "UObject/ConstructorHelpers.h"

APaintball_LoGiudiceGameMode::APaintball_LoGiudiceGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APaintball_LoGiudiceHUD::StaticClass();
}
