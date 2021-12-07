#include "LSystem.h"
#include <vector>

vector<LSystem> generateDemos(){
    vector<LSystem> demos;
    // Weed 0
    std::string weed2D_axiom = "F";
    LSystem weed2D(weed2D_axiom, 4, 25.0, .75);
    weed2D.addRule('F', "FF+[+F-F-F]-[-F+F+F]");
    weed2D.generateInstruction();

    demos.push_back(weed2D);

    // 2D Floral 2
    std::string floral2D_axiom = "[F]----[F]";
    LSystem floral2D(floral2D_axiom, 7, 45.0, .75);
    floral2D.addRule('F', "|[-F][+F]");
    floral2D.generateInstruction();

    demos.push_back(floral2D);

    // 3D Floral 3
    std::string floral3D_axiom = "[F]x[F]x[F]x[F]x[F]x[F]x[F]x[F]";
    LSystem floral3D(floral3D_axiom, 7, 45.0, .75);
    floral3D.addRule('F', "|[-F][+F]");
    floral3D.generateInstruction();

    demos.push_back(floral3D);


    // 2D Tree 3
    std::string tree2D_axiom = "F";
    LSystem tree2D(tree2D_axiom, 4, 20.0, 0.65);
    tree2D.addRule('F', "|[--F][+F][-F]");
    tree2D.generateInstruction();

    demos.push_back(tree2D);

    // Full 3D Tree 4
    std::string tree3D_axiom = "F";
    LSystem tree3D(tree3D_axiom, 4, 20.0, 0.65);
    tree3D.addRule('F', "|[--F][+F][-F][y--F][y+F][y-F][yy--F][yy+F][yy-F][yyy--F][yyy+F][yyy-F]");
    tree3D.generateInstruction();

    demos.push_back(tree3D);
    return demos;
}