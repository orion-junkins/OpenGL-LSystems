#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include "glut.h"

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

void testShape(){
  Point p0 = newPoint(0., 0., 0.);
  Point p1 = translateY(p0, 1.);
  
  //"F"
  drawLineSegment(p0, p1);

  // "["
  glPushMatrix();
    //"x"
    glTranslatef(p1.x, p1.y, p1.z);
    glRotatef( -45., 1., 0., 0. );
    // "F"
    drawLineSegment(p0, p1);
  // "]"
  glPopMatrix();

  // "X"
  glPushMatrix();
    glTranslatef(p1.x, p1.y, p1.z);
    glRotatef( 45., 1., 0., 0. );
    drawLineSegment(p0, p1);
  glPopMatrix();
}

void processSymbol(char symbol){
  printf("%c", symbol);
  switch(symbol){
    case 'F':
      // Draw a new segment with the current transformation matrix
      break;
    case 'B':
      // Draw a new segment with the current transformation matrix
      break;
    case 'x':
      // Rotate neg x
      break;
    case 'X':
      // Rotate pos x
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

void drawLSystem(){
  char* testInstruction = "F[-X][+X]";
  char * t;    
  for (t = testInstruction; *t != '\0'; t++){
    processSymbol(*t);
  }
}