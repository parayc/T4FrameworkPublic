// Copyright 2019-2020 SoonBo Noh. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "T4GameBuiltin_Types.generated.h"

/**
  * #40
 */
UENUM()
enum class ET4GameBuiltin_GameModeType : uint8
{
	TPS,
	ShoulderView, // #40

	None UMETA(Hidden),
};

enum ET4GameBuiltin_HotKeyType // #116
{
	HotKey1_Pressed,
	HotKey2_Pressed,
	HotKey3_Pressed,
	HotKey4_Pressed,
};

UENUM()
enum class ET4GameBuiltin_SkillSequence : uint8
{
	Ready, // #48
	Primary,
	Secondary,
	Tertiary,
	Finish, // #48

	Nums,
};

UENUM()
enum class ET4GameBuiltin_AIState : uint8 // #114
{
	Ready,
	Invisible,
	Active,
	Dead,
};

UENUM()
enum class ET4GameBuiltin_AttackTarget : uint8 // #112
{
	ObjectID,
	Location,
	Direction,

	None,
};
