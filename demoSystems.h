#include "LSystem.h"
#include <vector>

vector<LSystem> generateDemos(){
    vector<LSystem> demos;

    // 2D Tree
    std::string tree2D_axiom = "F";
    LSystem tree2D(tree2D_axiom, 4, 20.0, 0.65);
    tree2D.addRule('F', "|[--F][+F][-F]");
    tree2D.generateInstruction();

    demos.push_back(tree2D);

    // Full 3D Tree
    std::string tree3D_axiom = "F";
    LSystem tree3D(tree3D_axiom, 4, 20.0, 0.65);
    tree3D.addRule('F', "|[--F][+F][-F][y--F][y+F][y-F][yy--F][yy+F][yy-F][yyy--F][yyy+F][yyy-F]");
    tree3D.generateInstruction();

    demos.push_back(tree3D);
    return demos;
}