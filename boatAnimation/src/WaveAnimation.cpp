//
//  WaveAnimation.cpp
//  Wave Animations
//
//
//

#include "WaveAnimation.hpp"

WaveAnimation::WaveAnimation()
{
	pos = glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0);
	waveSize = glm::vec2(200.0, 100.0);
    setup();
}

WaveAnimation::WaveAnimation(glm::vec2 _pos, glm::vec2 _waveSize) {
	pos = _pos;
	waveSize = _waveSize;
    setup();
}

void WaveAnimation::setup() {
	inc = 0.0;
	width = ofGetWidth();
	height = ofGetHeight();
	ranOffset = ofRandom(1.0, 5.0);
}

void WaveAnimation::update(float _inc) {
	inc = _inc;
}

void WaveAnimation::draw() {
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(pos.x + (20.0 * sin(inc)) * ranOffset, pos.y);
	path.clear();
	path.setFilled(false);
	path.setStrokeColor(ofColor(40, 40, 40));
	path.setStrokeWidth(6.0);
	path.moveTo(-waveSize.x/2.0, 0);
	for (int i = 0; i < (int)width/(waveSize.x * 0.8); i++) {
		// if even, we go up
		if (i % 2 == 0) {
			path.quadBezierTo(glm::vec2((i * waveSize.x) - waveSize.x/2.0, 0), glm::vec2((i * waveSize.x), -waveSize.y), glm::vec2((i * waveSize.x) + waveSize.x/2.0, 0));
		} else {
			path.quadBezierTo(glm::vec2((i * waveSize.x) - waveSize.x/2.0, 0), glm::vec2((i * waveSize.x), waveSize.y), glm::vec2((i * waveSize.x) + waveSize.x/2.0, 0));
		}
	}
	path.draw();
	ofPopMatrix();
	ofPopStyle();
}
