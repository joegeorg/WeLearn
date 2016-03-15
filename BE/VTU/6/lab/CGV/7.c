#include<GL/glut.h>
void wall(double thick)
{
	glPushMatrix();
		glTranslated(0.5,.5*thick,.5);
	glScaled(1,thick,1);
	glutSolidCube(1.0);
	glPopMatrix();
}

void tableleg(double thick,double len)
{
	glPushMatrix();
		glTranslated(0,.5*len,0);
	glScaled(thick,len,thick);
	glutSolidCube(1.0);
	glPopMatrix();
}
void table(double topwid,double topthick,double legthick,double leglen)
{
	
	glPushMatrix();
		glTranslated(0,leglen,0);
	glScaled(topwid,topthick,topwid);
	glutSolidCube(1.0);
	glPopMatrix();

	double dist=0.95*topwid/2-legthick/2;
	glPushMatrix();
		glTranslated(dist,0,dist);
		tableleg(legthick,leglen);
		glTranslated(0,0,-2*dist);
		tableleg(legthick,leglen);
		glTranslated(-2*dist,0,2*dist);
		tableleg(legthick,leglen);
		glTranslated(0,0,-2*dist);
		tableleg(legthick,leglen);
		glPopMatrix();

}

void display()
{
	glClearColor(0,1,0,0);
	GLfloat mat_ambient[]={.7,.7,.7,1};
	GLfloat mat_diffuse[]={.5,.5,.5,1};
	GLfloat mat_specular[]={1,1,1,1};
	GLfloat mat_shininess[]={50};

	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

	GLfloat lightintensity[]={.7,.7,.7,1};
	GLfloat lightposition[]={2,6,3,0};

	glLightfv(GL_LIGHT0,GL_POSITION,lightposition);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightintensity);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat winht=1;
	glOrtho(-winht*64/48,winht*64/48,-winht,winht,0.1,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(2.3,1.3,2,0,0.25,0,0,1,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	

	glPushMatrix();
	glTranslated(0.6,.38,.5);
	glRotated(30,0,1,0);
	glutSolidTeapot(0.08);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.4,.0,0.4);
	table(0.6,0.02,.02,0.3);
	glPopMatrix();

	wall(0.02);

	glPushMatrix();
	glRotated(90,0,0,1);
	wall(.02);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90,1,0,0);
	wall(0.02);
	glPopMatrix();
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1024,768);
	glutCreateWindow("teapot");
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	glViewport(0,0,640,480);
	glutMainLoop();
}
