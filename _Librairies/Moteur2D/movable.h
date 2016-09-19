#ifndef MOVABLE_H
#define MOVABLE_H

#include "updatable.h"
#include "drawable.h"

class Movable : public Updatable, public Drawable
{
    public:
        Movable();
        virtual ~Movable();
        virtual int update(float seconds);
        virtual void draw(sf::Vector2f deltaPos = sf::Vector2f(0,0))=0;

        //Setters
        void setPosition(sf::Vector2f newPosition);
        void setPosition(float posX, float posY);
        void move(sf::Vector2f deltaPosition);
        void move(float deltaPosX, float deltaPosY);

        void setSpeed(sf::Vector2f newSpeed);
        void setSpeed(float speedX, float speedY);
        void increaseSpeed(sf::Vector2f deltaSpeed);
        void increaseSpeed(float deltaSpeedX, float deltaSpeedY);

        void setAcceleration(sf::Vector2f newAcceleration);
        void setAcceleration(float accelX, float accelY);
        void accelerate(sf::Vector2f deltaAcceleration);
        void accelerate(float deltaAccelX, float deltaAccelY);

        //GETTERS
        sf::Vector2f getPosition(){return m_position;}
        sf::Vector2f getSpeed(){return m_speed;}
        sf::Vector2f getAcceleration(){return m_acceleration;}

    protected:
        sf::Vector2f m_acceleration;
        sf::Vector2f m_speed;
        sf::Vector2f m_position;

    private:
};

#endif // MOVABLE_H
