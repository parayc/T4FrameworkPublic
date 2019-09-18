// Copyright 2019 SoonBo Noh. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "T4ActionCodeBase.h"
#include "T4ActionCodeStatus.generated.h"

/**
  *
 */
 // #T4_ADD_ACTION_TAG_CODE

// ET4ActionType::LockOn
// ET4ActionType::ChangeStance // #73
// ET4ActionType::EquipWeapon
// ET4ActionType::UnEquipWeapon
// ET4ActionType::ExchangeCostume // #72
// ET4ActionType::Die // #76
// ET4ActionType::Resurrect // #76

USTRUCT()
struct T4ENGINE_API FT4LockOnAction : public FT4CodeActionBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere)
	bool bSetLocked;

	UPROPERTY(EditAnywhere)
	float HeadYawAngle; // #40

public:
	FT4LockOnAction()
		: FT4CodeActionBase(StaticActionType())
		, bSetLocked(false)
		, HeadYawAngle(TNumericLimits<float>::Max())
	{
	}

	static ET4ActionType StaticActionType() { return ET4ActionType::LockOn; }

	FString ToString() const override
	{
		return FString(TEXT("LockOnAction"));
	}
};

// #73
USTRUCT()
struct T4ENGINE_API FT4ChangeStanceAction : public FT4CodeActionBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere)
	FName StanceName;

public:
	FT4ChangeStanceAction()
		: FT4CodeActionBase(StaticActionType())
		, StanceName(NAME_None)
	{
	}

	static ET4ActionType StaticActionType() { return ET4ActionType::ChangeStance; }

	FString ToString() const override
	{
		return FString(TEXT("ChangeStanceAction"));
	}
};

USTRUCT()
struct T4ENGINE_API FT4EquipWeaponAction : public FT4CodeActionBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<class UT4WeaponEntityAsset> WeaponEntityAsset;

	UPROPERTY(EditAnywhere)
	FName EquipPoint; // #57 : BoneOrSocketName;

	UPROPERTY(EditAnywhere)
	ET4LoadingPolicy LoadingPolicy;

public:
	FT4EquipWeaponAction()
		: FT4CodeActionBase(StaticActionType())
		, EquipPoint(NAME_None)
		, LoadingPolicy(ET4LoadingPolicy::Default)
	{
	}

	static ET4ActionType StaticActionType() { return ET4ActionType::EquipWeapon; }

	bool Validate(FString& OutMsg) override
	{
		if (WeaponEntityAsset.IsNull())
		{
			OutMsg = TEXT("Invalid WeaponEntityAsset");
			return false;
		}
		if (EquipPoint == NAME_None)
		{
			OutMsg = TEXT("Not set ActionPoint");
			return false;
		}
		return true;
	}

	FString ToString() const override
	{
		return FString(TEXT("EquipWeaponAction"));
	}
};

// #48
USTRUCT()
struct T4ENGINE_API FT4UnEquipWeaponAction : public FT4CodeActionBase
{
	GENERATED_USTRUCT_BODY()

public:
	FT4UnEquipWeaponAction()
		: FT4CodeActionBase(StaticActionType())
	{
	}

	static ET4ActionType StaticActionType() { return ET4ActionType::UnEquipWeapon; }

	bool Validate(FString& OutMsg) override
	{
		return true;
	}

	FString ToString() const override
	{
		return FString(TEXT("UnEquipWeaponAction"));
	}
};

// #37
USTRUCT()
struct T4ENGINE_API FT4ExchangeCostumeAction : public FT4CodeActionBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<class UT4CostumeEntityAsset> CostumeEntityAsset;

	UPROPERTY(EditAnywhere)
	FName TargetPartsName;
	
	UPROPERTY(EditAnywhere)
	bool bClearDefault; // #72 : Character Entity 에 지정된 기본값으로 변경

public:
	FT4ExchangeCostumeAction()
		: FT4CodeActionBase(StaticActionType())
		, TargetPartsName(NAME_None)
		, bClearDefault(false)
	{
	}

	static ET4ActionType StaticActionType() { return ET4ActionType::ExchangeCostume; }

	bool Validate(FString& OutMsg) override
	{
		if (!bClearDefault && CostumeEntityAsset.IsNull())
		{
			OutMsg = TEXT("Invalid CostumeEntityAsset");
			return false;
		}
		if (TargetPartsName == NAME_None)
		{
			OutMsg = TEXT("Not set TargetParts");
			return false;
		}
		return true;
	}

	FString ToString() const override
	{
		return FString(TEXT("ExchangeCostumeAction"));
	}
};

// #76
USTRUCT()
struct T4ENGINE_API FT4DieAction : public FT4CodeActionBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere)
	FName ReactionName;

	UPROPERTY(EditAnywhere)
	FVector ShotDirection;

	UPROPERTY(Transient)
	bool bTransientPlay;

public:
	FT4DieAction()
		: FT4CodeActionBase(StaticActionType())
		, ReactionName(NAME_None)
		, ShotDirection(FVector::ZeroVector)
		, bTransientPlay(false)
	{
	}

	static ET4ActionType StaticActionType() { return ET4ActionType::Die; }

	bool Validate(FString& OutMsg) override
	{
		return true;
	}

	FString ToString() const override
	{
		return FString(TEXT("DieAction"));
	}
};

// #76
USTRUCT()
struct T4ENGINE_API FT4ResurrectAction : public FT4CodeActionBase
{
	GENERATED_USTRUCT_BODY()

public:

public:
	FT4ResurrectAction()
		: FT4CodeActionBase(StaticActionType())
	{
	}

	static ET4ActionType StaticActionType() { return ET4ActionType::Resurrect; }

	bool Validate(FString& OutMsg) override
	{
		return true;
	}

	FString ToString() const override
	{
		return FString(TEXT("ResurrectAction"));
	}
};
