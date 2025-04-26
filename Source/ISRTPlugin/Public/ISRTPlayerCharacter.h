// Made by Inexhaustible Snake

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ISRTPlayerCharacter.generated.h"

class UISRTRuntimeDecalComponent;

UCLASS()
class ISRTPLUGIN_API AISRTPlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AISRTPlayerCharacter();

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ISRT Player Character")
    TObjectPtr<UISRTRuntimeDecalComponent> ISRTRuntimeDecalComponent;
};
