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

void drawLineSegment(Point start, Point end){
  printf("In drawing line\n\n");
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