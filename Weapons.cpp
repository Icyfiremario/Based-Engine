#include "Weapons.hpp"

Weapon::Weapon(float dmg, bool ranged, const char *texPath)
{
    if(ranged)
    {
        Id = "rangedWeapon";
    }
    else
    {
        Id = "meleeWeapon";
    }

    stackLimit = 1;
    
}

Weapon::~Weapon()
{}

WeaponManager::WeaponManager(Inventory *inv) : inventory(inv)
{
}

WeaponManager::~WeaponManager()
{
}

void WeaponManager::useWeapon(std::string id)
{
    Weapon* wep = WeaponManager::getWeapon(id);
    if(wep == nullptr)
    {
        PLOGI << "Weapon not avaible";
        return;
    }

    if(wep->ranged)
    {
        //do ranged things
        return;
    }

    //do melee things
    return;
}

bool WeaponManager::checkHeld(std::string id)
{
    if(inventory->checkHeld(id))
    {
        return true;
    }
    else
    {
        return false;
    }
}

Weapon *WeaponManager::getWeapon(std::string id)
{
    if(checkHeld(id))
    {
        
    }
    else
    {
        return nullptr;
    }
}
