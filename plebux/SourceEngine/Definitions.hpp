#pragma once

#include <Windows.h>

namespace SourceEngine
{
    typedef void* (*CreateInterfaceFn)(const char *pName, int *pReturnCode);
    typedef void* (*InstantiateInterfaceFn)();

    typedef unsigned int VPANEL;
    typedef void(*pfnDemoCustomDataCallback)(unsigned char *pData, size_t iSize);

    template<typename FuncType>
    inline FuncType CallVFunction(void* ppClass, DWORD index)
    {
        PDWORD pVTable = *(PDWORD*)ppClass;
        DWORD dwAddress = pVTable[index];
        return (FuncType)(dwAddress);
    }

    enum class FontFeature
    {
        FONT_FEATURE_ANTIALIASED_FONTS = 1,
        FONT_FEATURE_DROPSHADOW_FONTS = 2,
        FONT_FEATURE_OUTLINE_FONTS = 6,
    };

    enum class FontDrawType
    {
        FONT_DRAW_DEFAULT = 0,
        FONT_DRAW_NONADDITIVE,
        FONT_DRAW_ADDITIVE,
        FONT_DRAW_TYPE_COUNT = 2,
    };

    enum class FontFlags
    {
        FONTFLAG_NONE,
        FONTFLAG_ITALIC = 0x001,
        FONTFLAG_UNDERLINE = 0x002,
        FONTFLAG_STRIKEOUT = 0x004,
        FONTFLAG_SYMBOL = 0x008,
        FONTFLAG_ANTIALIAS = 0x010,
        FONTFLAG_GAUSSIANBLUR = 0x020,
        FONTFLAG_ROTARY = 0x040,
        FONTFLAG_DROPSHADOW = 0x080,
        FONTFLAG_ADDITIVE = 0x100,
        FONTFLAG_OUTLINE = 0x200,
        FONTFLAG_CUSTOM = 0x400,
        FONTFLAG_BITMAP = 0x800,
    };

	enum EFontFlags
	{
		FONTFLAG_NONE,
		FONTFLAG_ITALIC = 0x001,
		FONTFLAG_UNDERLINE = 0x002,
		FONTFLAG_STRIKEOUT = 0x004,
		FONTFLAG_SYMBOL = 0x008,
		FONTFLAG_ANTIALIAS = 0x010,
		FONTFLAG_GAUSSIANBLUR = 0x020,
		FONTFLAG_ROTARY = 0x040,
		FONTFLAG_DROPSHADOW = 0x080,
		FONTFLAG_ADDITIVE = 0x100,
		FONTFLAG_OUTLINE = 0x200,
		FONTFLAG_CUSTOM = 0x400,	// custom generated font -
	};

	enum ClientFrameStage
	{
		FRAME_UNDEFINED = -1,
		FRAME_START,
		FRAME_NET_UPDATE_START,
		FRAME_NET_UPDATE_POSTDATAUPDATE_START,
		FRAME_NET_UPDATE_POSTDATAUPDATE_END,
		FRAME_NET_UPDATE_END,
		FRAME_RENDER_START,
		FRAME_RENDER_END
	};

    enum class EntityFlags
    {
        FL_ONGROUND = (1 << 0),
        FL_DUCKING = (1 << 1),
        FL_WATERJUMP = (1 << 2),
        FL_ONTRAIN = (1 << 3),
        FL_INRAIN = (1 << 4),
        FL_FROZEN = (1 << 5),
        FL_ATCONTROLS = (1 << 6),
        FL_CLIENT = (1 << 7),
        FL_FAKECLIENT = (1 << 8)
    };

    enum class ClientFrameStage_t
    {
        FRAME_UNDEFINED = -1,
        FRAME_START,
        FRAME_NET_UPDATE_START,
        FRAME_NET_UPDATE_POSTDATAUPDATE_START,
        FRAME_NET_UPDATE_POSTDATAUPDATE_END,
        FRAME_NET_UPDATE_END,
        FRAME_RENDER_START,
        FRAME_RENDER_END
    };

