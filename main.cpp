/**
*** Code developpe par Guillaume LEMONNIER
*** Tous droits reserve
**/

/**
- vitesse moyenne = 20 000 pixels par seconde
**/

#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

sf::Image open_image(const char *NAME_IMAGE)
{
    sf::Image IMAGE;
    if(!IMAGE.loadFromFile(NAME_IMAGE))
    {
        cout << "error" << endl;
    }
    return IMAGE;
}

unsigned int receve_width_image(Image IMAGE)
{
    return IMAGE.getSize().x;
}

unsigned int receve_height_image(Image IMAGE)
{
    return IMAGE.getSize().y;
}

unsigned int pourcentage(unsigned int VALEUR_ACTUELLE, unsigned int VALEUR_FINALE)
{
    unsigned int RESULTAT;
    RESULTAT = (VALEUR_ACTUELLE * 100) / VALEUR_FINALE;
    return RESULTAT;
}


unsigned int color_one_pixel(Image IMAGE, unsigned int x, unsigned int y)
{
    sf::Color COLOR;
    unsigned int GRIS;
    COLOR = IMAGE.getPixel(x, y);
    GRIS = (COLOR.r + COLOR.g + COLOR.b) / 3;
    return GRIS;
}

char choix_ascii(unsigned int NIVEAU_GRIS, const char *ASCII)
{
    unsigned int NOMBRE_SIGNE_POSSIBLE;
    char SIGNE_CHOISI = {'1'};
    NOMBRE_SIGNE_POSSIBLE = 255 / (sizeof(ASCII) / 4);
    for(unsigned int x = 0; x < sizeof(ASCII) / 4; x ++)
    {
        if(255 != NIVEAU_GRIS && 0 != NIVEAU_GRIS)
        {

            if(NOMBRE_SIGNE_POSSIBLE * x < NIVEAU_GRIS) 
            {
                if(NIVEAU_GRIS <= NOMBRE_SIGNE_POSSIBLE * (x + 1))
                {
                    SIGNE_CHOISI = ASCII[x];
                    return SIGNE_CHOISI;
                }
            }
        }
        else if(255 != NIVEAU_GRIS)
        {
            SIGNE_CHOISI = ASCII[0];
            return SIGNE_CHOISI;
        }
        else
        {
            SIGNE_CHOISI = ASCII[(sizeof(ASCII) / 4) - 1];
            return SIGNE_CHOISI;
        }
    }
    return SIGNE_CHOISI;
}


int main()
{
    unsigned int HEIGHT, WIDTH, NIVEAU_GRIS, POURCENTAGE;
    const char *NAME_IMAGE = "image/paysage_2.jpg";
    const char ASCII[] = {'#', ' '};
    string const NAME_FICHIER = "ASCII.txt";

    sf::Image IMAGE;
    ofstream FICHIER(NAME_FICHIER.c_str());

    IMAGE = open_image(NAME_IMAGE);
    HEIGHT = receve_height_image(IMAGE);
    WIDTH = receve_width_image(IMAGE);

    for(unsigned int y = 0; y < HEIGHT; y ++)
    {
        for(unsigned int x = 0; x < WIDTH; x ++)
        {
            NIVEAU_GRIS = color_one_pixel(IMAGE, x, y);
            char ASCII_SIGNE = choix_ascii(NIVEAU_GRIS, ASCII);
            FICHIER << ASCII_SIGNE;
        }
        FICHIER << endl;
        POURCENTAGE = pourcentage(y, HEIGHT);
        cout << POURCENTAGE << " %" << endl;
    }

    return 0;
}