// Copyright 2019 Tech4 Labs, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Public/T4GameplayDataTypes.h"

#include "Classes/Network/Protocol/T4PacketCSMinimal.h" // #25
#include "Classes/Network/Protocol/T4PacketSCMinimal.h" // #25

#include "T4Framework/Classes/Player/T4PlayerController.h"

#include "T4GameplayPlayerController.generated.h"

/**
  * http://api.unrealengine.com/KOR/Gameplay/Framework/Controller/PlayerController/index.html
 */
UCLASS()
class T4GAMEPLAY_API AT4GameplayPlayerController : public AT4PlayerController
{
	GENERATED_UCLASS_BODY()

public:
	void SetMainWeaponDataID(const FT4GameDataID& InMainWeaponDataID) { MainWeaponDataID = InMainWeaponDataID; } // #48
	const FT4GameDataID& GetMainWeaponDataID() const { return MainWeaponDataID; } // #48

private:
	FT4GameDataID MainWeaponDataID; // #48

protected:
	// #27 : Protocol
	bool CS_RecvPacket_Validate(const FT4PacketCtoS* InPacket);
	void CS_RecvPacket_Implementation(const FT4PacketCtoS* InPacket);

	void SC_RecvPacket_Implementation(const FT4PacketStoC* InPacket);

private:
	friend class FT4PacketHandlerCS;

	// #T4_ADD_PACKET_TAG
	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_Move(const FT4PacketMoveCS& InPacket);

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_Jump(const FT4PacketJumpCS& InPacket);

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_Roll(const FT4PacketRollCS& InPacket); // #46

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_Turn(const FT4PacketTurnCS& InPacket); // #40

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_LockOn(const FT4PacketLockOnCS& InPacket);

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_LockOff(const FT4PacketLockOffCS& InPacket);

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_Equip(const FT4PacketEquipCS& InPacket);

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_UnEquip(const FT4PacketUnEquipCS& InPacket);

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_Exchange(const FT4PacketExchangeCS& InPacket); // #37

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_Attack(const FT4PacketAttackCS& InPacket);

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_CmdChangeWorld(const FT4PacketCmdChangeWorldCS& InPacket);

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_CmdPCEnter(const FT4PacketCmdPCEnterCS& InPacket);

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_CmdPCLeave(const FT4PacketCmdPCLeaveCS& InPacket);

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_CmdNPCEnter(const FT4PacketCmdNPCEnterCS& InPacket); // #31

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_CmdNPCLeave(const FT4PacketCmdNPCLeaveCS& InPacket); // #31

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_CmdFOEnter(const FT4PacketCmdFOEnterCS& InPacket); // #31

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_CmdFOLeave(const FT4PacketCmdFOLeaveCS& InPacket); // #31

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_CmdItemEnter(const FT4PacketCmdItemEnterCS& InPacket); // #41

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_CmdItemLeave(const FT4PacketCmdItemLeaveCS& InPacket); // #41

	UFUNCTION(Reliable, server, WithValidation)
	void CS_RecvPacket_CmdTeleport(const FT4PacketCmdTeleportCS& InPacket);

private:
	friend class FT4PacketHandlerSC;

	// #T4_ADD_PACKET_TAG
	UFUNCTION(Reliable, client)
	void SC_RecvPacket_ChangeWorld(const FT4PacketChangeWorldSC& InPacket);

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_MyPCEnter(const FT4PacketMyPCEnterSC& InPacket);

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_PCEnter(const FT4PacketPCEnterSC& InPacket);

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_PCLeave(const FT4PacketPCLeaveSC& InPacket);

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_NPCEnter(const FT4PacketNPCEnterSC& InPacket); // #31

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_NPCLeave(const FT4PacketNPCLeaveSC& InPacket); // #31

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_FOEnter(const FT4PacketFOEnterSC& InPacket); // #31

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_FOLeave(const FT4PacketFOLeaveSC& InPacket); // #31

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_ItemEnter(const FT4PacketItemEnterSC& InPacket); // #41

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_ItemLeave(const FT4PacketItemLeaveSC& InPacket); // #41

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_MoveTo(const FT4PacketMoveToSC& InPacket);

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_JumpTo(const FT4PacketJumpToSC& InPacket);

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_RollTo(const FT4PacketRollToSC& InPacket); // #46

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_TurnTo(const FT4PacketTurnToSC& InPacket); // #40

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_TeleportTo(const FT4PacketTeleportToSC& InPacket);

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_LockOn(const FT4PacketLockOnSC& InPacket);

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_LockOff(const FT4PacketLockOffSC& InPacket);

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_Equip(const FT4PacketEquipSC& InPacket);

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_UnEquip(const FT4PacketUnEquipSC& InPacket);

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_Exchange(const FT4PacketExchangeSC& InPacket); // #37

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_Attack(const FT4PacketAttackSC& InPacket);

	UFUNCTION(Reliable, client)
	void SC_RecvPacket_Effect(const FT4PacketEffectSC& InPacket);
};
