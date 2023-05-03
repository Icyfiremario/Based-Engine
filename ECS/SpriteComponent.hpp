#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include "Components.hpp"
#include "SDL2/SDL.h"
#include "../TextureManager.hpp"
#include "Animation.hpp"
#include <map>
#include "../AssetManager.hpp"

class SpriteComponent : public Component
{
    private:
    
        TransformComponent *transform;
        SDL_Texture *texture;
        SDL_Rect srcRect, destRect;

        bool animated = false;
        int frames = 0;
        int speed = 100;

    public: 

        int animIndex = 0;

        std::map<const char*, Animation> animations;

        SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

        SpriteComponent() = default;
        SpriteComponent(std::string id)
        {
            setTex(id);
        }

        SpriteComponent(std::string id, bool isAnimated)
        {
            animated = isAnimated;
            
            Animation idle = Animation(0, 3, 1500);
            Animation walkHoriz = Animation(1, 13, 150);
            Animation walkDown = Animation(2, 13, 150);
            Animation walkUp = Animation(3, 13, 150);

            animations.emplace("Idle", idle);
            animations.emplace("Walk Horiz", walkHoriz);
            animations.emplace("Walk Down", walkDown);
            animations.emplace("Walk Up", walkUp);

            Play("Idle");

            setTex(id);
        }

        ~SpriteComponent()
        {
        }

        void setTex(std::string id)
        {
            texture = Game::assets->GetTexture(id);
        }

        void init() override
        {
            
            transform = &entity->getComponent<TransformComponent>();

            srcRect.x = srcRect.y = 0;
            srcRect.w = transform->width;
            srcRect.h = transform->height;

            destRect.w = transform->width * transform->scale;
            destRect.h = transform->height * transform->scale;
            
        }

        void update() override
        {
            if(animated)
            {
                srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
                setAnimation();
            }
            
            srcRect.y = animIndex * transform->height;

            destRect.x = static_cast<int>(transform->posititon.x) - Game::camera.x;
            destRect.y = static_cast<int>(transform->posititon.y) - Game::camera.y;
            destRect.w = transform->width * transform->scale;
            destRect.h = transform->height * transform->scale;
        }

        void draw() override
        {
            TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
        }

        void Play(const char* animName)
        {
            frames = animations[animName].frames;
            animIndex = animations[animName].index;
            speed = animations[animName].speed;
        }

    private:

        void setAnimation()
        {
            if(entity->getComponent<TransformComponent>().velocity.x == 0 && entity->getComponent<TransformComponent>().velocity.y == 0)
            {
                Play("Idle");
                return;
            }
            else if((entity->getComponent<TransformComponent>().velocity.x == 1 && entity->getComponent<TransformComponent>().velocity.y == 0) || (entity->getComponent<TransformComponent>().velocity.x == -1 && entity->getComponent<TransformComponent>().velocity.y == 0))
            {
                Play("Walk Horiz");
                return;
            }
            else if(entity->getComponent<TransformComponent>().velocity.x == 0 && entity->getComponent<TransformComponent>().velocity.y == 1)
            {
                Play("Walk Down");
                return;
            }
            else if(entity->getComponent<TransformComponent>().velocity.x == 0 && entity->getComponent<TransformComponent>().velocity.y == -1)
            {
                Play("Walk Up");
                return;
            }

        }


};

#endif /* SpriteComponent_hpp */

//entity->getComponent<TransformComponent>().velocity.x == 1 && entity->getComponent<TransformComponent>().velocity.y == 0
//entity->getComponent<TransformComponent>().velocity.x == 0 && entity->getComponent<TransformComponent>().velocity.y == 0