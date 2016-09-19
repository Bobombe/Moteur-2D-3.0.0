#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <movablesprite.h>
#include "rectangularcollider.h"


class Obstacle : public MovableSprite, public RectangularCollider
{
    public:
        Obstacle(std::string pathObstacleSprite = "", float posX = 0, float posY = 0, sf::IntRect subTextureRect = sf::IntRect(-1, -1, -1, -1));
        virtual ~Obstacle();
        virtual int update(float seconds);
        virtual int applyCollitionWith(Collider * other, float seconds, sf::Vector2f * collisionPoint = 0){return 0;};
        virtual std::string getColliderName(){return "Obstacle";}
    protected:
    private:
};

#endif // OBSTACLE_H
