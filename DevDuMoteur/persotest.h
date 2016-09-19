#ifndef PERSOTEST_H
#define PERSOTEST_H

#include <movablesprite.h>
#include "keyboardlistener.h"
#include "rectangularcollider.h"
#include "collisionmanager.h"
#include "mouselistener.h"
#include "gamescreen.h"
#include "gravityblock.h"

class Bullet;


class PersoTest : public MovableSprite, public KeyboardListener, public RectangularCollider, public MouseListener
{
    public:
        PersoTest(CollisionManager *colMng =0, GameScreen* gs=0);
        virtual ~PersoTest();
        virtual int update(float seconds);

        //Keyboard
        virtual void keyPressed(sf::Keyboard::Key k);
        virtual void keyReleased(sf::Keyboard::Key k);
        virtual int applyCollitionWith(Collider * other, float seconds, sf::Vector2f * collisionPoint = 0);

        // Mouse
        virtual void buttonPressed(sf::Event::MouseButtonEvent mbe);
        void destructBullet(Bullet * b);

        void setGravityField(sf::Vector2f gf){m_gravityField = gf;}
        void setGravityBlock(GravityBlock *gb){m_gb = gb;}
    protected:

        //sf::Sprite m_spritePerso;
        // Pour bouger
        bool m_left;
        bool m_right;
        bool m_up;
        bool m_down;
        int m_jumpForce;

        sf::Vector2f m_gravityField;
        GravityBlock * m_gb;

        // Position texture
        int m_posTexture;

        CollisionManager* m_colMng;
        GameScreen* m_gameScreen;
    private:
};

#endif // PERSOTEST_H
