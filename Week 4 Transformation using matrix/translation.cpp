#include <GL/glut.h> 
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<iostream>
#include <math.h> 

using namespace std; 

#define PI 3.14159265
vector<vector<pair<int,int>>> objectmatrix;

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   gluOrtho2D(-200,200,200,-200);
}

void Timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(30, Timer, 0); // next Timer call milliseconds later
}

void draw_line()
{
    vector<pair<int,int>> v;

    int x1,y1,x2,y2;
    printf("Please enter the co ordinates of the first point:\n");
    scanf("%d %d",&x1,&y1);
    v.push_back(make_pair(x1,y1));
    printf("Please enter the co ordinates of the second point:\n");
    scanf("%d %d",&x2,&y2);
    v.push_back(make_pair(x2,y2));

    glBegin(GL_LINES);
        glVertex2i(v[0].first, v[0].second);
        glVertex2i(v[1].first, v[1].second);
    glEnd();
    glFlush();
    printf("Please take one of the following choices:\n1. Translation\n2. Rotation\n3. Scaling\n");
    int choice;
    scanf("%d",&choice);
    
    if(choice==1)
    {
                int direction,fx,fy;
                pair<int,int> translate;
                printf("Enter the translation factor in x and y direction\n");
                scanf("%d %d",&fx,&fy);
                translate = (make_pair(fx,fy));

                for(int size=0;size<v.size();size++)
	            {
                   v[size].first=v[size].first + translate.first;
                   v[size].second=v[size].second + translate.second;
                }

                glBegin(GL_LINES);
                    glVertex2i(v[0].first, v[0].second);
                    glVertex2i(v[1].first, v[1].second);
                glEnd();

    }else if(choice==2)
    {
        //Rotation
        printf("How many degrees do you want to rotate:\n");
                    int degree;
                    vector<pair<double,double>> rotationmatrix;
                    scanf("%d",&degree);
                    rotationmatrix.push_back(make_pair(cos(degree/PI),-sin(degree/PI)));
                    rotationmatrix.push_back(make_pair(sin(degree/PI),cos(degree/PI)));
                    
                    for(int size=0;size<v.size();size++)
	                {
                        v[size].first = v[size].first*rotationmatrix[0].first + v[size].second*rotationmatrix[0].second;
                        v[size].second = v[size].first*rotationmatrix[1].first + v[size].second*rotationmatrix[1].second;
                    }

                     glBegin(GL_LINES);
                    glVertex2i(v[0].first, v[0].second);
                    glVertex2i(v[1].first, v[1].second);
        glEnd();
        
    }else if(choice==3)
    {
        //Scaling
        printf("Enter the scaling factor:\n");
        int s;
        scanf("%d",&s);
        for(int size=0;size<v.size();size++)
	            {
                   v[size].first=v[size].first*s;
                   v[size].second=v[size].second*s;
                }
         glBegin(GL_LINES);
                    glVertex2i(v[0].first, v[0].second);
                    glVertex2i(v[1].first, v[1].second);
        glEnd();
    }
}

void draw_circle_sub(int xc,int yc,int r)
{
     int x,y,d;
   x=0;
   y=r;
   d = 3-2*r;
   
   glBegin(GL_POINTS);
   glColor3f(1.0, 0.0, 0.0);

   while(y >= x)
    {
        if(d<=0)
        {
            x = x+1;
            d = d + 4*x + 6;
        }else if(d>0)
        {
            x = x+1;
            y = y-1;
            d = d + 4*(x-y) +10;
        }
       
        glVertex2i(xc+x, yc+y); 
        glVertex2i(xc-x, yc+y); 
        glVertex2i(xc+x, yc-y); 
        glVertex2i(xc-x, yc-y); 
        glVertex2i(xc+y, yc+x); 
        glVertex2i(xc-y, yc+x); 
        glVertex2i(xc+y, yc-x); 
        glVertex2i(xc-y, yc-x);

    }
   
   glEnd();
   glFlush();
   return;
}

void draw_circle()
{
    int xc,yc,r;
    printf("Please enter the co ordinates of the center:\n");
    scanf("%d %d",&xc,&yc);
    printf("Please enter the radius:\n");
    scanf("%d",&r);
    draw_circle_sub(xc,yc,r);

    printf("Pick one of the following options:\n1. Translation\n2. Scaling\n");
    int choice;
    scanf("%d",&choice);
    
    if(choice==1)
    {
                int fx,fy;
                pair<int,int> translate;
                printf("Enter the translation factor in x and y direction\n");
                scanf("%d %d",&fx,&fy);
                translate = (make_pair(fx,fy));
                xc = xc+translate.first;
                yc = yc + translate.second;

                draw_circle_sub(xc,yc,r);
    }else if(choice ==2)
    {
                int sr;
                printf("Enter the scaling factor of the radius:\n");
                scanf("%d",&sr);
                r = r*sr;
                draw_circle_sub(xc,yc,r);
    }

    return ;
}


