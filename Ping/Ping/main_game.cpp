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
}
void main_game::Destroy(sf::RenderWindow* window)
{
}



