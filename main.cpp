#include "main.hpp"

RenderWindow window;
Input input;

Image icon;

Texture heroTexture;
Sprite heroSprite;

enum Dir { Down, Right, Up, Left, Down_atk, Right_atk, Up_atk, Left_atk};

Vector2i heroAnim(0, Down);

Clock animetime;

bool heroIdle = true;

bool resetanim = false;

FloatRect hitbox = heroSprite.getGlobalBounds();

int main()
{
    
    window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Firstgame", Style::Default);
    window.setVerticalSyncEnabled(true);

    if (!icon.loadFromFile("resources/image/logo.png"))
    {
        cout << "Erreur de chargement de l'icon";
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    if (!heroTexture.loadFromFile("resources/image/hero_sheet.png"))
    {
        cout << "Erreur lors du chargement de la texture";
    }

    heroSprite.setTexture(heroTexture);
    heroSprite.setTextureRect(IntRect(heroAnim.x * SPRITE_SIZE, heroAnim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }
        Checkbtn();
        animePLayer();
        heroSprite.setTextureRect(IntRect(heroAnim.x * SPRITE_SIZE, heroAnim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
        window.clear(Color::Black);

        window.draw(heroSprite);
        window.display();

    }

    return 0;
}

void Checkbtn()
{
    if (!resetanim)
    {
        if (input.GetButton().left == true)
        {
            heroAnim.y = Left;
            heroSprite.move(-WALK_SPEED, 0);
            heroIdle = false;
        }
        else if (input.GetButton().right == true)
        {
            heroAnim.y = Right;
            heroSprite.move(WALK_SPEED, 0);
            heroIdle = false;
        }
        else if (input.GetButton().up == true)
        {
            heroAnim.y = Up;
            heroSprite.move(0, -WALK_SPEED);
            heroIdle = false;
        }
        else if (input.GetButton().down == true)
        {
            heroAnim.y = Down;
            heroSprite.move(0, WALK_SPEED);
            heroIdle = false;
        }
        else
        {
            heroIdle = true;
        }
        if (input.GetButton().attack == true)
        {
            resetanim = true;
            heroAnim.x = 0;
            heroAnim.y += 4;
        }
        if (input.GetButton().escape == true)
        {
            window.close();
        }
    }
}

void animePLayer()
{
    heroSprite.setTextureRect(IntRect(heroAnim.x * SPRITE_SIZE, heroAnim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
    if (animetime.getElapsedTime().asSeconds() > 0.1f)
    {
        if (heroAnim.x * SPRITE_SIZE >= heroTexture.getSize().x - SPRITE_SIZE)
        {
            heroAnim.x = 0;
            if (resetanim)
            {
                resetanim = false;
                heroAnim.y -= 4;
            }
        }
        else
        {
            if(!heroIdle || resetanim)
                heroAnim.x++;
        }
        animetime.restart();
    }
}