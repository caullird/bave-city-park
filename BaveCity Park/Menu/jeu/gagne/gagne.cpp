#include <SFML/Graphics.hpp>
#include "gagne.h"
#include "../jeu.h"
#include "../../menu.h"
#define HAUTEUR_FENETRE 720
#define LARGEUR_FENETRE 1080

using namespace sf;

void affichageGagne()
{
    RenderWindow gagne(VideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE),"VOUS AVEZ GAGNE");

    Texture background;
    Sprite backg;

    background.loadFromFile("image/menugagne.png");
    backg.setTexture(background);

    SoundBuffer buffer;
    SoundBuffer buffer1;

    if(!buffer1.loadFromFile("son/SelectionMenu.wav"))
        return;
    if(!buffer.loadFromFile("son/Reussite.wav"))
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

    Text titre,rejouer,retour;

    rejouer.setFont(texte);
    rejouer.setPosition(LARGEUR_FENETRE/2-50,HAUTEUR_FENETRE/2);
    rejouer.setString("Rejouer");
    rejouer.setColor(Color::Black);

    retour.setFont(texte);
    retour.setPosition(LARGEUR_FENETRE/2-120,HAUTEUR_FENETRE/2+100);
    retour.setString("ReTour au menu");
    retour.setColor(Color::Black);





    while(gagne.isOpen())
    {
        while(gagne.pollEvent(evenement))
        {
            switch(evenement.type)
            {
            case Event::Closed:
                gagne.close();
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
                    gagne.close();
                    affichageJeu();
                }
                if(evenement.mouseButton.x>=LARGEUR_FENETRE/2-120 && evenement.mouseButton.x<=LARGEUR_FENETRE/2+120 && evenement.mouseButton.y>=HAUTEUR_FENETRE/2+100 && evenement.mouseButton.y<=HAUTEUR_FENETRE/2+130)
                {
                    sound.stop();
                    gagne.close();
                    affichageMenu();
                }
            }
        }
        gagne.clear();
        gagne.draw(backg);
        gagne.draw(rejouer);
        gagne.draw(retour);
        gagne.display();
    }
}
