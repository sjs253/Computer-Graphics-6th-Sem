#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<stdio.h>
#include<stdlib.h>

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */

int INSIDE=0;
int LEFT=1;
int RIGHT=2;
int BOTTOM=4;
int TOP=8;
float x_min,x_max,y_max,y_min;

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

void draw_line(float x1,float y1,float x2,float y2,float color)
{
   
   glPointSize(2.0f);
    glBegin(GL_LINES);
    if(color==1)
    {
         glColor3f(1.0, 0.0, 0.0);
    }

    if(color==3)
    {
        glColor3f(0.0,0.0,1.0);
    }
 
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);

    glEnd();   
   glFlush();  // Render now
}

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
   gluOrtho2D(-250,250,-250,250);
}

int compute_code(float x,float y)
{
    int code = INSIDE;

    if(x<x_min)
    {
        code=code|LEFT;
    }

    if(x>x_max)
    {
        code|=RIGHT;
    }

    if(y<y_min)
    {
        code|=BOTTOM;
    }

    if(y>y_max)
    {
        code|=TOP;
    }

    return code;
} 

void cohen(float a1,float a2,float b1,float b2)
{
    int acode,bcode;
    acode = compute_code(a1,a2);
    bcode = compute_code(b1,b2);

    bool accept = false;
    
    while(true)
    {
       
        if(acode==0 && bcode==0)
        {
            accept=true;
            break;
        }else if(acode & bcode)
        {
            break;
        }else
        {
            float x,y;
            int code_out;
            if(acode!=0)
            {
                code_out=acode;
            }else
            {
                code_out=bcode;
            }

            if(code_out & LEFT)
            {
                x=x_min;
                y=((b2-a2)/(b1-a1))*(x_min-b1) + b2;
            }

            if(code_out & RIGHT)
            {
                x=x_max;
                y=((b2-a2)/(b1-a1))*(x_max-b1) + b2;
            }

            if(code_out & TOP)
            {
                y=y_max;
                x=((b1-a1)/(b2-a2))*(y_max-b2) + b1;
            }

            if(code_out & BOTTOM)
            {
                y=y_min;
                x=((b1-a1)/(b2-a2))*(y_min-b2) + b1;
            }

            
            if(code_out==acode)
            {
                a1=x;
                a2=y;
                acode=compute_code(a1,a2);
            }else if(code_out==bcode)
            {
                b1=x;
                b2=y;
                bcode=compute_code(b1,b2);
            }
        }
    }
   
   if(accept)
   {
       draw_line(a1,a2,b1,b2,3);
   }  
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    printf("Enter x_min and x_max of the clipping window:\n");
   scanf("%f %f",&x_min,&x_max);
   printf("Enter y_min and y_max of the clipping window:\n");
   scanf("%f %f",&y_min,&y_max);

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2i(x_min,y_min);
        glVertex2i(x_max,y_min);
        glVertex2i(x_max,y_max);
        glVertex2i(x_min,y_max);
    glEnd();
    glFlush();

   printf("Enter the vertices of the triangle:\n");
   float a1,a2,b1,b2,c1,c2;
   scanf("%f %f",&a1,&a2);
   scanf("%f %f",&b1,&b2);
   scanf("%f %f",&c1,&c2);

    draw_line(a1,a2,b1,b2,1);
    draw_line(b1,b2,c1,c2,1);
    draw_line(a1,a2,c1,c2,1);

    glFlush();

    cohen(a1,a2,b1,b2); 
    cohen(a1,a2,c1,c2);
    cohen(b1,b2,c1,c2);

    // char string[] = "Cohen line clipping algorithm!";
    // int w;
    // // w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);
    // float x = .5; /* Centre in the middle of the window */
    // glRasterPos2f(x - (float) 500 / 2, 0.);
    // glColor3f(0., 1., 0.);
    // for (int i = 0; i < w; i++)
    // {
    //     glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
    // }

    glColor3f( 0.0, 1.0, 0.0 );
    glRasterPos2f(0, 200);
    int len, i;
    char string[]="Shreyansh";
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