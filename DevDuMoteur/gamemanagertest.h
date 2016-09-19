#ifndef GAMEMANAGERTEST_H
#define GAMEMANAGERTEST_H

#include "screenmanager.h"


class GameManagerTest : public ScreenManager
{
    public:
        GameManagerTest();
        virtual int update(float seconds);
        virtual void draw();
    protected:
        int m_stateMachine;
    private:
};

#endif // GAMEMANAGERTEST_H
