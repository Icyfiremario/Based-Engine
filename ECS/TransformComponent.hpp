#ifndef PositionComponent_hpp
#define PositionComponent_hpp

#include "Components.hpp"
#include "../Vector2D.hpp"
#include <string>

struct TransformComponent : public Component
{
    public:

        Vector2D posititon;
        Vector2D velocity;

        int height = 32;
        int width = 32;
        int scale = 1;

        int speed = 3;

        bool blocked = false;

        std::string Facing = "Right";

        TransformComponent()
        {
            posititon.Zero();
        }

        TransformComponent(int sc)
        {
            posititon.Zero();
            scale = sc;
        }
        
        TransformComponent(float x, float y)
        {
            posititon.x = x;
            posititon.y = y;
        }

        TransformComponent(float x, float y, int h, int w, int sc)
        {
            posititon.x = x;
            posititon.y = y;
            height = h;
            width = w;
            scale = sc;
        }
        
        void init() override
        {
            velocity.Zero();
        }

        void update() override
        {
            posititon.x += velocity.x * speed;
            posititon.y += velocity.y * speed;

            if(velocity.x == 1 && velocity.y ==0)
            {
                Facing = "Right";
            }
            else if(velocity.x == -1 && velocity.y == 0)
            {
                Facing = "Left";
            }
            else if(velocity.x == 0 && velocity.y == 1)
            {
                Facing = "Up";
            }
            else if(velocity.x == 0 && velocity.y == -1)
            {
                Facing = "Down";
            }
        }

};

#endif /* PositionComponent_hpp */