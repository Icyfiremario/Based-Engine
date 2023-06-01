#ifndef Inventory_hpp
#define Inventory_hpp

#include <string>
#include <map>
#include "Components.hpp"
#include "../Item.hpp"

class Inventory : public Component
{
    public:

        bool isPlayer;

        int maxItems = 20;
        
        Inventory(){}
        ~Inventory(){}

        Inventory(bool isPlayer)
        {

        }

        void update()
        {

        }

        void addItem(std::string id, Item* item)
        {
            if(sizeof(invItems) > maxItems)
            {
                PLOGW << "Inventory full could not add item";
                return;
            }
            else
            {
                invItems.emplace(id, item);
            }
        }
    
    private:

        std::map<std::string, Item*> invItems;

};





#endif /* Inventory_hpp */