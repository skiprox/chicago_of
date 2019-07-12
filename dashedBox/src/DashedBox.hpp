//
//  DashedBox.hpp
//  Dashed Line Class
//
//

#pragma once
#include "ofMain.h"

class DashedBox
{
public:

	DashedBox();
	DashedBox(glm::vec2 _pos, float _width, float _height, ofColor _color, int _incMax);

	void setup();
	void update(int _inc);
	void draw();

	ofPath path;

	glm::vec2 pos;

	int inc, incMax;

	float width, height;

	int desiredStrokeLen = 20;
	int numSegments;

	ofColor color;
};
