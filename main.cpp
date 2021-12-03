#include "renderingUtils.h"
#include "grammarParser.h"

int
main( int argc, char *argv[ ] )
{
  BasePairMap rules;

  string input = "F[G]";
  rules['F'] = "|[--F][+F][-F]";
  rules['G'] = "y|[--F][+F][-F]";

  string instructionString = generateLSysInstruction(input, rules, 6);
  cout << "Output instruction: " << instructionString << "\n";

	// turn on the glut package:
	// (do this before checking argc and argv since it might
	// pull some command line arguments out)

	glutInit( &argc, argv );

	// setup all the graphics stuff:

	InitGraphics( );

	// create the display structures that will not change:

	InitLists(instructionString);

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