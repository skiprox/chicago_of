#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255);
	ofSetCircleResolution(100);
	heart.load("test.svg");
	arrowSVG.load("arrow.svg");
	arrowImg.load("arrow.png");
	width = ofGetWidth();
	height = ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	float easedValue;
	// Linear
	ofSetHexColor(0xCC0000);
	ofDrawBitmapString("a) Linear (no ease)", 100, 30);
	ofPushMatrix();
	ofTranslate(200, 100);
	easedValue = ofClamp(incrementer/(incrementerMax - 50.0), 0.0, 1.0);
	ofScale(easedValue, easedValue);
	ofRotate(45 * easedValue);
	arrowImg.draw(-85, -100);
	ofPopMatrix();
	// Elastic Ease Out
	ofSetHexColor(0xCC0000);
	ofDrawBitmapString("b) Elastic Ease Out", 400, 30);
	ofPushMatrix();
	ofTranslate(500, 100);
	easedValue = elasticEaseOut(ofClamp(incrementer/(incrementerMax - 50.0), 0.0, 1.0));
	ofScale(easedValue, easedValue);
	ofRotate(45 * easedValue);
	arrowImg.draw(-85, -100);
	ofPopMatrix();
	// Bounce Ease Out
	ofSetHexColor(0xCC0000);
	ofDrawBitmapString("c) Bounce Ease Out", 700, 30);
	ofPushMatrix();
	ofTranslate(800, 100);
	easedValue = bounceEaseOut(ofClamp(incrementer/(incrementerMax - 50.0), 0.0, 1.0));
	ofScale(easedValue, easedValue);
	ofRotate(45 * easedValue);
	arrowImg.draw(-85, -100);
	ofPopMatrix();
	// Back Ease Out
	ofSetHexColor(0xCC0000);
	ofDrawBitmapString("d) Back Ease Out", 100, 260);
	ofPushMatrix();
	ofTranslate(200, 330);
	easedValue = backEaseOut(ofClamp(incrementer/(incrementerMax - 50.0), 0.0, 1.0));
	ofScale(easedValue, easedValue);
	ofRotate(45 * easedValue);
	arrowImg.draw(-85, -100);
	ofPopMatrix();
	// Cubic Ease Out
	ofSetHexColor(0xCC0000);
	ofDrawBitmapString("e) Cubic Ease Out", 400, 260);
	ofPushMatrix();
	ofTranslate(500, 330);
	easedValue = cubicEaseOut(ofClamp(incrementer/(incrementerMax - 50.0), 0.0, 1.0));
	ofScale(easedValue, easedValue);
	ofRotate(45 * easedValue);
	arrowImg.draw(-85, -100);
	ofPopMatrix();
	// Circ
	ofSetHexColor(0xCC0000);
	ofDrawBitmapString("f) Circ Ease Out", 700, 260);
	ofPushMatrix();
	ofTranslate(800, 330);
	easedValue = circEaseOut(ofClamp(incrementer/(incrementerMax - 50.0), 0.0, 1.0));
	ofScale(easedValue, easedValue);
	ofRotate(45 * easedValue);
	arrowImg.draw(-85, -100);
	ofPopMatrix();
	// Expo Ease Out
	ofSetHexColor(0xCC0000);
	ofDrawBitmapString("g) Expo Ease Out", 100, 490);
	ofPushMatrix();
	ofTranslate(200, 560);
	easedValue = expoEaseOut(ofClamp(incrementer/(incrementerMax - 50.0), 0.0, 1.0));
	ofScale(easedValue, easedValue);
	ofRotate(45 * easedValue);
	arrowImg.draw(-85, -100);
	ofPopMatrix();
	// Quad Ease Out
	ofSetHexColor(0xCC0000);
	ofDrawBitmapString("h) Quad Ease Out", 400, 490);
	ofPushMatrix();
	ofTranslate(500, 560);
	easedValue = quadEaseOut(ofClamp(incrementer/(incrementerMax - 50.0), 0.0, 1.0));
	ofScale(easedValue, easedValue);
	ofRotate(45 * easedValue);
	arrowImg.draw(-85, -100);
	ofPopMatrix();
	// Sine Ease Out
	ofSetHexColor(0xCC0000);
	ofDrawBitmapString("h) Sine Ease Out", 700, 490);
	ofPushMatrix();
	ofTranslate(800, 560);
	easedValue = sineEaseOut(ofClamp(incrementer/(incrementerMax - 50.0), 0.0, 1.0));
	ofScale(easedValue, easedValue);
	ofRotate(45 * easedValue);
	arrowImg.draw(-85, -100);
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
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
float ofApp::elasticEaseOut(float t){
	if (t==0) return 0.0;
	if (t==1) return 1.0;
	float p=.3f;
	float s=p/4;
	return (pow(2, -10 * t) * sin((t - s)*(2 * PI)/p) + 1.0);
}

//--------------------------------------------------------------
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

//--------------------------------------------------------------
float ofApp::backEaseOut(float t) {
	float s = 1.70158f;
	return ((t=t/1.0-1)*t*((s+1)*t + s) + 1);
}

//--------------------------------------------------------------
float ofApp::cubicEaseOut(float t) {
	return ((t=t-1)*t*t + 1);
}

//--------------------------------------------------------------
float ofApp::circEaseOut(float t) {
	return sqrt(1 - (t=t-1)*t);
}

//--------------------------------------------------------------
float ofApp::expoEaseOut(float t) {
	return (t==1.0) ? 1.0 : (-pow(2, -10 * t) + 1);
}

//--------------------------------------------------------------
float ofApp::quadEaseOut(float t) {
	return -1.0 *(t)*(t-2);
}

//--------------------------------------------------------------
float ofApp::sineEaseOut(float t) {
	return sin(t * (PI/2));
}
