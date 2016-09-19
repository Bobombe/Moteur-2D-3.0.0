#ifndef MOUSELISTENER_H_INCLUDED
#define MOUSELISTENER_H_INCLUDED


#include <SFML/Graphics.hpp>

class MouseListener
{
    public:
        MouseListener();
        virtual ~MouseListener();
        virtual void buttonPressed(sf::Event::MouseButtonEvent mbe){}
        virtual void buttonReleased(sf::Event::MouseButtonEvent mbe){}
        virtual void mouseMoved(sf::Event::MouseMoveEvent mme){}
        virtual void mouseWheel(sf::Event::MouseWheelEvent mwe){}
    protected:
        int m_id;
    private:
};



#endif // MOUSELISTENER_H_INCLUDED
