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
    sf::Vector2f velocity;

    Entity()
    {
        this->texture = new sf::Texture();
    }
    
    void Load(std::string filename)
    {
        this->texture->loadFromFile(resourcePath() + filename);
        this->setTexture(*this->texture);
    }
    
    virtual void Update()
    {
        this->move(this->velocity);
    }
    
    bool CheckCollision(Entity* entity)
    {
        return this->getGlobalBounds().intersects(entity->getGlobalBounds());
    }
    
    ~Entity()
    {
        delete this->texture;
    }
private:
    sf::Texture* texture;
};