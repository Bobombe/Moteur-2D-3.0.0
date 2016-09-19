#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <screen.h>
#include "keyboardlistener.h"


class TitleScreen : public Screen, public KeyboardListener
{
    public:
        TitleScreen();
        virtual ~TitleScreen();
        void init(std::string pathBackgroundScreen = "");
        virtual int update(float seconds);
        virtual void draw(sf::Vector2f deltaPos = sf::Vector2f(0,0));
        //Keyboard
        virtual void keyPressed(sf::Keyboard::Key k);
        virtual void keyReleased(sf::Keyboard::Key k);
    protected:
        sf::Sprite m_background;
        int m_state; // Represent the state of the screen:
        /*
            -1 : Not initializated
            0  : Biginning annimation
            1  : Ready for "start"
            2  : Start pressed
        //*/
        std::string m_pathBackgroundScreen;
    private:
};

#endif // TITLESCREEN_H
