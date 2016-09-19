#include "keyboardlistener.h"

#include "moteur2d.h"
#include "iostream"
KeyboardListener::KeyboardListener()
{
    //ctor
    m_id = Moteur2D::getInstance()->addKeyboardListener(this);
}

KeyboardListener::~KeyboardListener()
{
    std::cout << "dest KeyboardListener" << this << std::endl;
    Moteur2D::getInstance()->deleteKeyboardListener(m_id);
}
