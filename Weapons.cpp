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