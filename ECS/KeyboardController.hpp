#ifndef Keyboardcontroller_hpp
#define Keyboardcontroller_hpp

#include "../Game.hpp"
#include "ECS.hpp"
#include "Components.hpp"
#include "../MixerManager.hpp"
#include <SDL2/SDL_gamecontroller.h>
#include "WeaponComponent.hpp"

class KeyboardController : public Component
{
    public:
        TransformComponent *transform;
        SpriteComponent *sprite;
        WeaponComponenet* weapons;
        MixerManager* mixer = new MixerManager;
        SDL_Joystick* controller = NULL;

        void init() override
        {
            transform = &entity->getComponent<TransformComponent>();
            sprite = &entity->getComponent<SpriteComponent>();
            weapons = &entity->getComponent<WeaponComponenet>();

        }

        void update() override
        {
            SDL_JoystickUpdate();
            if(Game::event.type == SDL_JOYDEVICEADDED)
            {
                SetUpController();
            }
            if(Game::event.type == SDL_JOYDEVICEREMOVED)
            {
                controller = nullptr;
                std::cout << "Controller disconnected!" << std::endl;
            }
            if(Game::event.type == SDL_KEYDOWN)
            {
                switch (Game::event.key.keysym.sym)
                {
                case SDLK_w:
                    transform->velocity.y = -1;
                    break;

                case SDLK_a:
                    transform->velocity.x = -1;
                    sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
                    break;
                
                case SDLK_s:
                    transform->velocity.y = 1;
                    break;

                case SDLK_d:
                    transform->velocity.x = 1;
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
                    break;

                case SDLK_a:
                    transform->velocity.x = 0;
                    sprite->spriteFlip = SDL_FLIP_NONE;
                    break;
                
                case SDLK_s:
                    transform->velocity.y = 0;
                    break;

                case SDLK_d:
                    transform->velocity.x = 0;
                    break;
                
                case SDLK_ESCAPE:
                    Game::isRunning = false;

                default:
                    break;
                }
            }
            if(Game::event.type == SDL_JOYBUTTONDOWN)
            {
                
                if(SDL_JoystickGetButton(controller, 0))
                {
                    std::cout << "B button pressed" << std::endl;
                }
                if(SDL_JoystickGetButton(controller, 1))
                {
                    std::cout << "A button pressed" << std::endl;
                }
                
            }
            if(Game::event.type == SDL_JOYAXISMOTION)
            {
                if(SDL_JoystickGetAxis(controller, 0))
                {
                    if(SDL_JoystickGetAxis(controller, 0) >= 32767)
                    {
                        std::cout << "Dpad Right" << std::endl;
                    }
                    if(SDL_JoystickGetAxis(controller, 0) <= -32767)
                    {
                        std::cout << "Dpad left" << std::endl;
                    }

                }
                if(SDL_JoystickGetAxis(controller, 1))
                {
                    if(SDL_JoystickGetAxis(controller, 1) >= 32767)
                    {
                        std::cout << "Dpad Down" << std::endl;
                    }
                    if(SDL_JoystickGetAxis(controller, 1) <= -32767)
                    {
                        std::cout << "Dpad Up" << std::endl;
                    }   
                }
            }
            
        }
    
    private:

        void SetUpController()
        {
            if(SDL_NumJoysticks == 0)
            {
                std::cout << "Controller disconnected!" << std::endl;
            }
            else
            {
                for(int i = 0; i < SDL_NumJoysticks(); i++)
                {
                    if(SDL_IsGameController(i))
                    {
                      controller = SDL_JoystickOpen(i);
                      std::cout << "Controller Connected!" << std::endl;
                      break;
                    }
                }
                if(controller == NULL)
                {
                    std::cout << "ERROR: could not open game controller" << std::endl;
                }
            
            }
            
            
        }


    
};

#endif /* Keyboardcontroller_hpp */