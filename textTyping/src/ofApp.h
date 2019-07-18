#pragma once

#include "ofMain.h"
#include "TextTyping.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mouseReleased(int x, int y, int button);

		TextTyping textTyping, backgroundTyping;

		int incrementer;
		
};
