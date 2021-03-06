// Copyright 2019-2020 SoonBo Noh. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "T4ItemEntityAsset.h"
#include "T4WeaponEntityAsset.generated.h"

/**
  * #35
 */
struct FT4WeaponEntityCustomVersion
{
	enum Type
	{
		InitializeVer = 0,

		// -----<new versions can be added above this line>-------------------------------------------------
		VersionPlusOne,
		LatestVersion = VersionPlusOne - 1,
	};

	T4ASSET_API const static FGuid GUID;

private:
	FT4WeaponEntityCustomVersion() {}
};

class UStaticMesh;
class USkeletalMesh;
class UPhysicsAsset; // #76
class UMaterialInterface;
USTRUCT()
struct T4ASSET_API FT4EntityItemWeaponMeshData
{
	GENERATED_USTRUCT_BODY()

public:
	FT4EntityItemWeaponMeshData()
		: MeshType(ET4EntityMeshType::StaticMesh)
		, EquipPointName(NAME_None) // #106
		, RelativeRotation(FRotator::ZeroRotator) // #108
		, RelativeScale(1.0f)
		, StanceName(NAME_None) // #106
		, bOverlapEvent(false) // #106
	{
	}

	UPROPERTY(EditAnywhere)
	ET4EntityMeshType MeshType;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UStaticMesh> StaticMeshAsset;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Override Material Data"))
	FT4EntityOverrideMaterialData StaticMeshOverrideMaterialData; // #80

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<USkeletalMesh> SkeletalMeshAsset;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Override Material Data"))
	FT4EntityOverrideMaterialData SkeletalMeshOverrideMaterialData; // #80

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UParticleSystem> ParticleSystemAsset;

	UPROPERTY(EditAnywhere)
	FName EquipPointName; // #106

	UPROPERTY(EditAnywhere)
	FRotator RelativeRotation; // #108

	UPROPERTY(EditAnywhere)
	float RelativeScale; // #108

	UPROPERTY(EditAnywhere)
	FName StanceName; // #106

	UPROPERTY(EditAnywhere)
	bool bOverlapEvent; // #106
};

// #111
USTRUCT()
struct T4ASSET_API FT4EntityWeaponEditorSettings
{
	GENERATED_USTRUCT_BODY()

public:
	FT4EntityWeaponEditorSettings()
	{
		Reset();
	}

	void Reset()
	{
#if WITH_EDITOR
		WeaponAnimationLayerListLineCount = 77;
#endif
	}

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category = Editor, meta = (DisplayName = "ListLineCount (Editor)"))
	int32 WeaponAnimationLayerListLineCount;
#endif
};

// #80
class UAnimSequence;
USTRUCT()
struct T4ASSET_API FT4EntityWeaponEditorTransientData
{
	GENERATED_USTRUCT_BODY()

public:
	FT4EntityWeaponEditorTransientData()
	{
		Reset();
	}

	void Reset()
	{
#if WITH_EDITOR
		TransientItemOverrideMaterialSlotName = NAME_None; // #80
		TransientSelectWeaponAnimSectionName = NAME_None; // #107
#endif
	}

	UPROPERTY(VisibleAnywhere, Transient, meta = (DisplayName = "Slot Name"))
	FName TransientItemOverrideMaterialSlotName;

	UPROPERTY(EditAnywhere, Transient, meta = (DisplayName = "Material Asset"))
	TSoftObjectPtr<UMaterialInterface> TransientItemOverrideMaterialAsset;

	UPROPERTY(EditAnywhere, Transient)
	FName TransientSelectWeaponAnimSectionName; // #107

	UPROPERTY(EditAnywhere, Transient)
	TSoftObjectPtr<UAnimSequence> TransientWeaponAnimSequenceAsset; // #107
};

UCLASS(ClassGroup = T4Framework, Category = "T4Framework")
class T4ASSET_API UT4WeaponEntityAsset : public UT4ItemEntityAsset
{
	GENERATED_UCLASS_BODY()

public:
	//~ Begin UObject interface
	virtual void Serialize(FArchive& Ar) override;
	virtual void PostLoad() override;

	virtual void GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const override;
	//~ End UObject interface

public:
	ET4EntityType GetEntityType() const override { return ET4EntityType::Weapon; }

#if WITH_EDITOR
	virtual UStaticMesh* GetPrimaryStaticMeshAsset() const override // #81
	{
		if (ET4EntityMeshType::StaticMesh != MeshData.MeshType)
		{
			return nullptr;
		}
		if (MeshData.StaticMeshAsset.IsNull())
		{
			return nullptr;
		}
		return MeshData.StaticMeshAsset.LoadSynchronous();
	}

	virtual USkeletalMesh* GetPrimarySkeletalMeshAsset() const override // #81
	{
		if (ET4EntityMeshType::SkeletalMesh != MeshData.MeshType)
		{
			return nullptr;
		}
		if (MeshData.SkeletalMeshAsset.IsNull())
		{
			return nullptr;
		}
		return MeshData.SkeletalMeshAsset.LoadSynchronous();
	}

	virtual void ResetEditorTransientData() override
	{
		UT4ItemEntityAsset::ResetEditorTransientData();
		EditorTransientWeaponData.Reset();
	} // #73
#endif

public:
	UPROPERTY(EditAnywhere)
	FT4EntityItemWeaponMeshData MeshData;

	UPROPERTY(EditAnywhere)
	FT4EntityItemAnimationData AnimationData; // #107

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category = Editor)
	FT4EntityWeaponEditorSettings EditorSettings; // #111 : 에디터 세팅 옵션

	// #80 : OverrideMaterial Data/ Physics Asset
	// TODO : Transient 설정으로 Editor Dirty 가 발생함으로 다른 방법 고려 필요
	UPROPERTY(EditAnywhere, Transient)
	FT4EntityWeaponEditorTransientData EditorTransientWeaponData;
#endif
};
