#include "screenmanager.h"

ScreenManager::ScreenManager()
{
    //ctor
}

ScreenManager::~ScreenManager()
{
    //dtor
    std::cout << "dest ScreenManager " << this << std::endl;
}


// Fonctions d'ajouts
void ScreenManager::addScreen(int k,Screen*s)
{
    m_screens[k] = s;
}
