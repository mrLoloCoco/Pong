//
//  main_game.cpp
//  Ping
//
//  Created by Loren Colcol on 7/13/15.
//  Copyright (c) 2015 Loren Colcol. All rights reserved.
//

#include <stdio.h>
#include "main_game.h"
#include "main_menu.h"

#include "ResourcePath.hpp"


void main_game::Initiaize(sf::RenderWindow* window)
{
    this->paddle = new Entity();
    this->paddle->Load("paddle1.png");
}
void main_game::Update(sf::RenderWindow* window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        coreState.SetState(new main_menu());
    }
}
void main_game::Render(sf::RenderWindow* window)
{
    window->draw(*this->paddle);
}
void main_game::Destroy(sf::RenderWindow* window)
{
    delete this->paddle;
}



