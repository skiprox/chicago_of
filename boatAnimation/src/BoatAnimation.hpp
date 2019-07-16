//
//  BoatAnimation.hpp
//  Boat Animation Class
//
//

#pragma once
#include "ofMain.h"

class BoatAnimation
{
public:

	BoatAnimation();
    BoatAnimation(ofImage _boat, glm::vec2 _pos, glm::vec2 _size);

    void setup();
	void update(float _inc);
	void draw();
	float quadEaseOut(float t);

	ofImage boat;
	glm::vec2 pos, size;
    float inc;

};
