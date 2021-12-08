#include "LSystem.h"
#include <vector>

vector<LSystem> generateDemos(){
    vector<LSystem> demos;


    // Weed_2
    std::string weed_2_2D_axiom = "F";

    //LSystem( axiom, recursion depth, rotation angle, unit size scaler )
    LSystem weed_2_2D(weed_2_2D_axiom, 2, 25.0, .75); 
    weed_2_2D.addRule('F', "FF+[+F-F-F]-[-F+F+F]");
    weed_2_2D.generateInstruction();

    demos.push_back(weed_2_2D);



    // Weed_3_ 
    std::string weed_3_2D_axiom = "F";

    //LSystem( axiom, recursion depth, rotation angle, unit size scaler )
    LSystem weed_3_2D(weed_3_2D_axiom, 3, 25.0, .75);
    weed_3_2D.addRule('F', "FF+[+F-F-F]-[-F+F+F]");
    weed_3_2D.generateInstruction();

    demos.push_back(weed_3_2D);



    // Weed_4
    std::string weed_4_2D_axiom = "F";

    //LSystem( axiom, recursion depth, rotation angle, unit size scaler )
    LSystem weed_4_2D(weed_4_2D_axiom, 4, 25.0, .75);
    weed_4_2D.addRule('F', "FF+[+F-F-F]-[-F+F+F]");
    weed_4_2D.generateInstruction();

    demos.push_back(weed_4_2D);



    // Weed_5
    std::string weed_5_2D_axiom = "F";

    //LSystem( axiom, recursion depth, rotation angle, unit size scaler )
    LSystem weed_5_2D(weed_5_2D_axiom, 5, 25.0, .75);
    weed_5_2D.addRule('F', "FF+[+F-F-F]-[-F+F+F]");
    weed_5_2D.generateInstruction();

    demos.push_back(weed_5_2D);



    // 2D Floral_3
    std::string floral_3_2D_axiom = "F----F";

    //LSystem( axiom, recursion depth, rotation angle, unit size scaler )
    LSystem floral_3_2D(floral_3_2D_axiom, 3, 45.0, .75);
    floral_3_2D.addRule('F', "|[-F][+F]");
    floral_3_2D.generateInstruction();

    demos.push_back(floral_3_2D);



    // 2D Floral_5
    std::string floral_5_2D_axiom = "[F]----[F]";

    //LSystem( axiom, recursion depth, rotation angle, unit size scaler )
    LSystem floral_5_2D(floral_5_2D_axiom, 5, 45.0, .75);
    floral_5_2D.addRule('F', "|[-F][+F]");
    floral_5_2D.generateInstruction();

    demos.push_back(floral_5_2D);



    // 2D Floral_7
    std::string floral_7_2D_axiom = "[F]----[F]";

    //LSystem( axiom, recursion depth, rotation angle, unit size scaler )
    LSystem floral_7_2D(floral_7_2D_axiom, 7, 45.0, .75);
    floral_7_2D.addRule('F', "|[-F][+F]");
    floral_7_2D.generateInstruction();

    demos.push_back(floral_7_2D);



    // 3D Floral_7
    std::string floral_7_3D_axiom = "[F]x[F]x[F]x[F]x[F]x[F]x[F]x[F]";

    //LSystem( axiom, recursion depth, rotation angle, unit size scaler )
    LSystem floral_7_3D(floral_7_3D_axiom, 7, 45.0, .75);
    floral_7_3D.addRule('F', "|[-F][+F]");
    floral_7_3D.generateInstruction();

    demos.push_back(floral_7_3D);



    // 2D Tree
    std::string tree2D_axiom = "F";

    //LSystem( axiom, recursion depth, rotation angle, unit size scaler )
    LSystem tree2D(tree2D_axiom, 5, 20.0, 0.65);
    tree2D.addRule('F', "|[--F][+F][-F]");
    tree2D.generateInstruction();

    demos.push_back(tree2D);



    // Full 3D Tree
    std::string tree3D_axiom = "F";

    //LSystem( axiom, recursion depth, rotation angle, unit size scaler )
    LSystem tree3D(tree3D_axiom, 4, 25.0, 0.65);
    tree3D.addRule('F', "|[--F][+F][-F][y--F][y+F][y-F][yy--F][yy+F][yy-F][yyy--F][yyy+F][yyy-F]");
    tree3D.generateInstruction();

    demos.push_back(tree3D);
    return demos;
}