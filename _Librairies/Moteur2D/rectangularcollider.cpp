#include "rectangularcollider.h"
#include "iostream"

RectangularCollider::RectangularCollider(sf::FloatRect rectHitBox)
{
    //ctor
    m_rectHitBox = rectHitBox;
}

RectangularCollider::~RectangularCollider()
{
    //dtor
}

//Implementation pure virtual members

std::string RectangularCollider::getColliderName()
{
    return "RectangularCollider";
}
std::string RectangularCollider::getHitBoxType()// example : rectangular, spherical ...
{
    return "Rectangular";
}
/**
testCollisionWith :
return : 1 if collision, 0 if not, -1 if it can't process the collision(doesn't know other->getBBoxType)
*/
int RectangularCollider::testCollisionWith(Collider * other, sf::Vector2f * collisionPoint)
{
    if(other->getHitBoxType()=="Rectangular")
    {
        RectangularCollider* rectOther = (RectangularCollider*)other;
        sf::FloatRect hbOther = rectOther->getRectHitBox();
        if (!(m_rectHitBox.left > hbOther.left+hbOther.width ||
            m_rectHitBox.left+m_rectHitBox.width < hbOther.left ||
            m_rectHitBox.top > hbOther.top+hbOther.height ||
            m_rectHitBox.top+m_rectHitBox.height < hbOther.top))
        {
            // Collision
            if(collisionPoint)
            {
                float left = (hbOther.left+hbOther.width - m_rectHitBox.left);
                float right = (m_rectHitBox.left+m_rectHitBox.width - hbOther.left);
                float top = (hbOther.top+hbOther.height - m_rectHitBox.top);
                float bottom = (m_rectHitBox.top+m_rectHitBox.height - hbOther.top);
                left = left*left;
                right = right*right;
                top = top*top;
                bottom = bottom*bottom;

                if(left<right)
                {
                    if(top<bottom)
                    {
                        if(left<top)
                        {
                            //Left
                           collisionPoint->x= m_rectHitBox.left;
                           collisionPoint->y= m_rectHitBox.top+m_rectHitBox.height/2.;
                        }
                        else
                        {
                            //top
                           collisionPoint->x= m_rectHitBox.left+m_rectHitBox.width/2;
                           collisionPoint->y= m_rectHitBox.top;//+m_rectHitBox.height/2.;
                        }
                    }
                    else
                    {
                        if(left<bottom)
                        {
                            //Left
                           collisionPoint->x= m_rectHitBox.left;
                           collisionPoint->y= m_rectHitBox.top+m_rectHitBox.height/2.;
                        }
                        else
                        {
                            //bottom
                           collisionPoint->x= m_rectHitBox.left+m_rectHitBox.width/2;
                           collisionPoint->y= m_rectHitBox.top+m_rectHitBox.height;
                        }
                    }
                }
                else
                {
                    if(top<bottom)
                    {
                        if(right<top)
                        {
                            //right
                           collisionPoint->x= m_rectHitBox.left+m_rectHitBox.width;
                           collisionPoint->y= m_rectHitBox.top+m_rectHitBox.height/2.;
                        }
                        else
                        {
                            //top
                           collisionPoint->x= m_rectHitBox.left+m_rectHitBox.width/2;
                           collisionPoint->y= m_rectHitBox.top;//+m_rectHitBox.height/2.;
                        }
                    }
                    else
                    {
                        if(right<bottom)
                        {
                            //right
                           collisionPoint->x= m_rectHitBox.left+m_rectHitBox.width;
                           collisionPoint->y= m_rectHitBox.top+m_rectHitBox.height/2.;
                        }
                        else
                        {
                            //bottom
                           collisionPoint->x= m_rectHitBox.left+m_rectHitBox.width/2;
                           collisionPoint->y= m_rectHitBox.top+m_rectHitBox.height;
                        }
                    }

                }
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else//unknown
    {
        return -1;
    }
}


void RectangularCollider::setRectHitBox(sf::FloatRect rectHitBox)
{
    m_rectHitBox = rectHitBox;
}
