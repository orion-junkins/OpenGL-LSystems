#include <string>
#include "renderingUtils.h"
#include "LSystem.h"

int main( int argc, char *argv[ ] )
{
    std::string axiom = "F";
    LSystem system(axiom, 4, 20.0, 0.65);
    system.addRule('F', "|[--F][+F][-F][y--F][y+F][y-F][yy--F][yy+F][yy-F][yyy--F][yyy+F][yyy-F]");
    system.generateInstruction();

	// turn on the glut package:
	// (do this before checking argc and argv since it might
	// pull some command line arguments out)

	glutInit( &argc, argv );

	// setup all the graphics stuff:

	InitGraphics( );

	// create the display structures that will not change:

	InitLists(system);

	// init all the global variables used by Display( ):
	// this will also post a redisplay

	Reset( );

	// setup all the user interface stuff:

	InitMenus( );

	// draw the scene once and wait for some interaction:
	// (this will never return)

	glutSetWindow( MainWindow );
	glutMainLoop( );

	// glutMainLoop( ) never returns
	// this line is here to make the compiler happy:

	return 0;
}