//
//  TextFading.cpp
//  TextFadings
//
//
//

#include "TextFading.hpp"

TextFading::TextFading()
{
	texts.push_back(ofImage newImg);
    setup();
}

TextFading::TextFading(vector<ofImage> _texts) {
	texts = _texts;
    setup();
}

void TextFading::setup() {
	ofSetCircleResolution(100);
	inc = 0;
}

void TextFading::update(int _inc) {
	inc = _inc;
}

void TextFading::draw() {
	ofPushMatrix();
	ofPushStyle();
	// Left image
	texts[textIncrementer].draw(0, 0, 200, 300);
	// Center image
	texts[(textIncrementer + 1) % texts.size()].draw(200, 0, 200, 300);
	// Right image
	texts[(textIncrementer + 2) % texts.size()].draw(400, 0, 200, 300);
	ofPopStyle();
	ofPopMatrix();
}
