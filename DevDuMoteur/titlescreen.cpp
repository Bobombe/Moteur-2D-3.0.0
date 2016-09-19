#include "titlescreen.h"
#include "moteur2d.h"
#include "iostream"

TitleScreen::TitleScreen()
{
    //ctor
    m_state = -1;
    m_pathBackgroundScreen = "";
}

TitleScreen::~TitleScreen()
{
    //dtor
    std::cout << "dest TitleScreen " << this << std::endl;
    Moteur2D::getInstance()->unloadTexture(m_pathBackgroundScreen);
}

void TitleScreen::init(std::string pathBackgroundScreen)
{
    m_pathBackgroundScreen = pathBackgroundScreen;
    if(pathBackgroundScreen != "")
    {
        m_background.setTexture(*Moteur2D::getInstance()->getTexture(pathBackgroundScreen));
        m_state = 0;
        m_position.y = -Moteur2D::getInstance()->getScreenSize().y;
        m_background.setPosition(0, m_position.y);

    }
}

int TitleScreen::update(float seconds)
{
    Screen::update(seconds);
    if(m_state == 1 && m_position.y<0)//m_background.getPosition().y<0)
    {
        m_background.setPosition(0, m_position.y);
    }
    if(m_position.y>0)
    {
        m_position.y = 0;
        m_speed.y = 0;
        m_state = 2;
        m_background.setPosition(0, 0);
    }
    if(m_state==0)
    {
        m_state=1;
        m_speed.y = 600;
    }

    return m_state;
}

void TitleScreen::draw(sf::Vector2f deltaPos)
{
    if(m_state >= 0)
    {
        Moteur2D::getInstance()->getWindow().draw(m_background);
    }

    Screen::draw(deltaPos);
}

// KEYBOARD
void TitleScreen::keyPressed(sf::Keyboard::Key k)
{
    if(m_state == 2)
    {
        if(k==sf::Keyboard::Return)
        {
            m_state = 3;
        }
    }

}
void TitleScreen::keyReleased(sf::Keyboard::Key k)
{
}
