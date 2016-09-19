#ifndef VISOR_H
#define VISOR_H

#include "mouselistener.h"
#include "rectangularcollider.h"
#include "movable.h"

class Visor : MouseListener// , RectangularCollider
{
    public:
        Visor(std::vector<Collider*> *colliders = 0, Movable * shooter = 0);
        virtual ~Visor();
        virtual void buttonPressed(sf::Event::MouseButtonEvent mbe);
        virtual void buttonReleased(sf::Event::MouseButtonEvent mbe);
        virtual void mouseMoved(sf::Event::MouseMoveEvent mme){}
        virtual void mouseWheel(sf::Event::MouseWheelEvent mwe){}
        //virtual void applyCollitionWith(Collider * other, float seconds, sf::Vector2f * collisionPoint = 0){}
        // SETTERS
        void setColliders(std::vector<Collider*> *colliders)
        {
            m_colliders = colliders;
        }
        void setShooter(Movable * shooter)
        {
            m_shooter = shooter;
        }
    protected:
        std::vector<Collider*> * m_colliders;
        Movable * m_shooter;

    private:
};

#endif // VISOR_H
