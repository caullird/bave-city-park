#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <cmath>
#include "jeu.h"
#include "gameOver/gameOver.h"
#include "fonctionControleVoiture.h"
#include "../menu.h"
#include "gagne/gagne.h"
#define PASH 3
#define PAS2 4
#define PAS3 6
#define PAS4 6
#define PAS5 7
#define ROTATION 15
#define HAUTEUR_FENETRE 1080
#define LARGEUR_FENETRE 1920

using namespace sf;


void affichageJeu()
{
    Event evenement;


//-------------------------------------------------DEBUT_DES_SONS----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    SoundBuffer buffer2;
    SoundBuffer buffer1;
    SoundBuffer buffer6;
    SoundBuffer buffer7;
    SoundBuffer buffer9;

    if(!buffer1.loadFromFile("son/CollisionPersonne.wav"))
        return;
    if(!buffer2.loadFromFile("son/CollisionVoiture.wav"))
        return;
    if(!buffer6.loadFromFile("son/MusiqueGameOver.wav"))
        return;
    if(!buffer7.loadFromFile("son/MusiqueJeu.wav"))
        return;
    if(!buffer9.loadFromFile("son/Reussite.wav"))
        return;


    Sound collisionpersonne;
    Sound collisionvoiture;
    Sound musiquegameover;
    Sound musiquejeu;
    Sound reussite;

    collisionpersonne.setBuffer(buffer1);
    collisionpersonne.setVolume(70);

    collisionvoiture.setBuffer(buffer2);
    collisionvoiture.setVolume(40);

    musiquegameover.setBuffer(buffer6);
    musiquegameover.setVolume(70);

    musiquejeu.setBuffer(buffer7);
    musiquejeu.setVolume(100);
    musiquejeu.setLoop(true);

    reussite.setBuffer(buffer9);
    reussite.setVolume(70);
//-------------------------------------------------FIN_DES_SONS----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



    Font texte;
    texte.loadFromFile("police/transformers.ttf");


//-------------------------------------------------DEBUT_CHOIX_VOITURE----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    RenderWindow choixV(VideoMode(500,400),"Choix de voiture");

    Texture background;
    Sprite backg;

    background.loadFromFile("image/choixvehicule.png");
    backg.setTexture(background);

    Text choixVoiture;
    Texture v1,v2,v3,v4;
    Sprite choix1,choix2,choix3,choix4;
    Sprite  voiture;

    v1.loadFromFile("image/voiturechantierV2.png");
    v2.loadFromFile("image/voitureaquaV2.png");
    v3.loadFromFile("image/voitureleoV2.png");
    v4.loadFromFile("image/voiturenoirV2.png");
    choix1.setTexture(v1);
    choix2.setTexture(v2);
    choix3.setTexture(v3);
    choix4.setTexture(v4);

    choix1.setPosition(100,100);
    choix2.setPosition(300,100);
    choix3.setPosition(100,300);
    choix4.setPosition(300,300);

    while(choixV.isOpen())
    {
        while(choixV.pollEvent(evenement))
        {
        switch(evenement.type)
        {
          case Event::Closed:
            choixV.close();
            break;
          case Event::MouseMoved:
            if((evenement.mouseMove.x>=100 && evenement.mouseMove.x<=190)&&(evenement.mouseMove.y>=100&&evenement.mouseMove.y<=145))
            {
                choix1.setScale(1.2,1.2);
            }
            else
            {
                choix1.setScale(1,1);
            }
            if((evenement.mouseMove.x>=300 && evenement.mouseMove.x<=390)&&(evenement.mouseMove.y>=100&&evenement.mouseMove.y<=145))
            {
                choix2.setScale(1.2,1.2);
            }
            else
            {
                choix2.setScale(1,1);
            }
            if((evenement.mouseMove.x>=100 && evenement.mouseMove.x<=190)&&(evenement.mouseMove.y>=300&&evenement.mouseMove.y<=345))
            {
                choix3.setScale(1.2,1.2);
            }
            else
            {
                choix3.setScale(1,1);
            }
            if((evenement.mouseMove.x>=300 && evenement.mouseMove.x<=390)&&(evenement.mouseMove.y>=300&&evenement.mouseMove.y<=345))
            {
                choix4.setScale(1.2,1.2);
            }
            else
            {
                choix4.setScale(1,1);
            }
            break;
          case Event::MouseButtonPressed:
            if((evenement.mouseButton.x>=100 && evenement.mouseButton.x<=190)&&(evenement.mouseButton.y>=100&&evenement.mouseButton.y<=145))
            {
                voiture.setTexture(v1);
                choixV.close();
            }
            if((evenement.mouseButton.x>=300 && evenement.mouseButton.x<=390)&&(evenement.mouseButton.y>=100&&evenement.mouseButton.y<=145))
            {
                voiture.setTexture(v2);
                choixV.close();
            }
            if((evenement.mouseButton.x>=100 && evenement.mouseButton.x<=190)&&(evenement.mouseButton.y>=300&&evenement.mouseButton.y<=345))
            {
                voiture.setTexture(v3);
                choixV.close();
            }
            if((evenement.mouseButton.x>=300 && evenement.mouseButton.x<=390)&&(evenement.mouseButton.y>=300&&evenement.mouseButton.y<=345))
            {
                voiture.setTexture(v4);
                choixV.close();
            }
            break;

        }

        }
        choixV.clear();
        choixV.draw(backg);
        choixV.draw(choix1);
        choixV.draw(choix2);
        choixV.draw(choix3);
        choixV.draw(choix4);
        choixV.display();
    }
//-------------------------------------------------FIN_CHOIX_VOITURE----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




    Texture voi;




//-------------------------------------------------INITIALISATION_VARIABLES----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    float positionX=150,positionY=150;
    float depX=0,depY=0;
    float longueurV=90,largeurV=45;
    float angle=0;
    float vitesseVoiture=0,vitesseRotation=0;
    float largeur=500, hauteur=500;
    float largeur2=1970, hauteur2=255;
    float largeur3=-50, hauteur3=365;
    float largeur4=902.5, hauteur4=-50;
    float largeur5=1970, hauteur5=680, rotation=0;
    float largeur6=-50, hauteur6=220, pas=0;
    float largeur7=1050, hauteur7=-50, pas2=0;
    float largeur8=1970, hauteur8=825, pas3=0;
    int win=0;
    int fleche=0;
    int clique=0;
    int coeur=3;


//----------------------------------------------------------FIN_INITIALISATION_VARIABLES------------------------------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------DEBUT_INITIALISATION_PLACE_PARKING------------------------------------------------------------------------------------------------------------------------------------------

    int numPlace=1;
    // Load a sprite to display
    Position pos;
    Position placeActu;
    GenerationPlace(numPlace, &placeActu);
    pos.x=voiture.getPosition().x;
    pos.y=voiture.getPosition().y;
//----------------------------------------------------------FIN_INITIALISATION_PLACE_PARKING------------------------------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------DEBUT_CREATION_DES_HITBOXS------------------------------------------------------------------------------------------------------------------------------------------


    RectangleShape place1(Vector2f(30,50));
    place1.setPosition(1532.5,438);


    RectangleShape a1(Vector2f(43,215));
    a1.setPosition(0,0);

    RectangleShape a2(Vector2f(887.5,240));
    a2.setPosition(1052.5,-20);

    RectangleShape a3(Vector2f(857.5,240));
    a3.setPosition(0,405);

    RectangleShape a12(Vector2f(20,20));
    a12.setPosition(847.5,405);

    RectangleShape a13(Vector2f(23,90));
    a13.setPosition(847.5,555);

    RectangleShape a5(Vector2f(887.5,320));
    a5.setPosition(1052.5,830);

    RectangleShape a6(Vector2f(887.5,20));
    a6.setPosition(1052.5,405);

    RectangleShape a7(Vector2f(20,240));
    a7.setPosition(1052.5,405);

    RectangleShape a14(Vector2f(105,85));
    a14.setPosition(1072.5,425);

    RectangleShape a15(Vector2f(50,105));
    a15.setPosition(1472.5,425);

    RectangleShape a8(Vector2f(180-20-10,40-20));
    a8.setPosition(1052.5,628);

    RectangleShape a9(Vector2f(800,40-20));
    a9.setPosition(1390.5,628);

    RectangleShape a10(Vector2f(240,63));
    a10.setPosition(83-20,0);


    RectangleShape a11(Vector2f(565.5,220));
    a11.setPosition(283+20,0);

    RectangleShape a17(Vector2f(120,40));
    a17.setPosition(1228.5,757);


    RectangleShape a4(Vector2f(105,20));
    a4.setPosition(0,830);

    RectangleShape a18(Vector2f(580,15));
    a18.setPosition(330,830);

    RectangleShape a19(Vector2f(77,250));
    a19.setPosition(0,850);

    RectangleShape a20(Vector2f(380,100));
    a20.setPosition(85,1005);

    RectangleShape a21(Vector2f(405,100));
    a21.setPosition(465,1045);

    RectangleShape a22(Vector2f(107,400));
    a22.setPosition(763,850);


//----------------------------------------------------------FIN_CREATION_DES_HITBOXS------------------------------------------------------------------------------------------------------------------------------------------


    musiquejeu.play();

    Texture huilepng;
    Sprite huile;
    huilepng.loadFromFile("image/huileV2.png");
    huile.setTexture(huilepng);
    huile.setOrigin(20,20);
    huile.setPosition(500,760);
    RectangleShape huileH(Vector2f(10,10));
    huileH.setOrigin(10,10),
    huileH.setPosition(505,765);
    huileH.setFillColor(Color::Red);


    Texture Niveau1png;
    Sprite Niveau1;
    Niveau1png.loadFromFile("image/niveau1.png");
    Niveau1.setTexture(Niveau1png);
    Niveau1.setPosition(1073,0);

    Texture Niveau2png;
    Sprite Niveau2;
    Niveau2png.loadFromFile("image/niveau2.png");
    Niveau2.setTexture(Niveau2png);
    Niveau2.setPosition(1073,0);

    Texture Niveau3png;
    Sprite Niveau3;
    Niveau3png.loadFromFile("image/niveau3.png");
    Niveau3.setTexture(Niveau3png);
    Niveau3.setPosition(1073,0);

    Texture PanneauNiveau1png;
    Sprite PanneauNiveau1;
    PanneauNiveau1png.loadFromFile("image/paneauniveau1.png");
    PanneauNiveau1.setTexture(PanneauNiveau1png);
    PanneauNiveau1.setPosition(1423,60);

    Texture PanneauNiveau2png;
    Sprite PanneauNiveau2;
    PanneauNiveau2png.loadFromFile("image/paneauniveau2.png");
    PanneauNiveau2.setTexture(PanneauNiveau2png);
    PanneauNiveau2.setPosition(1423,60);

    RenderWindow jeu(VideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE),"Jeu",Style::Fullscreen);
    voiture.setOrigin(longueurV/2,largeurV/2);
    voiture.setPosition(positionX,positionY);
    jeu.draw(voiture);
    jeu.display();


