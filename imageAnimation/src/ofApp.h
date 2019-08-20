#pragma once

#include "ofMain.h"
#include "ImageAnimation.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);

		int incrementer = 0;
		int incMax = 100;

		ImageAnimation imgAnimation;
		
};
