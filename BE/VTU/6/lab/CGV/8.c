#include<GL/glut.h>
GLfloat v[][3]={{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1},{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1}};
void drawpolygon(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex3fv(v[a]);
	glColor3f(0.0,1.0,0.0);
	glVertex3fv(v[b]);
	glColor3f(0.0,0.0,1.0);
	glVertex3fv(v[c]);
	glColor3f(1.0,0.0,1.0);
	glVertex3fv(v[d]);
	glEnd();
}

void colorcube()
{
	drawpolygon(0,3,2,1);
	drawpolygon(2,3,7,6);
	drawpolygon(0,4,7,3);
	drawpolygon(0,1,5,4);
	drawpolygon(1,2,6,5);
	drawpolygon(4,5,6,7);
}

static GLfloat theta[]={0,0,0};
static GLint axis=2;
static GLdouble viewer[]={0,0,5};

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(viewer[0],viewer[1],viewer[2],0,0,0,0,1,0);
	glRotatef(theta[0],1,0,0);
	glRotatef(theta[1],0,1,0);
	glRotatef(theta[2],0,0,1);
	colorcube();
	glFlush();
	glutSwapBuffers();
}

void mouse(int bt,int st,int x, int y)
{
	if(bt==GLUT_LEFT_BUTTON && st==GLUT_DOWN)
		axis=0;
	if(bt==GLUT_MIDDLE_BUTTON && st==GLUT_DOWN)
		axis=1;
	if(bt==GLUT_RIGHT_BUTTON && st==GLUT_DOWN)
		axis=2;
}

void spin()
{
	theta[axis]+=2;
	if(theta[axis]>360)
		theta[axis]-=360;
	glutPostRedisplay();
}
void myreshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glFrustum(-2,2,-2*(GLfloat)h/(GLfloat)w,2*(GLfloat)h/(GLfloat)w,2,20);
	else
		glFrustum(-2,2,-2*(GLfloat)w/(GLfloat)h,2*(GLfloat)w/(GLfloat)h,2,20);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void keys(unsigned char key,int x, int y)
{
	if(key=='x') viewer[0]-=1;
	if(key=='X') viewer[0]+=1;
	if(key=='y') viewer[1]-=1;
	if(key=='Y') viewer[1]+=1;
	if(key=='z') viewer[2]-=1;
	if(key=='Z') viewer[2]+=1;
	display();	
}
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("view");
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutReshapeFunc(myreshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keys);
	glutIdleFunc(spin);
	glutMainLoop();
}