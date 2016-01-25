#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	serialLeft.listDevices();
	serialRight.listDevices();
	vector<ofSerialDeviceInfo> &deviceListLeft = serialLeft.getDeviceList();
	vector<ofSerialDeviceInfo> &deviceListRight = serialRight.getDeviceList();
	int baud = 57600;
	//int baud = 19200;
	if (serialLeft.setup("COM8", baud)) {
		printf("serial-Left is setup\n");
	}
	if (serialRight.setup("COM9", baud)) {
		printf("serial-Right is setup\n");
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 't') {
		int counter1 = 0;
		int counter2 = 0;
		while (counter1 < 50) {
			ofApp::forwardLeft();
			ofApp::forwardRight();
			counter1++;
		}
		while (counter2 < 70) {
			ofApp::turnClockwiseLeft();
			ofApp::turnCounterClockwiseRight();
			counter2++;
		}
		ofApp::stopRoomba();
	}
	if (key == 'v') {
		int counter1 = 0;
		int counter2 = 0;
		while (counter1 < 50) {
			ofApp::turnClockwiseRight();
			ofApp::turnCounterClockwiseLeft();
			counter1++;
		}
		while (counter2 < 40) {
			ofApp::backRight();
			ofApp::backLeft();
			counter2++;
		}
		ofApp::stopRoomba();
	}
	if (key == '0') { //Change Boud-rate to 57600
		unsigned char send_data[2] = { 0 };
		send_data[0] = 129;
		send_data[1] = 10;
		bool isChangeBaudLeft = serialLeft.writeBytes(send_data, 2);
		bool isChangeBaudRight = serialRight.writeBytes(send_data, 2);
		if (!isChangeBaudLeft) {
			printf("cannot send [ChangeBaud-Left]\n");
		}
		if (!isChangeBaudRight) {
			printf("cannot send [ChangeBaud-Right]\n");
		}
	}
	if (key == 'p') { //Power On
		bool isStartLeft = serialLeft.writeByte(128);
		bool isStartRight = serialRight.writeByte(128);
		if (!isStartLeft) {
			printf("cannot send [128-Left]\n");
		}
		if (!isStartRight) {
			printf("cannot send [128-Right]\n");
		}
	}
	if (key == 's') { //Safe Mode
		bool isSafeLeft = serialLeft.writeByte(131);
		bool isSafeRight = serialRight.writeByte(131);
		if (!isSafeLeft) {
			printf("cannot send [131-Left]\n");
		}
		if (!isSafeRight) {
			printf("cannot send [131-Right]\n");
		}
	}
	if (key == 'q') { //Forward (LeftRoomba)
		unsigned char send_data[4] = { 0 };
		send_data[0] = 0;
		send_data[1] = 200;
		send_data[2] = 128;
		send_data[3] = 0;
		bool isDriveStartLeft = serialLeft.writeByte(137);
		if (!isDriveStartLeft) {
			printf("cannot send [137-Left]\n");
		}
		bool isForwardLeft = serialLeft.writeBytes(send_data, 4);
		if (!isForwardLeft) {
			printf("cannot send [Forward-Left]\n");
		}
	}
	if (key == 'z') { //Forward (RightRoomba)
		unsigned char send_data[4] = { 0 };
		send_data[0] = 0;
		send_data[1] = 200;
		send_data[2] = 128;
		send_data[3] = 0;
		bool isDriveStartRight = serialRight.writeByte(137);
		if (!isDriveStartRight) {
			printf("cannot send [137-Right]\n");
		}
		bool isForwardRight = serialRight.writeBytes(send_data, 4);
		if (!isForwardRight) {
			printf("cannot send [Forward-Right]\n");
		}
	}
	if (key == '4') { //Stop
		ofApp::stopRoomba();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::forwardLeft() {
	unsigned char send_data[4] = { 0 };
	send_data[0] = 0;
	send_data[1] = 200;
	send_data[2] = 128;
	send_data[3] = 0;
	bool isDriveStartLeft = serialLeft.writeByte(137);
	if (!isDriveStartLeft) {
		printf("cannot send [137-Left]\n");
	}
	bool isForwardLeft = serialLeft.writeBytes(send_data, 4);
	if (!isForwardLeft) {
		printf("cannot send [Forward-Left]\n");
	}
}

void ofApp::forwardRight() {
	unsigned char send_data[4] = { 0 };
	send_data[0] = 0;
	send_data[1] = 200;
	send_data[2] = 128;
	send_data[3] = 0;
	bool isDriveStartRight = serialRight.writeByte(137);
	if (!isDriveStartRight) {
		printf("cannot send [137-Right]\n");
	}
	bool isForwardRight = serialRight.writeBytes(send_data, 4);
	if (!isForwardRight) {
		printf("cannot send [Forward-Right]\n");
	}
}

void ofApp::backLeft() {
	unsigned char send_data[4] = { 0 };
	send_data[0] = 255;
	send_data[1] = 56;
	send_data[2] = 128;
	send_data[3] = 0;
	bool isDriveStartLeft = serialLeft.writeByte(137);
	if (!isDriveStartLeft) {
		printf("cannot send [137-Left]\n");
	}
	bool isBackLeft = serialLeft.writeBytes(send_data, 4);
	if (!isBackLeft) {
		printf("cannot send [Back-Left]\n");
	}
}

void ofApp::backRight() {
	unsigned char send_data[4] = { 0 };
	send_data[0] = 255;
	send_data[1] = 56;
	send_data[2] = 128;
	send_data[3] = 0;
	bool isDriveStartRight = serialRight.writeByte(137);
	if (!isDriveStartRight) {
		printf("cannot send [137-Right]\n");
	}
	bool isBackRight = serialRight.writeBytes(send_data, 4);
	if (!isBackRight) {
		printf("cannot send [Back-Right]\n");
	}
}

void ofApp::turnClockwiseLeft() {
	unsigned char send_data[4] = { 0 };
	send_data[0] = 0;
	send_data[1] = 50;
	send_data[2] = 255;
	send_data[3] = 206;
	bool isDriveStartLeft = serialLeft.writeByte(145);
	if (!isDriveStartLeft) {
		printf("cannot send [145-Left]\n");
	}
	bool isTurnLeft = serialLeft.writeBytes(send_data, 4);
	if (!isTurnLeft) {
		printf("cannot send [turnClickwise-Left]\n");
	}
}

void ofApp::turnCounterClockwiseRight() {
	unsigned char send_data[4] = { 0 };
	send_data[0] = 255;
	send_data[1] = 206;
	send_data[2] = 0;
	send_data[3] = 50;
	bool isDriveStartRight = serialRight.writeByte(145);
	if (!isDriveStartRight) {
		printf("cannot send [145-Right]\n");
	}
	bool isTurnRight = serialRight.writeBytes(send_data, 4);
	if (!isTurnRight) {
		printf("cannot send [turnClickwise-Right]\n");
	}
}

void ofApp::turnClockwiseRight() {
	unsigned char send_data[4] = { 0 };
	send_data[0] = 0;
	send_data[1] = 50;
	send_data[2] = 255;
	send_data[3] = 206;
	bool isDriveStartRight = serialRight.writeByte(145);
	if (!isDriveStartRight) {
		printf("cannot send [145-Right]\n");
	}
	bool isTurnRight = serialRight.writeBytes(send_data, 4);
	if (!isTurnRight) {
		printf("cannot send [turnClickwise-Right]\n");
	}
}

void ofApp::turnCounterClockwiseLeft() {
	unsigned char send_data[4] = { 0 };
	send_data[0] = 255;
	send_data[1] = 206;
	send_data[2] = 0;
	send_data[3] = 50;
	bool isDriveStartLeft = serialLeft.writeByte(145);
	if (!isDriveStartLeft) {
		printf("cannot send [145-Left]\n");
	}
	bool isTurnLeft = serialLeft.writeBytes(send_data, 4);
	if (!isTurnLeft) {
		printf("cannot send [turnClickwise-Left]\n");
	}
}

void ofApp::stopRoomba() {
	unsigned char send_data[4] = { 0 };
	bool isDriveStopLeft = serialLeft.writeByte(137);
	bool isDriveStopRight = serialRight.writeByte(137);
	if (!isDriveStopLeft) {
		printf("cannot send [137-Left]\n");
	}
	if (!isDriveStopRight) {
		printf("cannot send [137-Right]\n");
	}
	bool isStopLeft = serialLeft.writeBytes(send_data, 4);
	bool isStopRight = serialRight.writeBytes(send_data, 4);
	if (!isStopLeft) {
		printf("cannot send [Stop-Left]\n");
	}
	if (!isStopRight) {
		printf("cannot send [Stop-Right]\n");
	}
}