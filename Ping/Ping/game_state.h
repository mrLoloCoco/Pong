//
//  game_state.h
//  Ping
//
//  Created by Loren Colcol on 7/10/15.
//  Copyright (c) 2015 Loren Colcol. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>

class tiny_state
{
public:
    virtual void Initiaize(sf::RenderWindow* window)
    {
    }
    
    virtual void Update(sf::RenderWindow* window)
    {
    }
    
    virtual void Render(sf::RenderWindow* window)
    {
    }
    
    virtual void Destroy(sf::RenderWindow* window)
    {
    }
};

class game_state
{
public:
    game_state()
    {
        this->state = NULL;
    }
    
    void SetWindow(sf::RenderWindow* window)
    {
        this->window = window;
    }
    
    void SetState(tiny_state* state)
    {
        if (this->state != NULL)
        {
            this->state->Destroy(this->window);
        }
        this->state = state;
        if (this->state != NULL)
        {
            this->state->Initiaize(this->window);
        }
    }
    
    void Update()
    {
        if (this->state != NULL)
        {
            this->state->Update(this->window);
        }
    }
    void Render()
    {
        if (this->state != NULL)
        {
            this->state->Render(this->window);
        }
    }
    
    ~game_state()
    {
        if (this->state != NULL)
        {
            this->state->Destroy(this->window);
        }
    }
    
private:
    sf::RenderWindow* window;
    tiny_state* state;
    
};

extern game_state coreState;


