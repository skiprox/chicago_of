//
//  BoatAnimation.cpp
//  Boat Animations
//
//
//

#include "BoatAnimation.hpp"

BoatAnimation::BoatAnimation()
{
	boat.load("ship.jpeg");
	pos = glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0);
	size = glm::vec2(250, 70);
    setup();
}

BoatAnimation::BoatAnimation(ofImage _boat, glm::vec2 _pos, glm::vec2 _size) {
	boat = _boat;
	pos = _pos;
	size = _size;
    setup();
}

void BoatAnimation::setup() {
	inc = 0.0;
}

void BoatAnimation::update(float _inc) {
	inc = _inc;
}

void BoatAnimation::draw() {
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(pos.x, pos.y + (20.0 * (sin(inc + 1.0))));
	ofRotate(sin(inc) * 5.0);
	boat.draw(-size.x/2.0, -size.y/2.0, size.x, size.y);
	ofPopMatrix();
	ofPopStyle();
}
