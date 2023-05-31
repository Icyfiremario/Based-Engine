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

GUI* GUIManager::toggleMenu(std::string id)
{
    GUI* gui = GUIs[id];

    if(!gui->isMenu)
    {
        PLOGI << "Menu Toggled";
    }
    else
    {
        PLOGW << "Attempted to toggle non menu GUI";
    }
}