// Copyright 2019 Tech4 Labs. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "T4PacketBase.h"
#include "T4PacketSC.h"
#include "T4PacketSC_World.generated.h"

/**
  *
 */
 // #T4_ADD_PACKET_TAG

// ET4PacketStoC::ChangeWorld
// ET4PacketStoC::MyPCEnter
// ET4PacketStoC::PCEnter
// ET4PacketStoC::PCLeave

// ET4PacketStoC::NPCEnter // #31
// ET4PacketStoC::NPCLeave // #31

// ET4PacketStoC::FOEnter // #31
// ET4PacketStoC::FOLeave // #31

// ET4PacketStoC::ItemEnter // #41
// ET4PacketStoC::ItemLeave // #41

USTRUCT()
struct T4FRAMEWORK_API FT4PacketChangeWorldSC : public FT4PacketStoC
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	FName WorldNameInTable;

public:
	FT4PacketChangeWorldSC()
		: FT4PacketStoC(ET4PacketStoC::ChangeWorld)
		, WorldNameInTable(NAME_None)
	{
	}

	FString ToString() const override
	{
		return FString(TEXT("SC_Packet:ChangeWorld"));
	}
};

USTRUCT()
struct T4FRAMEWORK_API FT4PacketMyPCEnterSC : public FT4PacketStoC
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	FT4ObjectID EnterObjectID;

	UPROPERTY(VisibleAnywhere)
	FName CharacterNameInTable;

	UPROPERTY(VisibleAnywhere)
	FVector SpawnLocation;

	UPROPERTY(VisibleAnywhere)
	FRotator SpawnRotation;

public:
	FT4PacketMyPCEnterSC()
		: FT4PacketStoC(ET4PacketStoC::MyPCEnter)
		, CharacterNameInTable(NAME_None)
		, SpawnLocation(FVector::ZeroVector)
		, SpawnRotation(FRotator::ZeroRotator)
	{
	}

	FString ToString() const override
	{
		return FString(TEXT("SC_Packet:MyPCEnter"));
	}
};

USTRUCT()
struct T4FRAMEWORK_API FT4PacketPCEnterSC : public FT4PacketStoC
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	FT4ObjectID EnterObjectID;

	UPROPERTY(VisibleAnywhere)
	FName CharacterNameInTable;

	UPROPERTY(VisibleAnywhere)
	FVector SpawnLocation;

	UPROPERTY(VisibleAnywhere)
	FRotator SpawnRotation;
	
public:
	FT4PacketPCEnterSC()
		: FT4PacketStoC(ET4PacketStoC::PCEnter)
		, CharacterNameInTable(NAME_None)
		, SpawnLocation(FVector::ZeroVector)
		, SpawnRotation(FRotator::ZeroRotator)
	{
	}

	FString ToString() const override
	{
		return FString(TEXT("SC_Packet:PCEnter"));
	}
};


USTRUCT()
struct T4FRAMEWORK_API FT4PacketPCLeaveSC : public FT4PacketStoC
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	FT4ObjectID LeaveObjectID;
	
public:
	FT4PacketPCLeaveSC()
		: FT4PacketStoC(ET4PacketStoC::PCLeave)
	{
	}

	FString ToString() const override
	{
		return FString(TEXT("SC_Packet:PCLeave"));
	}
};

// #31
USTRUCT()
struct T4FRAMEWORK_API FT4PacketNPCEnterSC : public FT4PacketStoC
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	FT4NetID NetID;

	UPROPERTY(VisibleAnywhere)
	FT4ObjectID EnterObjectID;

	UPROPERTY(VisibleAnywhere)
	FName NPCNameInTable;

	UPROPERTY(VisibleAnywhere)
	FVector SpawnLocation;

	UPROPERTY(VisibleAnywhere)
	FRotator SpawnRotation;
	
public:
	FT4PacketNPCEnterSC()
		: FT4PacketStoC(ET4PacketStoC::NPCEnter)
		, NPCNameInTable(NAME_None)
		, SpawnLocation(FVector::ZeroVector)
		, SpawnRotation(FRotator::ZeroRotator)
	{
	}

	FString ToString() const override
	{
		return FString(TEXT("SC_Packet:NPCEnter"));
	}
};

// #31
USTRUCT()
struct T4FRAMEWORK_API FT4PacketNPCLeaveSC : public FT4PacketStoC
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	FT4ObjectID LeaveObjectID;
	
public:
	FT4PacketNPCLeaveSC()
		: FT4PacketStoC(ET4PacketStoC::NPCLeave)
	{
	}

	FString ToString() const override
	{
		return FString(TEXT("SC_Packet:NPCLeave"));
	}
};

// #31
USTRUCT()
struct T4FRAMEWORK_API FT4PacketFOEnterSC : public FT4PacketStoC
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	FT4ObjectID EnterObjectID;

	UPROPERTY(VisibleAnywhere)
	FName FONameInTable;

	UPROPERTY(VisibleAnywhere)
	FVector SpawnLocation;

	UPROPERTY(VisibleAnywhere)
	FRotator SpawnRotation;
	
public:
	FT4PacketFOEnterSC()
		: FT4PacketStoC(ET4PacketStoC::FOEnter)
		, FONameInTable(NAME_None)
		, SpawnLocation(FVector::ZeroVector)
		, SpawnRotation(FRotator::ZeroRotator)
	{
	}

	FString ToString() const override
	{
		return FString(TEXT("SC_Packet:FOEnter"));
	}
};

// #31
USTRUCT()
struct T4FRAMEWORK_API FT4PacketFOLeaveSC : public FT4PacketStoC
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	FT4ObjectID LeaveObjectID;
	
public:
	FT4PacketFOLeaveSC()
		: FT4PacketStoC(ET4PacketStoC::FOLeave)
	{
	}

	FString ToString() const override
	{
		return FString(TEXT("SC_Packet:FOLeave"));
	}
};

// #41
USTRUCT()
struct T4FRAMEWORK_API FT4PacketItemEnterSC : public FT4PacketStoC
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	FT4ObjectID EnterObjectID;

	UPROPERTY(VisibleAnywhere)
	FName ItemNameInTable;

	UPROPERTY(VisibleAnywhere)
	FVector SpawnLocation;

	UPROPERTY(VisibleAnywhere)
	FRotator SpawnRotation;
	
public:
	FT4PacketItemEnterSC()
		: FT4PacketStoC(ET4PacketStoC::ItemEnter)
		, ItemNameInTable(NAME_None)
		, SpawnLocation(FVector::ZeroVector)
		, SpawnRotation(FRotator::ZeroRotator)
	{
	}

	FString ToString() const override
	{
		return FString(TEXT("SC_Packet:ItemEnter"));
	}
};

// #41
USTRUCT()
struct T4FRAMEWORK_API FT4PacketItemLeaveSC : public FT4PacketStoC
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	FT4ObjectID LeaveObjectID;
	
public:
	FT4PacketItemLeaveSC()
		: FT4PacketStoC(ET4PacketStoC::ItemLeave)
	{
	}

	FString ToString() const override
	{
		return FString(TEXT("SC_Packet:ItemLeave"));
	}
};
