//
//  entity.h
//  Ping
//
//  Created by Loren Colcol on 7/13/15.
//  Copyright (c) 2015 Loren Colcol. All rights reserved.
//

#ifndef Ping_entity_h
#define Ping_entity_h


#endif

#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "ResourcePath.hpp"


class Entity : public sf::Sprite
{
public:
    Entity()
    {
        this->texture = new sf::Texture();
    }
    
    void Load(std::string filename)
    {
        this->texture->loadFromFile(resourcePath() + filename);
        this->setTexture(*this->texture);
    }
    
    ~Entity()
    {
        delete this->texture;
    }
private:
    sf::Texture* texture;
};