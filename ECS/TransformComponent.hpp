#ifndef PositionComponent_hpp
#define PositionComponent_hpp

#include "Components.hpp"
#include "../Vector2D.hpp"

struct TransformComponent : public Component
{
    public:

        Vector2D posititon;
        Vector2D velocity;

        int height = 32;
        int width = 32;
        int scale = 1;

        int speed = 3;

        TransformComponent()
        {
            posititon.Zero();
        }

        TransformComponent(int sc)
        {
            posititon.x = 400;
            posititon.y = 320;
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
            
        }

};

#endif /* PositionComponent_hpp */