#include "Item.hpp"
#include "ECS/Components.hpp"

Item::Item()
{}
Item::~Item()
{}

Item::Item(std::string id, bool grabable, bool weapon, bool stackable, int stackLimit)
{
    Item::id = id;
    Item::grabable = grabable;
    Item::weapon = weapon;
    Item::stackable = stackable;
    Item::stackLimit = stackLimit;

    if(weapon)
    {
        //Create new weapon with new wepon class. TODO make weapon class and change weapon component to use weapon class
    }

}