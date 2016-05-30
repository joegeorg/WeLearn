#include<GL/glut.h>
GLfloat v[][3]={{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1},{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1}};
void draw_polygon(int a,int b,int c, int d)
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
	draw_polygon(0,3,2,1);
	draw_polygon(0,4,7,3);
	draw_polygon(1,2,6,5);
	draw_polygon(3,7,6,2);
	draw_polygon(4,5,6,7);
	draw_polygon(0,1,5,4);
}

static GLfloat theta[]={0,0,0};
static GLint axis=2;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(theta[0],1.0,0.0,0.0);
	glRotatef(theta[1],0.0,1.0,0.0);
	glRotatef(theta[2],0.0,0.0,1.0);
	colorcube();
	glFlush();
	glutSwapBuffers();
}
void spincube()
{
	theta[axis]+=1;
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
		glOrtho(-2,2,-2*(GLfloat)h/(GLfloat)w,2*(GLfloat)h/(GLfloat)w,-10,10);
	else
		glOrtho(-2,2,-2*(GLfloat)w/(GLfloat)h,2*(GLfloat)w/(GLfloat)h,-10,10);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void mouse(int bt,int st,int x,int y)
{
	if(bt==GLUT_LEFT_BUTTON && st==GLUT_DOWN)
		axis=0;
	if(bt==GLUT_MIDDLE_BUTTON && st==GLUT_DOWN)
		axis=1;
	if(bt==GLUT_RIGHT_BUTTON && st==GLUT_DOWN)
		axis=2;
}
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("3d cube");
	glutDisplayFunc(display);
	glutReshapeFunc(myreshape);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST);
	glutIdleFunc(spincube);
	glutMainLoop();
}