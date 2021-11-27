#include "main.hpp"

using namespace sf;

// Prototypes des fonctions 
void InputHandler(Event event, RenderWindow& window);

int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Firstgame");
    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            InputHandler(event, window);
        }
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