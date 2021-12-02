//include
#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include "input.hpp"

using namespace sf;
using namespace std;

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 576;
const int SPRITE_SIZE = 32;
const int WALK_SPEED = 1;

void Checkbtn();
void animePLayer();
void collisioncheck();