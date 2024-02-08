    #pragma once
    // GameVersion=v3.0.56.43
    // Updated 2/3/2024
     
constexpr long OFF_GRAPPLE_ACTIVE = 0x2c98;		      //
constexpr long OFF_GRAPPLE = 0x2c08;		              //
constexpr long OFF_GRAPPLE_ATTACHED = 0x0048;		      //
    // Core
    constexpr long OFF_REGION = 0x140000000;                      //[Static]->Region
    constexpr long OFF_LEVEL = 0x16d7de0;                         //[Miscellaneous]->LevelName
    constexpr long OFF_LOCAL_PLAYER = 0x2162818;                  //[Miscellaneous]->LocalPlayer
    constexpr long OFF_ENTITY_LIST = 0x1db4118;                   //[Miscellaneous]->cl_entitylist
        
    // Buttons
    constexpr long OFF_IN_ATTACK = 0x073ce9a0;                    //[Buttons]->in_attack
    constexpr long OFF_IN_JUMP = 0x073ceaa0;                      //[Buttons]->in_jump
    constexpr long OFF_IN_DUCK = 0x073ceba0;                      //[Buttons]->in_duck
    constexpr long OFFSET_IN_FORWARD = 0x073ce8f0;                   //[Buttons]->in_forward
    constexpr long OFFSET_TRAVERSAL_START_TIME = 0x2ac0;             //[Buttons]->m_traversalStartTime
    constexpr long OFFSET_TRAVERSAL_PROGRESS = 0x2abc;               //[Buttons]->m_traversalProgress
    constexpr long OFFSET_WALL_RUN_START_TIME = 0x3524;              //[Buttons]->m_wallRunStartTime
    constexpr long OOFFSET_WALL_RUN_CLEAR_TIME = 0x3528;              //[Buttons]->m_wallRunClearTime
        
    // Player
    constexpr long OFF_VIEW_MATRIX = 0x11a350;                    //[RecvTable.DT_Player]->ViewMatrix
    constexpr long OFF_VIEW_RENDER = 0x73cc3e0;                   //[RecvTable.DT_Player]->ViewRender
    constexpr long OFF_ZOOMING = 0x1b91;                          //[RecvTable.DT_Player]->m_bZooming
    constexpr long OFF_LOCAL_ORIGIN = 0x017c;                     //[DataMap.CBaseViewModel]->m_vecAbsOrigin
    constexpr long OFF_ABSVELOCITY = 0x0170;                      //[DataMap.C_BaseEntity]->m_vecAbsVelocity
    constexpr long OFF_TEAM_NUMBER = 0x030c;                      //[RecvTable.DT_BaseEntity]->m_iTeamNum
    constexpr long OFF_CURRENT_HEALTH = 0x02fc;                   //[RecvTable.DT_BaseEntity]->m_iHealth
    constexpr long OFF_CURRENT_SHIELDS = 0x01a0;                  //[RecvTable.DT_BaseEntity]->m_shieldHealth
    constexpr long OFF_NAME = 0x0449;                             //[RecvTable.DT_BaseEntity]->m_iName
    constexpr long OFF_SIGNIFIER_NAME = 0x0440;                   //[RecvTable.DT_BaseEntity]->m_iSignifierName
    constexpr long OFF_LIFE_STATE = 0x0658;                       //[RecvTable.DT_Player]->m_lifeState
    constexpr long OFF_BLEEDOUT_STATE = 0x26a0;                   //[RecvTable.DT_Player]->m_bleedoutState
    constexpr long OFF_LAST_VISIBLE_TIME = 0x194d + 0x3;          //[RecvTable.DT_BaseCombatCharacter]->m_hudInfo_visibilityTestAlwaysPasses + 0x3
    constexpr long OFF_LAST_AIMEDAT_TIME = 0x194d + 0x3 + 0x8;    //[RecvTable.DT_BaseCombatCharacter]->m_hudInfo_visibilityTestAlwaysPasses + 0x3 + 0x8
    constexpr long OFF_VIEW_ANGLES = 0x24f4 - 0x14;               //[DataMap.C_Player]->m_ammoPoolCapacity - 0x14
    constexpr long OFF_PUNCH_ANGLES = 0x23f8;                     //[DataMap.C_Player]->m_currentFrameLocalPlayer.m_vecPunchWeapon_Angle
    constexpr long OFF_BREATH_ANGLES = (OFF_VIEW_ANGLES - 0x10);
    constexpr long OFF_STUDIOHDR = 0xfb0;                         //[Miscellaneous]->CBaseAnimating!m_pStudioHdr
    constexpr long OFF_BONES = 0x0d60 + 0x48;                     //[RecvTable.DT_BaseAnimating]->m_nForceBone + 0x48
    constexpr long OFF_CAMERAORIGIN = 0x1e90;                     //[Miscellaneous]->CPlayer!camera_origin
    constexpr long OFF_MODELNAME = 0x0030;                        //[DataMap.C_BaseEntity]->m_ModelName     
    constexpr long OFF_NAMELIST = 0xc5eb2d0;                      //[Miscellaneous]->NameList
    constexpr long OFF_YAW = 0x21fc - 0x8;                        //[DataMap.C_Player]=>m_currentFramePlayer.m_ammoPoolCount - 0x8
    constexpr long OFF_NAMEINDEX = 0x0550;                        //[RecvTable.DT_BaseEntity]->m_instanceNameIndex
     
    // Weapon
    constexpr long OFF_WEAPON_HANDLE = 0x18f4;                    //[RecvTable.DT_BaseCombatCharacter]->m_latestPrimaryWeapons
    constexpr long OFF_WEAPON_INDEX = 0x1738;                     //[RecvTable.DT_WeaponX]->m_weaponNameIndex
    constexpr long OFFSET_AMMO = 0x1514;                      //[RecvTable.DT_PropSurvival]->m_ammoInClip
    constexpr long OFF_GRENADE_HANDLE = 0x1904;                   //[RecvTable.DT_Player]->m_latestNonOffhandWeapons
    constexpr long OFF_SKIN = 0x0d18;                             //[RecvTable.DT_BaseAnimating]->m_nSkin
    constexpr long OFF_WEAPON_DISCARDED = 0x1559;                 //[RecvTable.DT_WeaponX]->m_discarded
    constexpr long OFFSET_TIME_BASE = 0x2048;                        //[RecvTable.DT_Player]->m_currentFramePlayer.timeBase
     
    constexpr long OFF_PROJECTILESCALE = 0x04ec;                  //[WeaponSettings]->projectile_gravity_scale
    constexpr long OFF_PROJECTILESPEED = 0x04e4;                  //[WeaponSettings]->projectile_launch_speed
     
    // Glow
    constexpr long HIGHLIGHT_TYPE_SIZE = 0x34;
    constexpr long OFF_GLOW_ENABLE = 0x26c;                       //[DT_HighlightSettings].?
    constexpr long OFF_GLOW_THROUGH_WALL = 0x28c;                 //[DT_HighlightSettings].?
    constexpr long OFF_GLOW_FIX = 0x268;
    constexpr long OFF_GLOW_HIGHLIGHT_ID = 0x28C;                 //[DT_HighlightSettings].m_highlightServerActiveStates
    constexpr long OFF_GLOW_HIGHLIGHTS = 0xB93F2D0;
