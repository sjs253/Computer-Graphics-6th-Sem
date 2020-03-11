#include <GL/glut.h> 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <string> 
#include<vector>

int top=-1;
int n=6;
std::vector<int> queue;
int check =-1;

int front=0;
int rear=-1;

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   gluOrtho2D(0,400,400,0);
}

void draw_arrow_front()
{
    glColor3f(0.0,1.0,1.0);

    glBegin(GL_LINES);
        glVertex2f(50+front*35, 170);
        glVertex2f(50+front*35, 185);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(54+front*35,180);
        glVertex2f(50+front*35,185);
        glVertex2f(46+front*35,180);
    glEnd();

}

void draw_arrow_rear()
{
    glColor3f(1.0,.0,1.0);

    glBegin(GL_LINES);
        glVertex2f(50+rear*35, 170);
        glVertex2f(50+rear*35, 185);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(54+rear*35,180);
        glVertex2f(50+rear*35,185);
        glVertex2f(46+rear*35,180);
    glEnd();
}

void add_text(char string[])
{
    glColor3f( 1.0, 1.0, 0.0 );
    glRasterPos2f(150, 100);
    int len, i;
    for (i = 0; i < strlen(string); i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
    }
}

void draw_queue(int x,int y)
{
     glColor3f( 0.0, 1.0, 1.0 );
     glBegin(GL_QUADS);
        glVertex2f(x,y);
        glVertex2f(x+30,y);
        glVertex2f(x+30,y+60);
        glVertex2f(x,y+60);
    glEnd();
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClear(GL_COLOR_BUFFER_BIT);         
    char full_string[] = "Queue Full";
    char empty_string[] = "Queue Empty";
    char push_string[] = "Adding elements";
    char pop_string[] = "Removing elements";
    if(rear==-1)
    {
        add_text(empty_string);
    }else if(rear==n-1)
    {
        add_text(full_string);
    }else if(check==1)
    {
         add_text(push_string);
    }else if(check==0)
    {
        add_text(pop_string); 
    }

    draw_queue(50,190);
    draw_queue(85,190);
    draw_queue(120,190);
    draw_queue(155,190);
    draw_queue(190,190);
    draw_queue(225,190);

    draw_arrow_front();
    draw_arrow_rear();

   for(int j=0;j<queue.size();j++)
   {
        glColor3f( 0.0, 0.0, 0.0 );
        glRasterPos2f(60+front*35+j*35,220);
        std::string element = std::to_string(queue[j]);
        for (int i = 0; i < element.size(); i++) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13,element[i]);
        }
   }

   glFlush();  
}

void pop()
{
    queue.erase(queue.begin());
    front++;
    check=0;
    if(front==rear+1)
    {
        front=0;
        rear=-1;
    }
}

void push()
{
    rear++;
    int key=rand()%10;
    queue.push_back(key);
    check=1;
}


void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_F1:
        {
            push();
            break;
        }
            

        case GLUT_KEY_F2:
        {
            pop();
            break;
        }
            
   }

    glutPostRedisplay();  
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);                   // Initialize GLUT
   glutInitWindowSize(400, 400);          // Set the window's initial width & height
   glutInitWindowPosition(0, 200);          // Position the window's initial top-left corner
   glutCreateWindow("Queue");       // Create a window with the given title
   glutDisplayFunc(display);                // Register display callback handler for window re-paint
   glutSpecialFunc(specialKeys);
   initGL();                     // Our own OpenGL initialization
   glutMainLoop();               // Enter event-processing loop
   return 0;
}

// glTranslatef(0.2f, -0.3f, 0.0f);     
// glRotatef(180.0f, 0.0f, 0.0f, 1.0f); 