#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screen.h"
#include "collisionmanager.h"

class GameScreen : public Screen
{
    public:
        GameScreen();
        virtual ~GameScreen();
        int update(float seconds);
    protected:
        CollisionManager m_colMng;
    private:
};

#endif // GAMESCREEN_H
