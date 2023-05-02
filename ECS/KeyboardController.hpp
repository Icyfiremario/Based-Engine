#ifndef Keyboardcontroller_hpp
#define Keyboardcontroller_hpp

#include "../Game.hpp"
#include "ECS.hpp"
#include "Components.hpp"
#include "../MixerManager.hpp"

class KeyboardController : public Component
{
    public:
        TransformComponent *transform;
        SpriteComponent *sprite;
        MixerManager* mixer = new MixerManager;

        void init() override
        {
            transform = &entity->getComponent<TransformComponent>();
            sprite = &entity->getComponent<SpriteComponent>();
        }

        void update() override
        {
            if(Game::event.type == SDL_KEYDOWN)
            {
                switch (Game::event.key.keysym.sym)
                {
                case SDLK_w:
                    transform->velocity.y = -1;
                    setAnimation();
                    sprite->Play(animationID);
                    break;

                case SDLK_a:
                    transform->velocity.x = -1;
                    setAnimation();
                    sprite->Play(animationID);
                    sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
                    break;
                
                case SDLK_s:
                    transform->velocity.y = 1;
                    setAnimation();
                    sprite->Play(animationID);
                    break;

                case SDLK_d:
                    transform->velocity.x = 1;
                    setAnimation();
                    sprite->Play(animationID);
                    break;

                case SDLK_0:
                    mixer->PlaySFX("Shoot");
                    break;

                default:
                    break;
                }
            }
            if(Game::event.type == SDL_KEYUP)
            {
                switch (Game::event.key.keysym.sym)
                {
                case SDLK_w:
                    transform->velocity.y = 0;
                    sprite->Play("Idle");
                    break;

                case SDLK_a:
                    transform->velocity.x = 0;
                    sprite->Play("Idle");
                    sprite->spriteFlip = SDL_FLIP_NONE;
                    break;
                
                case SDLK_s:
                    transform->velocity.y = 0;
                    sprite->Play("Idle");
                    break;

                case SDLK_d:
                    transform->velocity.x = 0;
                    sprite->Play("Idle");
                    break;
                
                case SDLK_ESCAPE:
                    Game::isRunning = false;

                default:
                    break;
                }
            }
        }

    private:

        const char* animationID;

        void setAnimation()
        {
            if(entity->getComponent<TransformComponent>().Facing == "Right" || entity->getComponent<TransformComponent>().Facing == "Left")
            {
                animationID = "Walk Horiz";
                return;
            }
            else if(entity->getComponent<TransformComponent>().Facing == "Down")
            {
                animationID = "Walk Down";
                return;
            }
            else if(entity->getComponent<TransformComponent>().Facing == "Up")
            {
                animationID = "Walk Horiz";
            }
            else
            {
                animationID = "Walk Horiz";
            }
        }
};

#endif /* Keyboardcontroller_hpp */