#include "input.hpp"

Input::Input()
{
	button.left = button.right = button.up = button.down = button.attack = button.escape = false;
}

void InputHandler(Event event, RenderWindow& window)
{
    if (event.type == Event::Closed)
    {
        window.close();
    }

    if (event.type == Event::KeyPressed)
    {

    }

}
