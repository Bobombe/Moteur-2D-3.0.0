#include "gravityblock.h"
#include <cmath>

GravityBlock::GravityBlock(std::string pathObstacleSprite, float posX, float posY, sf::IntRect subTextureRect):
    Obstacle(pathObstacleSprite, posX, posY, subTextureRect)
{
    //ctor
}

GravityBlock::~GravityBlock()
{
    //dtor
}

sf::Vector2f GravityBlock::calculateGField(sf::Vector2f position)
{
    sf::Vector2f ret;
    if(position.y < m_rectHitBox.top)
    {
        ret.y=1;
        if(position.x < m_rectHitBox.left)//coin haut gauche
        {
            ret=sf::Vector2f(m_rectHitBox.left, m_rectHitBox.top)-position;
            float norm = (sqrt(ret.x*ret.x + ret.y*ret.y));
            ret = ret/norm;
        }
        else if(position.x > m_rectHitBox.left+m_rectHitBox.width)//haut droite
        {
            ret=sf::Vector2f(m_rectHitBox.left+m_rectHitBox.width, m_rectHitBox.top)-position;
            float norm = (sqrt(ret.x*ret.x + ret.y*ret.y));
            ret = ret/norm;
        }
    }
    else if(position.y > m_rectHitBox.top+m_rectHitBox.height)
    {
        ret.y=-1;
        if(position.x < m_rectHitBox.left)//coin bas gauche
        {
            ret=sf::Vector2f(m_rectHitBox.left, m_rectHitBox.top+m_rectHitBox.height)-position;
            float norm = (sqrt(ret.x*ret.x + ret.y*ret.y));
            ret = ret/norm;
        }
        else if(position.x > m_rectHitBox.left+m_rectHitBox.width)//bas droite
        {
            ret=sf::Vector2f(m_rectHitBox.left+m_rectHitBox.width, m_rectHitBox.top+m_rectHitBox.height)-position;
            float norm = (sqrt(ret.x*ret.x + ret.y*ret.y));
            ret = ret/norm;
        }
    }
    else if(position.x < m_rectHitBox.left)
    {
        ret.x=1;
    }
    else if(position.x > m_rectHitBox.left+m_rectHitBox.width)
    {
        ret.x=-1;
    }
    return ret;
}
