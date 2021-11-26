#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include "glut.h"

float ROT_ANGLE = 30.;
void drawUnitLineSegment();

typedef struct Point{
	float x, y, z;		// coordinates
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
  drawLineSegment(p0, p1);
  glTranslatef(0., 1., 0.);
}

void pushTransformations(){
  glPushMatrix();
}

void popTransformations(){
  glPopMatrix();
}

void rotatePosX(){
  glRotatef( ROT_ANGLE, 1., 0., 0. );
}

void rotateNegX(){
  glRotatef( -ROT_ANGLE, 1., 0., 0. );
}

void rotatePosY(){
  glRotatef( ROT_ANGLE, 0., 1., 0. );
}

void rotateNegY(){
  glRotatef( -ROT_ANGLE, 0., 1., 0. );
}

void rotatePosZ(){
  glRotatef( ROT_ANGLE, 0., 0., 1. );
}

void rotateNegZ(){
  glRotatef( -ROT_ANGLE, 0., 0., 1. );
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
    case 'x':
      // Rotate neg x
      rotateNegX();
      break;
    case '+':
    case 'X':
      // Rotate pos x
      rotatePosX();
      break;
    case 'y':
      // Rotate neg y
      rotateNegY();
      break;
    case 'Y':
      // Rotate pos y
      rotatePosY();
      break;
    case 'z':
      // Rotate neg z
      rotateNegZ();
      break;
    case 'Z':
      // Rotate pos z
      rotatePosZ();
      break;
    default:
      break;
  }
}

void drawLSystem(string instruction){
  for (char& curChar : instruction){
    processSymbol(curChar);
  }
}

