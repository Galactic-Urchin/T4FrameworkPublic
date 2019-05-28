// Copyright 2019 Tech4 Labs, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "T4PacketBase.h"
#include "T4PacketCS.h"
#include "T4PacketCS_Status.generated.h"

/**
  *
 */
 // #T4_ADD_PACKET_TAG

// ET4PacketCtoS::Equip
// ET4PacketCtoS::UnEquip
// ET4PacketCtoS::Exchange

USTRUCT()
struct FT4PacketEquipCS : public FT4PacketCtoS
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	FT4ObjectID SenderID;

	UPROPERTY(VisibleAnywhere)
	FName ItemNameID;

public:
	FT4PacketEquipCS()
		: FT4PacketCtoS(ET4PacketCtoS::Equip)
		, ItemNameID(NAME_None)
	{
	}

	bool Validate(FString& OutMsg) override
	{
		if (!SenderID.IsValid())
		{
			OutMsg = TEXT("Invalid Send ObjectID!");
			return false;
		}
		return true;
	}

	FString ToString() const override
	{
		return FString(TEXT("CS_Packet:Equip"));
	}
};

USTRUCT()
struct FT4PacketUnEquipCS : public FT4PacketCtoS
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	FT4ObjectID SenderID;

	UPROPERTY(VisibleAnywhere)
	FName ItemNameID;

public:
	FT4PacketUnEquipCS()
		: FT4PacketCtoS(ET4PacketCtoS::UnEquip)
		, ItemNameID(NAME_None)
	{
	}

	bool Validate(FString& OutMsg) override
	{
		if (!SenderID.IsValid())
		{
			OutMsg = TEXT("Invalid Send ObjectID!");
			return false;
		}
		return true;
	}

	FString ToString() const override
	{
		return FString(TEXT("CS_Packet:UnEquip"));
	}
};

USTRUCT()
struct FT4PacketExchangeCS : public FT4PacketCtoS
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	FT4ObjectID SenderID;

	UPROPERTY(VisibleAnywhere)
	FName ItemNameID;

public:
	FT4PacketExchangeCS()
		: FT4PacketCtoS(ET4PacketCtoS::Exchange)
		, ItemNameID(NAME_None)
	{
	}

	bool Validate(FString& OutMsg) override
	{
		if (!SenderID.IsValid())
		{
			OutMsg = TEXT("Invalid Send ObjectID!");
			return false;
		}
		return true;
	}

	FString ToString() const override
	{
		return FString(TEXT("CS_Packet:Exchange"));
	}
};