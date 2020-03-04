#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
   gluOrtho2D(-250,250,-250,250);
}


void draw_square(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        glVertex2f(x4,y4);
    glEnd();
    glFlush();
}

void draw_square_initial(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        glVertex2f(x4,y4);
    glEnd();
    glFlush();
}

void recurse_square(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,int recurse)
{

    if(recurse==0)
    {
        return;
    }

    recurse--;

    draw_square((3*x1+x2)/4,(y1+y4)/2,(x1+x2)/2,(y1+y4)/2,(x1+x2)/2,(3*y4+y1)/4,(3*x1+x2)/4,(3*y4+y1)/4);

    recurse_square(x1,(3*y4+y1)/4,(3*x1+x2)/4,(3*y4+y1)/4,(3*x1+x2)/4,y4,x4,y4,recurse);
    
    return;
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    printf("Enter length of the side initial Square:\n");
    int length;
    scanf("%d",&length);
    float x1,y1,x2,y2,x3,y3,x4,y4;
    
    x1=0;
    y1=0;
    x2=length;
    y2=0;
    x3=length;
    y3=length;
    x4=0;
    y4=length;

    draw_square_initial(x1,y1,x2,y2,x3,y3,x4,y4);

    printf("How many times do you want the recursion to go ahead:\n");
    int recurse;
    scanf("%d",&recurse);

    recurse_square(x1,y1,x2,y2,x3,y3,x4,y4,recurse);

    glColor3f( 0.0, 1.0, 0.0 );
    glRasterPos2f(0, 200);
    int len, i;
    char string[]="Sierpinski Square!";
    for (i = 0; i < 9; i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
    }

    glFlush();  // Render now
}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutInitWindowSize(500, 500);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("DDA algorithm"); // Create a window with the given title
   initGL();
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}