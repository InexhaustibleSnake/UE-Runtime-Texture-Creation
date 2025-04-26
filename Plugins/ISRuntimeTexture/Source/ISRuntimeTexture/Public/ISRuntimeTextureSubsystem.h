// Made by Inexhaustible Snake

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "ISRuntimeTextureSubsystem.generated.h"

UENUM(BlueprintType)
enum EImagesTypes : uint8
{
    jpg,
    png
};

UCLASS()
class ISRUNTIMETEXTURE_API UISRuntimeTextureSubsystem : public UEngineSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection);

    UFUNCTION(BlueprintCallable, Category = "ISRuntimeTextureSubsystem")
    TArray<FString> GetImagesNamesFromRuntimeTexturesFolder() const;

    UFUNCTION(BlueprintCallable, Category = "ISRuntimeTextureSubsystem")
    UTexture2D* ConvertImageToTexture(const FString& ImageName) const;

private:
    void CreateRuntimeTexturesFolder();

    FString GetRuntimeTextureFolderPath() const;

    TArray<EImagesTypes> AvaibleImagesExtensions = {EImagesTypes::jpg, EImagesTypes::png};

    FString RuntimeTexturesFolderName = "RuntimeTextures";
};
