#ifndef Item_hpp
#define Item_hpp

#include <string>
#include "TextureManager.hpp"

class Item
{
    public:
        
        std::string id;
        bool grabable;
        bool stackable;
        bool weapon;
        
        int stackLimit;
        int amountHeld;

        SDL_Texture* tex;

        Item();
        ~Item();

        Item(std::string id, bool grabable, bool weapon, bool stackable, int stackLimit);

};

#endif /* Item_hpp */