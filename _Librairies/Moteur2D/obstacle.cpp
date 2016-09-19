#include "obstacle.h"
#include "moteur2d.h"

Obstacle::Obstacle(std::string pathObstacleSprite, float posX, float posY, sf::IntRect subTextureRect) : MovableSprite(pathObstacleSprite, subTextureRect)
{
    //ctor
    setPosition(posX, posY);
}

Obstacle::~Obstacle()
{
    //dtor
}

int Obstacle::update(float seconds)
{
    // Code normalement à réimplanter dans les classes filles (ou appeler cette methode)
    // Application de l'accélération
    m_speed += m_acceleration*seconds;
    //Application de la vitesse
    m_position += m_speed*seconds;
    m_rectHitBox = sf::FloatRect(m_position.x, m_position.y, m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height);
    return 0;
}
