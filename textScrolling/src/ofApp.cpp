#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetCircleResolution(100);
	float width = ofGetWidth();
	float height = ofGetHeight();
	unabomber = TextScrolling("1. The Industrial Revolution and its consequences have been a disaster for the human\nrace. They have greatly increased the life-expectancy of those of us who live in\n“advanced” countries, but they have destabilized society, have made life unfulfilling,\nhave subjected human beings to indignities, have led to widespread psychological\nsuffering (in the Third World to physical suffering as well) and have inflicted severe\ndamage on the natural world. The continued development of technology will worsen\nthe situation. It will certainly subject human beings to greater indignities and inflict\ngreater damage on the natural world, it will probably lead to greater social disruption\nand psychological suffering, and it may lead to increased physical suffering even in\n“advanced” countries.\n\n2. The industrial-technological system may survive or it may break down. If it\nsurvives, it MAY eventually achieve a low level of physical and psychological\nsuffering, but only after passing through a long and very painful period of adjustment\nand only at the cost of permanently reducing human beings and many other living\norganisms to engineered products and mere cogs in the social machine. Furthermore, if\nthe system survives, the consequences will be inevitable: There is no way of reforming\nor modifying the system so as to prevent it from depriving people of dignity and\nautonomy.\n\n3. If the system breaks down the consequences will still be very painful. But the bigger\nthe system grows the more disastrous the results of its breakdown will be, so if it is to\nbreak down it had best break down sooner rather than later.", glm::vec2(width/2.0 + 2, height/2.0 + 1), ofColor(240, 40, 20), 16);
	incrementer = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	incrementer++;
	unabomber.update(incrementer);
}

//--------------------------------------------------------------
void ofApp::draw(){
	unabomber.draw();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	incrementer = 0;
}
