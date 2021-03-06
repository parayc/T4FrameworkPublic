// Copyright 2019-2020 SoonBo Noh. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Public/T4GameBuiltin_Types.h" // #114
#include "Public/T4GameBuiltin_GameDataTypes.h" // #48
#include "T4Framework/Classes/Object/T4GameObject.h"
#include "T4GameBuiltin_ClientObject.generated.h"

/**
  * #114 : BP 로 노출해서 게임 로직에서 사용한다.
 */
class IT4Framework;
class IT4WorldSystem;
class IT4WorldActor;
class IT4PlayerController;
class IT4GameBuiltin_ServerPacketHandler; // #114
struct FT4GameBuiltin_GamePlayerData;
struct FT4GameBuiltin_GameNPCData;
struct FT4GameBuiltin_GameWeaponData;
struct FT4GameBuiltin_GameCostumeData;
struct FT4GameBuiltin_GameSkillData;
struct FT4GameBuiltin_GameEffectData;
struct FT4GameBuiltin_PacketCS_Base;
UCLASS()
class T4GAMEBUILTIN_API UT4GameBuiltin_ClientObject : public UT4GameObject
{
	GENERATED_UCLASS_BODY()
		
public:
	// IT4GameObject
	IT4ObjectController* GetController() const override; // #114 : Server All, Client Player Only

public:
	// UT4GameObject
	bool IsClientObject() const override { return true; }

public:
	const FT4ActorID& GetControlActorID() const { return ControlActorID; } // #114 : ActorID 기억! 현재는 ObjectID.Value 와 같다. 이후 교체가 되어야 할 수 있음

	void SetMainWeaponDataID(const FT4GameBuiltin_GameDataID& InMainWeaponDataID) { MainWeaponDataID = InMainWeaponDataID; } // #48
	const FT4GameBuiltin_GameDataID& GetMainWeaponDataID() const { return MainWeaponDataID; } // #48

public:
	// Send Packet Process
	//
	bool OnSendPacket(FT4GameBuiltin_PacketCS_Base* InPacketCS); // #114

public:
	// Recv Packet Process
	//
	bool OnRecvLeave();

#if WITH_EDITOR
	bool OnRecvEnterWithEditor(
		const FT4EntityKey& InEntityKey,
		const FVector& InSpawnLocation,
		const FRotator& InSpawnRotation,
		bool bInPossess
	); // #114
#endif

	bool OnRecvEnterPlayer(
		const FT4GameBuiltin_GameDataID& InPlayerDataID,
		const FVector& InSpawnLocation,
		const FRotator& InSpawnRotation,
		bool bInPossess
	);
	bool OnRecvEnterNPC(const FT4GameBuiltin_GameDataID& InNPCDataID, const FVector& InSpawnLocation, const FRotator& InSpawnRotation);
	bool OnRecvEnterItem(const FT4GameBuiltin_GameDataID& InNPCDataID, const FVector& InSpawnLocation, const FRotator& InSpawnRotation);

	bool OnRecvMove(
		const FVector& InMoveToLocation,
		float InHeadYawAngle,
		bool bInForceMaxSpeed,
		const FVector& InServerNavPoint,
		const FVector& InServerDirection
	);
	bool OnRecvMoveStop(const FVector& InStopLocation, float InHeadYawAngle, bool bInSyncLocation);
	bool OnRecvMoveSpeedSync(float InMoveSpeed);

	bool OnRecvJump(const FVector& InJumpVelocity);
	bool OnRecvRoll(const FVector& InRollVelocity);
	bool OnRecvTurn(float InTargetYawAngle);
	bool OnRecvTeleport(const FVector& InTargetLocation);

	bool OnRecvLockOn(float InHeadYawAngle);
	bool OnRecvLockOff(float InHeadYawAngle);

	bool OnRecvAimSet(const FT4GameBuiltin_GameDataID& InSkillDataID, bool bInAimingStart, const FVector& InTargetLocation);
	bool OnRecvAimClear();

	bool OnRecvSkillTarget(
		const FT4GameBuiltin_GameDataID& InSkillDataID,
		ET4GameBuiltin_AttackTarget InTargetType,
		const FT4ObjectID& InTargetObjectID, // #63 : 타겟이 있으면 먼저 체크! 없으면 Direct 을 사용한다.
		FName InTargetHitBone, // #112 : TargetActorID Valid 일 경우만, 현재는 순수 비쥬얼 용도
		const FVector& InTargetLocationOrDirection, // #49, #68, #112
		float InProjectileDurationSec // #63 : Range Attack 이라면 ProjectileSpeed 로 계산된 Duration 시간이 넘어온다.
	);
	bool OnRecvEffectDirect(const FT4GameBuiltin_GameDataID& InEffectDataID, const FT4ObjectID& InAttackerObjectID);

	bool OnRecvChangeStance(FName InStanceName);
	bool OnRecvChangeSubStance(FName InSubStanceName);

	bool OnRecvEquipItem(
		const FT4GameBuiltin_GameDataID& InWeaponDataID, 
		bool bInMainWeapon,
		const FT4GameBuiltin_GameDataID& InUnequipItemWeaponDataID // #114, #116 : 이전에 장착한 무기가 있다면 해제 후 장착
	);
	bool OnRecvUnequipItem(const FT4GameBuiltin_GameDataID& InWeaponDataID, bool bInMainWeapon);
	bool OnRecvExchangeItem(const FT4GameBuiltin_GameDataID& InCostumeDataID);

	bool OnRecvDie(FName InReactionName, const FT4ObjectID& InAttackerObjectID);
	bool OnRecvResurrect();

protected:
	void Initialize() override;
	void Finalize() override;

	IT4WorldActor* GetControlActor() const;
	IT4PlayerController* GetPlayerController() const;
	IT4GameBuiltin_ServerPacketHandler* GetServerPacketHandler() const;

	IT4WorldActor* FindWorldActor(const FT4ObjectID& InObjectID) const;

	const FT4GameBuiltin_GamePlayerData* GetGamePlayerData();
	const FT4GameBuiltin_GameNPCData* GetGameNPCData();
	const FT4GameBuiltin_GameWeaponData* GetGameWeaponData();
	const FT4GameBuiltin_GameCostumeData* GetGameCostumeData();

	const FT4GameBuiltin_GameSkillData* GetGameSkillData(const FT4GameBuiltin_GameDataID& InSkillDataID);
	const FT4GameBuiltin_GameEffectData* GetGameEffectData(const FT4GameBuiltin_GameDataID& InEffectDataID);
	const FT4GameBuiltin_GameWeaponData* GetGameWeaponData(const FT4GameBuiltin_GameDataID& InWeaponDataID);
	const FT4GameBuiltin_GameCostumeData* GetGameCostumeData(const FT4GameBuiltin_GameDataID& InCostumeDataID);

private:
	bool bEntered;
	FT4ActorID ControlActorID; // #114 : ActorID 기억! 현재는 ObjectID.Value 와 같다. 이후 교체가 되어야 할 수 있음
	FT4GameBuiltin_GameDataID GameDataID;
	FT4GameBuiltin_GameDataID MainWeaponDataID;
};
