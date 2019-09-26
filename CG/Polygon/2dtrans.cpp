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

void rotateAroundPt(int px, int py, int cx, int cy) 
{ 
	float theta = 0.0; 
	while (1) { 
		glClear(GL_COLOR_BUFFER_BIT); 
		int xf, yf; 

		// update theta anticlockwise rotation 
		theta = theta + thetaSpeed; 

		// check overflow 
		if (theta >= (2.0 * 3.14159)) 
			theta = theta - (2.0 * 3.14159); 

		// actual calculations.. 
		xf = cx + (int)((float)(px - cx) * cos(theta)) 
			- ((float)(py - cy) * sin(theta)); 
		yf = cy + (int)((float)(px - cx) * sin(theta)) 
			+ ((float)(py - cy) * cos(theta)); 

		// drawing the centre point 
		drawPoint(cx, cy); 

		// drawing the rotating point 
		drawPoint(xf, yf); 
		glFlush(); 
		// creating a delay 
		// so that the point can be noticed 
		delay(10000); 
	} 
} 

void reflect() 
{ 
	 double x=50,y=200,x1=100,y1=0,x2=600,y2=1000,a=50,b=150,ca=100,d=200;
	 double m=(y2-y1)/(x2-x1);
	 double c=y1-m*x1;
	 double xn=((1-m*m)*x+2*m*y-2*m*c)/(m*m+1);
     double yn=((m*m-1)*y+2*m*x+2*c)/(m*m+1);
     double an=((1-m*m)*a+2*m*b-2*m*c)/(m*m+1);
     double bn=((m*m-1)*b+2*m*a+2*c)/(m*m+1);
     double cn=((1-m*m)*ca+2*m*d-2*m*c)/(m*m+1);
     double dn=((m*m-1)*d+2*m*ca+2*c)/(m*m+1);
	 //int c=y1
	 glLineWidth(3);
     glPointSize(2);
	 glClear(GL_COLOR_BUFFER_BIT);
	 /*drawPoint(x, y);
	 drawPoint(a, b);
	 drawPoint(ca, d);
	 drawPoint(xn, yn);*/
	 glColor3f(0,0,0);
	 glBegin(GL_LINE_LOOP);
        glVertex2i(x,y);
        glVertex2i(a,b);
        glVertex2i(ca,d);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(xn,yn);
        glVertex2i(an,bn);
        glVertex2i(cn,dn);
    glEnd();
	 glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
    glEnd();
    glFlush(); 
} 
// this function will translate the point 
void translatePoint(int tx, int ty) 
{ 
	int x1=150, x2=300,y1=100,y2=300; 
	glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
        glVertex2i(x1,y1);
        glVertex2i(x2,y1);
        glVertex2i(x2,y2);
        glVertex2i(x1,y2);
    glEnd();
    glFlush();
	while (1) { 
		
		// update 
		glClear(GL_COLOR_BUFFER_BIT);
		x1 = x1 + tx; 
		y1 = y1 + ty;
		x2 = x2 + tx; 
		y2 = y2 + ty; 
		if (x2 > maxWD || x1 < 0 || y2 > maxHT || y1 < 0) { 
			x1=150, x2=300,y1=100,y2=300;
		} 
		delay(10000); 
		glBegin(GL_LINE_LOOP);
        glVertex2i(x1,y1);
        glVertex2i(x2,y1);
        glVertex2i(x2,y2);
        glVertex2i(x1,y2);
    	glEnd(); 
    	glFlush();
    } 
} 
void shear(double tx, double ty) 
{ 
	double x1=150, x2=300,y1=100,y2=300;
	double xn1=x1,xn2=x2; 
	glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
        glVertex2i(x1,y1);
        glVertex2i(x2,y1);
        glVertex2i(x2,y2);
        glVertex2i(x1,y2);
    glEnd();
    glFlush();
	while (1) { 
		
		// update 
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1,0,0);
		xn1 = xn1 + tx*y2; 
		xn2 = xn2 + tx*y2; 
		if (x2 > maxWD || x1 < 0 || y2 > maxHT || y1 < 0) { 
			x1=150, x2=300,y1=100,y2=300;
		} 
		delay(100000); 
		glBegin(GL_LINE_LOOP);
        glVertex2i(x1,y1);
        glVertex2i(x2,y1);
        glVertex2i(xn2,y2);
        glVertex2i(xn1,y2);
    	glEnd(); 
    	glFlush();
    } 
}
// this function draws 
void scalePoint(double sx, double sy) 
{ 
	double x1=50, x2=30,y1=10,y2=30; 
	glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
        glVertex2i(x1,y1);
        glVertex2i(x2,y1);
        glVertex2i(x2,y2);
        glVertex2i(x1,y2);
    glEnd();
    glFlush();
	while (1) { 
		
		// update 
		glClear(GL_COLOR_BUFFER_BIT);
		x1 = x1 * sx; 
		y1 = y1 * sy;
		x2 = x2 * sx; 
		y2 = y2 * sy; 

		delay(5000); 
		glBegin(GL_LINE_LOOP);
        glVertex2i(x1,y1);
        glVertex2i(x2,y1);
        glVertex2i(x2,y2);
        glVertex2i(x1,y2);
    	glEnd(); 
    	glFlush();
    }
	
} 

// Actual display function 
void myDisplay(void) 
{ 
	int opt; 
	printf("\nEnter\n\t<1> for translation"
		"\n\t<2> for rotation"
		"\n\t<3> for scaling\n\t<4> for reflection\n\t<5> for shearing\n:"); 
	scanf("%d", &opt); 
	printf("\nGo to the window..."); 
	switch (opt) { 
	case 1: 
		translatePoint(1, 1); 
		break; 
	case 2: 
		rotateAroundPt(200, 200, maxWD / 2, maxHT / 2); 
		// point will circle around 
		// the centre of the window 
		break; 
	case 3: 
		scalePoint(1.01, 1.01); 
		break;
	case 4:
		reflect();
		break; 
	case 5:
		shear(0.01,0.01);
		break;
	} 
} 

int main(int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(maxWD, maxHT); 
	glutInitWindowPosition(100, 150); 
	glutCreateWindow("Transforming point"); 
	glutDisplayFunc(myDisplay); 
	myInit(); 
	glutMainLoop(); 
} 