void draw_polygon()
{
    vector<pair<int,int>> v;
    printf("Enter the number of vertices:\n");
    int vertices;
    scanf("%d",&vertices);

    printf("Please enter the vertices sequentially:\n");
    for(int i=0;i<vertices;i++)
    {
        int a,b;
        pair<int,int> p;
        scanf("%d %d",&a,&b);
        p = make_pair(a,b);
        v.push_back(p);
    }

    glBegin(GL_POLYGON);
        for(int i=0;i<vertices;i++)
        {
            glVertex2i(v[i].first,v[i].second);
        }
    glEnd();
    glFlush();
    printf("Please take one of the following choices:\n1. Translation\n2. Rotation\n3. Scaling\n4.Reflection about x and y axis\n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: {
            int fx,fy;
                pair<int,int> translate;
                printf("Enter the translation factor in x and y direction\n");
                scanf("%d %d",&fx,&fy);
                translate = (make_pair(fx,fy));

                for(int size=0;size<v.size();size++)
	            {
                   v[size].first=v[size].first + translate.first;
                   v[size].second=v[size].second + translate.second;
                }

                glBegin(GL_POLYGON);
                for(int i=0;i<vertices;i++)
                {
                       glVertex2i(v[i].first,v[i].second);
                }
                glEnd();
                glFlush();
                
                break;
        }
        case 2: {
                    printf("How many degrees do you want to rotate:\n");
                    int degree;
                    vector<pair<double,double>> rotationmatrix;
                    scanf("%d",&degree);
                    rotationmatrix.push_back(make_pair(cos(degree/PI),-sin(degree/PI)));
                    rotationmatrix.push_back(make_pair(sin(degree/PI),cos(degree/PI)));
                    
                    for(int size=0;size<v.size();size++)
	                {
                        v[size].first = v[size].first*rotationmatrix[0].first + v[size].second*rotationmatrix[0].second;
                        v[size].second = v[size].first*rotationmatrix[1].first + v[size].second*rotationmatrix[1].second;
                    }

                    glBegin(GL_POLYGON);
                    for(int i=0;i<vertices;i++)
                    {
                       glVertex2i(v[i].first,v[i].second);
                    }
                    glEnd();
                    glFlush();
                    break;
                }
        case 3: {
                printf("Enter the scaling factor in x and y:\n");
                int sx,sy;
                scanf("%d %d",&sx,&sy);

                for(int size=0;size<v.size();size++)
	            {
                   v[size].first=v[size].first*sx;
                   v[size].second=v[size].second*sy;
                }

                glBegin(GL_POLYGON);
                for(int i=0;i<vertices;i++)
                {
                       glVertex2i(v[i].first,v[i].second);
                }
                glEnd();
                glFlush();
                break;        
                }
        case 4:
        {
            vector <pair<int,int>> xreflection,yreflection;

            xreflection.push_back(make_pair(1,0));
            xreflection.push_back(make_pair(0,-1));

            yreflection.push_back(make_pair(-1,0));
            yreflection.push_back(make_pair(0,1));
                    glBegin(GL_POLYGON);
                    for(int i=0;i<vertices;i++)
                    {
                       glVertex2i(v[i].first*xreflection[0].first + v[i].second*xreflection[0].second,
                       v[i].first*xreflection[1].first + v[i].second*xreflection[1].second);
                    }
                    glEnd();
                    glFlush();

                    glBegin(GL_POLYGON);
                    for(int i=0;i<vertices;i++)
                    {
                       glVertex2i(v[i].first*yreflection[0].first + v[i].second*yreflection[0].second,
                       v[i].first*yreflection[1].first + v[i].second*yreflection[1].second);
                    }
                    glEnd();
                    glFlush();
            break;
        }
                
        
    }

    return;
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClear(GL_COLOR_BUFFER_BIT);

   int choice;
   printf("What do you want to draw ?\n1.Line\n2.Ploygon\n3.Circle\n");
   scanf("%d",&choice);

   switch(choice)
   {
        case 1: draw_line();
                break;
        case 2: draw_polygon();
                break;
        case 3: draw_circle();
                break;
   }


   glFlush();  
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);                   // Initialize GLUT
   glutInitWindowSize(400, 400);          // Set the window's initial width & height
   glutInitWindowPosition(0, 200);          // Position the window's initial top-left corner
   glutCreateWindow("Face");       // Create a window with the given title
   glutDisplayFunc(display);                // Register display callback handler for window re-paint
   initGL();                     // Our own OpenGL initialization
   glutMainLoop();               // Enter event-processing loop
   return 0;
}

// glTranslatef(0.2f, -0.3f, 0.0f);     
// glRotatef(180.0f, 0.0f, 0.0f, 1.0f); 