#include <iostream>
#include "App.h"

App* singleton;
void draw();

void timer(int id){
    // This will get called every 16 milliseconds after
    // you call it once
    float amount;
        float back = singleton->background1->getY();
		float back2 = singleton-> background2->getY();
		float back3 = singleton->background3->getY();

    float rocky1 = singleton->rock1->getY();
    float rocky2 = singleton->rock1->getY();
    float rocky3 = singleton->rock1->getY();

    if(!singleton->running){
        singleton->redraw();

    }
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
	if (singleton->running) { //Moving BackGround
		if (back <= -1) {
			back = 5;
		}
		if (back2 <= -1) {
			back2 = 5;
		}
		if (back3 <= -1) {
			back3 = 5;
		}
			
		else {
			if (back >= 2) {
				back = back - 3;
			}
			if (back2 >= 2) {
				back2 = back2 - 3;
			}
			if (back3 >= 2) {
				back3 = back3 - 3;
			}
		}
		amount = -singleton->Binc;
		singleton->background1->setY(back + amount);
		singleton->background2->setY(back2 + amount);
		singleton->background3->setY(back3 + amount);
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
	if (singleton->down && singleton->running) { //Stuff to go down
		float ypos = singleton->projectile->getY();
		ypos -= 0.05;
		singleton->projectile->setY(ypos);
		singleton->redraw();
		singleton->down = false;

	}


    
    glutTimerFunc(16, timer, id);
}


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    rock1 = new TexRect("/Users/andresrios/SpaceProject/Lab6/rock.png", -0.3, 0.9, 0.5, 0.5);
    rock2 =new TexRect("/Users/andresrios/SpaceProject/Lab6/rock.png", -.96, 0.9, 0.3, 0.3);
    rock3 =new TexRect("/Users/andresrios/SpaceProject/Lab6/rock.png", 0.5, 0.9, 0.8, 0.7);
    blaster = new TexRect("/Users/andresrios/SpaceProject/Lab6/blaster.png", 0.5, 0.9, 0.5, 0.5);
    projectile =new TexRect("/Users/andresrios/SpaceProject/Lab6/ship.png", -0.5, -0.8, 0.3, 0.3);
 gameover =new TexRect("/Users/andresrios/SpaceProject/Lab6/download.png", -1.0, 1.0, 2, 2);
    background1 =new TexRect("/Users/andresrios/SpaceProject/Lab6/stars.png", -1.0, 1.0, 2, 2);
    background2 =new TexRect("/Users/andresrios/SpaceProject/Lab6/stars.png", -1.0, 3.0, 2, 2);
	background3 = new TexRect("/Users/andresrios/SpaceProject/Lab6/stars.png", -1.0, 5.0, 2, 2); //Added third BackGround

    explosion = new AnimatedRect("/Users/andresrios/SpaceProject/Lab6/fireball.bmp", 6, 6, 150, true, true, rock1->getX(), rock1->getY(), 0.5, 0.5);
    up = false;
    inc=0.04;
	Binc = 0.02; //Incrememnt for Backgrounds
    left = false;
    move = true;
    running = true;
    singleton = this;
    shoot= false;
    timer(1);
}

void App::draw() {
    background1->draw(0.0);
    background2->draw(0.0);
	background3->draw(0.0);
 projectile->draw(0.1);
    rock1->draw(0.1);
    rock2-> draw(0.1);
    rock3->draw(0.1);
   

    if (projectile->getY() >= (rock1->getY() + 0.0) && projectile->getX() >= (rock1->getX() + 0.0) ) {
       running = false;
        up = false;
        
         singleton->gameover->draw(0.1);
        singleton->explosion->draw(0.1);

    }
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
	if (key == 's') { //Added Down Button
		down = true;
	}
}

App::~App(){
    delete rock1;
    std::cout << "Exiting..." << std::endl;
}
