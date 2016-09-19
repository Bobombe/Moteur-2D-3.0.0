#include "bullet.h"
#include "gravityblock.h"

Bullet::Bullet(PersoTest * perso) : MovableSprite("ressources/platform.bmp"), m_perso(perso)
{
    //ctor
}

Bullet::~Bullet()
{
    //dtor
}

int Bullet::applyCollitionWith(Collider * other, float seconds, sf::Vector2f * collisionPoint)
{

    if(other->getColliderName()=="Obstacle")
    {
        //Obstacle* obs = (Obstacle*)other;
        m_perso->setGravityField(getPosition());
        m_perso->destructBullet(this);
        delete this;
        return -1;
    }
    if(other->getColliderName()=="GravityBlock")
    {
        //Obstacle* obs = (Obstacle*)other;
        m_perso->setGravityBlock((GravityBlock*)other);
        m_perso->destructBullet(this);
        delete this;
        return -1;
    }
    return 0;
}

int Bullet::update(float seconds)
{
    // Code normalement à réimplanter dans les classes filles (ou appeler cette methode)
    // Application de l'accélération
    m_speed += m_acceleration*seconds;
    //Application de la vitesse
    m_position += m_speed*seconds;
    m_rectHitBox = sf::FloatRect(m_position.x, m_position.y, m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height);
    return 0;
}
