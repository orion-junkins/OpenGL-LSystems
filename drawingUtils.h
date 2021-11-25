#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include "glut.h"

float ROT_ANGLE = 60.;
void drawUnitLineSegment();

typedef struct Point{
	float x, y, z;		// coordinates
	// float nx, ny, nz;	// surface normal
	// float s, t;		// texture coords
} Point;

Point newPoint(float a, float b, float c) {
    Point p = { a, b, c };
    return p;
}

Point translateY(Point source, float distance){
  float x = source.x;
  float y = source.y + distance;
  float z = source.z;

  Point p = { x, y, z };
    return p;
}

void drawLineSegment(Point start, Point end){
  glColor3f( 1., 1., 1. );
  glPointSize(6.);
  glLineWidth( 1. );

  glBegin( GL_LINE_STRIP );
    glVertex3f( start.x, start.y, start.z);
    glVertex3f( end.x, end.y, end.z);
  glEnd( );

  glBegin( GL_POINTS );
    glVertex3f( start.x, start.y, start.z);
    glVertex3f( end.x, end.y, end.z);
  glEnd( );
}

void drawUnitLineSegment() {
  Point p0 = newPoint(0., 0., 0.);
  Point p1 = newPoint(0., 1., 0.);
  //Point p1 = translateY(p0, 1.);
  printf("drawLineSegment(p0, p1);\n");
  drawLineSegment(p0, p1);
  glTranslatef(0., 1., 0.);
}

void pushTransformations(){
  printf("glPushMatrix();\n");
  glPushMatrix();
}

void popTransformations(){
  printf("glPopMatrix();\n");
  glPopMatrix();
}

void rotatePosX(){
  printf("glRotatef( ROT_ANGLE, 1., 0., 0. );\n");
  glRotatef( ROT_ANGLE, 1., 0., 0. );
}

void rotateNegX(){
  printf("glRotatef( -ROT_ANGLE, 1., 0., 0. );\n");
  glRotatef( -ROT_ANGLE, 1., 0., 0. );
}

void processSymbol(char symbol){
  switch(symbol){
    case 'F':
      // Draw a new segment with the current transformation matrix
      drawUnitLineSegment();
      break;
    case 'B':
      // Draw a new segment with the current transformation matrix
      drawUnitLineSegment();
      break;
    case '[':
      // Push matrix onto the stack
      pushTransformations();
      break;
    case ']':
      // Pop matrix onto the stack
      popTransformations();
      break;
    case '-':
      // Rotate neg x
      rotateNegX();
      break;
    case '+':
      // Rotate pos x
      rotatePosX();
      break;
    case 'y':
      // Rotate neg y
      break;
    case 'Y':
      // Rotate pos y
      break;
    case 'z':
      // Rotate neg z
      break;
    case 'Z':
      // Rotate pos z
      break;
    default:
      break;
  }
}

void drawLSystem(char* testInstruction){
  //char* testInstruction = "F[xB][XB]";
  char * t;    
  for (t = testInstruction; *t != '\0'; t++){
    processSymbol(*t);
  }
}

