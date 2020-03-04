#include <GL/glut.h> 
#include<stdio.h>
#include<stdlib.h>

int side_length=10;

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   gluOrtho2D(0,400,400,0);
}

void draw(int xpos,int ypos)
{
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2i(xpos,ypos);
        glVertex2i(xpos+side_length,ypos);
        glVertex2i((xpos+side_length+xpos)/2,ypos+side_length);
   glEnd();
   
   glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2i(xpos,(ypos+ypos+side_length)/2);
        glVertex2i(xpos+side_length,(ypos+ypos+side_length)/2);
        glVertex2i((xpos+side_length+xpos)/2,(ypos+ypos+side_length)/2-side_length);
   glEnd();
   
   glFlush();  

}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClear(GL_COLOR_BUFFER_BIT);         
   
   
   glFlush();  
}
 
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_F1:   
            side_length+=2;
            break;

        case GLUT_KEY_F2:
            side_length-=2;
            break;  
   }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        
    }
   
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        printf("%d %d\n",x,y);
        draw(x,y);
    }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);                   // Initialize GLUT
   glutInitWindowSize(400, 400);          // Set the window's initial width & height
   glutInitWindowPosition(0, 200);          // Position the window's initial top-left corner
   glutCreateWindow("Transformation");       // Create a window with the given title
   glutDisplayFunc(display);                // Register display callback handler for window re-paint
   glutSpecialFunc(specialKeys);
   glutMouseFunc(mouse);
   initGL();                     // Our own OpenGL initialization
   glutMainLoop();               // Enter event-processing loop
   return 0;
}

// glTranslatef(0.2f, -0.3f, 0.0f);     
// glRotatef(180.0f, 0.0f, 0.0f, 1.0f); 