// Copyright Epic Games, Inc. All Rights Reserved.

#include "UMG_Slate_TemplateGameMode.h"
#include "UMG_Slate_TemplateCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUMG_Slate_TemplateGameMode::AUMG_Slate_TemplateGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
