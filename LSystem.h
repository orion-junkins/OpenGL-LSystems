#ifndef LSYSTEM_H
#define LSYSTEM_H
#include <string>
#include <map>
#include <iostream>
using namespace std;
typedef map<char, string> BasePairMap;

class LSystem {
    private:
        float recursion_depth = 1.0;
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
};

#endif //LSYSTEM_H