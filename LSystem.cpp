#include "./LSystem.h"
#include <iostream>

LSystem::LSystem(string axiom, int drawing_depth, float rotation_angle, float depth_scale_factor)
{
    m_axiom = axiom;
    m_instruction = axiom;
    m_drawing_depth = drawing_depth;
    m_rotation_angle = rotation_angle;
    m_depth_scale_factor = depth_scale_factor;
}

void LSystem::addRule(char input_character, string substitution)
{
    m_rules[input_character] = substitution;
}

string LSystem::substitute(char input) 
{
    string result = "";
    if ( m_rules.find(input) == m_rules.end() ) {
        result += input;
    } else {
        result += m_rules[input];
    }
    return result;
}

void LSystem::generateInstruction() 
{
    for(int i = m_drawing_depth; i > 0; i--)
    {
        string working_instruction = "";
        for(char& curChar : m_instruction) {
            working_instruction += substitute(curChar);
        }
        m_instruction = working_instruction;
    }
}


void LSystem::drawLineSegment(Point start, Point end)
{
    glColor3f( 1., 1., 1. );
    glLineWidth( 1. );

    glBegin( GL_LINE_STRIP );
        glVertex3f( start.m_x, start.m_y, start.m_z);
        glVertex3f( end.m_x, end.m_y, end.m_z);
    glEnd( );


    // glBegin( GL_POINTS );
    //   glVertex3f( start.x, start.y, start.z);
    //   glVertex3f( end.x, end.y, end.z);
    // glEnd( );
}

void LSystem::drawScaledLineSegment() 
{
    float segment_length = pow(m_depth_scale_factor, m_recursion_depth);
    Point p0 = Point(0., 0., 0.);
    Point p1 = Point(0., segment_length, 0.);
    drawLineSegment(p0, p1);
    glTranslatef(0., segment_length, 0.);
}

void LSystem::pushTransformations()
{
    glPushMatrix();
}

void LSystem::popTransformations()
{
    glPopMatrix();
}

void LSystem::rotatePosX()
{
    glRotatef( m_rotation_angle, 1., 0., 0. );
}

void LSystem::rotateNegX()
{
    glRotatef( -m_rotation_angle, 1., 0., 0. );
}

void LSystem::rotatePosY()
{
    glRotatef( m_rotation_angle, 0., 1., 0. );
}

void LSystem::rotateNegY()
{
    glRotatef( -m_rotation_angle, 0., 1., 0. );
}

void LSystem::rotatePosZ()
{
    glRotatef( m_rotation_angle, 0., 0., 1. );
}

void LSystem::rotateNegZ()
{
    glRotatef( -m_rotation_angle, 0., 0., 1. );
}


void LSystem::processSymbol(char symbol)
{
    switch(symbol)
    {
        case 'F':
            // Draw a new segment with the current transformation matrix
            drawScaledLineSegment();
            break;
        case 'B':
            // Draw a new segment with the current transformation matrix
            drawScaledLineSegment();
            break;
        case '[':
            // Push matrix onto the stack
            pushTransformations();
            // Update recursion Depth
            m_recursion_depth += 1;
            break;
        case ']':
            // Pop matrix onto the stack
            popTransformations();
            // Update recursion depth
            m_recursion_depth -= 1;
            break;
        case 'x':
            // Rotate neg x
            rotateNegX();
            break;
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
        case '-':
        case 'z':
            // Rotate neg z
            rotateNegZ();
            break;
        case '+':
        case 'Z':
            // Rotate pos z
            rotatePosZ();
            break;
        case '|':
            // Draw a line segment scaled to the current recursion depth
            drawScaledLineSegment();
            break;
        default:
            drawScaledLineSegment();
        break;
    }
}

void LSystem::draw()
{
    for (char& curChar : m_instruction)
    {
        processSymbol(curChar);
    }
}
