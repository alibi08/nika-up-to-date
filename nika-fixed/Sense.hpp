#pragma once
struct Sense {
    ConfigLoader* cl;
    Level* m_level;
    LocalPlayer* m_localPlayer;
    std::vector<Player*>* m_players;
    const float TB_MAX_RANGE_ZOOMED = util::metersToGameUnits(100);
    const float TB_MAX_RANGE_HIPFRE = util::metersToGameUnits(8);

    Sense(ConfigLoader* configLoada, Level* level, LocalPlayer* localPlayer, std::vector<Player*>* players) {
        this->cl = configLoada;
        this->m_level = level;
        this->m_localPlayer = localPlayer;
        this->m_players = players;
    }

    void update(int counter)
    {
        int senseMaxRange = 250;
        int senseMaxRangeOverWall = 250;
        int gameMode = 0;
        if (!m_level->playable)
            return;
        
        for (int i = 0; i < m_players->size(); i++) {
            Player *player = m_players->at(i);
            if (!player->isValid())
                continue;
            
            if (player->friendly) {
                player->setGlowEnable(1);
                player->setGlowThroughWall(1);
                int healthShield = player->currentHealth + player->currentShields;
                player->setCustomGlow(healthShield, true, true);
                continue;
            }
            double distance = math::calculateDistanceInMeters(
                m_localPlayer->localOrigin.x,
                m_localPlayer->localOrigin.y, 
                m_localPlayer->localOrigin.z,
                player->localOrigin.x,
                player->localOrigin.y,
                player->localOrigin.z);
            if (player->visible && !player->knocked && distance < senseMaxRange) {
                player->setGlowEnable(1);
                player->setGlowThroughWall(1);
                int healthShield = player->currentHealth + player->currentShields;
                player->setCustomGlow(healthShield, true, false);
            } 
            if (!player->visible && !player->knocked && distance < senseMaxRange){
                player->setGlowEnable(1);
                player->setGlowThroughWall(1);  
                int healthShield = player->currentHealth + player->currentShields; 
                player->setCustomGlow(healthShield, true, false);
            } 
            else if (distance < senseMaxRangeOverWall) {
                player->setGlowEnable(1);
                player->setGlowThroughWall(1);
                player->setCustomGlow(0, false, false);
            } else if (player->getGlowEnable() == 1 && player->getGlowThroughWall() == 1) {
                player->setGlowEnable(0);
                player->setGlowThroughWall(0);
            }
        }
    }
};








    
