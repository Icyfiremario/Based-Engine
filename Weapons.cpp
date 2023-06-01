#include "Weapons.hpp"

Weapon::Weapon()
{}
Weapon::~Weapon()
{}

Weapon::Weapon(std::string id, float dmg, bool ranged, const char* path) : weaponId(id), damage(dmg), isRanged(ranged)
{
    TextureManager::LoadTexture(path);
}

