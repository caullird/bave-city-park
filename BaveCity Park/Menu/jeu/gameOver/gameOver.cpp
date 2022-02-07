#include <SFML/Graphics.hpp>
#include "gameOver.h"
#include "../jeu.h"
#include "../../menu.h"
#define HAUTEUR_FENETRE 720
#define LARGEUR_FENETRE 1080

using namespace sf;

void affichageGameOver()
{
    RenderWindow gameOver(VideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE),"Game OVER");

    Texture background;
    Sprite backg;

    background.loadFromFile("image/gameover.png");
    backg.setTexture(background);

    SoundBuffer buffer;
    SoundBuffer buffer1;

    if(!buffer1.loadFromFile("son/SelectionMenu.wav"))
        return;
    if(!buffer.loadFromFile("son/MusiqueGameOver.wav"))
        return;

    Sound sound;
    Sound selectionmenu;

    sound.setBuffer(buffer);
    sound.setVolume(70);
    sound.play();

    selectionmenu.setBuffer(buffer1);
    selectionmenu.setVolume(40);

    Font texte;
    Event evenement;
    texte.loadFromFile("police/transformers.ttf");

    Text rejouer,retour;


    rejouer.setFont(texte);
    rejouer.setPosition(LARGEUR_FENETRE/2-50,HAUTEUR_FENETRE/2);
    rejouer.setString("Rejouer");
    rejouer.setColor(Color::Black);

    retour.setFont(texte);
    retour.setPosition(LARGEUR_FENETRE/2-120,HAUTEUR_FENETRE/2+100);
    retour.setString("ReTour au menu");
    retour.setColor(Color::Black);





    while(gameOver.isOpen())
    {
        while(gameOver.pollEvent(evenement))
        {
            switch(evenement.type)
            {
            case Event::Closed:
                gameOver.close();
                break;
            case Event::MouseMoved:
                if(evenement.mouseMove.x>=LARGEUR_FENETRE/2-50 && evenement.mouseMove.x<=LARGEUR_FENETRE/2+60 && evenement.mouseMove.y>=HAUTEUR_FENETRE/2 && evenement.mouseMove.y<=HAUTEUR_FENETRE/2+30)
                {
                    rejouer.setColor(Color::Red);
                    selectionmenu.play();
                }
                else
                {
                    rejouer.setColor(Color::Black);
                }
                if(evenement.mouseMove.x>=LARGEUR_FENETRE/2-120 && evenement.mouseMove.x<=LARGEUR_FENETRE/2+120 && evenement.mouseMove.y>=HAUTEUR_FENETRE/2+100 && evenement.mouseMove.y<=HAUTEUR_FENETRE/2+130)
                {
                    retour.setColor(Color::Red);
                    selectionmenu.play();
                }
                else
                {
                    retour.setColor(Color::Black);
                }
            case Event::MouseButtonPressed:
                if(evenement.mouseButton.x>=LARGEUR_FENETRE/2-50 && evenement.mouseButton.x<=LARGEUR_FENETRE/2+60 && evenement.mouseButton.y>=HAUTEUR_FENETRE/2 && evenement.mouseButton.y<=HAUTEUR_FENETRE/2+30)
                {
                    sound.stop();
                    gameOver.close();
                    affichageJeu();
                }
                if(evenement.mouseButton.x>=LARGEUR_FENETRE/2-120 && evenement.mouseButton.x<=LARGEUR_FENETRE/2+120 && evenement.mouseButton.y>=HAUTEUR_FENETRE/2+100 && evenement.mouseButton.y<=HAUTEUR_FENETRE/2+130)
                {
                    sound.stop();
                    gameOver.close();
                    affichageMenu();
                }
            }
        }
        gameOver.clear();
        gameOver.draw(backg);
        gameOver.draw(rejouer);
        gameOver.draw(retour);
        gameOver.display();
    }
}

