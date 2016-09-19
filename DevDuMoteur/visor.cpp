#include "visor.h"
#include <cmath>

Visor::Visor(std::vector<Collider*> *colliders, Movable * shooter)// : RectangularCollider(sf::FloatRect(0, 0, 3, 3))
{
    //ctor
    m_colliders = colliders;
    m_shooter = shooter;
}

Visor::~Visor()
{
    //dtor
}

void Visor::buttonPressed(sf::Event::MouseButtonEvent mbe)
{
    if(m_colliders!=0 && m_shooter!=0)
    {
        sf::Vector2f dir;
        dir = sf::Vector2f(mbe.x, mbe.y)-m_shooter->getPosition();
        float norm = (sqrt(dir.x*dir.x + dir.y*dir.y));
        dir = dir/norm;

    }

}
void Visor::buttonReleased(sf::Event::MouseButtonEvent mbe)
{

}
