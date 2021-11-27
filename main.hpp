//include
#include <iostream>
#include <SFML/Graphics.hpp>
#include "input.hpp"

using namespace sf;
using namespace std;

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

void loadfont();
void settext(Text& txt, String str, int size, Color color);