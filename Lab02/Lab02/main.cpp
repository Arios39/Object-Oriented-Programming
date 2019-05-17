//
//  main.cpp
//  Lab02
//
//  Created by Andres Rios on 2/19/19.
//  Copyright © 2019 Andres Rios. All rights reserved.
//Structure taken from lecture 
#include <vector>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <unistd.h>

#include "menu.h"
#include "Rect.h"
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif
using namespace std;
bool mode1 = false;
bool mode2 = false;
bool t=ran();
bool player1=t;
bool ai = false;
bool gameOver = false;


vector<rectangle> grid;

bool winX(vector<rectangle> grid);
bool winO(vector<rectangle> grid);


void GameState(vector<rectangle> grid){
    if (winX(grid)){
        cout << "player 1 wins" << endl;
        gameOver = true;
    }
    if (winO(grid)){
        cout << "player 2 wins" << endl;
        gameOver = true;
        
    }
    
    if (!gameOver){
        bool flag = true;
        for (int i = 0; i < grid.size(); i++) {
            if (!grid[i].occupied){
                flag = false;
                break;
            }
        }
        if (flag){
            gameOver = true;
            cout << "Nobody wins" << endl;
        }
    }
}

bool winX(vector<rectangle> grid){
    Shape temp = cross;
    if (grid[0].shape == temp && grid[1].shape ==  temp && grid[2].shape == temp){
        return true;
    }
    if (grid[3].shape == temp && grid[4].shape ==  temp && grid[5].shape == temp){
        return true;
    }
    if (grid[6].shape == temp && grid[7].shape ==  temp && grid[8].shape == temp){
        return true;
    }
    if (grid[0].shape == temp && grid[3].shape ==  temp && grid[6].shape == temp){
        return true;
    }
    if (grid[1].shape == temp && grid[4].shape ==  temp && grid[7].shape == temp){
        return true;
    }
    if (grid[2].shape == temp && grid[5].shape ==  temp && grid[8].shape == temp){
        return true;
    }
    if (grid[0].shape == temp && grid[4].shape ==  temp && grid[8].shape == temp){
        return true;
    }
    if (grid[2].shape == temp && grid[4].shape ==  temp && grid[6].shape == temp){
        return true;
    }
}

bool winO(vector<rectangle> grid){
    Shape temp = circle;
    if (grid[0].shape == temp && grid[1].shape ==  temp && grid[2].shape == temp){
        return true;
    }
    if (grid[3].shape == temp && grid[4].shape ==  temp && grid[5].shape == temp){
        return true;
    }
    if (grid[6].shape == temp && grid[7].shape ==  temp && grid[8].shape == temp){
        return true;
    }
    if (grid[0].shape == temp && grid[3].shape ==  temp && grid[6].shape == temp){
        return true;
    }
    if (grid[1].shape == temp && grid[4].shape ==  temp && grid[7].shape == temp){
        return true;
    }
    if (grid[2].shape == temp && grid[5].shape ==  temp && grid[8].shape == temp){
        return true;
    }
    if (grid[0].shape == temp && grid[4].shape ==  temp && grid[8].shape == temp){
        return true;
    }
    if (grid[2].shape == temp && grid[4].shape ==  temp && grid[6].shape == temp){
        return true;
    }
    
}


/*struct Rectangle {
    float x;
    float y;
    float w;
    float h;
    
    bool occupied;
    

    //angelos code
    Rectangle (float x, float y, float w, float h){
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        occupied = false;
    }
    
    bool contains(float mx, float my){
        return mx >= x && mx <= x + w && my <= y && my >= y - h;
    }
    
    void draw(){
        glBegin(GL_POLYGON);
        
        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y - h);
        glVertex2f(x, y - h);
        
        glEnd();
    }
    
};

*/

// Store the width and height of the window
int width = 640, height = 640;

