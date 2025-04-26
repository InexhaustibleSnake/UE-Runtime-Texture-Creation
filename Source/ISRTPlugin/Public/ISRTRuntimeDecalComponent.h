// Made by Inexhaustible Snake

#pragma once

#include "CoreMinimal.h"
#include "Components/DecalComponent.h"
#include "ISRTRuntimeDecalComponent.generated.h"

UCLASS(BlueprintType)
class ISRTPLUGIN_API UISRTRuntimeDecalComponent : public UDecalComponent
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "ISRT Runtime Decal Component")
    void SetDecalSize(const FVector NewSize) { DecalSize = NewSize; }
};
