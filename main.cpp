#include "main.hpp"

RenderWindow window;
Input input;

Texture heroTexture;
Sprite heroSprite;

int main()
{
    
    window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Firstgame", Style::Default);
    window.setVerticalSyncEnabled(true);

    if (!heroTexture.loadFromFile("resources/image/hero_sheet.png"))
    {
        cout << "Erreur lors du chargement de la texture";
    }

    heroSprite.setTexture(heroTexture);
    heroSprite.setTextureRect(IntRect(32, 0, 32, 32));

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);

        }
        Checkbtn();
        window.clear(Color::Black);
        window.draw(heroSprite);
        window.display();


    }

    return 0;
}

void Checkbtn()
{
    if (input.GetButton().left == true)
    {
        
    }
    if (input.GetButton().right == true)
    {
        
    }
    if (input.GetButton().up == true)
    {
        
    }
    if (input.GetButton().down == true)
    {
        
    } 
    if (input.GetButton().attack == true)
    {
       
    }
    if (input.GetButton().escape == true)
    {
        window.close();
    }
}