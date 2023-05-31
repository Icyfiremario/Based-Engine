#ifndef GUI_HPP
#define GUI_HPP

#include "SDL2/SDL.h"
#include <string>

class GUI
{
    public:

        std::string name;
        bool menu;

        GUI(){}
        ~GUI(){}

        void newGUI(std::string guiName, bool isMenu)
        {
            name = guiName;
            menu = isMenu;

            
        }

};


#endif /* GUI_HPP */