// Copyright 2019 SoonBo Noh. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "T4EnvironmentAssetFactory.generated.h"

/**
  * #90
 */
UCLASS()
class UT4EnvironmentAssetFactory : public UFactory 
{
	GENERATED_UCLASS_BODY()

protected:
	bool IsMacroFactory() const { return false; }

public:
	UObject* FactoryCreateNew(
		UClass* Class,
		UObject* InParent,
		FName Name,
		EObjectFlags Flags,
		UObject* Context,
		FFeedbackContext* Warn
	) override;
};