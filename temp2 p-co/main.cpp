//
//  main.cpp
//  Para_Coord
//
//  Created by Jinsong Wang on 4/9/14.
//  Copyright (c) 2014 jwang. All rights reserved.
//




#include <iostream>
#include <string.h>
#include <opengl/gl.h>
#include <GLUT/glut.h>



// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y=0;
double rotate_x=0;
int    SIZE=77;

// ----------------------------------------------------------
// Sample Data
// ----------------------------------------------------------

float ver[77][6] =
{
    {110,2,2,180,1.5,0.75},
    {130,3,2,210,2,0.75},
    {110,6,2,290,2,1.25},
    {120,1,3,210,0,0.75},
    {110,3,2,140,2,0.5},
    {110,1,1,180,0,1},
    {110,1,1,180,0,1},
    {100,2,1,140,2,0.75},
    {110,1,1,280,0,0.75},
    {110,3,1,250,1.5,0.75},
    {110,2,1,260,0,1.5},
    {110,2,1,180,0,1},
    {100,2,1,220,2,1},
    {130,3,2,170,1.5,0.5},
    {100,3,2,140,2.5,0.5},
    {110,2,1,200,0,1},
    {140,3,1,190,4,1},
    {100,3,1,200,3,1},
    {110,2,1,250,0,0.75},
    {110,1,1,140,0,1},
    {100,3,1,200,3,1},
    {110,2,1,200,1,0.75},
    {70,4,1,260,9,0.33},
    {50,4,0,140,14,0.5},
    {110,2,0,125,1,1},
    {100,2,0,290,1,1},
    {110,1,0,90,1,1},
    {110,3,3,140,4,0.5},
    {110,2,0,220,1,1},
    {110,2,1,125,1,1},
    {110,1,0,200,1,0.75},
    {100,3,0,0,3,0.8},
    {120,3,0,240,5,0.67},
    {110,2,1,170,1,-1},
    {140,3,1,170,2,0.75},
    {160,3,2,150,3,0.67},
    {120,2,1,190,0,0.67},
    {140,3,2,220,3,0.67},
    {90,3,0,170,3,-1},
    {100,3,0,320,1,1},
    {120,3,1,210,5,0.75},
    {90,2,0,0,2,0.5},
    {110,2,0,290,0,1},
    {110,2,1,70,1,0.75},
    {110,6,0,230,1,1},
    {70,4,1,130,10,0.33},
    {80,2,0,0,3,-1},
    {90,3,0,0,4,0.67},
    {90,3,0,0,3,0.67},
    {90,2,0,15,3,-1},
    {90,3,0,210,5,0.67},
    {120,3,2,160,5,0.67},
    {110,1,1,135,0,0.75},
    {100,2,0,45,0,0.88},
    {100,3,1,140,3,0.88},
    {110,3,0,170,3,0.25},
    {120,3,3,75,3,0.33},
    {110,1,0,180,0,1.33},
    {120,3,1,200,6,0.67},
    {120,3,5,15,2,-1},
    {120,1,2,220,0,0.75},
    {120,1,2,220,1,1},
    {100,4,2,150,2,0.67},
    {50,1,0,0,0,1},
    {50,2,0,0,1,-1},
    {100,4,1,135,2,0.5},
    {110,2,2,200,1,0.75},
    {90,2,1,200,4,0.67},
    {110,2,0,280,0,1},
    {100,2,0,190,1,0.75},
    {150,4,3,95,3,-1},
    {150,4,3,150,3,-1},
    {110,1,0,240,0,1.13},
    {100,3,1,230,3,0.67},
    {100,4,1,0,0,-1},
    {100,3,0,80,1,1},
    {100,5,2,0,2.7,0.67},
    
    
};






// ----------------------------------------------------------
// Text and values print
// ----------------------------------------------------------
void dis_values(int x, int y, int z, char string, void *font)
{
  
    glColor4f (1.0, 0.0, 1.0, 0.75);
    glRasterPos3f(x, y, z);
        glutBitmapCharacter(font, string);
    
}

void bitmap_output(int x, int y, int z, char *string, void *font)
{  int len, i;
    glRasterPos3f(x, y, 0);            // Locate Raster Position in 3-space
    len = (int) strlen(string);        // Find length of string
    for (i = 0; i < len; i++) {        // Loop through plotting all characters in font style
        glutBitmapCharacter(font, string[i]);
    }
}

// ----------------------------------------------------------
// Lable value and text in the coordinate
// ----------------------------------------------------------
void lables_slot() {
    
    for (GLfloat i = 0; i >=0&&i<=4; i++) {
        

        char a[] = "abcde";
        
        char A = a[(int)i];
        
        //char *A = &a[1];
        
        glPushMatrix();
        glTranslatef(-0.5+i*0.25, 0.5, 0.5);
        dis_values(0, 0, 0, A , GLUT_BITMAP_TIMES_ROMAN_24);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(-0.5+i*0.25, 0.5,-0.5);
        dis_values(0,0,0,  A , GLUT_BITMAP_TIMES_ROMAN_24);
        glPopMatrix();
        
        
    }

    
    
}

// ----------------------------------------------------------
// Draw Sample Curevs in the coordinates
// ----------------------------------------------------------




