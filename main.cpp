#include <string>
#include "renderingUtils.h"
#include "LSystem.h"
#include "demoSystems.h"

int main( int argc, char *argv[ ] )
{

    vector<LSystem> demoSystems = generateDemos();
    LSystem system = demoSystems[0];

	// turn on the glut package:
	// (do this before checking argc and argv since it might
	// pull some command line arguments out)

	glutInit( &argc, argv );

	// setup all the graphics stuff:

	InitGraphics( );

	// create the display structures that will not change:

	InitLists(demoSystems);

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