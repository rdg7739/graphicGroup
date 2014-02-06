#ifdef __APPLE__
  #include <GLUT/glut.h>
#else
  #include <GL/glut.h>
#endif

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <string>

#include "trackball.h"

//change this to define DEBUG if you're fond of EXTREME REDUNDANT printf spam. Seriously, it's a lifechanger.
#define DEBUGnope
#ifdef DEBUG
#define D(X) X
#else
#define D(X)
#endif // DEBUG


#define wizard(x) for(x)

#define COLORCALL glColor3f(1.0, 0.0, 0.0);

//I broke this up into several 
#include "classDefine.include"

/**
Returns the intersection of 2 2D lines, that go from (a|b)x1,y1 to (a|b)x2,y2.
This gets called to, uh, yeah.
Nevermind, it doesn't get called. I was thinking of doing some grand raytracing sort of thing, for each pixel we'd see which lines it intersects,
but then oh yeah glBegin(GL_LINE_LOOP)
*/
GLfloat intersect2D(GLfloat output[], GLfloat ax1, GLfloat ax2, GLfloat ay1, GLfloat ay2,GLfloat bx1, GLfloat bx2, GLfloat by1, GLfloat by2)
{
//GLfloat out[2]={99999.,99999.};
GLfloat aslope = (ay2-ay1)/(ax2-ax1);
GLfloat bslope = (by2-by1)/(bx2-bx1);

return output[0];
}



typedef std::vector<Line> ALineList;
ALineList* LineList;


//This is just initFile. I thought there would be more.
#include "bitsThatWork.include"

#include "coloringFunctions.include"
//All the glFunctions; mainly display(...) and keyboard(...)
#include "glFunctions.include"







int main(int argc, char** argv)
{
	D(printf("BEGIN PROGRAM\n");)
	char filename[80];
	if(argc<2)
	{sprintf(filename, "./data/matrices/subject01.txt");}
	else
	{sprintf(filename,"%s", argv[1]);}
	D(printf("YOU HAVE SELECTED FILE %s\n",filename);)
  

	glutInit(&argc, argv);
	   tbInit(GLUT_LEFT_BUTTON);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glMatrixMode(GL_PROJECTION);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	//glutCreateWindow("Space Mountain Express");
	glutCreateWindow("An actual patient in an actual setting!");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(processSpecialKeys);


	initFile(filename);
	//init();


	glutMainLoop();
	return 0;

}
