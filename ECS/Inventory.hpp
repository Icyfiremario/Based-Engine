#ifndef Inventory_hpp
#define Inventory_hpp

#include <string>
#include <map>
#include "Components.hpp"
#include "./Item.hpp"
#include "./LimitedMap.hpp"

class Inventory : public Component
{
    public:

        bool isPlayer;
        
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
            
        }
    
    private:

        //LimitedMap<std::string, Item*> Items;

};





#endif /* Inventory_hpp */