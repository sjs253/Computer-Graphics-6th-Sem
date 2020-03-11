#include <GL/glut.h> 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <string> 
#include<vector>

int top=-1;
int n=6;
std::vector<int> stack;
int check =-1;

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   gluOrtho2D(0,400,400,0);
}

void draw_arrow()
{
    glColor3f(0.0,1.0,1.0);

    glBegin(GL_LINES);
        glVertex2f(110, 210-top*35);
        glVertex2f(120, 210-top*35);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(120,214-top*35);
        glVertex2f(120,206-top*35);
        glVertex2f(125,210-top*35);
    glEnd();

}
void add_text(char string[])
{
    glColor3f( 1.0, 1.0, 0.0 );
    glRasterPos2f(250, 100);
    int len, i;
    for (i = 0; i < strlen(string); i++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
    }
}

void draw_stack(int x,int y)
{
     glColor3f( 0.0, 1.0, 1.0 );
     glBegin(GL_QUADS);
        glVertex2f(x,y);
        glVertex2f(x+60,y);
        glVertex2f(x+60,y+30);
        glVertex2f(x,y+30);
    glEnd();
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClear(GL_COLOR_BUFFER_BIT);         
    char full_string[] = "Stack Full";
    char empty_string[] = "Stack Empty";
    char push_string[] = "Adding elements";
    char pop_string[] = "Removing elements";
    if(top==-1)
    {
        add_text(empty_string);
    }else if(top==n-1)
    {
        add_text(full_string);
    }else if(check==1)
    {
         add_text(push_string);
    }else if(check==0)
    {
        add_text(pop_string); 
    }

    draw_stack(125,190);
    draw_stack(125,155);
    draw_stack(125,120);
    draw_stack(125,85);
    draw_stack(125,50);
    draw_stack(125,15);

    draw_arrow();

   for(int j=0;j<stack.size();j++)
   {
        glColor3f( 0.0, 0.0, 0.0 );
        glRasterPos2f(150, 210-j*35);
        std::string element = std::to_string(stack[j]);
        for (int i = 0; i < element.size(); i++) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13,element[i]);
        }
   }

   glFlush();  
}

void pop()
{
    stack.erase(stack.end()-1);
    top--;
    check=0;
}

void push()
{
    top++;
    int key=rand()%10;
    stack.push_back(key);
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
   glutCreateWindow("Stack");       // Create a window with the given title
   glutDisplayFunc(display);                // Register display callback handler for window re-paint
   glutSpecialFunc(specialKeys);
   initGL();                     // Our own OpenGL initialization
   glutMainLoop();               // Enter event-processing loop
   return 0;
}

// glTranslatef(0.2f, -0.3f, 0.0f);     
// glRotatef(180.0f, 0.0f, 0.0f, 1.0f); 