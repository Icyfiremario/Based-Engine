#include "Weapons.hpp"

Weapon::Weapon(std::string id, float dmg, bool ranged, const char* path) : weaponId(id), damage(dmg), ranged(ranged)
{
    TextureManager::LoadTexture(path);
}

Weapon::~Weapon()
{}

WeaponManager::WeaponManager(Inventory *inv) : inventory(inv)
{
}

WeaponManager::~WeaponManager()
{
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
