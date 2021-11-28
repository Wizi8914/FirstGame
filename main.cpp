#include "main.hpp"

RenderWindow window;
Input input;

int main()
{
    
    window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Firstgame", Style::Default);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);

        }
        Checkbtn();

        window.clear(Color::Black);
        window.display();


    }

    return 0;
}

void Checkbtn()
{
    if (input.GetButton().left == true)
    {
        
    }
    if (input.GetButton().right == true)
    {
        
    }
    if (input.GetButton().up == true)
    {
        
    }
    if (input.GetButton().down == true)
    {
        
    } 
    if (input.GetButton().attack == true)
    {
       
    }
    if (input.GetButton().escape == true)
    {
        window.close();
    }
}