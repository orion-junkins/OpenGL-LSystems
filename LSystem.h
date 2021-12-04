#ifndef LSYSTEM_H
#define LSYSTEM_H
#include <string>
#include <map>
#include <iostream>
#include "./Point.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include "glut.h"


using namespace std;
typedef map<char, string> BasePairMap;

class LSystem {
    private:
        float m_recursion_depth = 1.0;
    public:
        string m_axiom;
        int m_drawing_depth;
        float m_rotation_angle;
        float m_depth_scale_factor;
        BasePairMap m_rules;
        string m_instruction;

        LSystem(string axiom, int drawing_depth, float rotation_angle, float depth_scale_factor);

        void addRule(char input_character, string substitution);

        string substitute(char input);

        void generateInstruction();

        void processSymbol(char symbol);

        void drawLineSegment(Point start, Point end);

        void drawScaledLineSegment();

        void pushTransformations();

        void popTransformations();

        void rotatePosX();

        void rotateNegX();

        void rotatePosY();

        void rotateNegY();

        void rotatePosZ();

        void rotateNegZ();

        void draw();

};

#endif //LSYSTEM_H