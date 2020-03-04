#include <GL/glut.h> 
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<iostream>
#include <math.h>

using namespace std; 

#define PI 3.14159265

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glOrtho(-200,200,-200,200,-10,10);
}

void draw_cube()
{
    vector <vector<vector<float>>> cube;
    for(int i=0;i<6;i++)
    {
        vector<vector<float>> face;
        for(int j=0;j<4;j++)
        {
            vector<float> point;
            float x,y,z;
            cin>>x>>y>>z;
            point.push_back(x);
            point.push_back(y);
            point.push_back(z);
            face.push_back(point);
        }
        cube.push_back(face);
   }


    glBegin(GL_QUADS);                
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      for(int i=0;i<4;i++)
      {
          glVertex3f( cube[0][i][0], cube[0][i][1],  cube[0][i][2]);
      }
      
      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
        for(int i=0;i<4;i++)
      {
          glVertex3f( cube[1][i][0], cube[1][i][1],  cube[1][i][2]);
      }
 
      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
     for(int i=0;i<4;i++)
      {
          glVertex3f( cube[2][i][0], cube[2][i][1],  cube[2][i][2]);
      }
 
      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
     for(int i=0;i<4;i++)
      {
          glVertex3f( cube[3][i][0], cube[3][i][1],  cube[3][i][2]);
      }
 
      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      for(int i=0;i<4;i++)
      {
          glVertex3f( cube[4][i][0], cube[4][i][1],  cube[4][i][2]);
      }
 
      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
     for(int i=0;i<4;i++)
      {
          glVertex3f( cube[5][i][0], cube[5][i][1],  cube[5][i][2]);
      }

    glEnd();  
    glFlush();  

    printf("1.Translation      2.Scaling       3.Rotation");
    int choice;
    cin>>choice;
    if(choice==1)
    {
        printf("1.X     2.Y     3.Z");
        int dir,f;
        cin>>dir;
        if(dir==1)
        {
               printf("Enter factor");
               cin>>f;
               for(int i=0;i<6;i++)
                {
       
                   for(int j=0;j<4;j++)
                    {
                        cube[i][j][0]+=f;
                    }
       
                }

        }else if(dir==2)
        {
               printf("Enter factor");
               cin>>f;
               for(int i=0;i<6;i++)
                {
       
                   for(int j=0;j<4;j++)
                    {
                        cube[i][j][1]+=f;
                    }
       
                }
        }else if(dir==3)
        {
               printf("Enter factor");
               cin>>f;
               for(int i=0;i<6;i++)
                {
       
                   for(int j=0;j<4;j++)
                    {
                        cube[i][j][2]+=f;
                    }
       
                }
        }
     
    
    }else if(choice==2)
    {
        printf("Enter the scaling factor:\n");
        int scaling_factor;
        cin>>scaling_factor;
        for(int i=0;i<6;i++)
                {
       
                   for(int j=0;j<4;j++)
                    {
                        cube[i][j][0]=cube[i][j][0]*scaling_factor;
                        cube[i][j][1]=cube[i][j][1]*scaling_factor;
                        cube[i][j][2]=cube[i][j][2]*scaling_factor;
                    }
       
                }
    }else if(choice==3)
    {

    }

    glBegin(GL_QUADS);                
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      for(int i=0;i<4;i++)
      {
          glVertex3f( cube[0][i][0], cube[0][i][1],  cube[0][i][2]);
      }
      
      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
        for(int i=0;i<4;i++)
      {
          glVertex3f( cube[1][i][0], cube[1][i][1],  cube[1][i][2]);
      }
 
      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
     for(int i=0;i<4;i++)
      {
          glVertex3f( cube[2][i][0], cube[2][i][1],  cube[2][i][2]);
      }
 
      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
     for(int i=0;i<4;i++)
      {
          glVertex3f( cube[3][i][0], cube[3][i][1],  cube[3][i][2]);
      }
 
      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      for(int i=0;i<4;i++)
      {
          glVertex3f( cube[4][i][0], cube[4][i][1],  cube[4][i][2]);
      }
 
      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
     for(int i=0;i<4;i++)
      {
          glVertex3f( cube[5][i][0], cube[5][i][1],  cube[5][i][2]);
      }

    glEnd();  
    glFlush();  
 
}

