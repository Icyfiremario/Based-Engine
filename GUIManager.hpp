#ifndef GUIManager_HPP
#define GUIManager_HPP

#include "SDL2/SDL.h"
#include <string>
#include <map>
#include "ECS/ECS.hpp"
#include <plog/Log.h>



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

        std::string id = "";
        bool isMenu = false;
        bool isShowing = false;

        int sizeX = 0;
        int sizeY = 0;

        GUI();
        ~GUI();

        GUI(std::string id, bool isMenu);
        GUI(std::string id, bool isMenu, int sizeX, int sizeY);

        

        
};


#endif /* GUIManager_HPP */