#include "movablesprite.h"
#include "moteur2d.h"

MovableSprite::MovableSprite(std::string texturePath, sf::IntRect subTextureRect)
{
    //ctor
    setSprite(texturePath, subTextureRect);
}

MovableSprite::~MovableSprite()
{
    //dtor
    if (m_texturePath!="")
        Moteur2D::getInstance()->unloadTexture(m_texturePath);
}


void MovableSprite::draw(sf::Vector2f deltaPos)
{
    m_sprite.setPosition(m_position+deltaPos);
    Moteur2D::getInstance()->getWindow().draw(m_sprite);
}

void MovableSprite::setSprite(std::string texturePath, sf::IntRect subTextureRect)
{
    sf::Texture * t = 0;
    if(texturePath != "")
    {
        if(m_texturePath != texturePath) // Changement de texture
        {
            if (m_texturePath != "")
            {
                Moteur2D::getInstance()->unloadTexture(m_texturePath);
            }
            m_texturePath = texturePath;
            t = Moteur2D::getInstance()->getTexture(m_texturePath);
            m_sprite.setTexture(*t);
        }
    }
    if (subTextureRect.left!=-1) // changement du rectangle
    {
        if(t && (subTextureRect.width>t->getSize().x || subTextureRect.height>t->getSize().y))
        {
            t->setRepeated(true);
        }
        m_sprite.setTextureRect(subTextureRect);
    }
}
