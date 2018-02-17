// Lab1.cpp 17/11/15
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include "Windows.h"
#include "Tchar.h"
#include <atlstr.h>  
#include <vector>

using namespace std;

//#include <GL/glut.h>
// If the system can't find file glut.h, this file should be
// copied into the directory where source files are put,
// and the previous #include line replaced by
#include "glut.h"

const double PI = 4.0*atan(1.0); //3.141592654;

struct coords {
	int x;
	int y;
};

vector<coords> coordsToDraw;

// Variables passed between the main program and the drawing function
// must be global, because the drawing function can't have parameters.
int noOfSides (5); // no. of sides of regular polygon to be drawn

int main(int argc, char* argv[])
{
	void callbackDisplay();
	void getNoOfSides();
	void mouse(int button, int state, int x, int y);
	void keyboard(unsigned char key, int x, int y);
	glutInit(&argc,argv); // initialise GLUT; the command line arguments can be ignored
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // must be called before glutCreateWindow
	glutInitWindowSize(600,400); // set width and height of graphics window
	glutInitWindowPosition(50,50); // initial position of graphics window on screen
	glutCreateWindow("A simple OpenGL program"); // create graphics window and name its heading
	glutDisplayFunc(callbackDisplay); // function to be called whenever graphics window is redrawn
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glShadeModel(GL_SMOOTH); // interpolate colours between vertices
	glClearColor(0,0,0,1); // background colour: black
	gluOrtho2D(0,599,0,399); 
//	getNoOfSides(); // for regular polygon
	glutMainLoop(); // begin event-processing loop
	return 0;
}

void callbackDisplay()
{
	void example();
	void seriesOfLines();
	void polygon();
	void cube();
	glClear(GL_COLOR_BUFFER_BIT); // Clear graphics window (to colour set by glClearColor)
	example();
	polygon();
	seriesOfLines();
	cube();
	glutSwapBuffers();
	OutputDebugString("test");
}

void example()
{
	//glColor3f(1,1,1); // set colour (white) for drawing commands (until next glColor3f call)
	//glBegin(GL_POINTS); // draw a single point
	//	glVertex2i(300, 200);
	//glEnd();
	//glColor3f(0,0,1); // blue
	//glBegin(GL_LINES); // draw a line
	//	glVertex2i(100,300);
	//	glVertex2i(150,100);
	//glEnd();
	//glColor3f(1,0,0); // red
	//glBegin(GL_LINE_LOOP); // draw the edges of a polygon
	//	glVertex2i(500,300);
	//	glVertex2i(550,300);
	//	glVertex2i(520,250);
	//glEnd();
	//glColor3f(1,1,0); // yellow
	//glBegin(GL_POLYGON); // draw a filled polygon
	//	glVertex2i(500,200);
	//	glVertex2i(550,200);
	//	glVertex2i(530,150);
	//glEnd();
}

void getNoOfSides()
{
	cout << "How many sides? ";
	cin >> noOfSides;
	while (noOfSides < 3)
	{
		cout << "Too few sides.\n";
		cout << "How many sides? ";
		cin >> noOfSides;
	}
}

void polygon()
{
}

void seriesOfLines()
{
	const int noOfVertices (12);
	float vertices[][noOfVertices] =
	{
		{152, 75, 74,135,152,135,321,371,247, 75,152,371}, // x coords
		{256,324,149, 29,256, 29, 80,268,323,324,256,268}  // y coords
	};
}

void cube()
{
	const int noOfVertices (8);
	const float perspVertices[4][noOfVertices] =  // homogeneous coordinates of vertices
	{
	  {-144.806, -54.133,-122.762, -32.089,  32.089, 122.762,  54.133, 144.806},
	  { -58.080,-142.871, 121.829,  37.038, -37.038,-121.829, 142.871,  58.080},
	  {   0    ,   0    ,   0    ,   0    ,   0    ,   0    ,   0    ,   0    },
	  {   1.150,   0.836,   0.981,   0.667,   1.332,   1.018,   1.163,   0.849}
	};
	const int verticesPerFace (4);
	const int faces[][verticesPerFace] = // vertex indices in visible faces
	{
	  {0, 1, 3, 2},
	  {7, 3, 1, 5},
	  {7, 6, 2, 3}
	};
	const int noOfFaces (sizeof(faces)/sizeof(faces[0])); // no. of rows in the matrix
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		glutSwapBuffers();
		glBegin(GL_POINTS); // draw a single point
			glVertex2i(x, 400 - y);
		glEnd();

		coords coordToAdd;
		coordToAdd.x = x;
		coordToAdd.y = 400 - y;
		coordsToDraw.push_back(coordToAdd);

		if (coordsToDraw.size() == 5) {
			glColor3f(1,1,0); // yellow
			glBegin(GL_POLYGON); // draw a filled polygon
			for(coords coord : coordsToDraw) {
				glVertex2i(coord.x, coord.y);
			}
			glEnd();
			coordsToDraw.clear();
		}


		//CString s;
		//s.Format(_T("integer: %d\n"), y);
		//OutputDebugString((LPCTSTR)s);

		glutSwapBuffers();


	}
}
void keyboard(unsigned char key, int x, int y)
{
	if (key == 'q') {
		glutSwapBuffers();
		glBegin(GL_POLYGON); // draw a filled polygon
			glVertex2i(500, 200);
			glVertex2i(550, 200);
			glVertex2i(530, 150);
		glEnd();
		glutSwapBuffers();
	}
}
