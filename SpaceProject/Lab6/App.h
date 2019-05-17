#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"


class App: public GlutApp {
    AnimatedRect* explosion;
    TexRect* rock1;
    TexRect* rock2;
    TexRect* rock3;
    TexRect* projectile;
    TexRect* blaster;
    TexRect* background1;
    TexRect* gameover;

    TexRect* background2;
	TexRect* background3; // Added third Background *
    float inc;
	float Binc;
    bool left;
    bool shoot;
    bool blast;
    bool right;
    bool up;
	bool down; // added down stuff
    bool move;
    bool running;
public:
    
    void randomgen(int num);
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    void idle();
    
    friend void timer(int);
    

    
};

#endif
