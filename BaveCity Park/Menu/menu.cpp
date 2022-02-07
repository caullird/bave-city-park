#include "menu.h"
#include "jeu/jeu.h"
#define BACKGROUND "parking.jpg"
#define LARGEUR_FENETRE 1080
#define HAUTEUR_FENETRE 720
using namespace sf;
Event evenement;
Font texte;
Texture background;
Sprite backg;




//-----------------------------------AFFICHAGE_MENU--------------------------------------------------------------------------------------------------------------------------------------------
void affichageMenu()
{
    SoundBuffer buffer8;//-----------SON--------------
    if(!buffer8.loadFromFile("son/MusiqueMenu.wav"))//-----------SON--------------
        return;//-----------SON--------------
    Sound musiquemenu;//-----------SON--------------
    musiquemenu.setBuffer(buffer8);//-----------SON--------------
    musiquemenu.setVolume(70);//-----------SON--------------
    musiquemenu.play();//-----------SON--------------
    musiquemenu.setLoop(true);//-----------SON--------------

    SoundBuffer buffer10;//-----------SON--------------
    if(!buffer10.loadFromFile("son/SelectionMenu.wav"))//-----------SON--------------
        return;//-----------SON--------------
    Sound selectionmenu;//-----------SON--------------
    selectionmenu.setBuffer(buffer10);//-----------SON--------------
    selectionmenu.setVolume(40);//-----------SON--------------


    texte.loadFromFile("police/transformers.ttf");
    RenderWindow menu(VideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE),"Menu");

    RectangleShape rect(Vector2f(1,HAUTEUR_FENETRE));
    rect.setPosition(LARGEUR_FENETRE/2,0);
    rect.setFillColor(Color::Yellow);
//----------------TEXTURE--------------------------------------------------------------------------------------------------------------------------------------------
    background.loadFromFile("image/menubase.png");

//----------------SPRITE--------------------------------------------------------------------------------------------------------------------------------------------
    backg.setTexture(background);

//----------------POSITION_TEXTE--------------------------------------------------------------------------------------------------------------------------------------------
    Text jouer,regles,credit,quitter,titre;
    /*titre.setFont(texte);
    titre.setPosition(LARGEUR_FENETRE/5,HAUTEUR_FENETRE/10);
    titre.setString("TITRE DU JEU");
    titre.setCharacterSize(100);
    titre.setColor(Color::Yellow);*/

    jouer.setFont(texte);
    jouer.setPosition(LARGEUR_FENETRE/2-50,HAUTEUR_FENETRE/4);
    jouer.setString("Jouer");
    jouer.setCharacterSize(50);
    jouer.setColor(Color::Black);

    regles.setFont(texte);
    regles.setPosition(LARGEUR_FENETRE/2-145,(HAUTEUR_FENETRE/4)+100);
    regles.setString("Règles du jeu");
    regles.setCharacterSize(50);
    regles.setColor(Color::Black);

    credit.setFont(texte);
    credit.setPosition(LARGEUR_FENETRE/2-70,(HAUTEUR_FENETRE/4)+200);
    credit.setString("CrédiTs");
    credit.setCharacterSize(50);
    credit.setColor(Color::Black);

    quitter.setFont(texte);
    quitter.setPosition(LARGEUR_FENETRE/2-70,(HAUTEUR_FENETRE/4)+300);
    quitter.setString("QuiTTer");
    quitter.setCharacterSize(50);
    quitter.setColor(Color::Black);
