#ifndef INPUT_HPP
#define INPUT_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Input
{
	struct Button { bool left, right, up, down, attack, escape; };
public:
	Input();


private:
	Button button;
}


#endif

