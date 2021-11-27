#include "main.hpp"

using namespace sf;
using namespace std;

// Prototypes des fonctions 
void InputHandler(Event event, RenderWindow& window);
void loadfont();

Font font;

int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Firstgame");
    window.setVerticalSyncEnabled(true);

    loadfont();
    Text txt;
    txt.setFont(font);
    txt.setString("Hello World !");
    txt.setCharacterSize(20);
    txt.setFillColor(Color::Magenta);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            InputHandler(event, window);
        }

        window.clear(Color::Black);

        window.draw(txt);

        window.display();


    }

    return 0;
}

void InputHandler(Event event, RenderWindow &window)
{
    if (event.type == Event::Closed)
    {
        window.close();
    }
}

void loadfont()
{
    if (!font.loadFromFile("resources/roboto.ttf"))
    {
        cout << "font can be loaded";
    }
}