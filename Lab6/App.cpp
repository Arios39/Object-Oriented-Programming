#include <iostream>
#include "App.h"

App* singleton;
void draw();
void App::randomgen(){
    
}
void timer(int id){
    // This will get called every 16 milliseconds after
    // you call it once
    float amount;
        float back = singleton->background1->getY();
    float rocky1 = singleton->rock1->getY();
    float rocky2 = singleton->rock1->getY();
    float rocky3 = singleton->rock1->getY();

    if(singleton->running){
        if(rocky1<=-1){
            rocky1=5;
        }
        if(rocky2<=-1){
            rocky2=5;
        }
        if(rocky3<=-1){
            rocky3=5;
        }
        else{
            if (rocky1 >= 2){
                rocky1 = rocky1-3;
            }
            
            if (rocky2 >= 2){
                rocky2 = rocky2-3;
            }
            if (rocky2 >= 2){
                rocky2 = rocky2-3;
            }
            
        }
        amount=-singleton->inc;
        singleton->rock1->setY(rocky1+ amount);
        singleton->rock2->setY(rocky2+ amount);
        singleton->rock3->setY(rocky3+ amount);
            singleton->redraw();

         }
        
        
   
   
    
    if (singleton->up&&singleton->running){
        float ypos = singleton->projectile->getY();
        ypos +=0.05;
        singleton->projectile->setY(ypos);
        singleton->redraw();
        singleton->up= false;

    }

    if(singleton->left&&singleton->running){
    float xneg = singleton->projectile->getX();
       xneg-=0.25;
        singleton->projectile->setX(xneg);
        singleton->redraw();
        singleton->left= false;
    }
    
    if(singleton->right&&singleton->running){
        float xpos = singleton->projectile->getX();
        xpos+=0.25;
        singleton->projectile->setX(xpos);
        singleton->redraw();
        singleton->right= false;
    }
    if(singleton->shoot&&singleton->running){
        float ypos = singleton->blaster->getY();
        ypos +=0.02;
        singleton->blaster->setY(ypos);
        singleton->redraw();
    }


    
    glutTimerFunc(16, timer, id);
}


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    rock1 = new TexRect("/Users/andresrios/Lab6/rock.png", -0.3, 0.9, 0.5, 0.5);
    rock2 =new TexRect("/Users/andresrios/Lab6/rock.png", -.96, 0.9, 0.3, 0.3);
    rock3 =new TexRect("/Users/andresrios/Lab6/rock.png", 0.5, 0.9, 0.8, 0.7);
    blaster = new TexRect("/Users/andresrios/Lab6/blaster.png", 0.5, 0.9, 0.5, 0.5);
    projectile =new TexRect("/Users/andresrios/Lab6/ship.png", -0.5, -0.8, 0.3, 0.3);
    background1 =new TexRect("/Users/andresrios/Lab6/stars.png", -1.0, 1.0, 2, 2);
    background2 =new TexRect("/Users/andresrios/Lab6/stars.png", -1.0, 3.0, 2, 2);
    explosion = new AnimatedRect("/Users/andresrios/Lab6/fireball.bmp", 6, 6, 150, true, true, rock1->getX(), rock1->getY(), 0.5, 0.5);
    up = false;
    inc=0.13;
    left = false;
    move = true;
    running = true;
    singleton = this;
    shoot= false;
    timer(1);
}

void App::draw() {
    background1->draw(0.0);
    //background2->draw(0.0);
 projectile->draw(0.1);
    rock1->draw(0.1);
    rock2-> draw(0.1);
    rock3->draw(0.1);
   

  


    
}

void App::idle(){

    
    
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    if (key == ' '){
        shoot = true;
    }
   
    if(key == 'a'){
        left =true;
        
    }
    if(key == 'w'){
        up= true;
    }
    if(key=='d'){
        right = true;
    }
}

App::~App(){
    delete rock1;
    std::cout << "Exiting..." << std::endl;
}
