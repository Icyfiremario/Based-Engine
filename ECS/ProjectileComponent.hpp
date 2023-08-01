#ifndef Projectile_hpp
#define Projectile_hpp

#include "ECS.hpp"
#include "Components.hpp"
#include "../Vector2D.hpp"
#include <plog/Log.h>

class ProjectileComponent : public Component
{
    public:

        ProjectileComponent(int rng, int sp, Vector2D vel) : range(rng), speed(sp), velocity(vel)
        {}
        ~ProjectileComponent()
        {}

        void init() override
        {
            transform = &entity->getComponent<TransformComponent>();
            transform->velocity = velocity;
        }

        void update() override
        {
            distance += speed;

            if(distance > range)
            {
                PLOGI << "Out of range";
                entity->destroy();
            }
            else if (transform->posititon.x > Game::camera.x + Game::camera.w || transform->posititon.x < Game::camera.x || transform->posititon.y > Game::camera.y + Game::camera.h || transform->posititon.y < Game::camera.y)
            {
                PLOGI << "Out of bounds";
                entity->destroy();
            }

        }

    private:

        TransformComponent* transform;

        int range = 0;
        int speed = 0;
        int distance = 0;
        Vector2D velocity;
};

#endif /* Projectile_hpp */