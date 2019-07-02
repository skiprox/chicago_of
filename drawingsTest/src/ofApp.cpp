#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	width = ofGetWidth();
	height = ofGetHeight();
	// Create a bunch of random points?
	for (int i = 0; i < 5; i++) {
		pts.push_back(glm::vec2(ofRandom(width), ofRandom(height)));
	}
	// Create the point to chase
	pointToChase = glm::vec2(ofRandom(width), ofRandom(height));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (incrementer >= duration) {
		incrementer = 0;
		pts.push_back(pointToChase);
		pointToChase = glm::vec2(ofRandom(width), ofRandom(height));
	}
	path.setStrokeColor(ofColor(255, 40, 66));
	path.setStrokeWidth(100);
	path.setCurveResolution(100);
	path.clear();
	path.moveTo(glm::vec2(pts[0].x, pts[0].y));
	float lerpedX = ofLerp(pts[pts.size()-1].x, pointToChase.x, (float)incrementer/(float)duration);
	float lerpedY = ofLerp(pts[pts.size()-1].y, pointToChase.y, (float)incrementer/(float)duration);
	pts.push_back(glm::vec2(lerpedX, lerpedY));
	// create a new set of points, based on original points and final points and incrementer
	for (int i = 0; i < pts.size(); i++) {
		//we need to draw the first and last point
		//twice for a catmull curve
		// if (i == 0 || i == pts.size() - 1) {
		// 	path.curveTo(pts[i].x, pts[i].y);
		// }
		// This was the default code... for some reason it wants
		// us to only draw every 6th point...
		// if (i % rescaleRes == 0) path.curveTo(newPts[i].x, newPts[i].y);
		path.lineTo(pts[i].x, pts[i].y);
	}
	cout << "we made it through one rotation " << incrementer << endl;
	path.draw();
	pts.pop_back();
	incrementer++;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	// Update all the points
	// for (int i = 0; i < 100; i++) {
	// 	pts.erase(pts.begin(), pts.begin() + 1);
	// 	float x = ofRandom(width);
	// 	float y = ofRandom(height);
	// 	ofVec2f point = ofVec2f(x, y);
	// 	pts.push_back(point);
	// }
}
