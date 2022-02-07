#include "menu.h"
#define BACKGROUND "parking.jpg"
#define LARGEUR_FENETRE 1080
#define HAUTEUR_FENETRE 720
using namespace sf;
Event evenement;
Font texte;
Texture background;
Sprite backg;


void affichageCredit()
{
    RenderWindow cred(VideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE),"Crédits");


    background.loadFromFile("menucredit.png");
    backg.setTexture(background);

    Text nom1,nom2,nom3,nom4,nom5,retour,titre;

    SoundBuffer buffer10;//-----------SON--------------
    if(!buffer10.loadFromFile("SelectionMenu.wav"))//-----------SON--------------
        return;//-----------SON--------------
    Sound selectionmenu;//-----------SON--------------
    selectionmenu.setBuffer(buffer10);//-----------SON--------------
    selectionmenu.setVolume(70);//-----------SON--------------

    SoundBuffer buffer5;//-----------SON--------------
    if(!buffer5.loadFromFile("MusiqueCredits.wav"))//-----------SON--------------
        return;//-----------SON--------------v
    Sound musiquecredits;//-----------SON--------------
    musiquecredits.setBuffer(buffer5);//-----------SON--------------
    musiquecredits.setVolume(70);//-----------SON--------------
    musiquecredits.play();//-----------SON--------------
    musiquecredits.setLoop(true);//-----------SON--------------



    RectangleShape rect(Vector2f(1,HAUTEUR_FENETRE));
    rect.setPosition(LARGEUR_FENETRE/2,0);
    rect.setFillColor(Color::Yellow);
//----------------TEXTURE--------------------------------------------------------------------------------------------------------------------------------------------
    //background.loadFromFile("parking.jpg");

//----------------SPRITE--------------------------------------------------------------------------------------------------------------------------------------------
    //backg.setTexture(background);

//----------------POSITION_TEXTE-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    nom1.setFont(texte);
    nom1.setPosition(LARGEUR_FENETRE/2-140,HAUTEUR_FENETRE/3);
    nom1.setString("Dorian CAULLIREAU");
    nom1.setColor(Color::Black);

    nom2.setFont(texte);
    nom2.setPosition(LARGEUR_FENETRE/2-135,HAUTEUR_FENETRE/3+50);
    nom2.setString("Alexis VANHOUTTE");
    nom2.setColor(Color::Black);

    nom3.setFont(texte);
    nom3.setPosition(LARGEUR_FENETRE/2-180,HAUTEUR_FENETRE/3+100);
    nom3.setString("Leonardo SOUSA MORAIS");
    nom3.setColor(Color::Black);

    nom4.setFont(texte);
    nom4.setPosition(LARGEUR_FENETRE/2-110,HAUTEUR_FENETRE/3+150);
    nom4.setString("MaThis FIGUET");
    nom4.setColor(Color::Black);

    nom5.setFont(texte);
    nom5.setPosition(LARGEUR_FENETRE/2-105,HAUTEUR_FENETRE/3+200);
    nom5.setString("Edgar BRAND");
    nom5.setColor(Color::Black);

    retour.setFont(texte);
    retour.setPosition(LARGEUR_FENETRE/2-130,HAUTEUR_FENETRE/3+400);
    retour.setString("ReTour au menu");
    retour.setColor(Color::Black);
//----------------POSITION_TEXTE------------------------------------------------------------------------------------------------------------------------------------------------------------------

    while(cred.isOpen())
    {
        while(cred.pollEvent(evenement))
        {
            switch(evenement.type)
            {
            case Event::Closed:
                cred.close();
                break;
//------------------Si curseur sur le texte --> mot devient rouge----------------------------------------------------------------------------------------------------------------------------------------
            case Event::MouseMoved:
                if((evenement.mouseMove.x>=LARGEUR_FENETRE/2-130 && evenement.mouseMove.x<=LARGEUR_FENETRE/2+110)&&(evenement.mouseMove.y>=HAUTEUR_FENETRE/3+400 && evenement.mouseMove.y<=HAUTEUR_FENETRE/3+440))
                {
                    selectionmenu.play();//-----------SON--------------
                    retour.setColor(Color::Red);
                }
                else
                {
                     retour.setColor(Color::Black);
                }
                break;
//-----------------Si on clique sur le mot rouge --> quitte----------------------------------------------------------------------------------------------------------------------------------------------
            case Event::MouseButtonPressed:
                if((evenement.mouseButton.x>=LARGEUR_FENETRE/2-130 && evenement.mouseButton.x<=LARGEUR_FENETRE/2+110)&&(evenement.mouseButton.y>=HAUTEUR_FENETRE/3+400 && evenement.mouseButton.y<HAUTEUR_FENETRE/3+440))
                {
                    musiquecredits.stop();//-----------SON--------------
                    cred.close();
                    affichageMenu();
                }
                break;
            }
        }
    cred.clear();
    cred.draw(backg);
    cred.draw(nom1);
    cred.draw(nom2);
    cred.draw(nom3);
    cred.draw(nom4);
    cred.draw(nom5);
    cred.draw(retour);
    cred.display();;
    }
}
