#include "Item.hpp"
#include "ECS/Components.hpp"

Item::Item()
{
}

Item::~Item()
{}

Item::Item(std::string id, bool grabbable, bool stackable, int stackLimit) : Id(id), grabbable(grabbable)
{
    if(stackable)
    {
        Item::stackLimit = 1;
    }
    else
    {
        Item::stackLimit = stackLimit;
    }

    if(grabbable)
    {
        //do stuff to make grabbable
    }
}