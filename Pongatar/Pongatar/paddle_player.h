//
//  paddle_player.h
//  Ping
//
//  Created by Loren Colcol on 7/13/15.
//  Copyright (c) 2015 Loren Colcol. All rights reserved.
//

#ifndef Ping_paddle_player_h
#define Ping_paddle_player_h


#endif

#pragma once

#include "paddle.h"

class paddle_player : public paddle
{
public:
    paddle_player(int playerNumber);
    void Update();
    
private:
    int playerNumber;
};