#ifndef GRAVITYBLOCK_H
#define GRAVITYBLOCK_H

#include <obstacle.h>


class GravityBlock : public Obstacle
{
    public:
        GravityBlock(std::string pathObstacleSprite = "", float posX = 0, float posY = 0, sf::IntRect subTextureRect = sf::IntRect(-1, -1, -1, -1));
        virtual ~GravityBlock();
        sf::Vector2f calculateGField(sf::Vector2f position);
        virtual std::string getColliderName(){return "GravityBlock";}
    protected:
    private:
};

#endif // GRAVITYBLOCK_H
