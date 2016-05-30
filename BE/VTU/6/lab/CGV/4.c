#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

GLfloat h=100.0;
GLfloat k=100.0;
GLfloat theta;

void drawhouse()
{
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(100,100);
	glVertex2f(100,300);
	glVertex2f(250,300);
	glVertex2f(250,100);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(150,100);
	glVertex2f(150,150);
	glVertex2f(200,150);
	glVertex2f(200,100);
	glEnd();

	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(100,300);
	glVertex2f(175,400);
	glVertex2f(250,300);
	glEnd();
}

void rotate()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(h,k,0.0);
	glRotatef(theta,0.0,0.0,1.0);
	glTranslatef(-h,-k,0.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	drawhouse();
	rotate();
	drawhouse();
	glFlush();
	glutSwapBuffers();
}

void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);
}

void main(int argc, char** argv)
{
	printf("enter the rotation angle \n");
	scanf("%f",&theta);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("house rotation");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}