#include "GUIManager.hpp"

GUIManager::GUIManager(Manager* man)
{}

GUIManager::~GUIManager()
{}

void GUIManager::newGUI(std::string id, bool isMenu)
{
    GUIs.emplace(id, isMenu);
}

void GUIManager::newGUI(std::string id, bool isMenu, int sizeX, int sizeY)
{
    GUIs.emplace(id, isMenu, sizeX, sizeY);
    PLOGI << "New GUI created";
}

void GUIManager::toggleMenu(std::string id)
{
    GUI* gui = GUIs[id];

    if(!gui->isMenu)
    {
        gui->isShowing = !gui->isShowing;

        if(gui->isShowing)
        {
            SDL_ShowCursor(SDL_ENABLE);
        }
        else
        {
            SDL_ShowCursor(SDL_DISABLE);
        }

        PLOGI << "Menu Toggled to: " << gui->isShowing;
    }
    else
    {
        PLOGW << "Attempted to toggle non menu GUI";
    }
}