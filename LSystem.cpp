#include "./LSystem.h"
//#include <map>
//#include "Point.h"
//typedef std::map<char, std::string> BasePairMap;

LSystem::LSystem(string axiom, float rotation_angle){
    m_axiom = axiom;
    m_rotation_angle = rotation_angle;
}
void LSystem::addRule(char input_character, string substitution){
    m_rules[input_character] = substitution;
}