void xisplay(){
    for(int i = 0 ; i < grid.size();i++){    //draws x
        
        glColor3d(0.0, 1.0, 1.0);
        glLineWidth(2);
        glBegin(GL_LINES);
        for (int i = 0; i < grid.size(); i++) {
            grid[i].draw();
        }
    
        
        
        glEnd();
    }
}
void appDrawScene() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Draw squares for our grid

    for (int i = 0; i < grid.size(); i++) {
        grid[i].draw();
    }
    glColor3f(1.0, 0.0, 0.0);
    
    glLineWidth(21);
    
    glBegin(GL_LINES);
    
    glVertex3f(0.20, 0.60, 0.5);
    glVertex3f(0.20, -0.60, 0.5);
    
    glVertex3f(-0.20, 0.60, 0.5);
    glVertex3f(-0.20, -0.60, 0.5);
    
    glVertex3f(0.6, 0.2, 0.5);
    glVertex3f(-0.6, 0.2, 0.5);
    
    glVertex3f(0.6, -0.2, 0.5);
    glVertex3f(-0.6, -0.2, 0.5);
    
    glEnd();
    
    
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();}

//-------------------------------------------------------
// A function to convert window coordinates to scene
// We use it when a mouse event is handled
// Arguments:
//    x, y - the coordinates to be updated
//-------------------------------------------------------
void windowToScene(float& x, float& y) {
    x = (2.0f*(x / float(width))) - 1.0f;
    y = 1.0f - (2.0f*(y / float(height)));
}

//-------------------------------------------------------
// A function to handle window resizing
// Called every time the window is resized
// Arguments:
//    b    - mouse button that was clicked, left or right
//    s      - state, either mouse-up or mouse-down
//    x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appReshapeFunc(int w, int h) {
    // Window size has changed
    width = w;
    height = h;
    
    double scale, center;
    double winXmin, winXmax, winYmin, winYmax;
    
    // Define x-axis and y-axis range
    const double appXmin = -1.0;
    const double appXmax = 1.0;
    const double appYmin = -1.0;
    const double appYmax = 1.0;
    
    // Define that OpenGL should use the whole window for rendering
    glViewport(0, 0, w, h);
    
    // Set up the projection matrix using a orthographic projection that will
    // maintain the aspect ratio of the scene no matter the aspect ratio of
    // the window, and also set the min/max coordinates to be the disered ones
    w = (w == 0) ? 1 : w;
    h = (h == 0) ? 1 : h;
    
    if ((appXmax - appXmin) / w < (appYmax - appYmin) / h) {
        scale = ((appYmax - appYmin) / h) / ((appXmax - appXmin) / w);
        center = (appXmax + appXmin) / 2;
        winXmin = center - (center - appXmin)*scale;
        winXmax = center + (appXmax - center)*scale;
        winYmin = appYmin;
        winYmax = appYmax;
    }
    else {
        scale = ((appXmax - appXmin) / w) / ((appYmax - appYmin) / h);
        center = (appYmax + appYmin) / 2;
        winYmin = center - (center - appYmin)*scale;
        winYmax = center + (appYmax - center)*scale;
        winXmin = appXmin;
        winXmax = appXmax;
    }
    
    // Now we use glOrtho to set up our viewing frustum
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(winXmin, winXmax, winYmin, winYmax, -1, 1);
}


