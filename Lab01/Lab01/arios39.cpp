#include <iostream>
#include <cmath>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


using namespace std;

// Store the width and height of the window
int width = 640, height = 640;


//-------------------------------------------------------
// A function to draw the scene
//-------------------------------------------------------
void appDrawScene() {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to black
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    

    // Draw stuff here
    
    
    
 //--------------------------------------------A
    
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-1, 0.0);
    glVertex2f(-0.85,0.7);
    glVertex2f(-0.82,0.7);
    glVertex2f(-0.97, 0.0);
    glEnd();
    
  glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85, 0.7);
    glVertex2f(-0.82,0.7);
    glVertex2f(-0.65, 0.0);
    glVertex2f(-0.68, 0.0);
    glEnd();
    
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.93, 0.3);
    glVertex2f(-0.93,0.33);
    glVertex2f(-0.73, 0.33);
    glVertex2f(-0.73, 0.3);
  glEnd();
   
//---------------------------------------------N
    
    
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.60, 0.0);
    glVertex2f(-0.60,0.7);
    glVertex2f(-0.57,0.7);
    glVertex2f(-0.57, 0.0);
    glEnd();
    
   glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.60, 0.7);
    glVertex2f(-0.57,0.7);
    glVertex2f(-0.36, 0.0);
    glVertex2f(-0.39, 0.0);
    glEnd();
    
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.39, 0.7);
    glVertex2f(-0.36,0.7);
    glVertex2f(-0.36, 0.0);
    glVertex2f(-0.39, 0.0);
    glEnd();
 
//---------------------------------------------d

    
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.31, 0.0);
    glVertex2f(-0.31,0.7);
    glVertex2f(-0.28,0.7);
    glVertex2f(-0.28, 0.0);
    glEnd();
    
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.31, 0.0);
    glVertex2f(-0.31,0.03);
    glVertex2f(-0.10, 0.03);
    glVertex2f(-0.10, 0.0);
    glEnd();
    
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.31, 0.7);
    glVertex2f(-0.31,0.67);
    glVertex2f(-0.10, 0.67);
    glVertex2f(-0.10, 0.7);
    glEnd();
    
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    
    glVertex2f(-0.1, 0.0);
    glVertex2f(-0.13,0.03);
    glVertex2f(-0.05, 0.35);
    glVertex2f(-0.02, 0.35);
    glEnd();
  
    glColor3f(1.0, 1.0, 0.0);
  
    glBegin(GL_POLYGON);
    
    glVertex2f(-0.1, 0.7);
    glVertex2f(-0.13,0.67);
    glVertex2f(-0.05, 0.35);
    glVertex2f(-0.02, 0.35);
    glEnd();
   

    
