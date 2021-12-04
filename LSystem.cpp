#include "./LSystem.h"
#include <iostream>
LSystem::LSystem(string axiom, int drawing_depth, float rotation_angle, float depth_scale_factor){
    m_axiom = axiom;
    m_instruction = axiom;
    m_drawing_depth = drawing_depth;
    m_rotation_angle = rotation_angle;
    m_depth_scale_factor = depth_scale_factor;
}

void LSystem::addRule(char input_character, string substitution){
    m_rules[input_character] = substitution;
}

string LSystem::substitute(char input) {
  string result = "";
  if ( m_rules.find(input) == m_rules.end() ) {
    result += input;
  } else {
    result += m_rules[input];
  }
  return result;
}

void LSystem::generateInstruction() {
    for(int i = m_drawing_depth; i > 0; i--){
        string working_instruction = "";
        for(char& curChar : m_instruction) {
            working_instruction += substitute(curChar);
        }
        // cout << working_instruction << endl;
        m_instruction = working_instruction;
    }
}

