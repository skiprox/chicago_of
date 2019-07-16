#pragma once

#include "ofMain.h"
#include "BoatAnimation.hpp"
#include "WaveAnimation.hpp"

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

		void mouseReleased(int x, int y, int button);

		vector<BoatAnimation> boatAnimations;
		ofImage boat;

		vector<WaveAnimation> waveAnimations;
		
		float universalCounter = 0.0;
};
