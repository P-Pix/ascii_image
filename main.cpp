/** avec sfml recupérer une image 
- la transformé en noir et blanc 
- puis en fonction du niveau mettre un signe ascii
- faire une liste des caractère des plus clair au plus sombre
- signe choisi pour le pixel = ascii[niveau de gris]
**/

/**
- vitesse moyenne = 32 400 pixels par seconde
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

//recherche actuelle = obtenir le size de l'image

unsigned int receve_width_image(Image IMAGE)
{
    unsigned int WIDTH;
    WIDTH = 360;
    /**
    sf::Vector2u Vector;
    Vector = Image::getSize();
    Vector(IMAGE);
    **/
    return WIDTH;
}

unsigned int receve_height_image(Image IMAGE)
{
    unsigned int HEIGHT;
    HEIGHT = 360;
    /**
    sf::Vector2u Vector;
    Vector = Image::getSize();
    Vector(IMAGE);
    **/
    return HEIGHT;
}

float pourcentage(unsigned int VALEUR_ACTUELLE, unsigned int VALEUR_FINALE)
{
    float RESULTAT;
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

const char choix_ascii(unsigned int NIVEAU_GRIS, const char *ASCII)
{
    unsigned int NOMBRE_SIGNE_POSSIBLE;
    const char NON_SIGNE_CHOISI = {' '};
    NOMBRE_SIGNE_POSSIBLE = 255 / (sizeof(ASCII) / 4);
    for(unsigned int x = 0; x < sizeof(ASCII) / 4; x ++)
    {
        if(NIVEAU_GRIS > NOMBRE_SIGNE_POSSIBLE * x)
        {
            if(NIVEAU_GRIS <= NOMBRE_SIGNE_POSSIBLE * (x + 1))
            {
                const char SIGNE_CHOISI = ASCII[x];
                return SIGNE_CHOISI;
            }
        }
    }
    return NON_SIGNE_CHOISI;
}


int main()
{
    unsigned int HEIGHT, WIDTH, NIVEAU_GRIS;
    float POURCENTAGE;
    const char *NAME_IMAGE = "image/coeur.jpg", ASCII[] = {'a', '.', ' '};
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
            const char ASCII_SIGNE = choix_ascii(NIVEAU_GRIS, ASCII);
            FICHIER << ASCII_SIGNE;
        }
        FICHIER << endl;
        POURCENTAGE = pourcentage(y * y, HEIGHT * WIDTH);
        cout << POURCENTAGE << " %" << endl;
    }

    return 0;

    /**

    sf::Sprite load_sprite(sf::Texture IMAGE)
    {
        sf::Sprite SPRITE;
        SPRITE.setTexture(IMAGE);
        return SPRITE;
    }

    sprite_loaded = load_sprite(image_loaded);

    RenderWindow WINDOW(VideoMode(1080, 720), "My window");

    WINDOW.setFramerateLimit(60);

    while(WINDOW.isOpen())
    {
        Event event;
        while(WINDOW.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                WINDOW.close();
            }
        }
        sprite_loaded.setTexture(image_loaded);
        WINDOW.clear();
        WINDOW.draw(sprite_loaded);
        WINDOW.display();
    }
    **/
}