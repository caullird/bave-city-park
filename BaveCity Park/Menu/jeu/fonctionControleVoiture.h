#include <SFML/Graphics.hpp>
#include <math.h>
#define TAILLEVOITUREX 45
#define TAILLEVOITUREY 90
#define TAILLEPLACEX 69
#define TAILLEPLACEY 95
#define PROPORTIONPLACEX 5
#define PROPORTIONPLACEY 95
#define PROPORTIONPLACE2X 69
using namespace sf;
typedef struct
{
    float x, y;
} Position;

void TestGarage(Position *pos, float PX, float PY, int *numPlace);
void GenerationPlace(int numPlace,Position *placeActu);
void draw(RenderWindow *fenetre, float posx, float posy, float placeActux, float placeActuy, int numPlace);

