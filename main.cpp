#include "main.hpp"

// Prototypes des fonctions 
void InputHandler(Event event, RenderWindow& window);

RenderWindow window;

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

    if (event.type == Event::KeyPressed)
    {
        if (event.key.code == Keyboard::Escape)
        {
            window.close();
        }
        if (event.key.code == Keyboard::Left)
        {
            settext(txt, "<", 100, Color::Yellow);
        }

    }

    if (event.type == Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == Mouse::Right)
        {
            settext(txt, "Right", 100, Color::Yellow);
        }

        if (event.mouseButton.button == Mouse::Left)
        {
            settext(txt, "Left", 100, Color::Yellow);
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        settext(txt, "^", 100, Color::Yellow);
    }

    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        settext(txt, ">", 100, Color::Yellow);
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