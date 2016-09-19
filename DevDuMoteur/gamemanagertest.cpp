#include "gamemanagertest.h"
#include "titlescreen.h"
#include "gamescreen.h"

GameManagerTest::GameManagerTest()
{
    //ctor
    TitleScreen * s = new TitleScreen();
    s->init("ressources/Fond3.png");
    addScreen(0, s);
    m_stateMachine = 0;
}

int GameManagerTest::update(float seconds)
{
    switch (m_stateMachine)
    {
        case 0 :
            if(m_screens[0]->update(seconds)==3) // cond to state 1
            {
                // Transition Actions 0->1
                delete m_screens[0];
                addScreen(0, new GameScreen());
                //set m_stateMachine
                m_stateMachine = 1;
            }
            break;
        case 1 :
            m_screens[0]->update(seconds);
            break;

    }
    return m_stateMachine;
}

void GameManagerTest::draw()
{

    switch (m_stateMachine)
    {
        case 0 :
        case 1 :
            m_screens[0]->draw();
            break;
    }
    return;
}
