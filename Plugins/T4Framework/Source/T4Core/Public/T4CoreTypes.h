// Copyright 2019 Tech4 Labs. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "T4CoreTypes.generated.h"

/**
  * http://api.unrealengine.com/KOR/Programming/UnrealArchitecture/Reference/Properties/
 */
UENUM()
enum class ET4SceneLayer : uint8
{
	Server, // #15
	ServerMax,

	Client,
	ClientMax = Client + 10,

	Preview, // #30
	PreviewMax = Preview + 50,

	LevelEditor, // #17
	   
	Max,
};
