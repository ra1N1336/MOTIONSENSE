#pragma once

#include <Windows.h>
#include "SourceEngine/SDK.hpp"
#include "NetvarManager.hpp"
#include "SourceEngine/Definitions.hpp"
#include "PushNotifications.h"
#include "XorStr.hpp"
#include "Options.hpp"

#define TIME_TO_TICKS( dt )	( ( int )( 0.5f + ( float )( dt ) / Interfaces::GlobalVars()->interval_per_tick ) )

extern float OldSimulationTimes[65];

class CHudTexture;

class WeaponInfo_t
{
public:
	char _0x0000[4];
	BYTE m_bParsedScript; //0x0004 
	BYTE m_bLoadedHudElements; //0x0005 
	BYTE m_szClassName; //0x0006 
	char _0x0007[2041];
	__int32 m_iAmmoType; //0x07B0 
	char _0x07B4[12];
	CHudTexture* m_pHudTexture_WeaponSilenced; //0x07C0 
	CHudTexture* m_pHudTexture_Weapon; //0x07C4 
	CHudTexture* m_pHudTexture_Ammo; //0x07C8 
	char _0x07CC[4];
	CHudTexture* m_pHudTexture_Crosshair; //0x07D0 
	char _0x07D4[20];
	__int32 m_iWeaponType; //0x07E8 
	__int32 m_iTeam; //0x07EC 
	__int32 m_iWeaponId; //0x07F0 
	BYTE m_bFullAuto; //0x07F4 
	char _0x07F5[3];
	float m_flHeatPerShot; //0x07F8 
	__int32 m_iWeaponPrice; //0x07FC 
	float m_flArmorRatio; //0x0800 
	float m_flMaxPlayerSpeed; //0x0804 
	float m_flMaxPlayerSpeedAlt; //0x0808 
	__int32 m_iCrosshairMinDistance; //0x080C 
	__int32 m_iCrosshairDeltaDistance; //0x0810 
	float m_flPenetration; //0x0814 
	__int32 m_iDamage; //0x0818 
	float m_flRange; //0x081C 
	float m_flRangeModifier; //0x0820 
	__int32 m_iBullets; //0x0824 
	float m_flCycleTime; //0x0828 
	float m_flCycleTimeAlt; //0x082C 
	char _0x0830[416];
	float m_flSpread; //0x09D0 
	float m_flSpreadAlt; //0x09D4 
	float m_flInaccuracyCrouch; //0x09D8 
	float m_flInaccuracyCrouchAlt; //0x09DC 
	float m_flInaccuracyStand; //0x09E0 
	float m_flInaccuracyStandAlt; //0x09E4 
	float m_flInaccuracyJump; //0x09E8 
	float m_flInaccuracyJumpAlt; //0x09EC 
	float m_flInaccuracyLand; //0x09F0 
	float m_flInaccuracyLandAlt; //0x09F4 
	float m_flInaccuracyLadder; //0x09F8 
	float m_flInaccuracyLadderAlt; //0x09FC 
	float m_flInaccuracyFire; //0x0A00 
	float m_flInaccuracyFireAlt; //0x0A04 
	float m_flInaccuracyMove; //0x0A08 
	float m_flInaccuracyMoveAlt; //0x0A0C 
	float m_flRecoveryTimeStand; //0x0A10 
	float m_flRecoveryTimeCrouch; //0x0A14 
	float m_flInaccuracyReload; //0x0A18 
	float m_flInaccuracyAltSwitch; //0x0A1C 
	float m_flRecoilAngle; //0x0A20 
	float m_flRecoilAngleAlt; //0x0A24 
	float m_flRecoilAngleVariance; //0x0A28 
	float m_flRecoilAngleVarianceAlt; //0x0A2C 
	float m_flRecoilMagnitude; //0x0A30 
	float m_flRecoilMagnitudeAlt; //0x0A34 
	float m_flRecoilMagnitudeVariance; //0x0A38 
	float m_flRecoilMagnitudeVarianceAlt; //0x0A3C 
	__int32 m_iRecoilSeed; //0x0A40 
	float m_flFlinchVelocityModifierLarge; //0x0A44 
	float m_flFlinchVelocityModifierSmall; //0x0A48 
	float m_flTimeToIdle; //0x0A4C 
	float m_flIdleInterval; //0x0A50
};

