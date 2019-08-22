//
//  ImageScrolling.cpp
//  ImageScrollings
//
//
//

#include "ImageScrolling.hpp"

ImageScrolling::ImageScrolling()
{
	pos = glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0);
	size = glm::vec2(100, 100);
    setup();
}

ImageScrolling::ImageScrolling(ofImage _img, glm::vec2 _pos, glm::vec2 _size) {
	img = _img;
	pos = _pos;
	size = _size;
    setup();
}

void ImageScrolling::setup() {
	ofSetCircleResolution(100);
	inc = 0;
}

void ImageScrolling::update(int _inc) {
	inc = _inc;
	int modAmount = int(incScaler) * int(size.y + ofGetHeight());
	inc = inc % modAmount;
}

void ImageScrolling::draw() {
	ofPushMatrix();
	ofPushStyle();
	img.draw(pos.x - size.x/2.0, ofGetHeight() - inc/incScaler, size.x, size.y);
	ofPopStyle();
	ofPopMatrix();
}
