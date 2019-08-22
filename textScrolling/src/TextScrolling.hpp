//
//  TextScrolling.hpp
//  Text Scrolling Class
//
//

#pragma once
#include "ofMain.h"

class TextScrolling
{
public:

	TextScrolling();
	TextScrolling(string _text, glm::vec2 _pos, ofColor _color, int _fontSize);

	void setup();
	void update(int _inc);
	void draw();

	ofTrueTypeFont myfont;

	string text;

	glm::vec2 pos;

	int inc, fontSize;

	ofColor color;
};
