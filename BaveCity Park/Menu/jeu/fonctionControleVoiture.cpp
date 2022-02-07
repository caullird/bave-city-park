#include "fonctionControleVoiture.h"

void TestGarage(Position *pos, float PX, float PY, int *numPlace)
{
    if(pos->x-TAILLEVOITUREX/2>PX && pos->x+TAILLEVOITUREX/2<PX+TAILLEPLACEX && pos->y-TAILLEVOITUREY/2>PY && pos->y+35<TAILLEPLACEY+PY && (*numPlace <=2))
    {
        *numPlace+=1;
        //printf("Vous etes gares \n");
    }
    if(pos->x-TAILLEVOITUREY/2>PX && pos->x+TAILLEVOITUREX/2<PX+PROPORTIONPLACEY && pos->y-TAILLEVOITUREX/2>PY && pos->y+23<PROPORTIONPLACE2X+PY && (*numPlace > 2))
    {
        *numPlace+=1;
        //printf("Vous etes gares \n");
    }




}

void GenerationPlace(int numPlace,Position *placeActu)
{
    if(numPlace==1)
    {
        placeActu->x=1587,5;
        placeActu->y=438;
    }
    else if(numPlace==2)
    {
        placeActu->x=669;
        placeActu->y=941;
    }
    else if(numPlace>=3)
    {
        placeActu->x=1102.5;
        placeActu->y=530;
    }
    else
        printf("Erreur numero de place \n");
}
void draw(RenderWindow *fenetre, float posx, float posy, float placeActux, float placeActuy , int numPlace)
{

    RectangleShape voiture(Vector2f(TAILLEVOITUREX, TAILLEVOITUREY));
    voiture.setOrigin(TAILLEVOITUREX/2, TAILLEVOITUREY/2);
    voiture.setFillColor(Color ::Blue) ;
    voiture.setPosition(posx, posy);
    RectangleShape BordG(Vector2f(PROPORTIONPLACEX, PROPORTIONPLACEY));
    BordG.setPosition(placeActux,placeActuy);
    RectangleShape BordD(Vector2f(PROPORTIONPLACEX, PROPORTIONPLACEY));
    BordD.setPosition(placeActux+PROPORTIONPLACE2X,placeActuy);
    RectangleShape BordB(Vector2f(PROPORTIONPLACE2X, PROPORTIONPLACEX));
    BordB.setPosition(placeActux+PROPORTIONPLACEX,placeActuy+PROPORTIONPLACEY);
    RectangleShape BordH(Vector2f(PROPORTIONPLACE2X, PROPORTIONPLACEX));
    BordH.setPosition(placeActux+PROPORTIONPLACEX,placeActuy);

    RectangleShape BordB2(Vector2f(PROPORTIONPLACEY, PROPORTIONPLACEX));
    BordB2.setPosition(placeActux,placeActuy+PROPORTIONPLACE2X);
    RectangleShape BordH2(Vector2f(PROPORTIONPLACEY, PROPORTIONPLACEX));
    BordH2.setPosition(placeActux,placeActuy);
    RectangleShape BordG2(Vector2f(PROPORTIONPLACEX, PROPORTIONPLACE2X));
    BordG2.setPosition(placeActux,placeActuy);


    voiture.setPosition(posx, posy);
    if(numPlace == 1)
    {
        fenetre->draw(BordH); // la fenêtre dessine le rectangle
        fenetre->draw(BordD); // la fenêtre dessine le rectangle
        fenetre->draw(BordG); // la fenêtre dessine le rectangle
    }
    else if(numPlace == 2)
    {
        fenetre->draw(BordB); // la fenêtre dessine le rectangle
        fenetre->draw(BordD); // la fenêtre dessine le rectangle
        fenetre->draw(BordG); // la fenêtre dessine le rectangle
    }

    else if(numPlace == 3)
    {
        voiture.rotate(90);
        fenetre->draw(BordH2); // la fenêtre dessine le rectangle
        fenetre->draw(BordB2); // la fenêtre dessine le rectangle
        fenetre->draw(BordG2); // la fenêtre dessine le rectangle
    }

    fenetre->draw(voiture); // la fenêtre dessine le rectangle
    fenetre->display(); // la fenêtre affiche son ou ses dessins
}
