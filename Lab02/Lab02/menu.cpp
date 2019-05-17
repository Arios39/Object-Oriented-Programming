//
//  menu.cpp
//  Lab02
//
//  Created by Andres Rios on 2/19/19.
//  Copyright © 2019 Andres Rios. All rights reserved.
//
#include "menu.h"
#include<ctime>
#include<cstdlib>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

using namespace std;
int ran(){
    
    srand((unsigned)time(0));
    int i;
    i = (rand()%6)+1;
   // cout << i << "\n";
    if ( i % 2 == 0){
        
        return 1;
    }
        //cout << i << " is even.";

         //cout << i << " is odd.";

    return 0;
}




void menu(){

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
    
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f (-0.05, 0.2);
    glVertex2f(-0.05, 0.5);
    glVertex2f(0.05, 0.5);
    glVertex2f(0.05, 0.2);
    glEnd();
   
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f (-0.1, 0.4);
    glVertex2f(-0.05, 0.4);
    glVertex2f(-0.05, 0.5);
    glVertex2f(-0.1, 0.5);
    glEnd();
    
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f (-0.3, 0.1);
    glVertex2f(-0.3, 0.6);
    glVertex2f(0.3, 0.6);
    glVertex2f(0.3, 0.1);
    glEnd();
  
    
 
    //-------------------------Player vs Player
  
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.05, -0.25);
    glVertex2f(0.1, -0.25);
    glVertex2f(0.1, -0.4);
    glVertex2f(0.05, -0.4);
    glEnd();
    
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05, -0.35);
    glVertex2f(-0.1, -0.35);
    glVertex2f(-0.1, -0.5);
    glVertex2f(-0.05, -0.5);
    glEnd();
    
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.25);
    glVertex2f(0.1, -0.25);
    glVertex2f(0.1, -0.3);
    glVertex2f(-0.1, -0.3);
    glEnd();
    
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.35);
    glVertex2f(0.1, -0.35);
    glVertex2f(0.1, -0.4);
    glVertex2f(-0.1, -0.4);
    glEnd();
    
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.45);
    glVertex2f(0.1, -0.45);
    glVertex2f(0.1, -0.5);
    glVertex2f(-0.1, -0.5);
    glEnd();
    
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, -0.6);
    glVertex2f(-0.3, -0.1);
    glVertex2f(0.3, -0.1);
    glVertex2f(0.3, -0.6);
    glEnd();
    
    //------------------------player VS AI
    glFlush();
    glutSwapBuffers();
    
}








