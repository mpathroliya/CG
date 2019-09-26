// C code to implement basic 
// transformations in OPENGL 
#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include <GL/glut.h> 

// window size 
char title[] = "3D Shapes";
 void delay(unsigned int mseconds) 
{ 
	clock_t goal = mseconds + clock(); 
	while (goal > clock()) 
		; 
} 
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}
 
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    float x1=-1.0f,y1=-1.0f,z1=-1.0f;
    float x2=-1.0f,y2=-1.0f,z2=1.0f;
    float x3=-1.0f,y3=1.0f,z3=-1.0f;
    float x4=-1.0f,y4=1.0f,z4=1.0f;
    float x5=1.0f,y5=-1.0f,z5=-1.0f;
    float x6=1.0f,y6=-1.0f,z6=1.0f;
    float x7=1.0f,y7=1.0f,z7=-1.0f;
    float x8=1.0f,y8=1.0f,z8=1.0f;
    float px1=1.0f,py1=1.0f,pz1=1.0f;
    float px2=1.0f,py2=1.0f,pz2=3.0f;
    float px3=1.0f,py3=3.0f,pz3=1.0f;
    float px4=1.0f,py4=3.0f,pz4=3.0f;
    float px5=3.0f,py5=1.0f,pz5=1.0f;
    float px6=3.0f,py6=1.0f,pz6=3.0f;
    float px7=3.0f,py7=3.0f,pz7=1.0f;
    float px8=3.0f,py8=3.0f,pz8=3.0f;
    float theta = 0.0f;
    while(1){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
        glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
        
        // Render a color-cube consisting of 6 quads with different colors
        glLoadIdentity();                 // Reset the model-view matrix
        glTranslatef(-0.0f, 0.0f, -10.0f);  // Move right and into the screen
        glColor3f(1.0f, 0.0f, 0.0f);
        theta+=0.05f;
        if (theta >= (2.0 * 3.14159)) 
			theta = theta - (2.0 * 3.14159); 

		// actual calculations.. 
		z1 = pz1 * cos(theta) - py1*sin(theta); 
		y1 = pz1 * sin(theta) + py1* cos(theta);
        z2 = pz2 * cos(theta) - py2*sin(theta); 
		y2 = pz2 * sin(theta) + py2* cos(theta);
        z3 = pz3 * cos(theta) - py3*sin(theta); 
		y3 = pz3 * sin(theta) + py3* cos(theta);
        z4 = pz4 * cos(theta) - py4*sin(theta); 
		y4 = pz4 * sin(theta) + py4* cos(theta);
        z5 = pz5 * cos(theta) - py5*sin(theta); 
		y5 = pz5 * sin(theta) + py5* cos(theta);
        z6 = pz6 * cos(theta) - py6*sin(theta); 
		y6 = pz6 * sin(theta) + py6* cos(theta);
        z7 = pz7 * cos(theta) - py7*sin(theta); 
		y7 = pz7 * sin(theta) + py7* cos(theta);
        z8 = pz8 * cos(theta) - py8*sin(theta); 
		y8 = pz8 * sin(theta) + py8* cos(theta);
        glBegin(GL_LINE_LOOP);
            glVertex3f(-10.0f,0,0);
            glVertex3f(10.0f,0,0);
        glEnd();
        glBegin(GL_LINE_LOOP);                // Begin drawing the color cube with 6 quads
            // Top face (y = 1.0f)
            // Define vertices in counter-clockwise (CCW) order with normal pointing out
            glVertex3f(x3, y3, z3);
            glVertex3f(x4, y4, z4);
            glVertex3f(x8, y8,  z8);
            glVertex3f(x7, y7,  z7);
        glEnd();
        glBegin(GL_LINE_LOOP);
            // Bottom face (y = -1.0f)
            glVertex3f(x1, y1,  z1);
            glVertex3f(x2, y2,  z2);
            glVertex3f(x6, y6, z6);
            glVertex3f(x5, y5, z5);
        glEnd();    
        glBegin(GL_LINE_LOOP);
            // Front face  (z = 1.0f)
            glVertex3f(x4, y4, z4);
            glVertex3f(x2, y2, z2);
            glVertex3f(x6, y6, z6);
            glVertex3f(x8, y8, z8);
        glEnd();
        glBegin(GL_LINE_LOOP);
            // Back face (z = -1.0f)
            glVertex3f(x3, y3, z3);
            glVertex3f(x1, y1, z1);
            glVertex3f(x5, y5, z5);
            glVertex3f(x7, y7, z7);
        glEnd();
        glBegin(GL_LINE_LOOP);
            // Left face (x = -1.0f)
            glVertex3f(x3, y3,  z3);
            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
            glVertex3f(x4, y4,  z4);
        glEnd();
        glBegin(GL_LINE_LOOP);
            // Right face (x = 1.0f)
            glVertex3f(x8, y8, z8);
            glVertex3f(x6, y6,  z6);
            glVertex3f(x5, y5,  z5);
            glVertex3f(x7, y7, z7);
        glEnd();  // End of drawing color-cube
        
        
        glFlush();
        glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
        
        delay(50000);
    }
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
