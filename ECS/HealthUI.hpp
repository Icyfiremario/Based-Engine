#ifndef HealthUI_hpp
#define HealthUI_hpp

#include "ECS.hpp"
#include "Components.hpp"
#include "../Game.hpp"

class HealthUI : public Component
{
    public:

        int xpos;
        int ypos;
        int width;
        int height;
        float value;

        HealthUI()
        {}
        ~HealthUI()
        {}

        void HPBar(int xpos, int ypos, int width, int height, float value, SDL_Color FGColor, SDL_Color BGColor)
        {
            value = value > 1.f ? 1.f : value < 0.f ? 0.f : value;
            SDL_Color old;
            SDL_GetRenderDrawColor(Game::renderer, &old.r, &old.g, &old.g, &old.a);
            SDL_Rect bgrect = { xpos, ypos, width, height };
            SDL_SetRenderDrawColor(Game::renderer, BGColor.r, BGColor.g, BGColor.b, BGColor.a);
            SDL_RenderFillRect(Game::renderer, &bgrect);
            SDL_SetRenderDrawColor(Game::renderer, FGColor.r, FGColor.g, FGColor.b, FGColor.a);
            int pw = (int)((float)width * value);
            int px = xpos + (width - pw);
            SDL_Rect fgrect = { px, ypos, width, height };
            SDL_RenderFillRect(Game::renderer, &fgrect);
            SDL_SetRenderDrawColor(Game::renderer, old.r, old.g, old.b, old.a);
        }

    private:
};

#endif /* HealthUI_hpp */