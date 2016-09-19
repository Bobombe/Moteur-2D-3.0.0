#ifndef SCREEN_H
#define SCREEN_H

#include "movable.h"
#include <SFML/Graphics.hpp>


class Screen : public Movable
{
    public:
        Screen();
        virtual ~Screen();
        virtual int update(float seconds);
        virtual void draw(sf::Vector2f deltaPos = sf::Vector2f(0,0));

        // Fonctions d'ajout
        // Attention, il ne faut jamais ajouter plusieurs fois la même instance, même via deux mêthodes add différentes
        // TODO : Ajouter une vérification pour empécher l'ajout multiple ?
        void addUpdatable(Updatable*);
        void addDrawable(Drawable*);
        void addMovable(Movable*);

        void deleteMovable(Movable*);

    protected:
        std::vector<Updatable*> m_updatables;
        std::vector<Drawable*> m_drawables;
        std::vector<Movable*> m_movables;


    private:
};

#endif // SCREEN_H
