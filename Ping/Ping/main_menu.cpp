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
    
    this->title = new sf::Text("Pongatar", *this->font, 128U);
    this->title->setOrigin(this->title->getGlobalBounds().width /2, this->title->getGlobalBounds().height /2);
    this->title->setPosition(window->getSize().x /2, window->getSize().y /4);
    
    this->play = new sf::Text("Play", *this->font, 64U);
    this->play->setOrigin(this->play->getGlobalBounds().width /2, this->play->getGlobalBounds().height /2);
    this->play->setPosition(window->getSize().x /2, window->getSize().y /2);
}
void main_menu::Update(sf::RenderWindow* window)
{
}
void main_menu::Render(sf::RenderWindow* window)
{
    window->draw(*this->title);
    window->draw(*this->play);

}
void main_menu::Destroy(sf::RenderWindow* window)
{
    delete this->font;
    delete this->title;

}
