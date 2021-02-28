/** avec sfml
recupérer une image 
la transformé en noir et blanc 
puis en fonction du niveau mettre un signe ascii
faire une liste des caractère des plus clair au plus sombre
signe choisi pour le pixel = ascii[niveau de gris]
**/

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

Texture open_image(const char *NAME_IMAGE)
{
    Texture IMAGE_LOAD;
    if(!IMAGE_LOAD.loadFromFile(NAME_IMAGE))
    {
        cout << "error" << endl;
    }
    return IMAGE_LOAD;
}

Sprite load_sprite(Texture IMAGE)
{
    Sprite SPRITE;
    SPRITE.setTexture(IMAGE);
    return SPRITE;
}

Color color_one_pixel(Texture IMAGE)
{
    return 0;
}

int main()
{
    const char *NAME_IMAGE = "image/coeur.jpg";
    const char ASCII[] = {' ', '.', 'a'};

    Texture image_loaded;
    Sprite sprite_loaded;
    RenderWindow WINDOW(VideoMode(1080, 720), "My window");

    WINDOW.setFramerateLimit(60);

    image_loaded = open_image(NAME_IMAGE);
    //sprite_loaded = load_sprite(image_loaded);

    for(int x = 0; x < 3; x ++)
    {
        cout << "le " << x << " est '" << ASCII[x] << "' " << endl;
    }
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
    return 0;
}