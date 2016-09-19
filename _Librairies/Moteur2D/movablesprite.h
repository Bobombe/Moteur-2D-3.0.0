#ifndef MOVABLESPRITE_H
#define MOVABLESPRITE_H

#include <movable.h>


class MovableSprite : public Movable
{
    public:
        MovableSprite(std::string texturePath = "", sf::IntRect subTextureRect = sf::IntRect(-1, -1, -1, -1));
        virtual ~MovableSprite();
        virtual void draw(sf::Vector2f deltaPos = sf::Vector2f(0,0));
        void setSprite(std::string texturePath, sf::IntRect subTextureRect = sf::IntRect(-1, -1, -1, -1));
    protected:
        sf::Sprite m_sprite;
        std::string m_texturePath;
    private:
};

#endif // MOVABLESPRITE_H
