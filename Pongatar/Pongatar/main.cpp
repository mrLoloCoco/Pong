
#include "game_state.h"
#include "main_menu.h"

game_state coreState;
bool quitGame = false;

#include <iostream>
#include "ResourcePath.hpp"

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ping");
    
    
    coreState.SetWindow(&window);
    coreState.SetState(new main_menu());
    
    sf::Clock timer;
    sf::Time elapsed;
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        elapsed = timer.getElapsedTime();
        
        if (elapsed.asMicroseconds() > 162)
        {
            window.clear(sf::Color::Black);
            
            coreState.Update();
            coreState.Render();
            
            window.display();
            
            if (quitGame)
            {
                window.close();
            }
            timer.restart();
        }
    }
    
    return 0;
} 