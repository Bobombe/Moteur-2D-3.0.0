#include "screen.h"
#include "iostream"

Screen::Screen()
{
    //ctor
}

Screen::~Screen()
{
    //dtor
    std::cout << "dest Screen " << this << std::endl;
    for (unsigned int i = 0; i<m_updatables.size(); i++)
    {
        delete m_updatables[i];
    }
    for (unsigned int i = 0; i<m_drawables.size(); i++)
    {
        delete m_drawables[i];
    }
    for (unsigned int i = 0; i<m_movables.size(); i++)
    {
        delete m_movables[i];
    }
}

int Screen::update(float seconds)
{
    Movable::update(seconds);
    for (unsigned int i = 0; i < m_updatables.size(); i++)
    {
        m_updatables[i]->update(seconds);
    }
    for (unsigned int i = 0; i < m_movables.size(); i++)
    {
        m_movables[i]->update(seconds);
    }
    return 0;
}

void Screen::draw(sf::Vector2f deltaPos)
{
    for (unsigned int i = 0; i < m_drawables.size(); i++)
    {
        m_drawables[i]->draw(m_position+deltaPos);
    }
    for (unsigned int i = 0; i < m_movables.size(); i++)
    {
        m_movables[i]->draw(m_position+deltaPos);
    }
}

// Fonctions d'ajouts
void Screen::addUpdatable(Updatable*u)
{
    m_updatables.push_back(u);
}
void Screen::addDrawable(Drawable*d)
{
    m_drawables.push_back(d);
}
void Screen::addMovable(Movable*m)
{
    m_movables.push_back(m);
}

void Screen::deleteMovable(Movable*m)
{
    for (int i = 0; i<m_movables.size(); i++)
    {
        if (m==m_movables[i])
        {
            m_movables.erase(m_movables.begin()+i);
            return;
        }
    }
}
