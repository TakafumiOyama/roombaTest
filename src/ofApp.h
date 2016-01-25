#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		//Primitive Movement Function
		void forwardLeft();
		void forwardRight();
		void backLeft();
		void backRight();
		void turnClockwiseLeft();
		void turnCounterClockwiseRight();
		void turnClockwiseRight();
		void turnCounterClockwiseLeft();
		void stopRoomba();

		//Preset Movement Function

		
		ofSerial serialLeft;
		ofSerial serialRight;
		char byteReedStringLeft[4];
		char byteReedStringRight[4];
		char byteWriteStringLeft[4];
		char byteWriteStringRight[4];
};
