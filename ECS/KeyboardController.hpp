#ifndef Keyboardcontroller_hpp
#define Keyboardcontroller_hpp

#include "../Game.hpp"
#include "ECS.hpp"
#include "Components.hpp"
#include "../MixerManager.hpp"
#include <SDL2/SDL_gamecontroller.h>

class KeyboardController : public Component
{
    public:
        TransformComponent *transform;
        SpriteComponent *sprite;
        MixerManager* mixer = new MixerManager;
        SDL_Joystick* controller = NULL;

        void init() override
        {
            transform = &entity->getComponent<TransformComponent>();
            sprite = &entity->getComponent<SpriteComponent>();
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
                    //sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
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
                    //sprite->spriteFlip = SDL_FLIP_NONE;
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
                    //entity->getComponent<WeaponComponenet>().UseWeapon(false);
                }
                if(SDL_JoystickGetButton(controller, 9))
                {
                    std::cout << "Closing" << std::endl;
                    Game::isRunning = false;
                }
                
            }
            if(Game::event.type == SDL_JOYAXISMOTION)
            {
                if(SDL_JoystickGetAxis(controller, 0))
                {
                    if(SDL_JoystickGetAxis(controller, 0) >= 32767)
                    {
                        transform->velocity.x = 1;
                    }
                    if(SDL_JoystickGetAxis(controller, 0) <= -32767)
                    {
                        transform->velocity.x = -1;
                        //sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
                    }
                    if(SDL_JoystickGetAxis(controller, 0) == -256)
                    {
                        transform->velocity.x = 0;
                    }

                }
                if(SDL_JoystickGetAxis(controller, 1))
                {
                    if(SDL_JoystickGetAxis(controller, 1) >= 32767)
                    {
                        transform->velocity.y = 1;
                    }
                    if(SDL_JoystickGetAxis(controller, 1) <= -32767)
                    {
                        transform->velocity.y = -1;
                    }
                    if(SDL_JoystickGetAxis(controller, 1) == -256)
                    {
                        transform->velocity.y = 0;
                    }   
                }
            }
        }
    
    private:

        void SetUpController()
        {

            int numJoysticks = SDL_NumJoysticks();

            if(numJoysticks == 0)
            {
                std::cout << "Controller disconnected!" << std::endl;
            }
            else
            {
                for(int i = 0; i < numJoysticks; i++)
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