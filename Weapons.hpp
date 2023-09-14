#ifndef Weapons_hpp
#define Weapons_hpp

#include <string>
#include "SDL2/SDL.h"
#include "TextureManager.hpp"
#include "ECS/Inventory.hpp"
#include "Item.hpp"


//Defines the properties of a weapon which extends the Item class
class Weapon : public Item
{
    public:

        float damage;
        bool ranged;

        SDL_Texture* tex;

        Weapon(float dmg, bool ranged, const char* texPath);
        ~Weapon();

        bool isRanged() { return ranged; }

};

//Manages the weapons made in the provided inventory
class WeaponManager
{
    public:

        WeaponManager(Inventory* inv);
        ~WeaponManager();

        void useWeapon(std::string id);

    private:

        Inventory* inventory = nullptr;

        bool checkHeld(std::string id);
        Weapon* getWeapon(std::string id);
};

#endif /* Weapons_hpp */