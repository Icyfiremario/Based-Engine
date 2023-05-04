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
                entityPosition.x = entity->getComponent<TransformComponent>().posititon.x + 20;
                entityPosition.y = entity->getComponent<TransformComponent>().posititon.y;
                if(entity->getComponent<TransformComponent>().Facing == "UP")
                {
                    facingVector.x = 0;
                    facingVector.y = 1;
                }
                else if(entity->getComponent<TransformComponent>().Facing == "Down")
                {
                    facingVector.x = 0;
                    facingVector.y = -1;
                }
                else if (entity->getComponent<TransformComponent>().Facing == "Right")
                {
                    facingVector.x = 1;
                    facingVector.y = 0;
                }
                else if (entity->getComponent<TransformComponent>().Facing == "Left")
                {
                    facingVector.x = -1;
                    facingVector.y = 0;
                }
                Game::assets->CreateProjectile(entityPosition, facingVector, range, speed, "Ball");
                
            }
            else
            {
                std::cout << "Melee used" << std::endl;
            }
        }

    private:
        
        Vector2D facingVector;
        Vector2D entityPosition;


};

#endif /* WeaponComponent_hpp */