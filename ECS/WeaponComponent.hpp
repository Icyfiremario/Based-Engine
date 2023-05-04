#ifndef WeaponComponent_hpp
#define WeaponComponent_hpp

#include "ECS.hpp"
#include "Components.hpp"
#include <string>
#include <map>
#include "../AssetManager.hpp"
#include "../Game.hpp"
#include "../Vector2D.hpp"
#include "../TextureManager.hpp"

class WeaponComponenet : public Component
{
    public:

        int range = 0;
        int damage = 0;
        int speed = 0;
        bool ranged = false;
        std::string id;

        WeaponComponenet(int dmg, int rng, int sp)
        {
            damage = dmg;
            range = rng;
            speed = sp;
        }
        
        ~WeaponComponenet()
        {}


        void UseWeapon(bool rngd)
        {
            if(rngd)
            {
                entityPosition = entity->getComponent<TransformComponent>().posititon;
                if(entity->getComponent<TransformComponent>().Facing == "UP")
                {
                    facingVector = {0, 1};
                }
                else if(entity->getComponent<TransformComponent>().Facing == "Down")
                {
                    facingVector = {0, -1};
                }
                else if (entity->getComponent<TransformComponent>().Facing == "Right")
                {
                    facingVector = {1, 0};
                }
                else if (entity->getComponent<TransformComponent>().Facing == "Left")
                {
                    facingVector = {-1, 0};
                }
                Game::assets->CreateProjectile(entityPosition, facingVector, range, speed, id);
                
            }
        }

    private:
        
        Vector2D facingVector;
        Vector2D entityPosition;


};

#endif /* WeaponComponent_hpp */