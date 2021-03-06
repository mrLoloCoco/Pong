//
//  ball.h
//  Ping
//
//  Created by Loren Colcol on 7/14/15.
//  Copyright (c) 2015 Loren Colcol. All rights reserved.
//

#ifndef Ping_ball_h
#define Ping_ball_h


#endif

#pragma once

#include <SFML/Audio.hpp>
#include "paddle_player.h"
#include "score.h"

#define BALL_SPEED 1
#define BALL_MAX_SPEED (BALL_SPEED * 2)


class ball : public Entity
{
public:
    ball(Score* score1, Score* score2, paddle* player1, paddle* player2);
    
    void AddVelocity(paddle* paddle);
    
    bool GoingToCeil();
    bool GoingToFloor();
    
    float getHitX(float y);
    float getHitY(float x);
    
    void Update(sf::RenderWindow* window);
    void Reset(sf::RenderWindow* window);
    //~ball();
private:
    Score* score1;
    Score* score2;
    paddle* player1;
    paddle* player2;
    
    sf::SoundBuffer* buffer;
    sf::Sound* sound;
    
    sf::SoundBuffer* bufferOut;
    sf::Sound* soundOut;
};