//----------------POSITION_TEXTE--------------------------------------------------------------------------------------------------------------------------------------------

    while(menu.isOpen())
    {
        while(menu.pollEvent(evenement))
        {
            switch(evenement.type)
            {
            case Event::Closed:
                menu.close();
                break;
//------------------Si curseur sur le texte --> mot devient rouge-----------------------------------------------------------------------------------------------------
            case Event::MouseMoved:
               if((evenement.mouseMove.x>=LARGEUR_FENETRE/2-50 && evenement.mouseMove.x<=LARGEUR_FENETRE/2+80)&&(evenement.mouseMove.y>=HAUTEUR_FENETRE/4+15 && evenement.mouseMove.y<=HAUTEUR_FENETRE/4+50))
               {
                   selectionmenu.play();//-----------SON--------------
                   jouer.setColor(Color::Red);
               }
               else
               {
                   jouer.setColor(Color::Black);
               }

               if((evenement.mouseMove.x>=LARGEUR_FENETRE/2-145 && evenement.mouseMove.x<=LARGEUR_FENETRE/2+200)&&(evenement.mouseMove.y>=HAUTEUR_FENETRE/4+115 && evenement.mouseMove.y<=HAUTEUR_FENETRE/4+150))
               {
                   selectionmenu.play();//-----------SON--------------
                   regles.setColor(Color::Red);
               }
               else
               {
                   regles.setColor(Color::Black);
               }

               if((evenement.mouseMove.x>=LARGEUR_FENETRE/2-70 && evenement.mouseMove.x<=LARGEUR_FENETRE/2+90)&&(evenement.mouseMove.y>=HAUTEUR_FENETRE/4+215 && evenement.mouseMove.y<=HAUTEUR_FENETRE/4+250))
               {
                   selectionmenu.play();//-----------SON--------------
                   credit.setColor(Color::Red);
               }
               else
               {
                   credit.setColor(Color::Black);
               }

               if((evenement.mouseMove.x>=LARGEUR_FENETRE/2-70 && evenement.mouseMove.x<=LARGEUR_FENETRE/2+90)&&(evenement.mouseMove.y>=HAUTEUR_FENETRE/4+315 && evenement.mouseMove.y<=HAUTEUR_FENETRE/4+350))
               {
                   selectionmenu.play();//-----------SON--------------
                   quitter.setColor(Color::Red);
               }
               else
               {
                   quitter.setColor(Color::Black);
               }
               break;
//-----------------Si on clique sur le mot rouge --> quitte-----------------------------------------------------------------------------------------------------------
            case Event::MouseButtonPressed:
               if((evenement.mouseButton.x>=LARGEUR_FENETRE/2-70 && evenement.mouseButton.x<=LARGEUR_FENETRE/2+90)&&(evenement.mouseButton.y>=HAUTEUR_FENETRE/4+215 && evenement.mouseButton.y<=HAUTEUR_FENETRE/4+250))
               {
                   musiquemenu.stop();//-----------SON--------------
                   menu.close();
                   affichageCredit();
               }
               if((evenement.mouseButton.x>=LARGEUR_FENETRE/2-70 && evenement.mouseButton.x<=LARGEUR_FENETRE/2+90)&&(evenement.mouseButton.y>=HAUTEUR_FENETRE/4+315 && evenement.mouseButton.y<=HAUTEUR_FENETRE/4+350))
               {
                   menu.close();
               }
               if((evenement.mouseButton.x>=LARGEUR_FENETRE/2-50 && evenement.mouseButton.x<=LARGEUR_FENETRE/2+80)&&(evenement.mouseButton.y>=HAUTEUR_FENETRE/4+15 && evenement.mouseButton.y<=HAUTEUR_FENETRE/4+50))
               {
                   musiquemenu.stop();//-----------SON--------------
                   menu.close();
                   affichageJeu();
               }
               if((evenement.mouseButton.x>=LARGEUR_FENETRE/2-145 && evenement.mouseButton.x<=LARGEUR_FENETRE/2+200)&&(evenement.mouseButton.y>=HAUTEUR_FENETRE/4+115 && evenement.mouseButton.y<=HAUTEUR_FENETRE/4+150))
                {
                    musiquemenu.stop();//-----------SON--------------
                    menu.close();
                    affichageRegles();
                }
               break;
            }
        }
    menu.clear();
    menu.draw(backg);
    menu.draw(jouer);
    menu.draw(regles);
    menu.draw(credit);
    menu.draw(quitter);
    //menu.draw(titre);
    menu.display();;
    }
}
//-----------------------------------FIN_AFFICHAGE_MENU--------------------------------------------------------------------------------------------------------------------------------------------





//-----------------------------------AFFICHAGE_CREDIT--------------------------------------------------------------------------------------------------------------------------------------------
void affichageCredit()
{
    RenderWindow cred(VideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE),"Crédits");


    background.loadFromFile("image/menucredit.png");
    backg.setTexture(background);

    Text nom1,nom2,nom3,nom4,nom5,retour,titre;

    SoundBuffer buffer10;//-----------SON--------------
    if(!buffer10.loadFromFile("son/SelectionMenu.wav"))//-----------SON--------------
        return;//-----------SON--------------
    Sound selectionmenu;//-----------SON--------------
    selectionmenu.setBuffer(buffer10);//-----------SON--------------
    selectionmenu.setVolume(70);//-----------SON--------------

    SoundBuffer buffer5;//-----------SON--------------
    if(!buffer5.loadFromFile("son/MusiqueCredits.wav"))//-----------SON--------------
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
//-----------------------------------FIN_AFFICHAGE_CREDIT--------------------------------------------------------------------------------------------------------------------------------------------



void affichageRegles()
{
    RenderWindow regles(VideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE),"Règles du jeu");

    background.loadFromFile("image/reglemenu.png");
    backg.setTexture(background);

    Text retour;


    SoundBuffer buffer10;//-----------SON--------------
    if(!buffer10.loadFromFile("son/SelectionMenu.wav"))//-----------SON--------------
        return;//-----------SON--------------
    Sound selectionmenu;//-----------SON--------------
    selectionmenu.setBuffer(buffer10);//-----------SON--------------
    selectionmenu.setVolume(70);//-----------SON--------------

    SoundBuffer buffer5;//-----------SON--------------
    if(!buffer5.loadFromFile("son/MusiqueCredits.wav"))//-----------SON--------------
        return;//-----------SON--------------
    Sound musiquecredits;//-----------SON--------------
    musiquecredits.setBuffer(buffer5);//-----------SON--------------
    musiquecredits.setVolume(70);//-----------SON--------------
    musiquecredits.play();//-----------SON--------------
    musiquecredits.setLoop(true);//-----------SON--------------


    retour.setFont(texte);
    retour.setPosition(LARGEUR_FENETRE/2-130,HAUTEUR_FENETRE/3+400);
    retour.setString("ReTour au menu");
    retour.setColor(Color::Black);

    while(regles.isOpen())
    {
        while(regles.pollEvent(evenement))
        {
            switch(evenement.type)
            {
            case Event::Closed:
                regles.close();
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
                    regles.close();
                    affichageMenu();
                }
                break;
            }

        }
        regles.clear();
        regles.draw(backg);
        regles.draw(retour);
        regles.display();
    }
}
