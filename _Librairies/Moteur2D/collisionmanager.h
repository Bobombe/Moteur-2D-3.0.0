#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "collider.h"


class CollisionManager
{
    public:
        CollisionManager();
        virtual ~CollisionManager();
        void processCollisions(float seconds);
        void addCollider(Collider*c);
        std::vector<Collider*> * getColliders()
        {
            return &m_colliders;
        }
    protected:
        std::vector<Collider*> m_colliders;
    private:
};

#endif // COLLISIONMANAGER_H
