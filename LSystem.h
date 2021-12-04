#ifndef LSYSTEM_H
#define LSYSTEM_H
#include <string>
#include <map>
#include <iostream>
using namespace std;
typedef map<char, string> BasePairMap;

class LSystem {
    private:
        float m_rotation_angle;
    public:
        string m_axiom;
        BasePairMap m_rules;

        LSystem(string axiom, float rotation_angle);
        
        void addRule(char input_character, string substitution);
};

#endif //LSYSTEM_H