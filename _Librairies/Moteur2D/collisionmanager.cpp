#include "collisionmanager.h"
#include "iostream"

CollisionManager::CollisionManager()
{
    //ctor
}

CollisionManager::~CollisionManager()
{
    //dtor
}

void CollisionManager::processCollisions(float seconds)
{
    int res;
    sf::Vector2f collisionPoint;
    for(unsigned int i=0; i<m_colliders.size(); i++)
    {
        for(unsigned int j=i+1; j<m_colliders.size(); j++)
        {
            res = m_colliders[i]->testCollisionWith(m_colliders[j], &collisionPoint);
            if(res == -1)// collider de i ne connais pas le type de collider de j
            {
                res = m_colliders[j]->testCollisionWith(m_colliders[i], &collisionPoint);
            }
            if(res == -1)// collider de j ne connais pas non plus le type de collider de i
            {
                std::cout << "HitBoxes " << m_colliders[i]->getHitBoxType() << " et " << m_colliders[j]->getHitBoxType() << " incompatibles" << std::endl;
            }
            else if(res==1) //Collision !
            {
                //std::cout << "collision" << i << ":" << j <<std::endl;
                int retour = m_colliders[i]->applyCollitionWith(m_colliders[j], seconds, &collisionPoint);
                if (retour == -1)// demande de suppression du collider i
                {
                    m_colliders.erase(m_colliders.begin()+i);
                    j=i+1;
                }
                retour = m_colliders[j]->applyCollitionWith(m_colliders[i], seconds, &collisionPoint);
                if (retour == -1)// demande de suppression du collider i
                {
                    m_colliders.erase(m_colliders.begin()+j);
                    --j;
                }
                //break;
            }
        }
    }
}

void CollisionManager::addCollider(Collider*c)
{
    m_colliders.push_back(c);
}
