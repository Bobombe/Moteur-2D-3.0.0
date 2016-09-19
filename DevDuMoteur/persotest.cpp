#include "persotest.h"
#include "moteur2d.h"
#include "iostream"
#include "mathHelps.h"
#include "bullet.h"

// Pour la phisique :
#define G 2000
#define J 800
#define EJ 400
#define M 600


PersoTest::PersoTest(CollisionManager *colMng, GameScreen* gs) : MovableSprite("ressources/perso.png", sf::IntRect(0, 60, 40, 59))
{
    //ctor
    //m_spritePerso.setTexture(*Moteur2D::getInstance()->getTexture("ressources/personageDroite.bmp"));
    setPosition(500, 500);
    m_posTexture = 0;

    m_left = false;
    m_right = false;
    m_up = false;
    m_down = false;
    m_jumpForce = 0;

    m_colMng = colMng;
    m_gameScreen = gs;

    m_gravityField.y = 1;
    m_gb = 0;
    //gravityPoint.x = 9999999999;
}

PersoTest::~PersoTest()
{
    //dtor
    std::cout << "dest PersoTest " << this << std::endl;
}

int PersoTest::update(float seconds)
{
    //Gravité
    if(m_gb)
    {
        m_gravityField = m_gb->calculateGField(m_position+sf::Vector2f(m_rectHitBox.width/2., m_rectHitBox.height/2.));
    }
    else
    {
        /*
        dir = m_gravityField - m_position;
        float norm = (sqrt(dir.x*dir.x + dir.y*dir.y));
        dir = dir/norm;
        //*/
    }
    m_speed += m_gravityField*(G*seconds);

    //Maj du sprite
    int tempo = 10;
    if(m_right && !m_left)
    {
        std::cout << "test" << (m_posTexture/tempo) << std::endl;
        m_posTexture++;
        if(m_posTexture<tempo || m_posTexture > 6*tempo)
        {
            m_posTexture = tempo;
        }
        setSprite("", sf::IntRect((m_posTexture/tempo)*40, 60, 40, 59));
    }
    else
    {
        m_posTexture = 0;
        setSprite("", sf::IntRect(0, 60, 40, 59));
    }
    // Code normalement à réimplanter dans les classes filles (ou appeler cette methode)
    // Application de l'accélération
    m_speed += m_acceleration*seconds;
    //Application de la vitesse
    m_position += m_speed*seconds;
    m_rectHitBox = sf::FloatRect(m_position.x, m_position.y, m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height);
    return 0;
}