while (jeu.isOpen())
    {
        depX=cos(angle*M_PI/180)*vitesseVoiture;
        depY=sin(angle*M_PI/180)*vitesseVoiture;


        while (jeu.pollEvent(evenement))
        {
            switch (evenement.type)
            {
            case Event::Closed:
                jeu.close();
                break;
            case Event::KeyReleased:
                if(evenement.key.code==Keyboard::Up)        //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                {                                           //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                    vitesseVoiture=0;                       //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                }                                           //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                if(evenement.key.code==Keyboard::Down)      //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                {                                           //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                    vitesseVoiture=0;                       //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                }                                           //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                if(evenement.key.code==Keyboard::Right)     //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                {                                           //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                    vitesseRotation=0;                      //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                }                                           //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                if(evenement.key.code==Keyboard::Left)      //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                {                                           //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                    vitesseRotation=0;                      //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                }                                           //REINITIALISATION DE VITESSE QUAND ON RELACHE LA TOUCHE
                break;
            case Event::KeyPressed:
                if(evenement.key.code==Keyboard::F1)//NAVIGUATION DANS LE NIVEAU
                    numPlace=1;//NAVIGUATION DANS LE NIVEAU
                if(evenement.key.code==Keyboard::F2)//NAVIGUATION DANS LE NIVEAU
                    numPlace=2;//NAVIGUATION DANS LE NIVEAU
                if(evenement.key.code==Keyboard::F3)//NAVIGUATION DANS LE NIVEAU
                    numPlace=3;//NAVIGUATION DANS LE NIVEAU
                if(evenement.key.code==Keyboard::F4)//NAVIGUATION DANS LE NIVEAU
                    numPlace=4;//NAVIGUATION DANS LE NIVEAU
                if(evenement.key.code==Keyboard::F5)//NAVIGUATION DANS LE NIVEAU
                    coeur=-1;//NAVIGUATION DANS LE NIVEAU

            case Event::MouseButtonPressed:
                if((evenement.mouseButton.x>=1850 && evenement.mouseButton.x<=1910)&&(evenement.mouseButton.y>=15 && evenement.mouseButton.y<=70))
                    jeu.close();
                if((evenement.mouseButton.x>=1850 && evenement.mouseButton.x<=1910)&&(evenement.mouseButton.y>=75 && evenement.mouseButton.y<=130))
                {
                    jeu.close();
                    affichageMenu();
                }
                if((evenement.mouseButton.x>=1850 && evenement.mouseButton.x<=1910)&&(evenement.mouseButton.y>=135 && evenement.mouseButton.y<=190))
                {
                    if(clique==0)
                    {
                        musiquejeu.stop();
                        clique++;
                    }
                    else if(clique==1)
                    {
                        musiquejeu.play();
                        clique--;
                    }

                }


            }

        }


    //----------------------------------------------------------DEBUT_DES_FONCTIONS_DE_MOUVEMENTS------------------------------------------------------------------------------------------------------------------------------------------
            if(Keyboard::isKeyPressed(Keyboard::Down))
                {
                    if(angle==0)
                        positionX--;
                    vitesseVoiture+=0.2;
                    if(vitesseVoiture>6)
                        vitesseVoiture-=0.2;
                    voiture.move(-depX,depY);
                }
            if(Keyboard::isKeyPressed(Keyboard::Up))
                {
                    if(angle==0)
                        positionX++;
                    vitesseVoiture+=0.2;
                    if(vitesseVoiture>6)
                        vitesseVoiture-=0.2;
                    voiture.move(depX,-depY);
                }
            if((Keyboard::isKeyPressed(Keyboard::Right)&&Keyboard::isKeyPressed(Keyboard::Up))||(Keyboard::isKeyPressed(Keyboard::Right)&&Keyboard::isKeyPressed(Keyboard::Down)))
                {
                    vitesseRotation+=0.6;
                    if(vitesseRotation>6)
                    {
                        vitesseRotation-=0.6;
                    }
                    if(angle<=-180)
                    {
                        angle=180;
                    }

                    voiture.rotate(vitesseRotation);
                    angle=angle-vitesseRotation;
                }
            if((Keyboard::isKeyPressed(Keyboard::Left)&&Keyboard::isKeyPressed(Keyboard::Up))||(Keyboard::isKeyPressed(Keyboard::Left)&&Keyboard::isKeyPressed(Keyboard::Down)))
                {
                    vitesseRotation+=0.6;
                    if(vitesseRotation>6)
                    {
                        vitesseRotation-=0.6;
                    }
                    if(angle>=180)
                    {
                        angle=-180;
                    }

                    voiture.rotate(-vitesseRotation);
                    angle=angle+vitesseRotation;
                }
//----------------------------------------------------------FIN_DES_FONCTIONS_DE_MOUVEMENTS------------------------------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------DEBUT_DE_LA_MAP------------------------------------------------------------------------------------------------------------------------------------------

        Texture fonduniquepng;

        if (!fonduniquepng.loadFromFile("image/fondunique.png"))
            printf("Erreur chargement fondunique.png\n");

        Sprite Fondunique;
        Fondunique.setTexture(fonduniquepng);

        Fondunique.setPosition(0,0);


        jeu.draw(Fondunique);
//----------------------------------------------------------FIN_DE_LA_MAP------------------------------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------DEBUT_VOITURE-PLACE ------------------------------------------------------------------------------------------------------------------------------------------

         Texture voiturepngG1 ;

        if (!voiturepngG1.loadFromFile("image/voiturenoirV2.png"))
            printf("PB de chargement de l'image !\n" );

        Sprite voitureG1;
        voitureG1.setTexture(voiturepngG1);

        voitureG1.setPosition(595,941);
        voitureG1.rotate(90);


         Texture voiturepngG2 ;

        if (!voiturepngG2.loadFromFile("image/voitureaquaV2.png"))
            printf("PB de chargement de l'image !\n" );

        Sprite voitureG2;
        voitureG2.setTexture(voiturepngG2);

        voitureG2.setPosition(530,941);
        voitureG2.rotate(90);


         Texture voiturepngG3 ;

        if (!voiturepngG3.loadFromFile("image/voiturechantierV2.png"))
            printf("PB de chargement de l'image !\n" );

        Sprite voitureG3;
        voitureG3.setTexture(voiturepngG3);

        voitureG3.setPosition(1250,440);
        voitureG3.rotate(90);

         Texture voiturepngG4 ;

        if (!voiturepngG4.loadFromFile("image/voitureleoV2invers.png"))
            printf("PB de chargement de l'image !\n" );

        Sprite voitureG4;
        voitureG4.setTexture(voiturepngG4);

        voitureG4.setPosition(1300,440);
        voitureG4.rotate(90);

        Texture voiturepngG5 ;

        if (!voiturepngG5.loadFromFile("image/voiturenoirV2.png"))
            printf("PB de chargement de l'image !\n" );

        Sprite voitureG5;
        voitureG5.setTexture(voiturepngG5);

        voitureG5.setPosition(1350,440);
        voitureG5.rotate(90);


         Texture voiturepngG6 ;

        if (!voiturepngG6.loadFromFile("image/voitureaquaV2.png"))
            printf("PB de chargement de l'image !\n" );

        Sprite voitureG6;
        voitureG6.setTexture(voiturepngG6);

        voitureG6.setPosition(1462,440);
        voitureG6.rotate(90);

         Texture voiturepngG7 ;

        if (!voiturepngG7.loadFromFile("image/voiturechantierV2.png"))
            printf("PB de chargement de l'image !\n" );

        Sprite voitureG7;
        voitureG7.setTexture(voiturepngG7);

        voitureG7.setPosition(1250,440);
        voitureG7.rotate(90);

         Texture voiturepngG8 ;

        if (!voiturepngG8.loadFromFile("image/voitureleoV2invers.png"))
            printf("PB de chargement de l'image !\n" );

        Sprite voitureG8;
        voitureG8.setTexture(voiturepngG8);

        voitureG8.setPosition(1580,440);
        voitureG8.rotate(90);

         Texture voiturepngG9 ;

        if (!voiturepngG9.loadFromFile("image/voitureaquaV2.png"))
            printf("PB de chargement de l'image !\n" );

        Sprite voitureG9;
        voitureG9.setTexture(voiturepngG9);

        voitureG9.setPosition(1820,440);
        voitureG9.rotate(90);

         Texture voiturepngG10 ;

        if (!voiturepngG10.loadFromFile("image/voitureleoV2invers.png"))
            printf("PB de chargement de l'image !\n" );

        Sprite voitureG10;
        voitureG10.setTexture(voiturepngG10);

        voitureG10.setPosition(1758,440);
        voitureG10.rotate(90);

        jeu.draw(voitureG1);
        jeu.draw(voitureG2);
        jeu.draw(voitureG3);
        jeu.draw(voitureG4);
        jeu.draw(voitureG5);
        jeu.draw(voitureG6);
        jeu.draw(voitureG7);
        jeu.draw(voitureG8);
        jeu.draw(voitureG9);
        jeu.draw(voitureG10);

//----------------------------------------------------------FIN_VOITURE-PLACE ------------------------------------------------------------------------------------------------------------------------------------------




//----------------------------------------------------------DEBUT_PANNEAU ------------------------------------------------------------------------------------------------------------------------------------------

        Texture totalpng ;

        if (!totalpng.loadFromFile("image/total.png"))
            printf("PB de chargement de l'image !\n" );

        Sprite total;
        total.setTexture(totalpng);

        total.setPosition(1073,0);

        jeu.draw(total);

        Texture panneaupng;

        if (!panneaupng.loadFromFile("image/panneau.png"))
            printf("Erreur chargement panneau.png\n");

        Sprite panneau;
        panneau.setTexture(panneaupng);

        panneau.setPosition(1630,5);

        RectangleShape rectPanneau((Vector2f(400,800)));
        rectPanneau.setFillColor(Color::Red);
        rectPanneau.setPosition(750,100);

        if (voiture.getGlobalBounds().intersects(rectPanneau.getGlobalBounds()))
        jeu.draw(panneau);
//----------------------------------------------------------FIN_PANNEAU---------------------------------------------------------------------------------------------------------------




//----------------------------------------------------------DEBUT_VOITURE_2------------------------------------------------------------------------------------------------------------------------------------------

        Texture voiturepng2 ;

        if (!voiturepng2.loadFromFile("image/voiturenoirV2.png"))
            printf("PB de chargement de l'image !\n" );

        Sprite voiture2;
        voiture2.setTexture(voiturepng2);

        if ((largeur2<1155 && largeur2>1065) && ((hauteur4>-20 && hauteur4<270) || ((hauteur5<=680 && hauteur5>200) && (largeur5<1200))))
            largeur2+=PAS2;

        largeur2-=PAS2;
        voiture2.setPosition(largeur2, hauteur2);
        voiture2.setOrigin(45/2, 90/2);
        voiture2.rotate(180);
        jeu.draw(voiture2);

        if (largeur2<-100)
            largeur2=1970;

//----------------------------------------------------------FIN_VOITURE_2------------------------------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------DEBUT_VOITURE_3------------------------------------------------------------------------------------------------------------------------------------------

        Texture voiturepng3 ;

        if (!voiturepng3.loadFromFile("image/voitureaquaV2.png"))
            printf("PB de chargement de l'image !\n" );

        Sprite voiture3;
        voiture3.setTexture(voiturepng3);

        if ((largeur3>750 && largeur3<760)&& ((hauteur4>0 && hauteur4<400) || ((hauteur5<=680 && hauteur5>200) && (largeur5<1200))))
            largeur3-=PAS3;

        largeur3+=PAS3;
        voiture3.setPosition(largeur3, hauteur3);
        voiture3.setOrigin(45/2, 90/2);
        jeu.draw(voiture3);

        if (largeur3>2020)
            largeur3=-50;

//----------------------------------------------------------FIN_VOITURE_3------------------------------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------DEBUT_VOITURE_4------------------------------------------------------------------------------------------------------------------------------------------

         Texture voiturepng4 ;

        if (!voiturepng4.loadFromFile("image/voiturechantierV2.png"))
            printf("PB de chargement de l'image !\n" );

        Sprite voiture4;
        voiture4.setTexture(voiturepng4);
        hauteur4+=PAS4;
        voiture4.setPosition(largeur4, hauteur4);
        voiture4.setOrigin(45/2, 90/2);
        voiture4.rotate(90);
        jeu.draw(voiture4);

        if (hauteur4>1150)
            hauteur4=-50;

//----------------------------------------------------------FIN_VOITURE_4------------------------------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------DEBUT_VOITURE_5------------------------------------------------------------------------------------------------------------------------------------------

        Texture voiturepng5 ;

        if (!voiturepng5.loadFromFile("image/voitureleoV2invers.png"))
            printf("PB de chargement de l'image !\n" );

        Sprite voiture5;
        voiture5.setTexture(voiturepng5);

        if (largeur5>1012.5)
        {
            largeur5-=PAS5;
            hauteur5+=PAS5;
        }
        else if (largeur5<1012.5 && rotation!=90)
            rotation+=ROTATION;

        hauteur5-=PAS5;
        voiture5.rotate(rotation);
        voiture5.setPosition(largeur5, hauteur5);
        jeu.draw(voiture5);

        if (hauteur5<-100)
        {
            hauteur5=680;
            largeur5=1970;
            rotation=0;
        }
//----------------------------------------------------------FIN_VOITURE_5------------------------------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------DEBUT_HUMAIN------------------------------------------------------------------------------------------------------------------------------------------


        Texture humainpngr ;
        if (!humainpngr.loadFromFile("image/right.png"))
            printf("PB de chargement de l'image !\n" );
        Sprite characterR;
        characterR.setTexture(humainpngr);
        Texture humainpngl ;
        if (!humainpngl.loadFromFile("image/left.png"))
            printf("PB de chargement de l'image !\n" );
        Sprite characterL;
        characterL.setTexture(humainpngl);
       if (largeur6>=62 && largeur6<=100 && hauteur6>=67)
        {
            hauteur6-=PASH;
            characterL.rotate(-90);
            characterR.rotate(-90);
        }
        else if (hauteur6<=67 && largeur6<=298)
        {
            largeur6+=PASH;
        }
        else if (largeur6>=298 && hauteur6<=218)
        {
            hauteur6+=PASH;
            characterL.rotate(90);
            characterR.rotate(90);
        }
        else if (hauteur6>=218, largeur6<870)
            largeur6+=PASH;
        else if (largeur6>=870 && hauteur6<645)
        {
            hauteur6+=PASH;
            characterL.rotate(90);
            characterR.rotate(90);
        }
        else if (hauteur6>=645)
            largeur6+=PASH;
        if (largeur6>2000)
        {
            largeur6=-50;
            hauteur6=220;
        }
        if ( (largeur6>=870) && ((largeur2>750 && largeur2<1200) || ((largeur3>510 && largeur3<920))) && (hauteur6<=230))
        {
            hauteur6-=PASH;
            pas=0;
        }
        else if ( (hauteur6>=645) && ((hauteur4>385 && hauteur4<700) || ((hauteur5>385 && hauteur5<=700) && (largeur5<1300))) && (largeur6>=870 && largeur6<=880))
        {
            largeur6-=PASH;
            pas=0;
        }

        characterL.setOrigin(20,20);
        characterR.setOrigin(20,20);
        characterL.rotate(90);
        characterR.rotate(90);
        characterL.setPosition(largeur6, hauteur6);
        characterR.setPosition(largeur6, hauteur6);
        pas++;
        if (pas==1)
            jeu.draw(characterL);
        else if (pas==2)
            jeu.draw(characterL);
        else if (pas==3)
            jeu.draw(characterL);
        else if (pas==4)
            jeu.draw(characterL);
        else if (pas==5)
            jeu.draw(characterL);
        else if (pas==6)
            jeu.draw(characterR);
        else if (pas==7)
            jeu.draw(characterR);
        else if (pas==8)
            jeu.draw(characterR);
        else if (pas==9)
            jeu.draw(characterR);
        else if (pas==10)
        {
            jeu.draw(characterR);
            pas=0;
        }

//----------------------------------------------------------FIN_HUMAIN------------------------------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------DEBUT_HUMAIN_2------------------------------------------------------------------------------------------------------------------------------------------


        Texture humainpng2L ;
        if (!humainpng2L.loadFromFile("image/left.png"))
            printf("PB de chargement de l'image !\n" );
        Sprite character2L;
        character2L.setTexture(humainpng2L);
        Texture humainpng2R ;
        if (!humainpng2R.loadFromFile("image/right.png"))
            printf("PB de chargement de l'image !\n" );
        Sprite character2R;
        character2R.setTexture(humainpng2R);
        if (hauteur7<650)
            hauteur7+=PASH;
        else if (largeur7>-50 && hauteur7>=650)
        {
            largeur7-=PASH;
            character2L.rotate(90);
            character2R.rotate(90);
        }
        else if (largeur7<=-50)
        {
            hauteur7=-50;
            largeur7=1050;
        }
        if ((hauteur7>=200 && hauteur7<=240) && ((largeur2>960 && largeur2<1500) || (largeur3>800 && largeur3<1100)) )
        {
            hauteur7-=PASH;
            pas2=0;
        }
        else if ( (hauteur7>=650) && ((hauteur4>385 && hauteur4<700) || ((hauteur5>385 && hauteur5<700) && (largeur5<1300))) && (largeur7>1020))
        {
            pas2=0;
            largeur7+=PASH;
        }

        character2L.setOrigin(20,20);
        character2R.setOrigin(20,20);
        character2L.rotate(180);
        character2R.rotate(180);
        character2L.setPosition(largeur7,hauteur7);
        character2R.setPosition(largeur7,hauteur7);
        pas2++;
        if (pas2==1)
            jeu.draw(character2L);
        else if (pas2==2)
            jeu.draw(character2L);
        else if (pas2==3)
            jeu.draw(character2L);
        else if (pas2==4)
            jeu.draw(character2L);
        else if (pas2==5)
            jeu.draw(character2L);
        else if (pas2==6)
            jeu.draw(character2R);
        else if (pas2==7)
            jeu.draw(character2R);
        else if (pas2==8)
            jeu.draw(character2R);
        else if (pas2==9)
            jeu.draw(character2R);
        else if (pas2==10)
        {
            jeu.draw(character2R);
            pas2=0;
        }

//----------------------------------------------------------FIN_HUMAIN_2------------------------------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------DEBUT_HUMAIN_3------------------------------------------------------------------------------------------------------------------------------------------

        Texture humainpng3L ;
        if (!humainpng3L.loadFromFile("image/left.png"))
            printf("PB de chargement de l'image !\n" );
        Sprite character3L;
        character3L.setTexture(humainpng3L);
        Texture humainpng3R ;
        if (!humainpng3R.loadFromFile("image/right.png"))
            printf("PB de chargement de l'image !\n" );
        Sprite character3R;
        character3R.setTexture(humainpng3R);
        largeur8-=PASH;
        if ((hauteur4>300 && hauteur4<900) && (largeur8>1040 && largeur8<1060))
        {
            largeur8+=PASH;
            pas3=0;
        }
        else if(largeur8<-50)
            largeur8=1970;

        character3L.setOrigin(20,20);
        character3R.setOrigin(20,20);
        character3L.rotate(-90);
        character3R.rotate(-90);
        character3L.setPosition(largeur8,hauteur8);
        character3R.setPosition(largeur8,hauteur8);
        pas3++;
        if (pas3==1)
            jeu.draw(character3L);
        else if (pas3==2)
            jeu.draw(character3L);
        else if (pas3==3)
            jeu.draw(character3L);
        else if (pas3==4)
            jeu.draw(character3L);
        else if (pas3==5)
            jeu.draw(character3L);
        else if (pas3==6)
            jeu.draw(character3R);
        else if (pas3==7)
            jeu.draw(character3R);
        else if (pas3==8)
            jeu.draw(character3R);
        else if (pas3==9)
            jeu.draw(character3R);
        else if (pas3==10)
        {
            jeu.draw(character3R);
            pas3=0;
        }

//----------------------------------------------------------FIN_HUMAIN_3------------------------------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------DEBUT_FLECHE------------------------------------------------------------------------------------------------------------------------------------------

        Texture flechebpng ;
        if (!flechebpng.loadFromFile("image/flecheb.png"))
            printf("PB de chargement de l'image !\n" );
        Sprite flecheb;
        flecheb.setTexture(flechebpng);

        flecheb.setOrigin(25,20);

        Texture flechenpng ;
        if (!flechenpng.loadFromFile("image/flechen.png"))
            printf("PB de chargement de l'image !\n" );
        Sprite flechen;
        flechen.setTexture(flechenpng);

        flechen.setOrigin(25,20);

//----------------------------------------------------------FIN_FLECHE------------------------------------------------------------------------------------------------------------------------------------------




//----------------------------------------------------------DEBUT_DES_TESTS_COLLISIONS------------------------------------------------------------------------------------------------------------------------------------------

         if(voiture.getGlobalBounds().intersects(huile.getGlobalBounds()) && numPlace !=1)
         {
                vitesseVoiture+=1;
                voiture.move(depX,depY);
         }


        if(voiture.getGlobalBounds().intersects(voiture2.getGlobalBounds()) || voiture.getGlobalBounds().intersects(voiture3.getGlobalBounds()) || voiture.getGlobalBounds().intersects(voiture4.getGlobalBounds()) || voiture.getGlobalBounds().intersects(voiture5.getGlobalBounds()))
        {
            positionX=150;
            positionY=150;
            voiture.setPosition(positionX,positionY);
            coeur--;
            collisionvoiture.play();
            sleep(milliseconds(500));
        }


        if(voiture.getGlobalBounds().intersects(characterL.getGlobalBounds()) ||
           voiture.getGlobalBounds().intersects(characterR.getGlobalBounds()) ||
           voiture.getGlobalBounds().intersects(character2L.getGlobalBounds()) ||
           voiture.getGlobalBounds().intersects(character2R.getGlobalBounds()) ||
           voiture.getGlobalBounds().intersects(character3L.getGlobalBounds()) ||
           voiture.getGlobalBounds().intersects(character3R.getGlobalBounds()))
        {
            positionX=150;
            positionY=150;
            voiture.setPosition(positionX,positionY);
            coeur--;
            collisionpersonne.play();
            sleep(milliseconds(500));
        }


        if(voiture.getGlobalBounds().intersects(a1.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a2.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a3.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a4.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a5.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a6.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a7.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a8.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a9.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a10.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a11.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a13.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a14.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a15.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a17.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a18.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a19.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a20.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(a22.getGlobalBounds()))
        {
            positionX=150;
            positionY=150;
            voiture.setPosition(positionX,positionY);
            coeur--;
            collisionpersonne.play();
            sleep(milliseconds(500));
        }

        if(voiture.getGlobalBounds().intersects(voitureG1.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(voitureG2.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(voitureG3.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(voitureG4.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(voitureG5.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(voitureG6.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(voitureG7.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(place1.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(voitureG9.getGlobalBounds()) ||
                voiture.getGlobalBounds().intersects(voitureG10.getGlobalBounds()))
        {
            positionX=150;
            positionY=150;
            voiture.setPosition(positionX,positionY);
            coeur--;
            collisionpersonne.play();
            sleep(milliseconds(500));
        }

//----------------------------------------------------------FIN_DES_TESTS_COLLISIONS------------------------------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------DEBUT_VIE------------------------------------------------------------------------------------------------------------------------------------------



        Texture coeur3png ;
        if (!coeur3png.loadFromFile("image/coeur3.png"))
            printf("PB de chargement de l'image !\n" );
        Sprite coeur3;
        coeur3.setTexture(coeur3png);
        Texture coeur2png ;
        if (!coeur2png.loadFromFile("image/coeur2.png"))
            printf("PB de chargement de l'image !\n" );
        Sprite coeur2;
        coeur2.setTexture(coeur2png);
        Texture coeur1png ;
        if (!coeur1png.loadFromFile("image/coeur1.png"))
            printf("PB de chargement de l'image !\n" );
        Sprite coeur1;
        coeur1.setTexture(coeur1png);

        coeur3.setPosition(1100,40);
        coeur2.setPosition(1100,40);
        coeur1.setPosition(1100,40);

        if (coeur==3)
            jeu.draw(coeur3);
        else if (coeur==2)
            jeu.draw(coeur2);
        else if (coeur==1)
            jeu.draw(coeur1);
        else if (coeur==0)
            coeur--;
        else if (coeur==-1){
            sleep(milliseconds(1000));
            musiquejeu.stop();
            jeu.close();
            affichageGameOver();
        }


//----------------------------------------------------------FIN_VIE---------------------------------------------------------------------------------------------------------------------




//----------------------------------------------------------DEBUT_PLACE-PARKING------------------------------------------------------------------------------------------------------------------------------------------
        pos.x=voiture.getPosition().x;
        pos.y=voiture.getPosition().y;
        TestGarage(&pos, placeActu.x, placeActu.y, &numPlace);
        GenerationPlace(numPlace, &placeActu);



        if(numPlace == 1)
    {
        flecheb.setPosition(1625.5-3,493+60);
        flecheb.rotate(-90);
        flechen.setPosition(1625.5-3,493+60);
        flechen.rotate(-90);
        jeu.draw(Niveau1);
        jeu.draw(PanneauNiveau1);

    }
    else if(numPlace == 2)
    {
        flecheb.setPosition(710,910);
        flecheb.rotate(+90);
        flechen.setPosition(710,910);
        flechen.rotate(+90);
        jeu.draw(huile);
        //jeu.draw(huileH);
        jeu.draw(Niveau2);
        jeu.draw(PanneauNiveau2);
        if(win==0)
        {
            coeur=3;
            voiture.setPosition(positionX,positionY);
            sleep(milliseconds(500));
            win++;
        }

    }

    else if(numPlace == 3)
    {
        flecheb.setPosition(1625.5-400,493+70);
        flecheb.rotate(+180);
        flechen.setPosition(1625.5-400,493+70);
        flechen.rotate(+180);
        jeu.draw(huile);
        //jeu.draw(huileH);
        jeu.draw(Niveau3);
        jeu.draw(PanneauNiveau1);
        if(win==1)
        {
            win++;
            voiture.setPosition(positionX,positionY);
            sleep(milliseconds(500));
        }
    } // la fenêtre dessine le rectangle

    else if(numPlace == 4)
    {
        sleep(milliseconds(1000));
        musiquejeu.stop();
        jeu.close();
        affichageGagne();
    }



    if (fleche==0)
            jeu.draw(flechen);
        else if (fleche==1)
            jeu.draw(flechen);
        else if (fleche==2)
            jeu.draw(flechen);
        else if (fleche==3)
            jeu.draw(flecheb);
        else if (fleche==4)
            jeu.draw(flecheb);
        else if (fleche==5)
            jeu.draw(flecheb);
        else if (fleche==6)
        {
            jeu.draw(flecheb);
            fleche=0;
        }
        fleche++;

//----------------------------------------------------------FIN_PLACE_PARKING------------------------------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------DEBUT_LIMITES------------------------------------------------------------------------------------------------------------------------------------------
    if(pos.x >= 1965)
        voiture.setPosition(-30, pos.y);
    if(pos.x<=-31)
        voiture.setPosition(1960, pos.y);
    if(pos.y >= 1121)
        voiture.setPosition(pos.x, -30);
    if(pos.y <= -31)
        voiture.setPosition(pos.x, 1120);

//----------------------------------------------------------FIN_LIMITES----------------------------------------------------------------------------------------------------------------

            jeu.draw(voiture);
            jeu.display();
            jeu.setFramerateLimit(40);
    }
}
