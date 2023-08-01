#ifndef Inventory_hpp
#define Inventory_hpp

#include <string>
#include <map>
#include "Components.hpp"
#include "../Item.hpp"

//Handles the items in the inventory
class Inventory : public Component
{
    public:

        bool isPlayer;

        size_t maxItems = 20;
        
        Inventory(){}
        ~Inventory(){}

        Inventory(bool isPlayer)
        {

        }

        void update()
        {

        }

        bool addItem(std::string id, Item* item)
        {
            if(sizeof(invItems) > maxItems)
            {
                PLOGW << "Inventory full could not add item";
                return false;
            }
            else
            {
                invItems.emplace(id, item);
                return true;
            }
        }

        bool checkHeld(std::string id)
        {
            if(invItems.count(id))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    
    private:

        std::map<std::string, Item*> invItems;

};





#endif /* Inventory_hpp */