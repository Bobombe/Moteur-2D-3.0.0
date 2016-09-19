#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "updatable.h"
#include "screen.h"


class ScreenManager : public Updatable
{
    public:
        ScreenManager();
        virtual ~ScreenManager();

        //virtual int update(float seconds)=0;// Ici doit �tre impl�ment� la Machine � �tat g�rant les �crans dans la classe fille
        virtual void draw()=0;

        // Fonctions d'ajout
        void addScreen(int,Screen*);

    protected:
        std::map<int,Screen *> m_screens;

    private:
};

#endif // SCREENMANAGER_H
