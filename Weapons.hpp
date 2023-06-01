#ifndef Weapons_hpp
#define Weapons_hpp

#include <string>
#include "SDL2/SDL.h"
#include "TextureManager.hpp"


//Defines the properties of a weapon
class Weapon
{
    public:

        float damage;
        bool isRanged;
        std::string weaponId;

        SDL_Texture* tex;

        Weapon();
        ~Weapon();

        Weapon(std::string id, float dmg, bool ranged, const char* path);

};

//Manages the weapons made
class WeaponManager
{
    public:

        void useWeapon(std::string id)
        {
            Weapon* selWeapon = Weapons[id];            
        }
        
        void addWeapon(std::string id, Weapon* weapon)
        {
            Weapons.emplace(id, weapon);
        }

    private:

        std::map<std::string, Weapon*> Weapons;
};

#endif /* Weapons_hpp */