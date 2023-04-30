#ifndef StatsComponent_hpp
#define StatsComponent_hpp

#include "ECS.hpp"
#include "Components.hpp"

class StatsComponent : public Component
{
    public:

        StatsComponent()
        {}
        ~StatsComponent();

    private:
    int health;
    int armour;
    int magic;
};

#endif /* StatsComponent_hpp */