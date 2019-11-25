// Copyright 2019 SoonBo Noh. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "T4EngineTypes.h"
#include "T4Asset/Public/Entity/T4EntityTypes.h" // #94
#include "T4Asset/Classes/World/T4EnvironmentAsset.h"

/**
  * #92
 */
class UWorld;
class ADirectionalLight;
class ASkyLight;
class AAtmosphericFog;
class AExponentialHeightFog;
class UT4EnvironmentAsset; // #94
class AT4MapZoneVolume;
namespace T4EngineUtility
{
	// #90, #92 : World Editor 등의 툴에서의 호출을 위해 Utility 로 노출함!
	T4ENGINE_API AT4MapZoneVolume* FindMapZomeVolumeOnWorld(
		UWorld* InWorld,
		FName InMapZoneName
	);

	T4ENGINE_API bool GetMapZomeVolumesOnWorld(
		UWorld* InWorld,
		TArray<AT4MapZoneVolume*>& OutMapZoneVolumes
	);

#if WITH_EDITOR
	T4ENGINE_API AT4MapZoneVolume* SpawnMapZomeVolumeOnWorld(
		UWorld* InWorld,
		const FVector& InLocation,
		const FRotator& InRotation,
		const FVector& InScale,
		ET4EntityZoneBrushType InBrushType,
		bool bTransient
	); // #94
#endif

	T4ENGINE_API FName GetNextTimeTagName(FName InTimeName); // #93
	T4ENGINE_API FName GetPrevTimeTagName(FName InTimeName); // #93

	// #T4_ADD_TOD_TAG
	T4ENGINE_API bool ApplyDirectional(
		UWorld* InWorld,
		const FT4EnvDirectionalData* InData,
		ADirectionalLight* InCachedActor = nullptr // #92
	); // #93
	T4ENGINE_API bool ApplyDirectionalLight(
		UWorld* InWorld, 
		const FT4EnvDirectionalLightData* InData,
		ADirectionalLight* InCachedActor = nullptr // #92
	);
	T4ENGINE_API bool ApplyBPSkySphere(
		UWorld* InWorld,
		const FT4EnvBPSkySphereData* InData,
		AActor* InCachedActor = nullptr,
		ADirectionalLight* InCachedDirectionalLightActor = nullptr
	);// #97
	T4ENGINE_API bool ApplySkyLight(
		UWorld* InWorld, 
		const FT4EnvSkyLightData* InData,
		ASkyLight* InCachedActor = nullptr // #92
	);
	T4ENGINE_API bool ApplyAtmosphericFog(
		UWorld* InWorld, 
		const FT4EnvAtmosphericFogData* InData,
		AAtmosphericFog* InCachedActor = nullptr // #92
	);
	T4ENGINE_API bool ApplyExponentialHeightFog(
		UWorld* InWorld, 
		const FT4EnvExponentialHeightFogData* InData,
		AExponentialHeightFog* InCachedActor = nullptr // #92
	);


	T4ENGINE_API void BlendTimeTagData(
		const FT4EnvTimeTagData& InTimeTagData,
		float InWeight,
		FT4EnvTimeTagData& OutTimeTagData
	); // #93

	// #T4_ADD_TOD_TAG
	T4ENGINE_API void BlendDirectional(
		const FT4EnvDirectionalData* InData,
		float InWeight,
		FT4EnvDirectionalData& OutData // #93
	); // #93
	T4ENGINE_API void BlendDirectionalLight(
		const FT4EnvDirectionalLightData* InData,
		float InWeight,
		FT4EnvDirectionalLightData& OutData // #93
	);
	T4ENGINE_API void BlendBPSkySphere(
		const FT4EnvBPSkySphereData* InData,
		float InWeight,
		FT4EnvBPSkySphereData& OutData
	); // #97
	T4ENGINE_API void BlendSkyLight(
		const FT4EnvSkyLightData* InData,
		float InWeight,
		FT4EnvSkyLightData& OutData // #93
	);
	T4ENGINE_API void BlendAtmosphericFog(
		const FT4EnvAtmosphericFogData* InData,
		float InWeight,
		FT4EnvAtmosphericFogData& OutData // #93
	);
	T4ENGINE_API void BlendExponentialHeightFog(
		const FT4EnvExponentialHeightFogData* InData,
		float InWeight,
		FT4EnvExponentialHeightFogData& OutData // #93
	);

	// #T4_ADD_TOD_TAG
	// #97
	T4ENGINE_API ADirectionalLight* SpawnDirectionalLightActor(
		UWorld* InWorld, 
		EObjectFlags InObjectFlags,
		const FT4EnvDirectionalLightData* InData = nullptr
	);
	T4ENGINE_API AActor* SpawnBPSkySphereActor(
		UWorld* InWorld,
		EObjectFlags InObjectFlags,
		const FT4EnvBPSkySphereData* InData = nullptr
	);
	T4ENGINE_API ASkyLight* SpawnSkyLightActor(
		UWorld* InWorld, 
		EObjectFlags InObjectFlags,
		const FT4EnvSkyLightData* InData = nullptr
	);
	T4ENGINE_API AAtmosphericFog* SpawnAtmosphericFogActor(
		UWorld* InWorld, 
		EObjectFlags InObjectFlags,
		const FT4EnvAtmosphericFogData* InData = nullptr
	);
	T4ENGINE_API AExponentialHeightFog* SpawnExponentialHeightFogActor(
		UWorld* InWorld, 
		EObjectFlags InObjectFlags,
		const FT4EnvExponentialHeightFogData* InData = nullptr
	);
	// ~#97

	// #97
	T4ENGINE_API ADirectionalLight* FindDirectionalLightActor(UWorld* InWorld);
	T4ENGINE_API AActor* FindBPSkySphereActor(UWorld* InWorld); // #97
	T4ENGINE_API ASkyLight* FindSkyLightActor(UWorld* InWorld);
	T4ENGINE_API AAtmosphericFog* FindAtmosphericFogActor(UWorld* InWorld);
	T4ENGINE_API AExponentialHeightFog* FindExponentialHeightFogActor(UWorld* InWorld);
	// #97

#if WITH_EDITOR
	// #T4_ADD_TOD_TAG
	T4ENGINE_API bool GetDirectionalData(UWorld* InWorld, FT4EnvDirectionalData* OutData); // #93
	T4ENGINE_API bool GetDirectionalLightData(UWorld* InWorld, FT4EnvDirectionalLightData* OutData);
	T4ENGINE_API bool GetBPSkySphereData(UWorld* InWorld, FT4EnvBPSkySphereData* OutData); // #97
	T4ENGINE_API bool GetSkyLightData(UWorld* InWorld, FT4EnvSkyLightData* OutData);
	T4ENGINE_API bool GetAtmosphericFogData(UWorld* InWorld, FT4EnvAtmosphericFogData* OutData);
	T4ENGINE_API bool GetExponentialHeightFogData(UWorld* InWorld, FT4EnvExponentialHeightFogData* OutData);
#endif
}