//
//  ball.cpp
//  Ping
//
//  Created by Loren Colcol on 7/14/15.
//  Copyright (c) 2015 Loren Colcol. All rights reserved.
//

#include "ball.h"

ball::ball(Score* score1, Score* score2, paddle* player1, paddle* player2)
{
    this->Load("ball.png");
    this->score1 = score1;
    this->score2 = score2;
    this->player1 = player1;
    this->player2 = player2;
    
    this->buffer = new sf::SoundBuffer();
    this->buffer->loadFromFile(resourcePath() + "bounce.wav");
    this->sound = new sf::Sound(*this->buffer);
    
    this->bufferOut = new sf::SoundBuffer();
    this->bufferOut->loadFromFile(resourcePath() + "gametinywarp.wav");
    this->soundOut = new sf::Sound(*this->bufferOut);

}

void ball::AddVelocity(paddle* paddle)
{
    if (abs(this->velocity.y) < BALL_MAX_SPEED)
    {
        if (this->velocity.y > 0)
        {
            if (paddle->velocity.y > 0)
            {
                this->velocity.y += this->velocity.y * 1.25f;
            }
            else if (paddle->velocity.y < 0)
            {
                this->velocity.y += this->velocity.y * -1.25f;
            }
        }
        else if (this->velocity.y < 0)
        {
            if (paddle->velocity.y > 0)
            {
                this->velocity.y += this->velocity.y * -1.25f;
            }
            else if (paddle->velocity.y < 0)
            {
                this->velocity.y += this->velocity.y * 1.25f;
            }
        }
    }
}

bool ball::GoingToCeil()
{
    float py = 0;
    float oy = this->getPosition().y;
    float vy = this->velocity.y;
    
    float d = (py - oy) / vy;
    
    float vx = this->velocity.x;
    float ox = this->getPosition().x;
    float px = d * vx + ox;
    
    return (px > 0 && px < 800);
}
bool ball::GoingToFloor()
{
    float py = 800;
    float oy = this->getPosition().y;
    float vy = this->velocity.y;
    
    float d = (py - oy) / vy;
    
    float vx = this->velocity.x;
    float ox = this->getPosition().x;
    float px = d * vx + ox;
    
    return (px > 0 && px < 800);
}

float ball::getHitX(float y)
{
    float py = y;
    float oy = this->getPosition().y;
    float vy = this->velocity.y;
    
    float d = (py - oy) / vy;
    
    float vx = this->velocity.x;
    float ox = this->getPosition().x;
    float px = d * vx + ox;
    
    return px;
}

float ball::getHitY(float x)
{
    float px = x;
    float vx = this->velocity.x;
    float ox = this->getPosition().x;
    
    float d = (px - ox) / vx;
    
    float vy = this->velocity.y;
    float oy = this->getPosition().y;
    float py = d * vy + oy;
    
    return py;
}

void ball::Update(sf::RenderWindow* window)
{
    if (this->CheckCollision(this->player1))
    {
        this->velocity.x *= -1;
        if (this->velocity.y > 0)
        {
            if (this->player1->velocity.y > 0)
            {
                this->velocity.y += this->velocity.y * 1.25f;
            }
            else if (this->player1->velocity.y < 0)
            {
                this->velocity.y += this->velocity.y * -1.25f;
            }
        }
        else if (this->velocity.y < 0)
        {
            if (this->player1->velocity.y > 0)
            {
                this->velocity.y += this->velocity.y * -1.25f;
            }
            else if (this->player1->velocity.y < 0)
            {
                this->velocity.y += this->velocity.y * 1.25f;
            }
        }
        this->sound->play();
    }
    if (this->CheckCollision(this->player2))
    {
        this->velocity.x *= -1;
        if (this->velocity.y > 0)
        {
            if (this->player2->velocity.y > 0)
            {
                this->velocity.y += this->velocity.y * 1.25f;
            }
            else if (this->player2->velocity.y < 0)
            {
                this->velocity.y += this->velocity.y * -1.25f;
            }
        }
        else if (this->velocity.y < 0)
        {
            if (this->player2->velocity.y > 0)
            {
                this->velocity.y += this->velocity.y * -1.25f;
            }
            else if (this->player2->velocity.y < 0)
            {
                this->velocity.y += this->velocity.y * 1.25f;
            }
        }
        this->sound->play();
    }
    if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > window->getSize().y)
    {
        this->velocity.y *= -1;
        this->sound->play();

    }
    
    if (this->getPosition().x < this->player1->getGlobalBounds().width - 100)
    {
        this->soundOut->play();
        this->score2->IncrementScore();
        this->Reset(window);
    }
    if (this->getPosition().x + this->getGlobalBounds().width > window->getSize().x - this->player2->getGlobalBounds().width + 100)
    {
        this->soundOut->play();
        this->score1->IncrementScore();
        this->Reset(window);
    }
    
    if (this->score1->value == 5 || this->score2->value == 5)
    {
        this->score1->Reset();
        this->score2->Reset();
    }
    Entity::Update();
}

void ball::Reset(sf::RenderWindow *window)
{
    this->velocity.x = BALL_SPEED;
    this->velocity.y = ((rand() % 2) == 0) ? BALL_SPEED : -BALL_SPEED;
    this->setPosition(window->getSize().x / 2, window->getSize().y / 2);
    this->player1->setPosition(0, window->getSize().y / 2 + this->player1->getGlobalBounds().height / 2);
    this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width, window->getSize().y / 2 + this->player2->getGlobalBounds().height / 2);

}

/*
ball::~ball()
{
    delete this->sound;
    delete this->buffer;
}
*/