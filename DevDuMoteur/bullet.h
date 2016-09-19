#ifndef BULLET_H
#define BULLET_H

#include <movablesprite.h>
#include "rectangularcollider.h"
#include "persotest.h"


class Bullet : public MovableSprite, public RectangularCollider
{
    public:
        Bullet(PersoTest * perso);
        virtual ~Bullet();
        virtual int update(float seconds);
        virtual int applyCollitionWith(Collider * other, float seconds, sf::Vector2f * collisionPoint = 0);
    protected:
        PersoTest * m_perso;
    private:
};

#endif // BULLET_H
