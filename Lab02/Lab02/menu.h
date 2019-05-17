//
//  menu.h
//  Lab02
//
//  Created by Andres Rios on 2/19/19.
//  Copyright © 2019 Andres Rios. All rights reserved.
//
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
#ifndef menu_h
#define menu_h





int ran();
void menu();
void appDrawScene();
#endif /* menu_h */