void SampleCurves() {
    

    
    for (int n=0; n>=0&&n<=77; n++) {
        
        glBegin(GL_LINE_STRIP);
        glColor4f (1.0, 0.0, 0.0, 0.75);
        glVertex3f(  -0.5,   ver[n][0] /1000, ver[n][5]/ 4 );
        glVertex3f( -0.25,   ver[n][1] /12,   ver[n][5]/ 4 );
        glVertex3f(     0,   ver[n][2] /50,    ver[n][5]/ 4 );
        glVertex3f(  0.25,   ver[n][3] /1000,  ver[n][5]/ 4);
        glVertex3f(   0.5,   ver[n][4] /80,  ver[n][5]/ 4 );
        glEnd();
        
        
    }
    
    
    
    
}

// ----------------------------------------------------------
// Lable the Occurrence
// ----------------------------------------------------------

void lable_curve_Occurrence(){
    
    
    float numbs[SIZE];
    int idx;
    int n=77;
    int count=0;
    
    std::cout << "( "<< "Z values" << ", "<< " Occurrence " << " )"<< std::endl;

    for(idx = 0; idx<n; idx++)
        numbs[idx] = ver[idx][5];
    
	for (int i = 0; i < n; i++)
	{
		bool matching = false;
		for (int j = 0; (j < i) && (matching == false); j++) {
            
            if (numbs[i] == numbs[j]) {
                
                matching = true;
            }
            
        }
		if (!matching){
            for(idx = 0; idx<n; idx++) {
                
                if (numbs[idx]==numbs[i]) {
                    count++;
                }
                
            }
            
            
            //Lable Occurrence
                        std::cout << "( "<< numbs[i] << ", "<< count << " )"<< std::endl;
            
            
            
            glPushMatrix();
            glTranslatef(0.5, 0, numbs[i]/4);
            bitmap_output (0,0,0, "0" , GLUT_BITMAP_TIMES_ROMAN_24);
            glPopMatrix();
            
            count = 0 ;
            
            
        }
    }
    
    
    
    
    
}



// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void display(){
    
    
    
    //  Clear screen and Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    // Reset transformations
    glLoadIdentity();
    
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    
    // side - BACK
    glBegin(GL_POLYGON);
    glColor4f(   1.0,  1.0, 1.0, 1.0);
    glVertex3f(  0.5, -0.5, 0.5 );
    glVertex3f(  0.5,  0.5, 0.5 );
    glVertex3f( -0.5,  0.5, 0.5 );
    glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();
    
    
    
    // side - LEFT
    glBegin(GL_POLYGON);
    glColor4f(   0.85,  0.85,  0.85, 0.75 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    
    
    // side - BOTTOM
    glBegin(GL_POLYGON);
    glColor4f(   0.75,  0.75,  0.75, 1.0 );
    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    
    
    //Sample Curevs in the coordinates
    SampleCurves();
    
    //lable units to the axis
    lables_slot();
    lable_curve_Occurrence();
    
    
    
    glBegin(GL_POLYGON);
    glColor4f(   0.8,  0.8,  0.8, 0.25 );
    glVertex3f( -0.25, -0.5,  0.5 );
    glVertex3f( -0.25,  0.5,  0.5 );
    glVertex3f( -0.25,  0.5, -0.5 );
    glVertex3f( -0.25, -0.5, -0.5 );
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor4f(   0.8,  0.8,  0.8, 0.25 );
    glVertex3f( 0, -0.5,  0.5 );
    glVertex3f( 0,  0.5,  0.5 );
    glVertex3f( 0,  0.5, -0.5 );
    glVertex3f( 0, -0.5, -0.5 );
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor4f(   0.8,  0.8,  0.8, 0.25 );
    glVertex3f( 0.25, -0.5,  0.5 );
    glVertex3f( 0.25,  0.5,  0.5 );
    glVertex3f( 0.25,  0.5, -0.5 );
    glVertex3f( 0.25, -0.5, -0.5 );
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor4f(   0.8,  0.8,  0.8, 0.25 );
    glVertex3f( 0.5, -0.5,  0.5 );
    glVertex3f( 0.5,  0.5,  0.5 );
    glVertex3f( 0.5,  0.5, -0.5 );
    glVertex3f( 0.5, -0.5, -0.5 );
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f (0.1, 0.1, 0.1);
    glVertex3f( 0,  0.5,  -0.5 );
    glVertex3f( 0, -0.5,  -0.5 );
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f( -0.5, -0.5,  -0.5 );
    glVertex3f( -0.5,  0.5,  -0.5 );
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(  0.5, -0.5,  -0.5 );
    glVertex3f(  0.5,  0.5,  -0.5 );
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f( -0.25, -0.5,  -0.5 );
    glVertex3f( -0.25,  0.5,  -0.5 );
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f (0.1, 0.1, 0.1);
    glVertex3f(  0.25,  0.5,  -0.5 );
    glVertex3f(  0.25, -0.5,  -0.5 );
    glEnd();
    
    
    glFlush();
    glutSwapBuffers();
    
}



// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {
    
    //  Right arrow - increase rotation by 5 degree
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    
    //  Left arrow - decrease rotation by 5 degree
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    
    //  Request display update
    glutPostRedisplay();
    
}

// ----------------------------------------------------------
//
// ----------------------------------------------------------




// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]){
    
    //  Initialize GLUT and process user parameters
    glutInit(&argc,argv);
    
    //  Request double buffered true color window with Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    // Create window
    glutCreateWindow("Awesome Cube");
    
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  
    //  Enable Z-buffer depth test
    glEnable(GL_DEPTH_TEST);
    
    // Callback functions
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    
    //  Pass control to GLUT for events
    glutMainLoop();
    
    //  Return to OS
    return 0;
}