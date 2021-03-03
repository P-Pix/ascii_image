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

sf::Texture open_image(const char *NAME_IMAGE)
{
    sf::Texture IMAGE_LOAD;
    if(!IMAGE_LOAD.loadFromFile(NAME_IMAGE))
    {
        cout << "error" << endl;
    }
    return IMAGE_LOAD;
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

int receve_width_image(const char *NAME_IMAGE)
{
    int WIDTH;
    WIDTH = 10; //NAME_IMAGE.getSize();
    cout << WIDTH << endl;
    return WIDTH;
}

int receve_height_image(Texture IMAGE)
{
    int HEIGHT;
    HEIGHT = 10; //IMAGE.getSize();
    cout << HEIGHT << endl;
    return HEIGHT;
}


int color_one_pixel(Image IMAGE, int x, int y)
{
    IMAGE.getPixel(x, y);
    return 0;
}


int main()
{
    int HEIGHT;
    int WIDTH;
    const char *NAME_IMAGE = "image/coeur.jpg";
    const char ASCII[] = {' ', '.', 'a'};

    sf::Image IMAGE;
    sf::Texture IMAGE_LOADED;
    sf::Sprite SPRITE_LOADED;

    IMAGE_LOADED = open_image(NAME_IMAGE);
    HEIGHT = receve_height_image(IMAGE_LOADED);
    WIDTH = receve_width_image(NAME_IMAGE);
    //color_one_pixel(image_loaded);

    for(int y = 0; y < HEIGHT; y ++)
    {
        for(int x = 0; x < WIDTH; x ++)
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