    enum class LifeState
    {
        LIFE_ALIVE = 0,// alive
        LIFE_DYING = 1, // playing death animation or still falling off of a ledge waiting to hit ground
        LIFE_DEAD = 2 // dead. lying still.
    };

    enum EItemDefinitionIndex
    {
        weapon_deagle = 1,
        weapon_elite = 2,
        weapon_fiveseven = 3,
        weapon_glock = 4,
        weapon_ak47 = 7,
        weapon_aug = 8,
        weapon_awp = 9,
        weapon_famas = 10,
        weapon_g3sg1 = 11,
        weapon_galilar = 13,
        weapon_m249 = 14,
        weapon_m4a1 = 16,
        weapon_mac10 = 17,
        weapon_p90 = 19,
        weapon_ump = 24,
        weapon_xm1014 = 25,
        weapon_bizon = 26,
        weapon_mag7 = 27,
        weapon_negev = 28,
        weapon_sawedoff = 29,
        weapon_tec9 = 30,
        weapon_taser = 31,
        weapon_hkp2000 = 32,
        weapon_mp7 = 33,
        weapon_mp9 = 34,
        weapon_nova = 35,
        weapon_p250 = 36,
        weapon_scar20 = 38,
        weapon_sg556 = 39,
        weapon_ssg08 = 40,
        weapon_knife = 42,
        weapon_flashbang = 43,
        weapon_hegrenade = 44,
        weapon_smokegrenade = 45,
        weapon_molotov = 46,
        weapon_decoy = 47,
        weapon_incgrenade = 48,
        weapon_c4 = 49,
        weapon_knife_t = 59,
        weapon_m4a1_silencer = 60,
        weapon_usp_silencer = 61,
        weapon_cz75a = 63,
        weapon_revolver = 64,
        weapon_bayonet = 500,
        weapon_knife_flip = 505,
        weapon_knife_gut = 506,
        weapon_knife_karambit = 507,
        weapon_knife_m9_bayonet = 508,
        weapon_knife_tactical = 509,
        weapon_knife_falchion = 512,
        weapon_knife_survival_bowie = 514,
        weapon_knife_butterfly = 515,
        weapon_knife_push = 516
    };

