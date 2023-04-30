#ifndef StatsComponent_hpp
#define StatsComponent_hpp

#include "ECS.hpp"
#include "Components.hpp"

class StatsComponent : public Component
{
    public:

        int health;
        int armour;
        int magic;

        StatsComponent(int hp, int ap, int mp)
        {
            health = hp;
            armour = ap;
            magic = mp;
        }
        ~StatsComponent();
        
};

#endif /* StatsComponent_hpp */