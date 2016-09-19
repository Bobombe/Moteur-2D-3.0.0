#ifndef RECTANGULARCOLLIDER_H
#define RECTANGULARCOLLIDER_H

#include <collider.h>
#include <SFML/Graphics.hpp>


class RectangularCollider : public Collider
{
    public:
        RectangularCollider(sf::FloatRect rectHitBox = sf::FloatRect());
        virtual ~RectangularCollider();
        //Implementation pure virtual members

        virtual std::string getColliderName();
        virtual std::string getHitBoxType();// example : rectangular, spherical ...
        /**
        testCollisionWith :
        return : 1 if collision, 0 if not, -1 if it can't process the collision(doesn't know other->getBBoxType)
        */
        virtual int testCollisionWith(Collider * other, sf::Vector2f * collisionPoint = 0);
        /**
        applyCollitionWith define the reaction of this when touched by other
        */
        virtual int applyCollitionWith(Collider * other, float seconds, sf::Vector2f * collisionPoint = 0)=0;

        // Specifics to RectangularCollider
        void setRectHitBox(sf::FloatRect rectHitBox);
        sf::FloatRect getRectHitBox()
        {
            return m_rectHitBox;
        }
    protected:
        sf::FloatRect m_rectHitBox;
    private:
};

#endif // RECTANGULARCOLLIDER_H
