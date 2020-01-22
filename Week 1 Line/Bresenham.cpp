#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<stdio.h>
#include<stdlib.h>
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */

float abs(float a)
{
    if(a>0)
    {
        return a;
    }else
    {
        return a*(float)(-1);
    }
}

float compare(float a,float b)
{
    if(abs(a)>abs(b))
    {
        return abs(a);
    }else
    {
        return  abs(b);
    }

}

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
   gluOrtho2D(0,100,0,100);
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
   int x1,x2,y1,y2;
   printf("Enter First point\n");
   scanf("%d %d",&x1,&y1);
   printf("Enter Second point\n");
   scanf("%d %d",&x2,&y2);

   int m_new = 2 * (y2 - y1); 
   int slope_error_new = m_new - (x2 - x1);
   glPointSize(2.0f);
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 1.0);
    for (int x = x1, y = y1; x <= x2; x++) 
   { 
      glVertex2i(x, y);
  
      slope_error_new += m_new; 
  
      if (slope_error_new >= 0) 
      { 
         y++; 
         slope_error_new  -= 2 * (x2 - x1); 
      } 
   } 
    glEnd();   
   glFlush();  // Render now
}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutInitWindowSize(1300, 1300);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("DDA algorithm"); // Create a window with the given title
   initGL();
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}