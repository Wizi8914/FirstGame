#include "main.hpp"

using namespace sf;
using namespace std;

// Prototypes des fonctions 
void InputHandler(Event event, RenderWindow& window);
void loadfont();
void settext(Text& txt, String str, int size, Color color);

Font font;

int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Firstgame");
    window.setVerticalSyncEnabled(true);

    loadfont();
    Text txt;
    settext(txt, "Hello World !", 100, Color::Yellow);

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

void settext(Text &txt, String str, int size, Color color)
{
    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(size);
    txt.setFillColor(color);
}