/** avec sfml recupérer une image 
- la transformé en noir et blanc 
- puis en fonction du niveau mettre un signe ascii
- faire une liste des caractère des plus clair au plus sombre
- signe choisi pour le pixel = ascii[niveau de gris]
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

void right_in_txt(const char *ASCII_SIGNE, ofstream FICHIER, bool END_LIGNE)
{
    if(END_LIGNE)
    {
        FICHIER << ASCII_SIGNE << endl;
    }
    else
    {
        FICHIER << ASCII_SIGNE;
    }
}

//recherche actuelle = obtenir le size de l'image

unsigned int receve_width_image(Image IMAGE)
{
    unsigned int WIDTH;
    WIDTH = 10;
    sf::Vector2u Vector;
    Vector = Image::getSize();
    Vector(IMAGE);
    return WIDTH;
}

unsigned int receve_height_image(Image IMAGE)
{
    unsigned int HEIGHT;
    HEIGHT = 10;
    sf::Vector2u Vector;
    Vector = Image::getSize();
    Vector(IMAGE);
    return HEIGHT;
}


unsigned int color_one_pixel(Image IMAGE, unsigned int x, unsigned int y)
{
    sf::Color COLOR;
    COLOR = IMAGE.getPixel(x, y);
    return 0;
}


int main()
{
    unsigned int HEIGHT, WIDTH;
    const char *NAME_IMAGE = "image/coeur.jpg", ASCII[] = {'a', '.', ' '};

    sf::Image IMAGE;

    IMAGE = open_image(NAME_IMAGE);
    HEIGHT = receve_height_image(IMAGE);
    WIDTH = receve_width_image(IMAGE);
    //color_one_pixel(image_loaded);

    for(unsigned int y = 0; y < HEIGHT; y ++)
    {
        for(unsigned int x = 0; x < WIDTH; x ++)
        {
            // appel fonction color et choix ascii
            // verifier si le x == WIDTH si oui faire le endl
            // appel fonction right_in_txt
            cout << "le y = " << y << " et le x = " << x << endl;
        }
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