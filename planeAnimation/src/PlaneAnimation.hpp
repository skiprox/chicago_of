//
//  PlaneAnimation.hpp
//  Plane Animation Class
//
//

#pragma once
#include "ofMain.h"

class PlaneAnimation
{
public:

	PlaneAnimation();
    PlaneAnimation(ofImage);

    void setup();
	void update(float _inc);
	void draw();
	float quadEaseOut(float t);

	ofImage plane;
	float width, height;
	ofPath path;
    float inc;

};
