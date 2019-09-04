#pragma once

#include "ofMain.h"
#include "TextFading.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);

		int incrementer;
		TextFading textFading;
		
};
