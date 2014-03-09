#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"
#include "synth/Synth.h"
#include "colourMapping/RGBtoColourMags.h"

class testApp : public ofxiOSApp{
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
	
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
    
    // sound generation setup
    ofSoundStream soundStream;
    void audioOut(float * output, int bufferSize, int nChannels);
    
    // synth setup
    Synth synth;
    
    // video input
    ofVideoGrabber  vidGrabber;
    unsigned char * image;
    ofTexture               videoTexture;
    
    // video scaling
    int                     xOffset;
    int                     yOffset;
    int                     camWidth;
    int                     camHeight;
    float                   scaling;
    
    // function to return rgb values at x, y
    void getImagePixelRGB(int x, int y, int * r, int * g, int * b);
    
    // function that returns wether x, y screen coordinates are inside image or not
    bool onImage(int x, int y);
};


