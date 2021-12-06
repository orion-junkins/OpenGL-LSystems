#include "LSystem.h"
#include <vector>

vector<LSystem> generateDemos(){
    vector<LSystem> demos;

    // Full 3D Tree
    std::string axiom = "F";
    LSystem system(axiom, 4, 20.0, 0.65);
    system.addRule('F', "|[--F][+F][-F][y--F][y+F][y-F][yy--F][yy+F][yy-F][yyy--F][yyy+F][yyy-F]");
    system.generateInstruction();

    demos.push_back(system);
    return demos;
}