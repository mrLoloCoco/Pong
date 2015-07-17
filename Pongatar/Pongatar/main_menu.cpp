//
//  test_state.cpp
//  Ping
//
//  Created by Loren Colcol on 7/10/15.
//  Copyright (c) 2015 Loren Colcol. All rights reserved.
//

#include <iostream>
#include "main_menu.h"
#include "main_game.h"
#include "ResourcePath.hpp"


void main_menu::Initiaize(sf::RenderWindow* window)
{
    this->selected = 0;
    
    this->font = new sf::Font();
    this->font->loadFromFile(resourcePath() + "agata.regular.ttf");
    
    this->title = new sf::Text("Pongatar", *this->font, 128U);
    this->title->setOrigin(this->title->getGlobalBounds().width /2, this->title->getGlobalBounds().height /2);
    this->title->setPosition(window->getSize().x /2, window->getSize().y /4);
    
    this->play = new sf::Text("Play", *this->font, 42U);
    this->play->setOrigin(this->play->getGlobalBounds().width /2, this->play->getGlobalBounds().height /2.5);
    this->play->setPosition(window->getSize().x /2, window->getSize().y /1.5);
    
    this->quit = new sf::Text("Exit", *this->font, 42U);
    this->quit->setOrigin(this->quit->getGlobalBounds().width /2, this->play->getGlobalBounds().height /2.5);
    this->quit->setPosition(window->getSize().x /2, window->getSize().y /1.5 + 75 );
    
    this->instructions = new sf::Text("Use Arrow Keys / Enter to select Menu Option, W & S to move paddle, esc to Exit" , *this->font, 21U);
    this->instructions->setOrigin(this->instructions->getGlobalBounds().width /2, this->play->getGlobalBounds().height /2.5);
    this->instructions->setPosition(window->getSize().x /2, window->getSize().y /1.5 + 150 );
}
void main_menu::Update(sf::RenderWindow* window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey)
    {
        this->selected -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey)
    {
        this->selected += 1;
    }
    if (this->selected > 1)
    {
        this->selected = 0;
    }
    if (this->selected < 0)
    {
        this->selected = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
    {
            switch (this->selected)
            {
                case 0:
                    coreState.SetState(new main_game());
                    break;
                case 1:
                    quitGame = true;
                    break;
            }
        }
    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}
void main_menu::Render(sf::RenderWindow* window)
{
    this->play->setColor(sf::Color::White);
    this->quit->setColor(sf::Color::White);
    switch (this->selected)
    {
        case 0:
            this->play->setColor(sf::Color::Cyan);
            break;
        case 1:
            this->quit->setColor(sf::Color::Cyan);
            break;
     
    }
    window->draw(*this->title);
    window->draw(*this->play);
    window->draw(*this->quit);
    window->draw(*this->instructions);
    
}
void main_menu::Destroy(sf::RenderWindow* window)
{
    delete this->font;
    delete this->title;
    delete this->play;
    delete this->quit;
    delete this->instructions;

}