    enum EClassIds
    {
		CAI_BaseNPC = 0U,
		CAK47 = 1U,
		CBaseAnimating = 2U,
		CBaseAnimatingOverlay = 3U,
		CBaseAttributableItem = 4U,
		CBaseButton = 5U,
		CBaseCombatCharacter = 6U,
		CBaseCombatWeapon = 7U,
		CBaseCSGrenade = 8U,
		CBaseCSGrenadeProjectile = 9U,
		CBaseDoor = 10U,
		CBaseEntity = 11U,
		CBaseFlex = 12U,
		CBaseGrenade = 13U,
		CBaseParticleEntity = 14U,
		CBasePlayer = 15U,
		CBasePropDoor = 16U,
		CBaseTeamObjectiveResource = 17U,
		CBaseTempEntity = 18U,
		CBaseToggle = 19U,
		CBaseTrigger = 20U,
		CBaseViewModel = 21U,
		CBaseVPhysicsTrigger = 22U,
		CBaseWeaponWorldModel = 23U,
		CBeam = 24U,
		CBeamSpotlight = 25U,
		CBoneFollower = 26U,
		CBreakableProp = 27U,
		CBreakableSurface = 28U,
		CC4 = 29U,
		CCascadeLight = 30U,
		CChicken = 31U,
		CColorCorrection = 32U,
		CColorCorrectionVolume = 33U,
		CCSGameRulesProxy = 34U,
		CCSPlayer = 35U,
		CCSPlayerResource = 36U,
		CCSRagdoll = 37U,
		CCSTeam = 38U,
		CDEagle = 39U,
		CDecoyGrenade = 40U,
		CDecoyProjectile = 41U,
		CDynamicLight = 42U,
		CDynamicProp = 43U,
		CEconEntity = 44U,
		CEconWearable = 45U,
		CEmbers = 46U,
		CEntityDissolve = 47U,
		CEntityFlame = 48U,
		CEntityFreezing = 49U,
		CEntityParticleTrail = 50U,
		CEnvAmbientLight = 51U,
		CEnvDetailController = 52U,
		CEnvDOFController = 53U,
		CEnvParticleScript = 54U,
		CEnvProjectedTexture = 55U,
		CEnvQuadraticBeam = 56U,
		CEnvScreenEffect = 57U,
		CEnvScreenOverlay = 58U,
		CEnvTonemapController = 59U,
		CEnvWind = 60U,
		CFEPlayerDecal = 61U,
		CFireCrackerBlast = 62U,
		CFireSmoke = 63U,
		CFireTrail = 64U,
		CFish = 65U,
		CFlashbang = 66U,
		CFogController = 67U,
		CFootstepControl = 68U,
		CFunc_Dust = 69U,
		CFunc_LOD = 70U,
		CFuncAreaPortalWindow = 71U,
		CFuncBrush = 72U,
		CFuncConveyor = 73U,
		CFuncLadder = 74U,
		CFuncMonitor = 75U,
		CFuncMoveLinear = 76U,
		CFuncOccluder = 77U,
		CFuncReflectiveGlass = 78U,
		CFuncRotating = 79U,
		CFuncSmokeVolume = 80U,
		CFuncTrackTrain = 81U,
		CGameRulesProxy = 82U,
		CHandleTest = 83U,
		CHEGrenade = 84U,
		CHostage = 85U,
		CHostageCarriableProp = 86U,
		CIncendiaryGrenade = 87U,
		CInferno = 88U,
		CInfoLadderDismount = 89U,
		CInfoOverlayAccessor = 90U,
		CItem_Healthshot = 91U,
		CKnife = 92U,
		CKnifeGG = 93U,
		CLightGlow = 94U,
		CMaterialModifyControl = 95U,
		CMolotovGrenade = 96U,
		CMolotovProjectile = 97U,
		CMovieDisplay = 98U,
		CParticleFire = 99U,
		CParticlePerformanceMonitor = 100U,
		CParticleSystem = 101U,
		CPhysBox = 102U,
		CPhysBoxMultiplayer = 103U,
		CPhysicsProp = 104U,
		CPhysicsPropMultiplayer = 105U,
		CPhysMagnet = 106U,
		CPlantedC4 = 107U,
		CPlasma = 108U,
		CPlayerResource = 109U,
		CPointCamera = 110U,
		CPointCommentaryNode = 111U,
		CPoseController = 112U,
		CPostProcessController = 113U,
		CPrecipitation = 114U,
		CPrecipitationBlocker = 115U,
		CPredictedViewModel = 116U,
		CProp_Hallucination = 117U,
		CPropDoorRotating = 118U,
		CPropJeep = 119U,
		CPropVehicleDriveable = 120U,
		CRagdollManager = 121U,
		CRagdollProp = 122U,
		CRagdollPropAttached = 123U,
		CRopeKeyframe = 124U,
		CSCAR17 = 125U,
		CSceneEntity = 126U,
		CSensorGrenade = 127U,
		CSensorGrenadeProjectile = 128U,
		CShadowControl = 129U,
		CSlideshowDisplay = 130U,
		CSmokeGrenade = 131U,
		CSmokeGrenadeProjectile = 132U,
		CSmokeStack = 133U,
		CSpatialEntity = 134U,
		CSpotlightEnd = 135U,
		CSprite = 136U,
		CSpriteOriented = 137U,
		CSpriteTrail = 138U,
		CStatueProp = 139U,
		CSteamJet = 140U,
		CSun = 141U,
		CSunlightShadowControl = 142U,
		CTeam = 143U,
		CTeamplayRoundBasedRulesProxy = 144U,
		CTEArmorRicochet = 145U,
		CTEBaseBeam = 146U,
		CTEBeamEntPoint = 147U,
		CTEBeamEnts = 148U,
		CTEBeamFollow = 149U,
		CTEBeamLaser = 150U,
		CTEBeamPoints = 151U,
		CTEBeamRing = 152U,
		CTEBeamRingPoint = 153U,
		CTEBeamSpline = 154U,
		CTEBloodSprite = 155U,
		CTEBloodStream = 156U,
		CTEBreakModel = 157U,
		CTEBSPDecal = 158U,
		CTEBubbles = 159U,
		CTEBubbleTrail = 160U,
		CTEClientProjectile = 161U,
		CTEDecal = 162U,
		CTEDust = 163U,
		CTEDynamicLight = 164U,
		CTEEffectDispatch = 165U,
		CTEEnergySplash = 166U,
		CTEExplosion = 167U,
		CTEFireBullets = 168U,
		CTEFizz = 169U,
		CTEFootprintDecal = 170U,
		CTEFoundryHelpers = 171U,
		CTEGaussExplosion = 172U,
		CTEGlowSprite = 173U,
		CTEImpact = 174U,
		CTEKillPlayerAttachments = 175U,
		CTELargeFunnel = 176U,
		CTEMetalSparks = 177U,
		CTEMuzzleFlash = 178U,
		CTEParticleSystem = 179U,
		CTEPhysicsProp = 180U,
		CTEPlantBomb = 181U,
		CTEPlayerAnimEvent = 182U,
		CTEPlayerDecal = 183U,
		CTEProjectedDecal = 184U,
		CTERadioIcon = 185U,
		CTEShatterSurface = 186U,
		CTEShowLine = 187U,
		CTesla = 188U,
		CTESmoke = 189U,
		CTESparks = 190U,
		CTESprite = 191U,
		CTESpriteSpray = 192U,
		CTest_ProxyToggle_Networkable = 193U,
		CTestTraceline = 194U,
		CTEWorldDecal = 195U,
		CTriggerPlayerMovement = 196U,
		CTriggerSoundOperator = 197U,
		CVGuiScreen = 198U,
		CVoteController = 199U,
		CWaterBullet = 200U,
		CWaterLODControl = 201U,
		CWeaponAug = 202U,
		CWeaponAWP = 203U,
		CWeaponBaseItem = 204U,
		CWeaponBizon = 205U,
		CWeaponCSBase = 206U,
		CWeaponCSBaseGun = 207U,
		CWeaponCycler = 208U,
		CWeaponElite = 209U,
		CWeaponFamas = 210U,
		CWeaponFiveSeven = 211U,
		CWeaponG3SG1 = 212U,
		CWeaponGalil = 213U,
		CWeaponGalilAR = 214U,
		CWeaponGlock = 215U,
		CWeaponHKP2000 = 216U,
		CWeaponM249 = 217U,
		CWeaponM3 = 218U,
		CWeaponM4A1 = 219U,
		CWeaponMAC10 = 220U,
		CWeaponMag7 = 221U,
		CWeaponMP5Navy = 222U,
		CWeaponMP7 = 223U,
		CWeaponMP9 = 224U,
		CWeaponNegev = 225U,
		CWeaponNOVA = 226U,
		CWeaponP228 = 227U,
		CWeaponP250 = 228U,
		CWeaponP90 = 229U,
		CWeaponSawedoff = 230U,
		CWeaponSCAR20 = 231U,
		CWeaponScout = 232U,
		CWeaponSG550 = 233U,
		CWeaponSG552 = 234U,
		CWeaponSG556 = 235U,
		CWeaponSSG08 = 236U,
		CWeaponTaser = 237U,
		CWeaponTec9 = 238U,
		CWeaponTMP = 239U,
		CWeaponUMP45 = 240U,
		CWeaponUSP = 241U,
		CWeaponXM1014 = 242U,
		CWorld = 243U,
		DustTrail = 244U,
		MovieExplosion = 245U,
		ParticleSmokeGrenade = 246U,
		RocketTrail = 247U,
		SmokeTrail = 248U,
		SporeExplosion = 249U,
		SporeTrail = 250U,
    };
}