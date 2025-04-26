// Made by Inexhaustible Snake

#include "ISRTPlayerCharacter.h"
#include "ISRTRuntimeDecalComponent.h"

AISRTPlayerCharacter::AISRTPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	ISRTRuntimeDecalComponent = CreateDefaultSubobject<UISRTRuntimeDecalComponent>("ISRTRuntimeDecalComponent");
    ISRTRuntimeDecalComponent->SetupAttachment(GetRootComponent());
}


