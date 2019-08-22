//
//  ImageScrolling.hpp
//  Image Scrolling Class
//
//

#pragma once
#include "ofMain.h"

class ImageScrolling
{
public:

	ImageScrolling();
	ImageScrolling(ofImage _img, glm::vec2 _pos, glm::vec2 _size);

	void setup();
	void update(int _inc);
	void draw();

	ofImage img;

	glm::vec2 pos, size;

	int inc;

	float incScaler = 5.0;
};
