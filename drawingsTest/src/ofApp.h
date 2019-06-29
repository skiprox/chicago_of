#pragma once

#include "ofMain.h"
#include "ofxSvg.h"
#include "ofxVectorGraphics.h"

#ifndef PI
#define PI  3.14159265
#endif

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		float elasticEaseOut(float t);
		float bounceEaseOut(float t);
		float backEaseOut(float t);
		float cubicEaseOut(float t);
		float circEaseOut(float t);
		float expoEaseOut(float t);
		float quadEaseOut(float t);
		float sineEaseOut(float t);

		ofxSVG heart;
		ofxSVG arrowSVG;
		ofImage arrowImg;

		float width;
		float height;

		float incrementer = 0.0;
		float incrementerMax = 200.0;
		
};
