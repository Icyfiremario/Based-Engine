#ifndef Weapons_hpp
#define Weapons_hpp

#include <string>
#include "SDL2/SDL.h"
#include "TextureManager.hpp"
#include "ECS/Inventory.hpp"


//Defines the properties of a weapon
class Weapon
{
    public:

        std::string weaponId;
        float damage;
        bool ranged;

        SDL_Texture* tex;

        Weapon(std::string id, float dmg, bool ranged, const char* path);
        ~Weapon();

        bool isRanged() {return ranged;}

};

//Manages the weapons made
class WeaponManager
{
    public:

        WeaponManager(Inventory* inv);
        ~WeaponManager();

        void useWeapon(std::string id)
        {
            Weapon* selWeapon = Weapons[id];

            if(selWeapon->isRanged())
            {
                //do ranged things
            }
            else
            {
                //do melee things
            }
        }
        
        void addWeapon(std::string id, Weapon* weapon)
        {
            Weapons.emplace(id, weapon);
        }

    private:

        std::map<std::string, Weapon*> Weapons;
        Inventory* inventory = nullptr;

        bool checkHeld();
};

#endif /* Weapons_hpp */