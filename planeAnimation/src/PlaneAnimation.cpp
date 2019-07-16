//
//  PlaneAnimation.cpp
//  PlaneAnimations
//
//
//

#include "PlaneAnimation.hpp"

PlaneAnimation::PlaneAnimation()
{
	plane.load("plane.jpeg");
    setup();
}

PlaneAnimation::PlaneAnimation(ofImage _plane) {
	plane = _plane;
    setup();
}

void PlaneAnimation::setup() {
	width = ofGetWidth();
	height = ofGetHeight();
	inc = 0.0;
}

void PlaneAnimation::update(float _inc) {
	inc = _inc;
}

void PlaneAnimation::draw() {
	path.clear();
	path.setFilled(true);
	path.setFillColor(ofColor(40, 40, 40));
	path.moveTo(0, height/2.0 + 200);
	path.lineTo(400, height/2.0 + 200);
	path.lineTo(300, height/2.0 + 300);
	path.lineTo(0, height/2.0 + 300);
	path.close();
	path.draw();
	ofPushStyle();
	float scaledInc = inc * (width/4) - 400;
	ofTranslate(scaledInc, (200.0 * (sin(inc/1.4 + 1.0))) + height/2.0);
	plane.draw(-250, -110, 500, 220);
	ofPopStyle();
}
