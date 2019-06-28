#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	heart.load("test.svg");
	arrow.load("arrow.svg");
	width = ofGetWidth();
	height = ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	float easedValue;
	// Elastic Ease Out
	ofPushMatrix();
	ofTranslate(200, 0);
	easedValue = elasticEaseOut(ofClamp(incrementer/(incrementerMax - 50.0), 0.0, 1.0));
	ofScale(easedValue, easedValue);
	ofRotate(45 * easedValue);
	arrow.draw();
	ofPopMatrix();
	ofPushMatrix();
	ofTranslate(500, 0);
	easedValue = bounceEaseOut(ofClamp(incrementer/(incrementerMax - 50.0), 0.0, 1.0));
	ofScale(easedValue, easedValue);
	ofRotate(45 * easedValue);
	arrow.draw();
	ofPopMatrix();
	// Incrementer
	if (incrementer >= incrementerMax) {
		incrementer = 0.0;
	} else {
		incrementer++;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

//--------------------------------------------------------------
// t = value between [0, 1] to add ease to
float ofApp::elasticEaseOut(float t){
	if (t==0) return 0.0;
	if (t==1) return 1.0;
	float p=.3f;
	float s=p/4;
	return (pow(2, -10 * t) * sin((t - s)*(2 * PI)/p) + 1.0);
}

float ofApp::bounceEaseOut(float t) {
	if (t < (1/2.75f)) {
		return (7.5625f*t*t);
	} else if (t < (2/2.75f)) {
		float postFix = t-=(1.5f/2.75f);
		return (7.5625f*(postFix)*t + .75f);
	} else if (t < (2.5/2.75)) {
			float postFix = t-=(2.25f/2.75f);
		return (7.5625f*(postFix)*t + .9375f);
	} else {
		float postFix = t-=(2.625f/2.75f);
		return (7.5625f*(postFix)*t + .984375f);
	}
}
