#include <GL/glut.h> 
#include<stdio.h>
#include<stdlib.h>

bool color=1;
float angle=0;
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   gluOrtho2D(0,100,0,100);
}

// void Timer(int value) {
//    glutPostRedisplay();      
//    glutTimerFunc(30, Timer, 0); 
// }

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClear(GL_COLOR_BUFFER_BIT);         
   
   glBegin(GL_QUADS);
        glVertex2i(20,20);
        glVertex2i(40,20);
        glVertex2i(40,40);
        glVertex2i(20,40);
   glEnd();

   glTranslatef(40,40,0);
   glRotatef(angle,0.0f,0.0f,1.0f);
   glBegin(GL_QUADS);
        glVertex2i(30,30);
        glVertex2i(50,30);
        glVertex2i(50,50);
        glVertex2i(30,50);
   glEnd();
   glRotatef(angle,0.0f,0.0f,1.0f);
   glTranslatef(-40,-40,0);
   glFlush();  // Render now
}
 
void specialKeys(int key, int x, int y) {
   switch (key) {
      case GLUT_KEY_F2:   
         color = !color;         
         if (color) {
            glColor3f(0.0, 0.0, 1.0);
            angle+=10;
            glutPostRedisplay();  
         } else {                                         
            glColor3f(1.0,0.0,0.0);
            angle+=10;
            glutPostRedisplay();  
         }
         break;
   }
}
  
int main(int argc, char** argv) {
   glutInit(&argc, argv);                   // Initialize GLUT
   glutInitWindowSize(100, 100);          // Set the window's initial width & height
   glutInitWindowPosition(0, 200);          // Position the window's initial top-left corner
   glutCreateWindow("Transformation");       // Create a window with the given title
   glutDisplayFunc(display);                // Register display callback handler for window re-paint
   glutSpecialFunc(specialKeys);
   initGL();                     // Our own OpenGL initialization
   glutMainLoop();               // Enter event-processing loop
   return 0;
}

// glTranslatef(0.2f, -0.3f, 0.0f);     
// glRotatef(180.0f, 0.0f, 0.0f, 1.0f); 