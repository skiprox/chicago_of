//
//  ImageButton.cpp
//  Image Buttons
//
//
//

#include "ImageButton.hpp"

ImageButton::ImageButton()
{
	image.load("plane.png");
	pos = glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0);
	size = glm::vec2(500, 158);
    setup();
}

ImageButton::ImageButton(ofImage _image, glm::vec2 _pos, glm::vec2 _size) {
	image = _image;
	pos = _pos;
	size = _size;
    setup();
}

void ImageButton::setup() {
	ofSetCircleResolution(100);
	inc = 0.0;
}

void ImageButton::update(float _inc) {
	inc = _inc;
}

void ImageButton::draw() {
	// Bouncing image
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2.0, size.y/2.0);
	ofScale(ofMap(sin(inc), -1.0, 1.0, 0.8, 1.0, true));
	image.draw(-(size.x/2.0), -(size.y/2.0), size.x, size.y);
	ofPopMatrix();
	ofPopStyle();
	// Fading in/out image
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2.0, (size.y/2.0) * 4.0);
	ofSetColor(255, 255, 255, ofMap(sin(inc), -1.0, 1.0, 0.0, 255.0, true));
	ofFill();
	ofDrawRectangle(-(size.x/2.0), -(size.y/2.0), size.x, size.y);
	image.draw(-(size.x/2.0), -(size.y/2.0), size.x, size.y);
	ofPopMatrix();
	ofPopStyle();
	// Bouncing image with background
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2.0, (size.y/2.0) * 8.0);
	ofPushStyle();
	ofPushMatrix();
	ofSetColor(0);
	ofNoFill();
	ofScale(ofMap(sin(inc), -1.0, 1.0, 1.0, 1.2, true));
	ofTranslate(0, ofMap(sin(inc), -1.0, 1.0, 0.0, -7.5));
	image.draw(-(size.x/2.0), -(size.y/2.0), size.x, size.y);
	ofPopMatrix();
	ofPopStyle();
	// ofScale(ofMap(sin(inc), -1.0, 1.0, 0.8, 1.0, true));
	image.draw(-(size.x/2.0), -(size.y/2.0), size.x, size.y);
	ofPopMatrix();
	ofPopStyle();
}
