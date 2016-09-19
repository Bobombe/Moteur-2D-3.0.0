#ifndef COLLIDER_H
#define COLLIDER_H

#include "string"
#include <SFML/Graphics.hpp>


class Collider
{
    public:
        Collider();
        virtual ~Collider();
        virtual std::string getColliderName()=0;
        virtual std::string getHitBoxType()=0;// example : rectangular, spherical ...
        /**
        testCollisionWith :
        return : 1 if collision, 0 if not, -1 if it can't process the collision(doesn't know other->getBBoxType)
        */
        virtual int testCollisionWith(Collider * other, sf::Vector2f * collisionPoint = 0) = 0 ;
        /**
        applyCollitionWith define the reaction of this when touched by other
        */
        virtual int applyCollitionWith(Collider * other, float seconds, sf::Vector2f * collisionPoint = 0) = 0 ;
    protected:
    private:
};

#endif // COLLIDER_H