//----------------------------------------------------R
    
    glColor3f(0.0, 1.0, 1.0);
    
    glBegin(GL_POLYGON);
    
    glVertex2f(0.07, 0.0);
    glVertex2f(0.07,0.7);
    glVertex2f(0.04, 0.7);
    glVertex2f(0.04, 0.0);
    glEnd();
    
    glColor3f(0.0, 1.0, 1.0);
    
    glBegin(GL_POLYGON);
    
    glVertex2f(0.04, 0.7);
    glVertex2f(0.07,0.67);
    glVertex2f(0.26, 0.67);
    glVertex2f(0.26, 0.7);
    glEnd();
    
    glColor3f(0.0, 1.0, 1.0);
    
    glBegin(GL_POLYGON);
    
    glVertex2f(0.26, 0.67);
    glVertex2f(0.23,0.67);
    glVertex2f(0.23, 0.45);
    glVertex2f(0.26, 0.45);
    glEnd();
    
    glBegin(GL_POLYGON);
    
    glVertex2f(0.04, 0.45);
    glVertex2f(0.07,0.48);
    glVertex2f(0.26, 0.48);
    glVertex2f(0.26, 0.45);
    glEnd();
    
    glBegin(GL_POLYGON);
    
    glVertex2f(0.04, 0.45);
    glVertex2f(0.07,0.45);
    glVertex2f(0.23, 0.0);
    glVertex2f(0.26, 0.0);
    glEnd();
    
    
    //---------------------------------\\E
    glColor3f(1.0, 0.0, 0.0);
  
    glBegin(GL_POLYGON);
    
    glVertex2f(0.31, 0.0);
    glVertex2f(0.34,0.0);
    glVertex2f(0.34, 0.7);
    glVertex2f(0.31, 0.7);
    
    glEnd();
    
    glBegin(GL_POLYGON);
    
    glVertex2f(0.31, 0.7);
    glVertex2f(0.31,0.67);
    glVertex2f(0.61, 0.67);
    glVertex2f(0.61, 0.7);
    
    glEnd();
    glBegin(GL_POLYGON);
    
    glVertex2f(0.31, 0.0);
    glVertex2f(0.31,0.03);
    glVertex2f(0.61, 0.03);
    glVertex2f(0.61, 0.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    
    glVertex2f(0.31, 0.40);
    glVertex2f(0.31,0.37);
    glVertex2f(0.61, 0.37);
    glVertex2f(0.61, 0.40);
    glEnd();
    
   //---------------------------------S
    glColor3f(1.0, 0.0, 1.0);
  
    glBegin(GL_POLYGON);
    
    glVertex2f(0.66, 0.0);
    glVertex2f(0.66,0.03);
    glVertex2f(0.96, 0.03);
    glVertex2f(0.96, 0.0);
    
    glEnd();
    
    glBegin(GL_POLYGON);
    
    glVertex2f(0.66, 0.7);
    glVertex2f(0.66,0.67);
    glVertex2f(0.96, 0.67);
    glVertex2f(0.96, 0.7);
    
    glEnd();
    
    glBegin(GL_POLYGON);
    
    glVertex2f(0.66, 0.40);
    glVertex2f(0.66,0.37);
    glVertex2f(0.96, 0.37);
    glVertex2f(0.96, 0.40);
    glEnd();
    
    glBegin(GL_POLYGON);
    
    glVertex2f(0.66, 0.7);
    glVertex2f(0.69,0.67);
    glVertex2f(0.69, 0.37);
    glVertex2f(0.66, 0.40);
    glEnd();
    
    glBegin(GL_POLYGON);
    
    glVertex2f(0.96, 0.37);
    glVertex2f(0.93,0.4);
    glVertex2f(0.93, 0.0);
    glVertex2f(0.96, 0.0);
    glEnd();
    //--------------------------------
    
    /*glColor3f(1.0, 0.0, 0.0);
    
    glLineWidth(5);
    
    glBegin(GL_LINES);
    
    glVertex3f(-1.0, 0.0, 0.5);
    glVertex3f(1.0, 0.0, 0.5);
    
    glVertex3f(0.0, 1.0, 0.5);
    glVertex3f(0.0, -1.0, 0.5);
    
    glEnd();
*/
	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();
}

//-------------------------------------------------------
// A function to convert window coordinates to scene
// We use it when a mouse event is handled
// Arguments: 	
//	x, y - the coordinates to be updated
//-------------------------------------------------------
void windowToScene(float& x, float& y) {
	x = (2.0f*(x / float(width))) - 1.0f;
	y = 1.0f - (2.0f*(y / float(height)));
}

//-------------------------------------------------------
// A function to handle window resizing
// Called every time the window is resized
// Arguments: 	
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
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
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appMouseFunc(int b, int s, int x, int y) {
	// Convert from Window to Scene coordinates
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);

	// Redraw the scene by calling appDrawScene above
	// so that the point we added above will get painted
	glutPostRedisplay();
}

//-------------------------------------------------------
// A function to handle mouse dragging
// Called every time mouse moves while button held down
// Arguments: 	
//	x, y - current coordinates of the mouse
//-------------------------------------------------------
void appMotionFunc(int x, int y) {

	// Again, we redraw the scene
	glutPostRedisplay();
}

//-------------------------------------------------------
// A function to handle keyboard events
// Called every time a key is pressed on the keyboard
// Arguments: 	
//	key  - the key that was pressed
//	x, y - coordinates of the mouse when key is pressed
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

}


int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

	// Setup window position, size, and title
	glutInitWindowPosition(20, 60);
	glutInitWindowSize(width, height);
	glutCreateWindow("CSE165 OpenGL Demo");

	// Setup some OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);


	// Set callback for drawing the scene
	glutDisplayFunc(appDrawScene);

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
