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
    float x1=1.0f,y1=1.0f,z1=1.0f;
    float x2=1.0f,y2=1.0f,z2=3.0f;
    float x3=1.0f,y3=3.0f,z3=1.0f;
    float x4=1.0f,y4=3.0f,z4=3.0f;
    float x5=3.0f,y5=1.0f,z5=1.0f;
    float x6=3.0f,y6=1.0f,z6=3.0f;
    float x7=3.0f,y7=3.0f,z7=1.0f;
    float x8=3.0f,y8=3.0f,z8=3.0f;
    float sx = 0.01f,sy=0.01f,sz=0.01f;
    while(1){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
        glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
        
        x3+=sy*y3 + sz*z3;
        x4+=sy*y4 + sz*z4;
        x8+=sy*y8 + sz*z8;
        x7+=sy*y7 + sz*z7;
        // Render a color-cube consisting of 6 quads with different colors
        glLoadIdentity();                 // Reset the model-view matrix
        glTranslatef(-2.5f, -2.5f, -10.0f);  // Move right and into the screen
        glColor3f(1.0f, 0.0f, 0.0f);

		// actual calculations.. 
		
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
        
        delay(500000);
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