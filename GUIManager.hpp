#ifndef GUIManager_HPP
#define GUIManager_HPP

#include "SDL2/SDL.h"
#include <string>
#include <map>
#include "ECS/ECS.hpp"
#include "Game.hpp"

class GUIManager
{
    public:

        GUIManager(Manager* man);
        ~GUIManager();

        void newGUI(std::string id, bool isMenu);
        void newGUI(std::string id, bool isMenu, int sizeX, int sizeY);

        void toggleMenu(std::string id);

    private:

        Manager* manager;

        std::map<std::string, GUI*> GUIs;


        

};

class GUI
{
    public:

        std::string id;
        bool isMenu;
        bool isShowing = false;

        int sizeX;
        int sizeY;

        
};


#endif /* GUIManager_HPP */