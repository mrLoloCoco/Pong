//
//  score.h
//  Ping
//
//  Created by Loren Colcol on 7/14/15.
//  Copyright (c) 2015 Loren Colcol. All rights reserved.
//

#ifndef Ping_score_h
#define Ping_score_h


#endif

#pragma once

#include <SFML/Graphics.hpp>

class Score : public sf::Text
{
public:
    Score(sf::Font &font, unsigned int size);
    void IncrementScore();
    void Update();
    int value;
    void Reset();
private:
   
};