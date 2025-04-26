// Made by Inexhaustible Snake

#include "ISRuntimeTextureSubsystem.h"
#include "HAL/FileManagerGeneric.h"
#include "ImageUtils.h"
#include "Misc/Paths.h"

void UISRuntimeTextureSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    IFileManager& FileManager = FFileManagerGeneric::Get();

    bool DirectoryExist = FileManager.DirectoryExists(*GetRuntimeTextureFolderPath());

    if (!DirectoryExist)
    {
        CreateRuntimeTexturesFolder();
    }
}

TArray<FString> UISRuntimeTextureSubsystem::GetImagesNamesFromRuntimeTexturesFolder() const
{
    TArray<FString> Images;
    IFileManager& FileManager = FFileManagerGeneric::Get();

    const auto SearchDirectory = GetRuntimeTextureFolderPath();

    for (const auto OneImageExtension : AvaibleImagesExtensions)
    {
        TArray<FString> FoundImages;

        FileManager.FindFiles(FoundImages, *SearchDirectory, *UEnum::GetValueAsString(OneImageExtension));

        Images.Append(FoundImages);
    }

    return Images;
}

UTexture2D* UISRuntimeTextureSubsystem::ConvertImageToTexture(const FString& ImageName) const
{
    return FImageUtils::ImportFileAsTexture2D(GetRuntimeTextureFolderPath() + ImageName); //TO DO: User can create the same texture multiple times, which can cause a memory leak. Need to fix
}

void UISRuntimeTextureSubsystem::CreateRuntimeTexturesFolder()
{
    IFileManager& FileManager = FFileManagerGeneric::Get();

    const auto FolderPath = GetRuntimeTextureFolderPath();

    FileManager.MakeDirectory(*FolderPath);
}

FString UISRuntimeTextureSubsystem::GetRuntimeTextureFolderPath() const
{
    FString RealivePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());

    FString RuntimeTexturesPath = RealivePath + RuntimeTexturesFolderName + "/";

    return RuntimeTexturesPath;
}
