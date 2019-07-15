//
//  LineArrow.cpp
//  LineArrows
//
//
//

#include "LineArrow.hpp"

LineArrow::LineArrow()
{
	float width = ofGetWidth();
	float height = ofGetHeight();
	array<glm::vec2, 2> newPoints1 = {{glm::vec2(0, 0), glm::vec2(400, 400)}};
	pts.push_back(newPoints1);
	array<glm::vec2, 2> newPoints2 = {{glm::vec2(400, 400), glm::vec2(800, 100)}};
	pts.push_back(newPoints2);
	strokeWidth = 10.0;
	color = ofColor(240, 60, 40);
	incMax = 250;
    setup();
}

LineArrow::LineArrow(vector<std::array<glm::vec2, 2>> _pts, float _strokeWidth, ofColor _color, int _incMax) {
	pts = _pts;
	strokeWidth = _strokeWidth;
	color = _color;
	incMax = _incMax;
    setup();
}

void LineArrow::setup() {
	inc = 0;
	numSegments = pts.size();
	path.setCurveResolution(100);
	ofSetCircleResolution(100);
}

void LineArrow::update(int _inc) {
	inc = _inc;
}

void LineArrow::draw() {
	ofPushStyle();
	path.clear();
	path.setStrokeWidth(strokeWidth);
	path.setStrokeColor(color);
	path.setFilled(false);
	for (int i = 0; i < numSegments; i++) {
		if (inc > (incMax/(numSegments) * i) && inc <= incMax/(numSegments) * (i + 1)) {
			for (int j = 0; j < i; j++) {
				path.moveTo(pts[j][0]);
				path.lineTo(pts[j][1]);
				path.close();
				path.draw();
			}
			path.moveTo(pts[i][0]);
			float upperEq = (float)inc - ((float)incMax/((float)numSegments) * i);
			float lowerEq = ((float)incMax/((float)numSegments) * ((float)i + 1.0)) - ((float)incMax/((float)numSegments) * i);
			float easedIncrement = quadEaseOut(upperEq/lowerEq);
			path.lineTo(ofLerp(pts[i][0].x, pts[i][1].x, easedIncrement), ofLerp(pts[i][0].y, pts[i][1].y, easedIncrement));
			path.close();
			path.draw();
		} else if (inc >= incMax) {
			path.moveTo(pts[i][0]);
			path.lineTo(pts[i][1]);
			path.close();
			path.draw();
		}
	}
	ofPopStyle();
}

//--------------------------------------------------------------
float LineArrow::quadEaseOut(float t) {
	return -1.0 *(t)*(t-2);
}
