#include "movable.h"
#include "iostream"

Movable::Movable()
{
    //ctor
}

Movable::~Movable()
{
    //dtor
    std::cout << "dest Movable " << this << std::endl;
}

int Movable::update(float seconds)
{
    // Code normalement à réimplanter dans les classes filles (ou appeler cette methode)
    // Application de l'accélération
    m_speed += m_acceleration*seconds;
    //Application de la vitesse
    m_position += m_speed*seconds;
    return 0;
}

        //Setters
void Movable::setPosition(sf::Vector2f newPosition)
{
    m_position = newPosition;
}
void Movable::setPosition(float posX, float posY)
{
    m_position = sf::Vector2f(posX, posY);
}
void Movable::move(sf::Vector2f deltaPosition)
{
    setPosition(m_position+deltaPosition);
}
void Movable::move(float deltaPosX, float deltaPosY)
{
    setPosition(m_position+sf::Vector2f(deltaPosX, deltaPosY));
}

void Movable::setSpeed(sf::Vector2f newSpeed)
{
    m_speed = newSpeed;
}
void Movable::setSpeed(float speedX, float speedY)
{
    m_speed = sf::Vector2f(speedX, speedY);
}
void Movable::increaseSpeed(sf::Vector2f deltaSpeed)
{
    setPosition(m_speed+deltaSpeed);
}
void Movable::increaseSpeed(float deltaSpeedX, float deltaSpeedY)
{
    setPosition(m_speed+sf::Vector2f(deltaSpeedX, deltaSpeedY));
}

void Movable::setAcceleration(sf::Vector2f newAcceleration)
{
    m_acceleration=newAcceleration;
}
void Movable::setAcceleration(float accelX, float accelY)
{
    m_acceleration = sf::Vector2f(accelX, accelY);
}
void Movable::accelerate(sf::Vector2f deltaAcceleration)
{
    setAcceleration(m_acceleration+deltaAcceleration);
}
void Movable::accelerate(float deltaAccelX, float deltaAccelY)
{
    setAcceleration(m_acceleration+sf::Vector2f(deltaAccelX, deltaAccelY));
}