class C_BaseCombatWeapon;

class DT_EconEntity : public SourceEngine::IClientEntity
{
	template<class T>
	inline T GetFieldValue(int offset)
	{
		return *(T*)((DWORD)this + offset);
	}
	template<class T>
	T* GetFieldPointer(int offset)
	{
		return (T*)((DWORD)this + offset);
	}
public:
	void SetWear(float Wear)
	{

	}
	void SetPaintKit(int ID)
	{

	}
	void SetSeed(float Seed)
	{

	}
	void SetStatTrak(int Kills)
	{

	}
};

class C_CSPlayer : public SourceEngine::IClientEntity
{
	template<class T>
	inline T GetFieldValue(int offset)
	{
		return *(T*)((DWORD)this + offset);
	}
	template<class T>
	inline void SetFieldValue(int offset, T dat)
	{
		*(T*)((DWORD)this + offset) = dat;
	}
	template<class T>
	T* GetFieldPointer(int offset)
	{
		return (T*)((DWORD)this + offset);
	}
public:
	static C_CSPlayer* GetLocalPlayer()
	{
		return (C_CSPlayer*)SourceEngine::Interfaces::EntityList()->GetClientEntity(SourceEngine::Interfaces::Engine()->GetLocalPlayer());
	}
	C_BaseCombatWeapon* GetActiveWeapon()
	{
		using namespace SourceEngine;
		static int m_hActiveWeapon = GET_NETVAR(XorStr("DT_BaseCombatCharacter"), XorStr("m_hActiveWeapon"));
		return (C_BaseCombatWeapon*)Interfaces::EntityList()->GetClientEntityFromHandle(GetFieldValue<CHandle<IClientEntity>>(m_hActiveWeapon));
	}
	int GetHealth()
	{
		static int m_iHealth = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("m_iHealth"));
		return GetFieldValue<int>(m_iHealth);
	}
	bool IsAlive()
	{
		static int m_lifeState = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("m_lifeState"));
		return GetFieldValue<int>(m_lifeState) == 0;
	}
	int GetTeamNum()
	{
		static int m_iTeamNum = GET_NETVAR(XorStr("DT_BaseEntity"), XorStr("m_iTeamNum"));
		return GetFieldValue<int>(m_iTeamNum);
	}
	int GetFlags()
	{
		static int m_fFlags = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("m_fFlags"));
		return GetFieldValue<int>(m_fFlags);
	}
	SourceEngine::Vector GetViewOffset()
	{
		static int m_vecViewOffset = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("localdata"), XorStr("m_vecViewOffset[0]"));
		return GetFieldValue<SourceEngine::Vector>(m_vecViewOffset);
	}
	SourceEngine::Vector GetVelocity()
	{
		static int m_vecVelocity = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("localdata"), XorStr("m_vecVelocity[0]"));
		return GetFieldValue<SourceEngine::Vector>(m_vecVelocity);
	}
	SourceEngine::Vector GetOrigin()
	{
		static int m_vecOrigin = GET_NETVAR(XorStr("DT_BaseEntity"), XorStr("m_vecOrigin"));
		return GetFieldValue<SourceEngine::Vector>(m_vecOrigin);
	}
	SourceEngine::Vector GetEyePos()
	{
		return GetOrigin() + GetViewOffset();
	}
	SourceEngine::Vector* ViewPunch()
	{
		static int m_viewPunchAngle = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("localdata"), XorStr("m_Local"), XorStr("m_viewPunchAngle"));
		return GetFieldPointer<SourceEngine::Vector>(m_viewPunchAngle);
	}
	SourceEngine::Vector* AimPunch()
	{
		static int m_aimPunchAngle = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("localdata"), XorStr("m_Local"), XorStr("m_aimPunchAngle"));
		return GetFieldPointer<SourceEngine::Vector>(m_aimPunchAngle);
	}
	SourceEngine::QAngle GetEyeAngles()
	{
		static int m_viewAngle = GET_NETVAR(XorStr("DT_CSPlayer"), XorStr("m_angEyeAngles"));
		return GetFieldValue<SourceEngine::QAngle>(m_viewAngle);
	}
	SourceEngine::QAngle* EyeAngles()
	{
		static int m_viewAngle = GET_NETVAR(XorStr("DT_CSPlayer"), XorStr("m_angEyeAngles"));
		return GetFieldPointer<SourceEngine::QAngle>(m_viewAngle);
	}
	int InCross()
	{
		SourceEngine::Ray_t ray;
		SourceEngine::CGameTrace tr;
		SourceEngine::CTraceFilter filter;
		filter.pSkip = C_CSPlayer::GetLocalPlayer();

		Vector LocalEyePos = GetEyePos();
		QAngle EyeAngles;
		Interfaces::Engine()->GetViewAngles(EyeAngles);
		Vector EndPos = LocalEyePos + (EyeAngles).Direction() * 8192.0f;
		ray.Init(LocalEyePos, EndPos);
		SourceEngine::Interfaces::EngineTrace()->TraceRay(ray, 0x4600400B, &filter, &tr);

		if (tr.m_pEnt)
			return tr.m_pEnt->GetClientNetworkable()->EntIndex();
		return 0;
	}
	int GetMoveType()
	{
		return GetFieldValue<int>(0x258);
	}
	bool GetGunGameImmunity()
	{
		static int m_bGunGameImmunity = GET_NETVAR(XorStr("DT_CSPlayer"), XorStr("m_bGunGameImmunity"));
		return GetFieldValue<bool>(m_bGunGameImmunity);
	}
	Vector GetNetworkOrigin() {
		static int m_flFriction = GET_NETVAR("DT_BasePlayer", "localdata", "m_flFriction") - sizeof(Vector);
		return GetFieldValue<Vector>(m_flFriction);
	}
	float GetSimulationTime()
	{
		static int m_flSimulationTime = GET_NETVAR(XorStr("DT_BaseEntity"), XorStr("m_flSimulationTime"));
		return GetFieldValue<float>(m_flSimulationTime);
	}
	float GetLowerBodyYawTarget()
	{
		static int m_flLowerBodyYawTarget = GET_NETVAR(XorStr("DT_CSPlayer"), XorStr("m_flLowerBodyYawTarget"));
		return GetFieldValue<float>(m_flLowerBodyYawTarget);
	}
	float GetPoseParameter()
	{
		static int m_flPoseParameter = GET_NETVAR(XorStr("DT_BaseAnimating"), XorStr("m_flPoseParameter"));
		return GetFieldValue<float>(m_flPoseParameter);
	}
	int GetChockedPackets()
	{
		if (GetSimulationTime() > OldSimulationTimes[EntIndex()])
			return TIME_TO_TICKS(fabs(GetSimulationTime() - OldSimulationTimes[EntIndex()]));
		return 0;
	}
	SourceEngine::Vector GetBone(int Bone)
	{
		SourceEngine::matrix3x4_t boneMatrix[128];
		if (!SetupBones(boneMatrix, 128, 0x00000100, SourceEngine::Interfaces::Engine()->GetLastTimeStamp()))
			return SourceEngine::Vector();
		SourceEngine::matrix3x4_t hitbox = boneMatrix[Bone];
		SourceEngine::Vector BonePos(hitbox[0][3], hitbox[1][3], hitbox[2][3]);
		if (GetChockedPackets() > 5 && Config.g_iFakeLagFix == 1)
		{
			BonePos -= GetOrigin();
			BonePos += GetNetworkOrigin();
		}
		return BonePos;
	}
	Vector GetBoneByName(std::string name)
	{
		auto Mdl = GetModel();
		if (!Mdl) return Vector();
		studiohdr_t* pStudioHdr = Interfaces::ModelInfo()->GetStudioModel(Mdl);
		if (!pStudioHdr) return Vector();
		for (int j = 0; j < pStudioHdr->numbones; j++)
		{
			mstudiobone_t* pBone = pStudioHdr->pBone(j);
			if (pBone && (pBone->flags & BONE_USED_BY_HITBOX) && std::string(pBone->pszName()) == name)
				return GetBone(j);
		}
		return Vector();
	}
	int HitboxSet()
	{
		static int m_nHitboxSet = GET_NETVAR(XorStr("DT_BaseAnimating"), XorStr("m_nHitboxSet"));
		return GetFieldValue<int>(m_nHitboxSet);
	}
	mstudiohitboxset_t* GetHitBoxSet()
	{
		if (!GetModel()) return false;
		studiohdr_t* pHeader = Interfaces::ModelInfo()->GetStudioModel(GetModel());
		if (!pHeader) return nullptr;
		mstudiohitboxset_t* pHitBoxSet = pHeader->pHitboxSet(HitboxSet());
		if (!pHitBoxSet) return nullptr;
		return pHitBoxSet;
	}
	Vector GetHeadCenterPos()
	{
		SourceEngine::Vector bonePos = GetBoneByName(XorStr("head_0"));
		if (!bonePos.IsValid()) return Vector();
		SourceEngine::Vector up = GetEyeAngles().Up();
		SourceEngine::Vector Offset = up * 1.15f;
		return bonePos + Offset;
	}
	bool IsScoped()
	{
		int m_bIsScoped = GET_NETVAR(XorStr("DT_CSPlayer"), XorStr("m_bIsScoped"));
		return GetFieldValue<bool>(m_bIsScoped);
	}
	int GetArmor()
	{
		static int m_ArmorValue = GET_NETVAR(XorStr("DT_CSPlayer"), XorStr("m_ArmorValue"));
		return GetFieldValue<int>(m_ArmorValue);
	}
	bool HasHelmet()
	{
		static int m_bHasHelmet = GET_NETVAR(XorStr("DT_CSPlayer"), XorStr("m_bHasHelmet"));
		return GetFieldValue<bool>(m_bHasHelmet);
	}
	int GetTickBase()
	{
		static int m_nTickBase = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("localdata"), XorStr("m_nTickBase"));
		return GetFieldValue<int>(m_nTickBase);
	}
	int GetMoveState()
	{
		static int m_iMoveState = GET_NETVAR(XorStr("DT_CSPlayer"), XorStr("m_iMoveState"));
		return GetFieldValue<int>(m_iMoveState);
	}
	int GetPlayerState()
	{
		static int m_iPlayerState = GET_NETVAR(XorStr("DT_CSPlayer"), XorStr("m_iPlayerState"));
		return GetFieldValue<int>(m_iPlayerState);
	}
	SourceEngine::Vector GetPunchAngleVelocity()
	{
		static int m_aimPunchAngleVel = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("localdata"), XorStr("m_Local"), XorStr("m_aimPunchAngleVel"));
		return GetFieldValue<SourceEngine::Vector>(m_aimPunchAngleVel);
	}
	SourceEngine::QAngle* PlayerAngles()
	{
		static int m_vecAngles = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("pl"), XorStr("deadflag")) + 0x4;
		return GetFieldPointer<SourceEngine::QAngle>(m_vecAngles);
	}
	char* GetLastPlaceName()
	{
		static int m_szLastPlaceName = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("m_szLastPlaceName"));
		return GetFieldPointer<char>(m_szLastPlaceName);
	}
	float GetMaxSpeed()
	{
		static int m_flMaxspeed = GET_NETVAR(XorStr("DT_BasePlayer"), XorStr("m_flMaxspeed"));
		return GetFieldValue<float>(m_flMaxspeed);
	}
	int GetScoreboardKills()
	{
		static int m_iMatchStats_Kills = GET_NETVAR(XorStr("DT_CSPlayer"), XorStr("m_iMatchStats_Kills"));
		return GetFieldValue<int>(m_iMatchStats_Kills);
	}
	int GetScoreboardDeaths()
	{
		static int m_iMatchStats_Deaths = GET_NETVAR(XorStr("DT_CSPlayer"), XorStr("m_iMatchStats_Deaths"));
		return GetFieldValue<int>(m_iMatchStats_Deaths);
	}
	float GetNextAttack()
	{
		static int m_flNextAttack = GET_NETVAR(XorStr("DT_BaseCombatCharacter"), XorStr("bcc_localdata"), XorStr("m_flNextAttack"));
		return GetFieldValue<float>(m_flNextAttack);
	}
	bool IsReloading()
	{
		return GetFieldValue<bool>(0x3235);
	}
};

