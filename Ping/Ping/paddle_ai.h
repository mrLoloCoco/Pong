//
//  paddle_ai.h
//  Ping
//
//  Created by Loren Colcol on 7/14/15.
//  Copyright (c) 2015 Loren Colcol. All rights reserved.
//

#ifndef Ping_paddle_ai_h
#define Ping_paddle_ai_h


#endif

#pragma once

#include "paddle.h"
#include "ball.h"

class paddle_ai : public paddle
{
public:
    paddle_ai(int playerNumber);
    void SetBall(ball* ballObject);
    void Update();
    
private:
    ball* ballObject;
    int playerNumber;
    float speed;
};