#ifndef INPUT_HPP
#define INPUT_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Input
{
	struct Button { bool left, right, up, down, attack, escape; };

public:
	Input();

	Button GetButton(void) const;

	void InputHandler(Event event, RenderWindow& window);


private:
	Button button;
};


#endif

