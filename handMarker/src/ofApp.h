#pragma once

#include "ofMain.h"
#include "HandMarker.hpp"

#ifndef PI
	#define PI       3.14159265358979323846
#endif

#ifndef TWO_PI
	#define TWO_PI   6.28318530717958647693
#endif

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);
		void mouseReleased(int x, int y, int button);

		HandMarker handMarker;

		float universalCounter = 0.0;
		
};
