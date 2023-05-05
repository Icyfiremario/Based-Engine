#ifndef StatsComponent_hpp
#define StatsComponent_hpp

#include "ECS.hpp"
#include "Components.hpp"


//Handles health and armour and will trigger the Game over screen
class StatsComponent : public Component
{
    public:

        float totalHealth;
        float curHP;
        int armour;
        float totalMagic;
        float curMP;
        bool player;

        StatsComponent()
        {}
        ~StatsComponent()
        {}

        StatsComponent(int hp, int ap, int mp, bool isPLayer)
        {
            totalHealth = curHP = hp;
            armour = ap;
            totalMagic = curMP = mp;
            player = isPLayer;
        }

        void update() override
        {
            if(curHP == 0)
            {
                GameOver();
            }
        }

        void GameOver()
        {
            std::cout << "Game Over" << std::endl;
        }
        
};

#endif /* StatsComponent_hpp */