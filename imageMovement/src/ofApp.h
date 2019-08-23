#pragma once

#include "ofMain.h"
#include "ImageMovement.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);

		float incrementer;

		ImageMovement imgMovement;
		
};
