#include "gamescreen.h"
#include "persotest.h"
#include "gravityblock.h"

GameScreen::GameScreen()
{
    //ctor
    PersoTest * p = new PersoTest(&m_colMng, this);
    addMovable(p);
    m_colMng.addCollider(p);

    GravityBlock * o = new GravityBlock("ressources/platform.bmp", 40, 600, sf::IntRect(0, 0, 1000, 40));
    addMovable(o);
    m_colMng.addCollider(o);

    o = new GravityBlock("ressources/platform.bmp", 0, 0, sf::IntRect(0, 0, 40, 800));
    addMovable(o);
    m_colMng.addCollider(o);
    o = new GravityBlock("ressources/platform.bmp", 1000, 0, sf::IntRect(0, 0, 40, 800));
    addMovable(o);
    m_colMng.addCollider(o);
    o = new GravityBlock("ressources/platform.bmp", 500, 300, sf::IntRect(0, 0, 40, 40));
    addMovable(o);
    m_colMng.addCollider(o);
}

GameScreen::~GameScreen()
{
    //dtor
}

int GameScreen::update(float seconds)
{
    Screen::update(seconds);
    m_colMng.processCollisions(seconds);
    return 0;
}
