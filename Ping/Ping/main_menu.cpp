//
//  test_state.cpp
//  Ping
//
//  Created by Loren Colcol on 7/10/15.
//  Copyright (c) 2015 Loren Colcol. All rights reserved.
//

#include <iostream>
#include "main_menu.h"
#include "ResourcePath.hpp"


void main_menu::Initiaize(sf::RenderWindow* window)
{
    this->font = new sf::Font();
    this->font->loadFromFile(resourcePath() + "agata.regular.ttf");
    
    this->title = new sf::Text("Pingatar", *this->font, 128U);
}
void main_menu::Update(sf::RenderWindow* window)
{
}
void main_menu::Render(sf::RenderWindow* window)
{
    window->draw(*this->title);
}
void main_menu::Destroy(sf::RenderWindow* window)
{
    delete this->font;
    delete this->title;

}
