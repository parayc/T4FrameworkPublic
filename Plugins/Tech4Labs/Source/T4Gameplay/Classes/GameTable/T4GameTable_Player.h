// Copyright 2019 SoonBo Noh. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Classes/GameTable/T4GameTableDataTypes.h" // #48

#include "Classes/Engine/DataTable.h"

#include "T4GameTable_Player.generated.h"

/**
  * http://api.unrealengine.com/KOR/Gameplay/DataDriven/
 */
class UT4CharacterEntityAsset;

USTRUCT()
struct FT4GamePlayerTableRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, Category= Common)
	FName Name;

	UPROPERTY(EditAnywhere, Category= Common)
	FGuid Guid;

	UPROPERTY(EditAnywhere, Category = ClientOnly)
	TSoftObjectPtr<UT4CharacterEntityAsset> EntityAsset;

public:
	FT4GamePlayerTableRow()
	{
	}
};
