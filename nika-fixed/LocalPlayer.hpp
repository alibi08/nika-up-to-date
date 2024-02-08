#pragma once
struct LocalPlayer {
    MyDisplay *display;
    uint64_t base;
    bool dead;
    bool knocked;
    int teamNumber;
    bool inAttack;
    bool inZoom;
    bool inJump;
    Vector3D localOrigin;
    Vector3D CameraPosition;
    Vector2D viewAngles;
    Vector2D punchAngles;
    Vector2D punchAnglesPrev;
    Vector2D punchAnglesDiff;
    int weaponIndex;

    long weaponEntity; 
    int grenadeID;
    int ammoInClip;
    int currentHealth;
    long weaponHandleMasked;
    float WeaponProjectileSpeed;
    long weaponHandle;
    float WeaponProjectileScale;
    float local_yaw;


    void reset() {
        base = 0;
    }

    void readFromMemory() {
        base = mem::Read<uint64_t>(OFF_REGION + OFF_LOCAL_PLAYER);
        if (base == 0) return;
        dead = mem::Read<short>(base + OFF_LIFE_STATE) > 0;
        knocked = mem::Read<short>(base + OFF_BLEEDOUT_STATE) > 0;
        inZoom = mem::Read<short>(base + OFF_ZOOMING) > 0;
        teamNumber = mem::Read<int>(base + OFF_TEAM_NUMBER);
        inAttack = mem::Read<bool>(OFF_REGION + OFF_IN_ATTACK) > 0;
        inJump = mem::Read<bool>(OFF_REGION + OFF_IN_JUMP) > 0;
        localOrigin = mem::Read<Vector3D>(base + OFF_LOCAL_ORIGIN);
        local_yaw = mem::Read<float>(base + OFF_YAW);

        currentHealth = mem::Read<int>(base + OFF_CURRENT_HEALTH);
        CameraPosition = mem::Read<Vector3D>(base + OFF_CAMERAORIGIN);
        viewAngles = mem::Read<Vector2D>(base + OFF_VIEW_ANGLES);
        punchAngles = mem::Read<Vector2D>(base + OFF_PUNCH_ANGLES);
        punchAnglesDiff = punchAnglesPrev.Subtract(punchAngles);
        punchAnglesPrev = punchAngles;
        if (!dead && !knocked) {
            weaponHandle = mem::Read<long>(base + OFF_WEAPON_HANDLE);
            weaponHandleMasked = weaponHandle & 0xffff;
            grenadeID = mem::Read<int>(base + OFF_GRENADE_HANDLE);
            weaponEntity = mem::Read<long>(OFF_REGION + OFF_ENTITY_LIST + (weaponHandleMasked << 5));
            ammoInClip = mem::Read<int>(weaponEntity + OFFSET_AMMO);     
            weaponIndex = mem::Read<int>(weaponEntity + OFF_WEAPON_INDEX);
            WeaponProjectileSpeed = mem::Read<float>(weaponEntity + OFF_PROJECTILESPEED);
            WeaponProjectileScale = mem::Read<float>(weaponEntity + OFF_PROJECTILESCALE); 
              
        }
    }
    bool isValid() {
        return base != 0;
    }
    bool isCombatReady() {
        if (base == 0) return false;
        if (dead) return false;
        if (knocked) return false;
        return true;
    }
    void setYaw(float angle)
    {
        long ptrLong = base + OFF_VIEW_ANGLES + sizeof(float);
        mem::Write<float>(ptrLong, angle);
    }
};