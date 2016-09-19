#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <SFML/Graphics.hpp>
#include "iostream"

class Drawable
{
    public:
        //*
        virtual ~Drawable()
        {
            std::cout << "dest Drawable " << this << std::endl;
        }
        //*/
        virtual void draw(sf::Vector2f deltaPos = sf::Vector2f(0,0))=0;
    protected:
    private:
};

#endif // DRAWABLE_H
