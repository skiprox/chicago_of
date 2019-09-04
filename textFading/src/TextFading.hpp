//
//  TextFading.hpp
//  Text Scrolling Class
//
//

#pragma once
#include "ofMain.h"

class TextFading
{
public:

	TextFading();
	TextFading(vector<ofImage> _texts);

	void setup();
	void update(int _inc);
	void draw();

	vector<ofImage> texts;
	int textIncrementer = 0;
};
