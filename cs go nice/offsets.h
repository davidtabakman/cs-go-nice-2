#pragma once
#include <cstddef>
#include <cstdint>
#include <Windows.h>

// Offsets timestamp
// Thu, 28 Sep 2017 23:19:43 +0200

const DWORD m_ArmorValue = 0xB228;
const DWORD m_Collision = 0x318;
const DWORD m_CollisionGroup = 0x470;
const DWORD m_Local = 0x2FAC;
const DWORD m_MoveType = 0x258;
const DWORD m_OriginalOwnerXuidHigh = 0x316C;
const DWORD m_OriginalOwnerXuidLow = 0x3168;
const DWORD m_aimPunchAngle = 0x301C;
const DWORD m_aimPunchAngleVel = 0x3028;
const DWORD m_bGunGameImmunity = 0x3890;
const DWORD m_bHasDefuser = 0xB238;
const DWORD m_bHasHelmet = 0xB21C;
const DWORD m_bInReload = 0x3245;
const DWORD m_bIsDefusing = 0x3884;
const DWORD m_bIsScoped = 0x387C;
const DWORD m_bSpotted = 0x939;
const DWORD m_bSpottedByMask = 0x97C;
const DWORD m_dwBoneMatrix = 0x2698;
const DWORD m_fAccuracyPenalty = 0x32B0;
const DWORD m_fFlags = 0x100;
const DWORD m_flFallbackWear = 0x3178;
const DWORD m_flFlashDuration = 0xA2E8;
const DWORD m_flFlashMaxAlpha = 0xA2E4;
const DWORD m_flNextPrimaryAttack = 0x31D8;
const DWORD m_hActiveWeapon = 0x2EE8;
const DWORD m_hMyWeapons = 0x2DE8;
const DWORD m_hObserverTarget = 0x3360;
const DWORD m_hOwner = 0x29BC;
const DWORD m_hOwnerEntity = 0x148;
const DWORD m_iAccountID = 0x2FA8;
const DWORD m_iClip1 = 0x3204;
const DWORD m_iCompetitiveRanking = 0x1A44;
const DWORD m_iCompetitiveWins = 0x1B48;
const DWORD m_iCrosshairId = 0xB294;
const DWORD m_iEntityQuality = 0x2F8C;
const DWORD m_iFOVStart = 0x31D8;
const DWORD m_iGlowIndex = 0xA300;
const DWORD m_iHealth = 0xFC;
const DWORD m_iItemDefinitionIndex = 0x2F88;
const DWORD m_iItemIDHigh = 0x2FA0;
const DWORD m_iObserverMode = 0x334C;
const DWORD m_iShotsFired = 0xA2A0;
const DWORD m_iState = 0x31F8;
const DWORD m_iTeamNum = 0xF0;
const DWORD m_lifeState = 0x25B;
const DWORD m_nFallbackPaintKit = 0x3170;
const DWORD m_nFallbackSeed = 0x3174;
const DWORD m_nFallbackStatTrak = 0x317C;
const DWORD m_nForceBone = 0x267C;
const DWORD m_nTickBase = 0x3404;
const DWORD m_rgflCoordinateFrame = 0x440;
const DWORD m_szCustomName = 0x301C;
const DWORD m_szLastPlaceName = 0x3588;
const DWORD m_vecOrigin = 0x134;
const DWORD m_vecVelocity = 0x110;
const DWORD m_vecViewOffset = 0x104;
const DWORD m_viewPunchAngle = 0x3010;

		const DWORD dwClientState = 0x5A5344;
		const DWORD dwClientState_GetLocalPlayer = 0x180;
		const DWORD dwClientState_Map = 0x28C;
		const DWORD dwClientState_MapDirectory = 0x188;
		const DWORD dwClientState_MaxPlayer = 0x310;
		const DWORD dwClientState_PlayerInfo = 0x5240;
		const DWORD dwClientState_State = 0x108;
		const DWORD dwClientState_ViewAngles = 0x4D10;
		const DWORD dwClientState_IsHLTV = 0x4CC8;
		const DWORD dwEntityList = 0x4A8D05C;
		const DWORD dwForceAttack = 0x2ECF3DC;
		const DWORD dwForceAttack2 = 0x2ECF3E8;
		const DWORD dwForceBackward = 0x2ECF460;
		const DWORD dwForceForward = 0x2ECF424;
		const DWORD dwForceJump = 0x4F23F08;
		const DWORD dwForceLeft = 0x2ECF46C;
		const DWORD dwForceRight = 0x2ECF448;
		const DWORD dwGameDir = 0x643BD0;
		const DWORD dwGameRulesProxy = 0x4F8E254;
		const DWORD dwGetAllClasses = 0x4F8E328;
		const DWORD dwGlobalVars = 0x5A5048;
		const DWORD dwGlowObjectManager = 0x4FA9AA8;
		const DWORD dwInput = 0x4ED7C20;
		const DWORD dwInterfaceLinkList = 0x6EB7E4;
		const DWORD dwLocalPlayer = 0xAAFC3C;
		const DWORD dwMouseEnable = 0xAB54A0;
		const DWORD dwMouseEnablePtr = 0xAB5470;
		const DWORD dwPlayerResource = 0x2ECD76C;
		const DWORD dwRadarBase = 0x4EC1D54;
		const DWORD dwSensitivity = 0xAB533C;
		const DWORD dwSensitivityPtr = 0xAB5310;
		const DWORD dwViewMatrix = 0x4A7EAB4;
		const DWORD dwWeaponTable = 0x4ED8814;
		const DWORD dwWeaponTableIndex = 0x31FC;
		const DWORD dwYawPtr = 0xAB5100;
		const DWORD dwZoomSensitivityRatioPtr = 0xABA168;
		const DWORD dwbSendPackets = 0xCAB8A;
		const DWORD dwppDirect3DDevice9 = 0xA1F40;
		const DWORD dwSetClanTag = 0x848F0;
		const DWORD m_pStudioHdr = 0x293C;

const DWORD EntLoopDist = 0x10;
const DWORD dwDormant = 0xE9;
