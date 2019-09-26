// C code to implement basic 
// transformations in OPENGL 
#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include <GL/glut.h> 

// window size 
#define maxWD 640 
#define maxHT 480 

// rotation speed 
#define thetaSpeed 0.05 

// this creates delay between two actions 
void delay(unsigned int mseconds) 
{ 
	clock_t goal = mseconds + clock(); 
	while (goal > clock()) 
		; 
} 

// this is a basic init for the glut window 
void myInit(void) 
{ 
	glClearColor(1.0, 1.0, 1.0, 0.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluOrtho2D(0.0, maxWD, 0.0, maxHT); 
	glClear(GL_COLOR_BUFFER_BIT); 
	glFlush(); 
} 

// this function just draws a point 
void drawPoint(int x, int y) 
{ 
	glPointSize(7.0); 
	glColor3f(0.0f, 0.0f, 1.0f); 
	glBegin(GL_POINTS); 
	glVertex2i(x, y); 
	glEnd(); 
} 

void rotateAroundPt() 
{ 
	double x1=200,y1=200,x2=200,y2=300,x3=250,y3=200,cx=320,cy=240,sx=1.01,sy=1.01;
	double theta = 0.0; 
	glLineWidth(3);
    glPointSize(2);
	while (1) { 
		glClear(GL_COLOR_BUFFER_BIT); 
		double x1f, y1f,x2f,y2f,x3f,y3f; 

		// update theta anticlockwise rotation 
		theta = theta + thetaSpeed; 

		// check overflow 
		if (theta >= (2.0 * 3.14159)) 
			theta = theta - (2.0 * 3.14159); 

		// actual calculations.. 
		x1f = cx + ((x1 - cx) * cos(theta)) 
			- ((y1 - cy) * sin(theta)); 
		y1f = cy + ((x1 - cx) * sin(theta)) 
			+ ((y1 - cy) * cos(theta)); 
		x2f = cx + ((x2 - cx) * cos(theta)) 
			- ((y2 - cy) * sin(theta)); 
		y2f = cy + ((x2 - cx) * sin(theta)) 
			+ ((y2 - cy) * cos(theta));
		x3f = cx + ((x3 - cx) * cos(theta)) 
			- ((y3 - cy) * sin(theta)); 
		y3f = cy + ((x3 - cx) * sin(theta)) 
			+ ((y3 - cy) * cos(theta));	
		// drawing the centre point 
		drawPoint(cx, cy); 
		if(theta < 3.14159){
			x1*=sx;
			x2*=sx;
			x3*=sx;
			y1*=sy;
			y2*=sy;
			y3*=sy;
		}
		else{
			x1/=sx;
			x2/=sx;
			x3/=sx;
			y1/=sy;
			y2/=sy;
			y3/=sy;
		}
		// drawing the rotating point 
		/*drawPoint(x1f, y1f);
		drawPoint(x2f, y2f);
		drawPoint(x3f, y3f);*/
		glBegin(GL_LINE_LOOP);
        glVertex2i(x1f,y1f);
        glVertex2i(x2f,y2f);
        glVertex2i(x3f,y3f);
    	glEnd(); 
		glFlush(); 
		// creating a delay 
		// so that the point can be noticed 
		delay(100000); 
	} 
} 
int main(int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(maxWD, maxHT); 
	glutInitWindowPosition(100, 150); 
	glutCreateWindow("Transforming point"); 
	glutDisplayFunc(rotateAroundPt); 
	myInit(); 
	glutMainLoop(); 
} 

