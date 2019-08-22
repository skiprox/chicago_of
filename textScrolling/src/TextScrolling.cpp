//
//  TextScrolling.cpp
//  TextScrollings
//
//
//

#include "TextScrolling.hpp"

TextScrolling::TextScrolling()
{
	text = "Hello World!";
	pos = glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0);
	color = ofColor(250, 40, 40);
	fontSize = 12;
    setup();
}

TextScrolling::TextScrolling(string _text, glm::vec2 _pos, ofColor _color, int _fontSize) {
	text = _text;
	pos = _pos;
	color = _color;
	fontSize = _fontSize;
    setup();
}

void TextScrolling::setup() {
	myfont.load("helveticaneue-std.ttf", fontSize);
	ofSetCircleResolution(100);
	inc = 0;
}

void TextScrolling::update(int _inc) {
	inc = _inc;
	int modAmount = 3 * int(myfont.getStringBoundingBox(text, 0,0).height + ofGetHeight());
	inc = inc % modAmount;
}

void TextScrolling::draw() {
	ofPushMatrix();
	ofPushStyle();
	ofSetColor(color);
	ofRectangle rect = myfont.getStringBoundingBox(text, 0,0);
	myfont.setLineHeight(fontSize * 2.0);
	myfont.drawString(text, pos.x - rect.width/2.0, ofGetHeight() - inc/3.0);
	ofPopStyle();
	ofPopMatrix();
}
