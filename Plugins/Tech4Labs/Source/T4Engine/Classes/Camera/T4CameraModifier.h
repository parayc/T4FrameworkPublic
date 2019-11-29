// Copyright 2019 SoonBo Noh. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraModifier.h"
#include "Engine/Scene.h" // #98
#include "T4CameraModifier.generated.h"

/**
  * #100
*/
UCLASS()
class T4ENGINE_API UT4CameraModifier : public UCameraModifier
{
	GENERATED_UCLASS_BODY()

public:
	//~ Begin UCameraModifer Interface
	virtual bool ModifyCamera(float DeltaTime, struct FMinimalViewInfo& InOutPOV) override;
	//~ End UCameraModifer Interface

public:
	void Reset();

public:
	TArray<float> PostProcessBlendWeights;
	TArray<FPostProcessSettings*> PostProcessSettings;

#if WITH_EDITOR
	float EditorPostProcessWeight;
	FPostProcessSettings EditorPostProcessSetting;
#endif
};
