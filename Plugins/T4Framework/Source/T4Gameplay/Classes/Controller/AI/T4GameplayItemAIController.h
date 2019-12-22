// Copyright 2019 SoonBo Noh. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Public/T4GameplayTypes.h"
#include "Classes/GameTable/T4GameTableDataTypes.h" // #48

#include "T4Frame/Classes/Controller/AI/T4GameAIController.h"
#include "T4GameplayItemAIController.generated.h"

/**
  * WARN : AI Controller 는 서버에서만 사용하고, 클라리언트에서는 사용하지 않음에 유의할 것!
  * http://api.unrealengine.com/KOR/Gameplay/Framework/Controller/AIController/
 */
UCLASS()
class T4GAMEPLAY_API AT4GameplayItemAIController : public AT4GameAIController
{
	GENERATED_UCLASS_BODY()

public:
	void TickActor(
		float InDeltaTime,
		enum ELevelTick InTickType,
		FActorTickFunction& InThisTickFunction
	) override;

public:
	bool Bind(const FT4GameDataID& InItemGameDataID); // #31, #50

public:
	// class IT4ObjectController
	FName GetClassTypeName() const override { return DefaultItemClassName; } // #104 : Object type 을 Enum 이 아니라 FName 으로 처리. N개가 될 수 있음을 가정하겠음

protected:
	void NotifyAIStart() override; // #50
	void NotifyAIEnd() override; // #50

private:
	FT4GameDataID ItemGameDataID;

	ET4AIDataLoadState AIDataLoadState; // #50
};