//
//  WaveAnimation.hpp
//  Wave Animation Class
//
//

#pragma once
#include "ofMain.h"

class WaveAnimation
{
public:

	WaveAnimation();
    WaveAnimation(glm::vec2 _pos, glm::vec2 _waveSize);

    void setup();
	void update(float _inc);
	void draw();
	float quadEaseOut(float t);

	glm::vec2 pos, waveSize;
	ofPath path;
	float width, height, ranOffset;
    float inc;

};