class C_BaseCombatWeapon : public SourceEngine::IClientEntity
{
	template<class T>
	inline T GetFieldValue(int offset)
	{
		return *(T*)((DWORD)this + offset);
	}
public:
    C_CSPlayer* GetOwner()
    {
        using namespace SourceEngine;
        static int m_hOwnerEntity = GET_NETVAR(XorStr("DT_BaseEntity"), XorStr("m_hOwnerEntity"));
        return (C_CSPlayer*)Interfaces::EntityList()->GetClientEntityFromHandle(GetFieldValue<CHandle<C_CSPlayer>>(m_hOwnerEntity));
    }
    float NextPrimaryAttack()
    {
        static int m_flNextPrimaryAttack = GET_NETVAR(XorStr("DT_BaseCombatWeapon"), XorStr("LocalActiveWeaponData"), XorStr("m_flNextPrimaryAttack"));
        return GetFieldValue<float>(m_flNextPrimaryAttack);
    }
	int GetClip1()
	{
		static int m_iClip1 = GET_NETVAR(XorStr("DT_BaseCombatWeapon"), XorStr("m_iClip1"));
		return GetFieldValue<int>(m_iClip1);
	}
	int GetClip2()
	{
		static int m_iClip2 = GET_NETVAR(XorStr("DT_BaseCombatWeapon"), XorStr("m_iClip2"));
		return GetFieldValue<int>(m_iClip2);
	}
	float GetAccuracyPenalty()
	{
		static int m_fAccuracyPenalty = GET_NETVAR(XorStr("DT_WeaponCSBase"), XorStr("m_fAccuracyPenalty"));
		return GetFieldValue<float>(m_fAccuracyPenalty);
	}
	SourceEngine::EItemDefinitionIndex GetItemDefinitionIndex()
	{
		static int m_iItemDefinitionIndex = GET_NETVAR(XorStr("DT_BaseAttributableItem"), XorStr("m_AttributeManager"), XorStr("m_Item"), XorStr("m_iItemDefinitionIndex"));
		return GetFieldValue<SourceEngine::EItemDefinitionIndex>(m_iItemDefinitionIndex);
	}
	WeaponInfo_t* GetCSWpnData()
	{
		typedef WeaponInfo_t*(__thiscall* tGetCSWpnData)(void*);
		return SourceEngine::CallVFunction<tGetCSWpnData>(this, 456)(this);
	}
	bool IsAutomatic()
	{
		int Index = GetItemDefinitionIndex();
		if (Index == 7 || Index == 8 || Index == 10 || Index == 11 || Index == 13 || Index == 14 || Index == 16 || Index == 17 || Index == 19 || Index == 24 || Index == 25 ||
			Index == 26 || Index == 28 || Index == 33 || Index == 34 || Index == 38 || Index == 39 || Index == 63)
			return true;
		return false;
	}
	bool IsSemiAutomatic()
	{
		return !IsAutomatic();
	}
	bool IsKnife()
	{
		int Index = GetItemDefinitionIndex();
		if (Index == 42 || Index == 59 || Index >= 500)
			return true;
		return false;
	}
	bool IsSniper()
	{
		int Index = GetItemDefinitionIndex();
		if (Index == 9 || Index == 11 || Index == 40 || Index == 38)
			return true;
		return false;
	}
	bool IsAR()
	{
		int Index = GetItemDefinitionIndex();
		if (Index == 7 || Index == 8 || Index == 10 || Index == 13 || Index == 16 || Index == 39 || Index == 60)
			return true;
		return false;
	}
	bool IsPistol()
	{
		int Index = GetItemDefinitionIndex();
		if (Index == 1 || Index == 2 || Index == 3 || Index == 4 || Index == 30 || Index == 36 || Index == 61 || Index == 63 || Index == 64)
			return true;
		return false;
	}
	bool IsGrenade()
	{
		int Index = GetItemDefinitionIndex();
		if (Index == 43 || Index == 44 || Index == 45 || Index == 46 || Index == 47 || Index == 48)
			return true;
		return false;
	}
	bool IsC4()
	{
		int Index = GetItemDefinitionIndex();
		if (Index == 49)
			return true;
		return false;
	}
	bool CanFire()
	{
		auto Owner = GetOwner();
		if (!Owner) return false;
		return !(Owner->IsReloading()) && NextPrimaryAttack() <= Owner->GetTickBase() * SourceEngine::Interfaces::GlobalVars()->interval_per_tick && Owner->GetNextAttack() <= Owner->GetTickBase() * SourceEngine::Interfaces::GlobalVars()->interval_per_tick;
	}
	std::string GetWeaponName()
	{
		int ID = GetItemDefinitionIndex();
		using namespace SourceEngine;
		if (ID == weapon_deagle) return XorStr("Desert Eagle");
		if (ID == weapon_elite) return XorStr("Dual Berettas");
		if (ID == weapon_fiveseven) return XorStr("Five-SeveN");
		if (ID == weapon_glock) return XorStr("Glock-18");
		if (ID == weapon_ak47) return XorStr("AK-47");
		if (ID == weapon_aug) return XorStr("AUG");
		if (ID == weapon_awp) return XorStr("AWP");
		if (ID == weapon_famas) return XorStr("FAMAS");
		if (ID == weapon_g3sg1) return XorStr("G3SG1");
		if (ID == weapon_galilar) return XorStr("Galil AR");
		if (ID == weapon_m249) return XorStr("M249");
		if (ID == weapon_m4a1) return XorStr("M4A4");
		if (ID == weapon_mac10) return XorStr("MAC-10");
		if (ID == weapon_p90) return XorStr("P90");
		if (ID == weapon_ump) return XorStr("UMP-45");
		if (ID == weapon_xm1014) return XorStr("XM1014");
		if (ID == weapon_bizon) return XorStr("PP-Bizon");
		if (ID == weapon_mag7) return XorStr("MAG-7");
		if (ID == weapon_negev) return XorStr("Negev");
		if (ID == weapon_sawedoff) return XorStr("Sawed-Off");
		if (ID == weapon_tec9) return XorStr("Tec-9");
		if (ID == weapon_taser) return XorStr("Zeus");
		if (ID == weapon_hkp2000) return XorStr("P2000");
		if (ID == weapon_mp7) return XorStr("MP7");
		if (ID == weapon_mp9) return XorStr("MP9");
		if (ID == weapon_nova) return XorStr("Nova");
		if (ID == weapon_p250) return XorStr("P250");
		if (ID == weapon_scar20) return XorStr("SCAR-20");
		if (ID == weapon_sg556) return XorStr("SG-553");
		if (ID == weapon_ssg08) return XorStr("SSG-08");
		if (ID == weapon_knife) return XorStr("Knife");
		if (ID == weapon_flashbang) return XorStr("Flashbang");
		if (ID == weapon_hegrenade) return XorStr("HE Grenade");
		if (ID == weapon_smokegrenade) return XorStr("Smoke Grenade");
		if (ID == weapon_molotov) return XorStr("Molotov");
		if (ID == weapon_decoy) return XorStr("Decoy");
		if (ID == weapon_incgrenade) return XorStr("Incendiary");
		if (ID == weapon_c4) return XorStr("C4 Explosive");
		if (ID == weapon_knife_t) return XorStr("Knife");
		if (ID == weapon_m4a1_silencer) return XorStr("M4A1-S");
		if (ID == weapon_usp_silencer) return XorStr("USP-S");
		if (ID == weapon_cz75a) return XorStr("CZ75-Auto");
		if (ID == weapon_revolver) return XorStr("R8 Revolver");
		if (ID == weapon_bayonet) return XorStr("Bayonet");
		if (ID == weapon_knife_flip) return XorStr("Flip Knife");
		if (ID == weapon_knife_gut) return XorStr("Gut Knife");
		if (ID == weapon_knife_karambit) return XorStr("Karambit");
		if (ID == weapon_knife_m9_bayonet) return XorStr("M9 Bayonet");
		if (ID == weapon_knife_tactical) return XorStr("Huntsman Knife");
		if (ID == weapon_knife_falchion) return XorStr("Falchion Knife");
		if (ID == weapon_knife_survival_bowie) return XorStr("Bowie Knife");
		if (ID == weapon_knife_butterfly) return XorStr("Butterfly Knife");
		if (ID == weapon_knife_push) return XorStr("Shadow Daggers");
		return XorStr("");
	}
};