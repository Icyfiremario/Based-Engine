#ifndef UILable_hpp
#define UILable_hpp

#include "ECS.hpp"
#include "../AssetManager.hpp"
#include "../Game.hpp"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class UILable : public Component
{
    public:

        UILable(int xpos, int ypos, std::string text, std::string font, SDL_Color& color) : labelText(text), labelFont(font), textColor(color)
        {
            position.x = xpos;
            position.y = ypos;



        }
        ~UILable()
        {}

        void SetLabelText()
        {
            SDL_Surface* surf = TTF_RenderText_Blended(Game::assets->GetFont(labelFont), labelText.c_str(), textColor);
            labelTexture = SDL_CreateTextureFromSurface(Game::renderer, surf);
            SDL_FreeSurface(surf);

            SDL_QueryTexture(labelTexture, nullptr, nullptr, &position.w, &position.h);
        }

        void draw() override
        {
            SDL_RenderCopy(Game::renderer, labelTexture, nullptr, &position);
        }

    private:

        SDL_Rect position;
        std::string labelText;
        std::string labelFont;
        SDL_Color textColor;
        SDL_Texture* labelTexture;
};

#endif /* UILable_hpp */