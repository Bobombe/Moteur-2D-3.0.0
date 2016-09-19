#include <iostream>
#include "moteur2d.h"

#include <SFML/Graphics.hpp>

#include "gamemanagertest.h"
#include "titlescreen.h"

int main()
{
    std::cout << "GO !" << std::endl;

    Moteur2D* moteur = Moteur2D::getInstance();
    moteur->init(1024, 768);
/*
    sf::Sprite *s = new sf::Sprite();
    s->setTexture(*moteur->getTexture("ressources/Fond3.png"));
    s->setPosition(sf::Vector2f(10, 10));//*/
    //Moteur2D::getInstance()->unloadTexture("ressources/Fond3.png");

    //moteur->addDrawable(s);


    GameManagerTest gmt;
    moteur->setScreenManager(&gmt);


    moteur->run();
    std::cout << moteur->getTime().asSeconds() << std::endl;
}
