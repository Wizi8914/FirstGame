#include "main.hpp"

// Prototypes des fonctions 

RenderWindow window;

Input input;

Font font;
Text txt;

int main()
{
    window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Firstgame");
    window.setVerticalSyncEnabled(true);

    loadfont();
    settext(txt, "Hello World !", 100, Color::Yellow);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }

        window.clear(Color::Black);

        window.draw(txt);

        window.display();


    }

    return 0;
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