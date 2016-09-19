#ifndef MOTEUR2D_H
#define MOTEUR2D_H

#include <SFML/Graphics.hpp>

#include "mouselistener.h"
#include "keyboardlistener.h"

#include "updatable.h"
#include "screenmanager.h"

class Moteur2D
{
    public:
        static Moteur2D* getInstance();

  /////////////////////////////////////////////////////
 ///////////          METHODES             ///////////
/////////////////////////////////////////////////////
        void init(int width=800, int height=600, std::string windowName ="Youpi");
        void run();

  /////////////////////////////////////////////////////
 ///////////           ADDERS              ///////////
/////////////////////////////////////////////////////
/* TODO sup pour ecran
        int addPreDrawable(sf::Sprite* s);
        int addDrawable(sf::Sprite *s);
        int addPostDrawable(sf::Sprite* s);
        //*/
        void setScreenManager (ScreenManager * scm)
        {
            m_scm = scm;
        }

        int addKeyboardListener(KeyboardListener* kl);
        int addMouseListener(MouseListener* ml);

        int addUpdate(Updatable *u);

  /////////////////////////////////////////////////////
 ///////////          DELETERS             ///////////
/////////////////////////////////////////////////////
/* TODO sup pour ecran
        void deletePreDrawable(int index);
        void deleteDrawable(int index);
        void deletePostDrawable(int index);
        //*/

        void deleteKeyboardListener(int index);
        void deleteMouseListener(int index);

        void deleteUpdate(int index);

        // Pas vraiment un seleter
        void unloadTexture(const std::string& imagePath);

  /////////////////////////////////////////////////////
 ///////////           GETTERS             ///////////
/////////////////////////////////////////////////////
        sf::Texture* getTexture(const std::string& imagePath);

        sf::RenderWindow & getWindow();

        const std::map <int, KeyboardListener*>& getKeyboardListeners();
        const std::map <int, MouseListener*>& getMouseListeners();

        sf::Time getTime();


        ScreenManager * getScreenManager ()
        {
            return m_scm;
        }

        sf::Vector2i getScreenSize()
        {
            return m_screenSize;
        }

    protected:
        Moteur2D();
        virtual ~Moteur2D();

        static Moteur2D * m_instance;

        sf::RenderWindow *m_window;

        // Managing Textures
        std::map<std::string, sf::Texture*> m_textures;
        std::map<std::string, int> m_texturesUtilisations;


        // First called by eventmanager
        std::map <int, KeyboardListener*> m_keyboardListeners;
        int m_keyboardListenersId;
        std::map <int, MouseListener*> m_mouseListeners;
        int m_mouseListenersId;

        /* TODO sup pour ecran
        // Dessinables avant perso et autres
        std::map <int, sf::Sprite*> m_preDraw;
        int m_preDrawablesIndex;

        // Dessins au niveau du perso
        std::map <int, sf::Sprite*> m_drawables;
        int m_drawablesIndex;

        // Dessinables après perso et autres
        std::map <int, sf::Sprite*> m_postDraw;
        int m_postDrawablesIndex;
        //*/
        ScreenManager * m_scm;

        // Toutes classes nécessitant d'être mises à jour
        // De base ne devrait contenir que le gestionnaire d'écran
        std::map <int, Updatable*> m_updates;
        int m_updatesId;

        sf::Clock m_clock;
        sf::Time m_t;

        sf::Vector2i m_screenSize;

    private:
};

#endif // MOTEUR2D_H
