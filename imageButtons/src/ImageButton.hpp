//
//  ImageButton.hpp
//  Image Button Class
//
//

#pragma once
#include "ofMain.h"

class ImageButton
{
public:

	ImageButton();
	ImageButton(ofImage _image, glm::vec2 _pos, glm::vec2 _size);

	void setup();
	void update(float _inc);
	void draw();

	ofImage image;

	glm::vec2 pos, size;

	float inc;

};
