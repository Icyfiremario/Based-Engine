#ifndef Projectile_hpp
#define Projectile_hpp

#include "ECS.hpp"
#include"Components.hpp"

class ProjectileComponent : public Component
{
    public:

        ProjectileComponent(int rng, int sp) : range(rng), speed(sp)
        {}
        ~ProjectileComponent();

        void init() override
        {
            transform = &entity->getComponent<TransformComponent>();
        }

        void update() override
        {
            distance += speed;

            if(distance > range)
            {
                entity->destroy();
            }
            else if (transform->posititon.x > Game::camera.x + Game::camera.w || transform->posititon.x < Game::camera.x || transform->posititon.y > Game::camera.y + Game::camera.h || transform->posititon.y < Game::camera.y)
            {
                entity->destroy();
            }

        }

    private:

        TransformComponent* transform;

        int range = 0;
        int speed = 0;
        int distance = 0;
};

#endif /* Projectile_hpp */