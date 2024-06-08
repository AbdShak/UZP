// Copyright Epic Games, Inc. All Rights Reserved.

#include "UZPGameMode.h"
#include "UZPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUZPGameMode::AUZPGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
