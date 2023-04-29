#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include "Components.hpp"
#include "SDL2/SDL.h"
#include "../TextureManager.hpp"
#include "Animation.hpp"
#include <map>

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
        SpriteComponent(const char* path)
        {
            setTex(path);
        }

        SpriteComponent(const char* path, bool isAnimated)
        {
            animated = isAnimated;
            
            Animation idle = Animation(0, 3, 1500);
            Animation walk = Animation(1, 13, 150);

            animations.emplace("Idle", idle);
            animations.emplace("Walk", walk);

            Play("Idle");

            setTex(path);
        }

        ~SpriteComponent()
        {
            SDL_DestroyTexture(texture);
        }

        void setTex(const char* path)
        {
            texture = TextureManager::LoadTexture(path);
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
            }
            
            srcRect.y = animIndex * transform->height;

            destRect.x = static_cast<int>(transform->posititon.x);
            destRect.y = static_cast<int>(transform->posititon.y);
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


};

#endif /* SpriteComponent_hpp */