int PersoTest::applyCollitionWith(Collider * other, float seconds, sf::Vector2f * collisionPoint)
{
    float friction = 100;
    if (other->getColliderName() != "GravityBlock" && other->getColliderName() != "Obstacle")
    {
        return 0;
    }
    if(collisionPoint->y>m_position.y+m_rectHitBox.height*0.75)// en bas
    {
        //std::cout << "bas" << std::endl;
        if(other->getHitBoxType()=="Rectangular")
        {
            RectangularCollider* rectOther = (RectangularCollider*)other;
            sf::FloatRect hbOther = rectOther->getRectHitBox();
            m_position.y = hbOther.top-m_rectHitBox.height;
        }
        else
        {
            m_position.y -= m_speed.y*seconds;
        }
        m_speed.y = 0;
        // friction
        if(m_speed.x>0 && !m_left && !m_right)
        {
            m_speed.x-=friction*seconds;
            if(m_speed.x<0)
            {
                m_speed.x=0;
            }
        }
        else if(m_speed.x<0 && !m_left && !m_right)
        {
            m_speed.x+=friction*seconds;
            if(m_speed.x>0)
            {
                m_speed.x=0;
            }
        }
        m_up = false;
        m_down = false;
    }
    else if(collisionPoint->y<m_position.y+m_rectHitBox.height/4)// en haut
    {
        //std::cout << "haut" << std::endl;
        if(other->getHitBoxType()=="Rectangular")
        {
            RectangularCollider* rectOther = (RectangularCollider*)other;
            sf::FloatRect hbOther = rectOther->getRectHitBox();
            m_position.y = hbOther.top+hbOther.height;
        }
        else
        {
            m_position.y -= m_speed.y*seconds;
        }
        m_speed.y = 0;
        // friction
        if(m_speed.x>0 && !m_left && !m_right)
        {
            m_speed.x-=friction*seconds;
            if(m_speed.x<0)
            {
                m_speed.x=0;
            }
        }
        else if(m_speed.x<0 && !m_left && !m_right)
        {
            m_speed.x+=friction*seconds;
            if(m_speed.x>0)
            {
                m_speed.x=0;
            }
        }
        m_up = false;
        m_down = false;
    }
    else if(collisionPoint->x>m_position.x+m_rectHitBox.width*0.75)// droite
    {
        //std::cout << "droite" << std::endl;
        if(other->getHitBoxType()=="Rectangular")
        {
            RectangularCollider* rectOther = (RectangularCollider*)other;
            sf::FloatRect hbOther = rectOther->getRectHitBox();
            m_position.x = hbOther.left-m_rectHitBox.width;
        }
        else
        {
            m_position.x -= m_speed.y*seconds;
        }
        m_speed.x = 0;
        m_right = false;
        m_left = false;
    }
    else if(collisionPoint->x<m_position.x+m_rectHitBox.width/4)// gauche
    {
        //std::cout << "gauche" << std::endl;
        if(other->getHitBoxType()=="Rectangular")
        {
            RectangularCollider* rectOther = (RectangularCollider*)other;
            sf::FloatRect hbOther = rectOther->getRectHitBox();
            m_position.x = hbOther.left+hbOther.width;
        }
        else
        {
            m_position.y -= m_speed.y*seconds;
        }
        m_speed.x = 0;
        // friction à revoir selon roientation
        if(m_speed.x>0 && !m_left && !m_right)
        {
            m_speed.x-=friction*seconds;
            if(m_speed.x<0)
            {
                m_speed.x=0;
            }
        }
        else if(m_speed.x<0 && !m_left && !m_right)
        {
            m_speed.x+=friction*seconds;
            if(m_speed.x>0)
            {
                m_speed.x=0;
            }
        }
        m_right = false;
        m_left = false;
    }
    else
    {
        //ddddddddddddddddddddddstd::cout << "autre" << std::endl;
        m_position -= m_speed*seconds;
        m_speed.x = m_speed.y = 0;
        m_left = false;
        m_right = false;
        m_up = false;
        m_down = false;
    }
    return 0;
}
// KEYBOARD
void PersoTest::keyPressed(sf::Keyboard::Key k)
{
    if(k>=sf::Keyboard::Left && k<=sf::Keyboard::Down)
    {
        if(k==sf::Keyboard::Left && !m_left)
        {
            m_speed.x += -M;
            m_left = true;
        }
        if(k==sf::Keyboard::Right && !m_right)
        {
            m_speed.x += M;
            m_right = true;
        }
        if(k==sf::Keyboard::Up && !m_up)
        {
            m_speed += m_gravityField*(float)(-J);
            m_up = true;
        }
        if(k==sf::Keyboard::Down && !m_down)
        {
            //m_speed.y += J;
            m_down = true;
        }
    }

}
void PersoTest::keyReleased(sf::Keyboard::Key k)
{
    if(k>=sf::Keyboard::Left && k<=sf::Keyboard::Down)
    {
        if(k==sf::Keyboard::Left && m_left)
        {
            m_speed.x -= -M;
            m_left = false;
        }
        if(k==sf::Keyboard::Right && m_right)
        {
            m_speed.x -= M;
            m_right = false;
        }
        if(k==sf::Keyboard::Up && m_up)
        {
            //m_speed.y -= -J;
            if(scal(m_speed, m_gravityField)<-EJ)
            {
                sf::Vector2f gPrime = getRot90(m_gravityField);
                m_speed = m_gravityField*(float)(-EJ) + scal(m_speed, gPrime)*gPrime;
            }
            m_up = false;
        }
        if(k==sf::Keyboard::Down && m_down)
        {
            //m_speed.y -= J;
            m_down = false;
        }
    }
}

void PersoTest::buttonPressed(sf::Event::MouseButtonEvent mbe)
{
    Bullet * b = new Bullet(this);
    b->setPosition(getPosition());
    b->setSpeed(sf::Vector2f(mbe.x, mbe.y)-getPosition());
    m_colMng->addCollider(b);
    m_gameScreen->addMovable(b);
}

void PersoTest::destructBullet(Bullet * b)
{
    m_gameScreen->deleteMovable(b);
}
