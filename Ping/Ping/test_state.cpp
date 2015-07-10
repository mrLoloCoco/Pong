//
//  test_state.cpp
//  Ping
//
//  Created by Loren Colcol on 7/10/15.
//  Copyright (c) 2015 Loren Colcol. All rights reserved.
//

#include <iostream>
#include "test_state.h"

void test_state::Initiaize(sf::RenderWindow* window)
{
    std::cout << "inited\n";
    this->paused = false;
}
void test_state::Update(sf::RenderWindow* window)
{
    if (paused)
    {
        // normal game here
    }
    else
    {
        // paused gamed here
    }
    
}
void test_state::Render(sf::RenderWindow* window)
{
    
}
void test_state::Destroy(sf::RenderWindow* window)
{
    std::cout << "destroyed\n";

}