void draw_pyramid()
{
    vector<vector<vector<float>>> pyramid;

    for(int i=0;i<4;i++)
    {
        vector<vector<float>> face;
        for(int j=0;j<3;j++)
        {
            vector<float> point;
            float x,y,z;
            cin>>x>>y>>z;
            point.push_back(x);
            point.push_back(y);
            point.push_back(z);
            face.push_back(point);
        }
        pyramid.push_back(face);
    }
    vector<vector<float>> face;
    for(int i=0;i<4;i++)
    {
        vector<float> point;
            float x,y,z;
            cin>>x>>y>>z;
            point.push_back(x);
            point.push_back(y);
            point.push_back(z);
            face.push_back(point);
    }
    pyramid.push_back(face);
     glBegin(GL_TRIANGLES);                
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      for(int i=0;i<3;i++)
      {
          glVertex3f( pyramid[0][i][0],pyramid[0][i][1],pyramid[0][i][2]);
      }
      
      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      for(int i=0;i<3;i++)
      {
          glVertex3f( pyramid[1][i][0],pyramid[1][i][1],pyramid[1][i][2]);
      }
 
      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      for(int i=0;i<3;i++)
      {
          glVertex3f( pyramid[2][i][0],pyramid[2][i][1],pyramid[2][i][2]);
      }
 
      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
     for(int i=0;i<3;i++)
      {
          glVertex3f( pyramid[3][i][0],pyramid[3][i][1],pyramid[3][i][2]);
      }
    glEnd();

    glBegin(GL_QUADS);
       glColor3f(0.0f, 1.0f, 0.0f);     // Blue
     for(int i=0;i<4;i++)
      {
          glVertex3f( pyramid[4][i][0],pyramid[4][i][1],pyramid[4][i][2]);
      }
 
    glEnd();  
    glFlush(); 

    printf("1.Translation      2.Scaling       3.Rotation");
    int choice;
    cin>>choice;
    if(choice==1)
    {
        printf("1.X     2.Y     3.Z");
        int dir,f;
        cin>>dir;
        if(dir==1)
        {
               printf("Enter factor");
               cin>>f;
               for(int i=0;i<4;i++)
                {
       
                   for(int j=0;j<3;j++)
                    {
                        pyramid[i][j][0]+=f;
                    }
       
                }

                for(int i=0;i<4;i++)
                {
                    pyramid[4][i][0]+=f;
                }

        }else if(dir==2)
        {
               printf("Enter factor");
               cin>>f;
               for(int i=0;i<4;i++)
                {
       
                   for(int j=0;j<3;j++)
                    {
                        pyramid[i][j][1]+=f;
                    }
       
                }

                for(int i=0;i<4;i++)
                {
                    pyramid[4][i][1]+=f;
                }
        }else if(dir==3)
        {
               printf("Enter factor");
               cin>>f;
               for(int i=0;i<4;i++)
                {
       
                   for(int j=0;j<3;j++)
                    {
                        pyramid[i][j][2]+=f;
                    }
       
                }

                for(int i=0;i<4;i++)
                {
                    pyramid[4][i][2]+=f;
                }
        }
     
    
    }else if(choice==2)
    {
        printf("Enter the scaling factor:\n");
        int scaling_factor;
        cin>>scaling_factor;
        for(int i=0;i<4;i++)
                {
       
                   for(int j=0;j<3;j++)
                    {
                        pyramid[i][j][0]=pyramid[i][j][0]*scaling_factor;
                        pyramid[i][j][1]=pyramid[i][j][1]*scaling_factor;
                        pyramid[i][j][2]=pyramid[i][j][2]*scaling_factor;
                    }
       
                }

                for(int i=0;i<4;i++)
                {
                        pyramid[4][i][0]=pyramid[4][i][0]*scaling_factor;
                        pyramid[4][i][1]=pyramid[4][i][1]*scaling_factor;
                        pyramid[4][i][2]=pyramid[4][i][2]*scaling_factor; 
                }
    }else if(choice==3)
    {

    }

      glBegin(GL_TRIANGLES);                
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      for(int i=0;i<3;i++)
      {
          glVertex3f( pyramid[0][i][0],pyramid[0][i][1],pyramid[0][i][2]);
      }
      
      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      for(int i=0;i<3;i++)
      {
          glVertex3f( pyramid[1][i][0],pyramid[1][i][1],pyramid[1][i][2]);
      }
 
      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      for(int i=0;i<3;i++)
      {
          glVertex3f( pyramid[2][i][0],pyramid[2][i][1],pyramid[2][i][2]);
      }
 
      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
     for(int i=0;i<3;i++)
      {
          glVertex3f( pyramid[3][i][0],pyramid[3][i][1],pyramid[3][i][2]);
      }
    glEnd();

    glBegin(GL_QUADS);
       glColor3f(0.0f, 1.0f, 0.0f);     // Blue
     for(int i=0;i<4;i++)
      {
          glVertex3f( pyramid[4][i][0],pyramid[4][i][1],pyramid[4][i][2]);
      }
 
    glEnd();  
    glFlush(); 
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClear(GL_COLOR_BUFFER_BIT);
  
    printf("1.Cube      2.Pyramid");
    int figure;
    cin>>figure;
    if(figure==1)
    {
        draw_cube();
    }else if(figure==2)
    {
        draw_pyramid();
    }
   
   
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