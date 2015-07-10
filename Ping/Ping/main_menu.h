//
//  test_state.h
//  Ping
//
//  Created by Loren Colcol on 7/10/15.
//  Copyright (c) 2015 Loren Colcol. All rights reserved.
//

#pragma once

#include "game_state.h"

class main_menu : public tiny_state
{
public:
    void Initiaize(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);
    void Destroy(sf::RenderWindow* window);
    
    ~main_menu();
private:
    sf::Font* font;
    sf::Text* title;
};

