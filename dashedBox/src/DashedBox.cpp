//
//  DashedBox.cpp
//  DashedBoxs
//
//
//

#include "DashedBox.hpp"

DashedBox::DashedBox()
{
    pos = glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0);
    width = 100.0;
    height = 100.0;
    color = ofColor(255, 40, 20);
    incMax = 500;
    setup();
}

DashedBox::DashedBox(glm::vec2 _pos, float _width, float _height, ofColor _color, int _incMax) {
	pos = _pos;
	width = _width;
	height = _height;
	color = _color;
	incMax = _incMax;
    setup();
}

void DashedBox::setup() {
	path.setCurveResolution(100);
	ofSetCircleResolution(100);
	// Need to figure out number of segments,
	// based on desired segment length
	numSegments = fabs(ofDist(pos.x, pos.y, pos.x + width, pos.y + height))/desiredStrokeLen;
	inc = 0;
}

void DashedBox::update(int _inc) {
	inc = min(_inc, incMax);
}

void DashedBox::draw() {
	// ofPushStyle();
	// path.clear();
	// path.setStrokeColor(color);
	// path.setFilled(false);
	// path.setStrokeWidth(2);
	// float segBreaker = (float)incMax/(float)numSegments;
	// float distX = start.x - end.x;
	// float distY = start.y - end.y;
	// float segmentLenX = (distX/((float)incMax/segBreaker))/2.0;
	// float segmentLenY = (distY/((float)incMax/segBreaker))/2.0;
	// for (int i = 0; i < inc/segBreaker; i++) {
	// 	float posX = ofLerp(start.x, end.x, (float)i/((float)incMax/segBreaker));
	// 	float posY = ofLerp(start.y, end.y, (float)i/((float)incMax/segBreaker));
	// 	path.moveTo(posX, posY);
	// 	path.lineTo(posX + segmentLenX, posY + segmentLenY);
	// }
	// path.draw();
	// ofPopStyle();
	ofPushStyle();
	path.clear();
	path.setStrokeColor(color);
	path.setFilled(false);
	path.setStrokeWidth(2);
	for (int i = 0; i < 10; i++) {
		path.moveTo(pos.x + (width/10.0 * i), pos.y);
	}
	for (int i = 0; i < 5; i++) {
		float posX = ofLerp(pos.x, pos.x + width, (float)i/((float)incMax/5.0));
		float posY = pos.y;
		path.moveTo(posX, posY);
		path.lineTo(posX + 10.0, posY);
	}
	path.draw();
	ofPopStyle();
}
