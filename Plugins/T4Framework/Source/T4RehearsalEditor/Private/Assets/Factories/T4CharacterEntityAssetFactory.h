// Copyright 2019 SoonBo Noh. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "T4CharacterEntityAssetFactory.generated.h"

/**
  * #39
 */
UCLASS()
class UT4CharacterEntityAssetFactory : public UFactory 
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