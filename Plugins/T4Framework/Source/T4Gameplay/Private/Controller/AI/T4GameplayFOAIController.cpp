// Copyright 2019 SoonBo Noh. All Rights Reserved.

#include "Classes/Controller/AI/T4GameplayFOAIController.h"

#include "GameDB/T4GameDB.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"

#include "T4GameplayInternal.h"

/**
  * WARN : AI Controller 는 서버에서만 사용하고, 클라리언트에서는 사용하지 않음에 유의할 것!
  * http://api.unrealengine.com/KOR/Gameplay/Framework/Controller/AIController/
 */
AT4GameplayFOAIController::AT4GameplayFOAIController(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
	, AIDataLoadState(ET4AIDataLoadState::AIDataLoad_Ready) // #50
{
}

void AT4GameplayFOAIController::TickActor(
	float InDeltaTime,
	enum ELevelTick InTickType,
	FActorTickFunction& InThisTickFunction
)
{
	Super::TickActor(InDeltaTime, InTickType, InThisTickFunction);
}

void AT4GameplayFOAIController::NotifyAIEnd() // #50
{
	// WARN : AsyncLoad 가 걸렸을 수 있음으로 종료 시 명시적으로 Reset 을 호출해야 한다.
	//BlackboardAssetLoader.Reset();
	//BehaviorTreeAssetLoader.Reset();
}

void AT4GameplayFOAIController::NotifyAIStart() // #50
{

}

bool AT4GameplayFOAIController::Bind(
	const FT4GameDataID& InFOGameDataID
)
{
	FT4GameDB& GameDB = GetGameDB();
	const FT4GameNPCData* NPCData = GameDB.GetGameData<FT4GameNPCData>(InFOGameDataID);
	if (nullptr == NPCData)
	{
		UE_LOG(
			LogT4Gameplay,
			Warning,
			TEXT("AT4GameplayFOAIController : Failed to FOBind. FOGameDataID '%s' Not Found."),
			*(InFOGameDataID.ToString())
		);
		return false;
	}

	AIDataLoadState = ET4AIDataLoadState::AIDataLoad_NoData; // #50

	// #31
	//const TCHAR* DebugTableName = *(InFOGameDataID.ToString());
	//BlackboardAssetLoader.Load(InBlackboardDataPath, false, DebugTableName);
	//BehaviorTreeAssetLoader.Load(InBehaviorTreePath, false, DebugTableName);
	FOGameDataID = InFOGameDataID;
	return true;
}