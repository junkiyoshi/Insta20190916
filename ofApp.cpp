#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofColor color;
	color.setHex(0xD7E8DC);
	ofBackground(color);

	color.setHex(0x0E8BAD);
	this->color_list.push_back(color);
	color.setHex(0x3B6469);
	this->color_list.push_back(color);
	color.setHex(0xCA6A4A);
	this->color_list.push_back(color);
	color.setHex(0xBD2831);
	this->color_list.push_back(color);
}


//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 72;
	int radius = 30;

	for (int x = span * 0.5; x < ofGetWidth() + span * 0.5; x += span) {

		for (int y = span * 0.5; y < ofGetHeight() + span * 0.5; y += span) {

			int identity = ofRandom(1000);
			identity = identity / 60 * 60;
			int rotate_param = ofRandom(4) + (identity + ofGetFrameNum()) / 240;
			int identity_param = (identity + ofGetFrameNum()) % 240;
			int add_rotate = identity_param < 210 ? 0 : ofMap(identity_param, 210, 240, 0, 90);

			ofPushMatrix();
			ofTranslate(x, y);
			ofRotate(rotate_param * 90 + add_rotate);

			int color_index = ofRandom(this->color_list.size());
			ofSetColor(this->color_list[color_index]);

			this->draw_arc(glm::vec2(), radius, 0, 270);

			ofPopMatrix();
		}
	}

	for (int i = 0; i < 6000; i++) {

		float x = ofRandom(ofGetWidth());
		float y = ofRandom(ofGetHeight());

		ofSetColor(255, 32);
		ofDrawCircle(x, y, 0.5);
	}
}

//--------------------------------------------------------------
void ofApp::draw_arc(glm::vec2 location, float radius, int start_deg, int stop_deg) {

	vector<glm::vec2> vertices;
	for (int deg = start_deg; deg <= stop_deg; deg++) {

		vertices.push_back(location + glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
	}
	vertices.push_back(location);

	ofFill();

	ofBeginShape();
	ofVertices(vertices);
	ofEndShape(true);

	ofSetColor(39);
	ofNoFill();

	ofBeginShape();
	ofVertices(vertices);
	ofEndShape(true);
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}