//-------------------------------------------------------
// A function to handle mouse clicks
// Called every time the mouse button goes up or down
// Arguments:
//    b    - mouse button that was clicked, left or right
//    s      - state, either mouse-up or mouse-down
//    x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appMouseFunc(int b, int s, int x, int y) {
    // Convert from Window to Scene coordinates
    float mx = (float)x;
    float my = (float)y;
    windowToScene(mx, my);
  
    if (b==0){
        if(s==0){
     

            if (mode1==false&&mode2==true){
                for (int i = 0; i < grid.size(); i++) {
                    if (!gameOver){
                        if (grid[i].contains(mx, my)){
                            if (!grid[i].occupied){
                                if (player1){
                                    grid[i].shape = cross;
                                }
                                else{
                                    grid[i].shape = circle;
                                }
                                grid[i].occupied = true;
                                player1 = !player1;
                            }
                            GameState(grid);
                
                            break;
                        }
                    }
                }
            }

            if (mode1==true&&mode2==false){
                ai= true;
                player1 = true;
                for (int i = 0; i < grid.size(); i++) {

                    if (!gameOver){
                  

                        if (grid[i].contains(mx, my)){
                           
                            if (!grid[i].occupied){
                                if (player1){
                                    grid[i].shape = cross;
                                }
                                else{
                                    grid[i].shape = circle;
                                }
                                grid[i].occupied = true;
                                player1 = !player1;
                            }
                            
                            GameState(grid);
                            if (ai && !gameOver){
                                for (int i = 0; i < grid.size(); i++) {
                                    if (!grid[i].occupied){
                                        grid[i].shape = circle;
                                        grid[i].occupied = true;
                                        player1 = !player1;
                                        break;
                                    }
                                }
                                GameState(grid);
                            }
                            
                            break;
                        }
                    }
                }
            }
            if (mode1==false && mode2==false){
                if (mx>-0.3&&mx<0.3&& my>0.1&&my<0.6){
                    mode1=true;
                    
                    glutDisplayFunc(appDrawScene);
                    // cout<<mode1<<endl;
                }
                if(mx>-0.3&&mx<0.3&& my>-0.6&&my<-0.1){
                    mode2=true;
                    cout<<mode2<<endl;
                    glutDisplayFunc(appDrawScene);
                    
                }
            }
        }
    }
    
    
    
    
    
    
    // Redraw the scene by calling appDrawScene above
    // so that the point we added above will get painted
    glutPostRedisplay();
}
//-------------------------------------------------------
// A function to handle mouse dragging
// Called every time mouse moves while button held down
// Arguments:
//    x, y - current coordinates of the mouse
//-------------------------------------------------------
void appMotionFunc(int x, int y) {
    
    // Again, we redraw the scene
    glutPostRedisplay();
}

//-------------------------------------------------------
// A function to handle keyboard events
// Called every time a key is pressed on the keyboard
// Arguments:
//    key  - the key that was pressed
//    x, y - coordinates of the mouse when key is pressed
//-------------------------------------------------------
void appKeyboardFunc(unsigned char key, int x, int y) {
    
    switch (key) {
        case 27:
            exit(0);
            break;

        default:
            break;
    }
    
    // After all the state changes, redraw the scene
    glutPostRedisplay();
}


void idle() {
  //  if (mode1)glutDisplayFunc(appDrawScene);
   // if (mode2)glutDisplayFunc(appDrawScene);
}


int main(int argc, char** argv) {
    if (t==1){
        cout<<"player 1 will go first"<<endl;
    }
    else{
        cout<<"player 2 will go first"<<endl;
        

    }
 // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    
    // Setup window position, size, and title
    glutInitWindowPosition(20, 60);
    glutInitWindowSize(width, height);
    glutCreateWindow("Tic-Tac-Toe");
    
    // Setup some OpenGL options
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    
    grid.push_back(rectangle(-0.6, 0.6, 0.4, 0.4));
    grid.push_back(rectangle(-0.2, 0.6, 0.4, 0.4));
    grid.push_back(rectangle(0.2, 0.6, 0.4, 0.4));
    
    grid.push_back(rectangle(-0.6, 0.2, 0.4, 0.4));
    grid.push_back(rectangle(-0.2, 0.2, 0.4, 0.4));
    grid.push_back(rectangle(0.2, 0.2, 0.4, 0.4));
    
    grid.push_back(rectangle(-0.6, -0.2, 0.4, 0.4));
    grid.push_back(rectangle(-0.2, -0.2, 0.4, 0.4));
    grid.push_back(rectangle(0.2, -0.2, 0.4, 0.4));
   
    // Set callback for drawing the scene
    glutDisplayFunc(menu);
    
    // Set callback for resizing th window
    glutReshapeFunc(appReshapeFunc);
    
    // Set callback to handle mouse clicks
    glutMouseFunc(appMouseFunc);
    
    // Set callback to handle mouse dragging
    glutMotionFunc(appMotionFunc);
    
    // Set callback to handle keyboad events
    glutKeyboardFunc(appKeyboardFunc);
    
    glutIdleFunc(idle);
    
    // Start the main loop
    glutMainLoop();
}
