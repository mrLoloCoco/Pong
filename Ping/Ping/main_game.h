//
//  main_game.h
//  Ping
//
//  Created by Loren Colcol on 7/13/15.
//  Copyright (c) 2015 Loren Colcol. All rights reserved.
//

#ifndef Ping_main_game_h
#define Ping_main_game_h


#endif

#pragma once

#include "game_state.h"


class main_game : public tiny_state
{
public:
    void Initiaize(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);
    void Destroy(sf::RenderWindow* window);
    
private:
};
