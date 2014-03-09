#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
    // initialise sound
    soundStream.setup(this, 2, 0, SAMPLE_RATE, BUFFER_SIZE, 4);
    
    camWidth = 640;
    camHeight = 480;
    
    // init web cam
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth, camHeight);
    
    // set size of image that we're grabbing
    image = new unsigned char[camWidth*camWidth*3];
    videoTexture.allocate(camWidth, camHeight, GL_RGB);
    
    // TODO what does this do?
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::audioOut(float * output, int bufferSize, int nChannels){
    synth.addAudioOut(output, bufferSize, nChannels);
}

//--------------------------------------------------------------
void testApp::update(){
    // grab frame of video
    vidGrabber.update();
    
    if(vidGrabber.isFrameNew()) {
        image = vidGrabber.getPixels();
        videoTexture.loadData(image, camWidth, camHeight, GL_RGB);
    }
    
    scaling = MIN(ofGetWidth()/(float)camWidth, ofGetHeight()/(float)camHeight);
    
    xOffset = (ofGetWidth() - (camWidth * scaling)) / 2;
    yOffset = (ofGetHeight() - (camHeight * scaling)) / 2;
}

//--------------------------------------------------------------
// test of finger/mouse is on image covered part of screen
bool testApp::onImage(int x, int y){
    return x > xOffset
    && y > yOffset
    && x < ofGetWidth() - xOffset
    && y < ofGetHeight() - yOffset;
}

//--------------------------------------------------------------
void testApp::getImagePixelRGB(int x, int y, int * r, int * g, int * b){
    // scale position on screen
    x -= xOffset;
    y -= yOffset;
    x *= scaling;
    y *= scaling;
    
    // double check image scaling hasn't put us out of bounds
    if(x >= camWidth) { x = camWidth - 1; }
    if(x < 0) { x = 0; }
    if(y >= camHeight) { y = camHeight - 1; }
    if(y < 0) { y = 0; }
    
    // work out position in image to read back
    int imagePos = ((y * camWidth) + x) * 3;
    
    *r = (int)image[imagePos];
    *g = (int)image[imagePos + 1];
    *b = (int)image[imagePos + 2];
}

//--------------------------------------------------------------
void testApp::draw(){
    videoTexture.draw(xOffset, yOffset, camWidth * scaling, camHeight * scaling);
}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
    int x = touch.x;
    int y = touch.y;
    
    if(onImage(x, y)) {
        int r, g, b;
        
        // get rgb from image int r, g, b;
        getImagePixelRGB(x, y, &r, &g, &b);
        
        // get colour magnitudes
        double white, black, grey, blue, yellow, green, red;
        rgbToColourMags(&white, &black, &grey, &green, &red, &blue, &yellow, r, g, b);
        
        synth.mapColourMags(white, black, grey, green, red, blue, yellow);
    } else {
        synth.fadeOut();
    }
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::lostFocus(){

}

//--------------------------------------------------------------
void testApp::gotFocus(){

}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){

}

