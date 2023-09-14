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
            if(sizeof(invItems) == maxItems)
            {
                PLOGI << "Inventory full could not add item";
                return false;
            }

            if(invItems[id]->amountHeld == invItems[id]->stackLimit)
            {
                PLOGI << "Max amout of " << id << " held";
                return false;
            }

            invItems.emplace(id, item);
            return true;
            
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

        Item* getItem(std::string id)
        {
            if(!checkHeld(id))
            {
                return nullptr;
            }
            
            return invItems[id];
        }
    
    private:

        std::map<std::string, Item*> invItems;

};

#endif /* Inventory_hpp */