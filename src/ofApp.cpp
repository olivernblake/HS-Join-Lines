#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);
    spacingX = ofGetWidth()/numX;
    spacingY = ofGetHeight()/numY;
    startingX = spacingX/2;
    startingY = spacingY/2;
    stepSize = 50;
    distHyp = spacingX;
    ofSetLineWidth(3);
    ofSetCircleResolution(60);

    
    for (int x = 0; x < numX; x++) {
        for (int y = 0; y < numY; y++) {
            noiseSeeds[x][y] = ofRandom(1000);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    vector<glm::vec2> location_list;
    
    ofSetColor(255, 80);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
//    float sinShape = sin(ofDegToRad(ofGetFrameNum()*2));
//    distHyp = ofMap(sinShape, -1, 1, spacingX/2, spacingX*2, true);
    
    ofSetColor(0);
    int r = 4;
    for (int x = 0; x < numX; x++) {
        for (int y = 0; y < numY; y++) {
            float distortX = ofSignedNoise(noiseSeeds[x][y]) * stepSize;
            float distortY = ofSignedNoise(noiseSeeds[x][y] + 500) * stepSize;
            
            int locX = startingX + (x * spacingX);
            int locY = startingY + (y * spacingY);

            locX = locX + distortX;
            locY = locY + distortY;
 
            ofDrawCircle(locX, locY, r);
            noiseSeeds[x][y] += 0.02;
            
            location_list.push_back(glm::vec2(locX, locY));
        }
    }
    
    for (int i = 0; i < location_list.size(); i++) {
        for (int k = i + 1; k < location_list.size(); k++) {
            auto distance = glm::distance(location_list[i], location_list[k]);
            if (distance < distHyp) {
                ofDrawLine(location_list[i].x, location_list[i].y, location_list[k].x, location_list[k].y);
            }
        }
    }
    
//    for (int x = 0; x < numX; x++) {
//        for (int y = 0; y < numY; y++) {
//            int distN = ofDist(posX[x], posY[y], posX[x], posY[y-1]);
//            int distNE = ofDist(posX[x], posY[y], posX[x+1], posY[y-1]);
//            int distE = ofDist(posX[x], posY[y], posX[x+1], posY[y]);
//            int distSE = ofDist(posX[x], posY[y], posX[x+1], posY[y+1]);
//            int distS = ofDist(posX[x], posY[y], posX[x], posY[y+1]);
//            int distSW = ofDist(posX[x], posY[y], posX[x-1], posY[y+1]);
//            int distW = ofDist(posX[x], posY[y], posX[x-1], posY[y]);
//            int distNW = ofDist(posX[x], posY[y], posX[x-1], posY[y+1]);
//
//            if (distN < distHyp) {
//                ofDrawLine(posX[x], posY[y], posX[x], posY[y-1]);
//            }
//            if (distNE < distHyp) {
//                ofDrawLine(posX[x], posY[y], posX[x+1], posY[y-1]);
//            }
//            if (distE < distHyp) {
//                ofDrawLine(posX[x], posY[y], posX[x+1], posY[y]);
//            }
//            if (distSE < distHyp) {
//                ofDrawLine(posX[x], posY[y], posX[x+1], posY[y+1]);
//            }
//            if (distS < distHyp) {
//                ofDrawLine(posX[x], posY[y], posX[x], posY[y+1]);
//            }
//            if (distSW < distHyp) {
//                ofDrawLine(posX[x], posY[y], posX[x-1], posY[y+1]);
//            }
//            if (distW < distHyp) {
//                ofDrawLine(posX[x], posY[y], posX[x-1], posY[y]);
//            }
//            if (distNW < distHyp) {
//                ofDrawLine(posX[x], posY[y], posX[x-1], posY[y+1]);
//            }
//        }
//    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
