#pragma once
#include "SFML/Graphics.hpp"
#define NB_MAX_CREDIT 1
using namespace sf;


class Credit
{
public:
    Credit(float width, float height);


    void draw(RenderWindow &fenetre);
    void MvmHaut();
    void MvmBas();
    int GetPressedItem() {return selectedItemIndex; }

private:
    int selectedItemIndex;
    Font font;
    Text cred[NB_MAX_CREDIT];
};
