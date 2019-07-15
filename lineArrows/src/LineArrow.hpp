//
//  LineArrow.hpp
//  Line Arrow Class
//
//

#pragma once
#include "ofMain.h"

class LineArrow
{
public:

	LineArrow();
    LineArrow(vector<std::array<glm::vec2, 2>> _pts, float _strokeWidth, ofColor _color, int _incMax);

    void setup();
	void update(int _inc);
	void draw();
	float quadEaseOut(float t);

	ofPath path;

    vector<std::array<glm::vec2, 2>> pts;

    float strokeWidth;

    int inc, incMax, numSegments;

	ofColor color;
};
