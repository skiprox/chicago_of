#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetCircleResolution(100);
	vector<ofImage> imgs;
	ofImage text1, text2, text3, text4, text5, text6, text7;
	text1.load("images/lorem1.png");
	text2.load("images/lorem2.png");
	text3.load("images/lorem3.png");
	text4.load("images/lorem4.png");
	text5.load("images/lorem5.png");
	text6.load("images/lorem6.png");
	text7.load("images/lorem7.png");
	imgs.push_back(text1);
	imgs.push_back(text2);
	imgs.push_back(text3);
	imgs.push_back(text4);
	imgs.push_back(text5);
	imgs.push_back(text6);
	imgs.push_back(text7);
	textFading = TextFading(imgs);
}

//--------------------------------------------------------------
void ofApp::update(){
	incrementer++;
	textFading.update(incrementer);
}

//--------------------------------------------------------------
void ofApp::draw(){
	textFading.draw();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
