#include<GL/glut.h>
#include<stdbool.h>

double xmin=50,ymin=50,xmax=100,ymax=100;
double xvmin=200,yvmin=200,xvmax=300,yvmax=300;

#define RIGHT 8
#define LEFT 2
#define TOP 4
#define BOTTOM 1

int computecode(double x,double y)
{
	int code=0;
	if(x>xmax)
		code |= RIGHT;
	if(x<xmin)
		code |= LEFT;
	if(y>ymax) 
		code |= TOP;
	if(y<ymin) 
		code |= BOTTOM;
	return code;
}

void cohensutherland(double x0, double y0, double x1, double y1)
{
	int o0,o1,out;
	bool accept=false, done=false;
	o0=computecode(x0,y0);
	o1=computecode(x1,y1);

	do
	{
		if(!(o0|o1))
		{
			accept=true;
			done=true;
		}
		else if(o0&o1)
			done=true;
		else
		{
			double x,y;
			out = o0?o0:o1;

			if(out&RIGHT)
			{
				x=xmax;
				y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
			}
			else if(out&LEFT)
			{
				x=xmin;
				y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
			}
			else if(out&TOP)
			{
				y=ymax;
				x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
			}
			else
			{
				y=ymin;
				x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
			}
			
			if(out==o0)
			{
				x0=x;
				y0=y;
				o0=computecode(x0,y0);
			}
			else
			{
				x1=x;
				y1=y;
				o1=computecode(x1,y1);
			}
		}
	}
	while(!done);

	if(accept)
	{
		double sx=(xvmax-xvmin)/(xmax-xmin);
		double sy=(yvmax-yvmin)/(ymax-ymin);
		double vx0=xvmin+(x0-xmin)*sx;
		double vy0=yvmin+(y0-ymin)*sy;
		double vx1=xvmin+(x1-xmin)*sx;
		double vy1=yvmin+(y1-ymin)*sy;

		glColor3f(0.0,0.0,1.0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(xvmin,yvmin);
		glVertex2f(xvmin,yvmax);
		glVertex2f(xvmax,yvmax);
		glVertex2f(xvmax,yvmin);
		glEnd();

		glColor3f(0.0,1.0,0.0);
		glBegin(GL_LINES);
		glVertex2d(vx0,vy0);
		glVertex2d(vx1,vy1);
		glEnd();
	}
}

void display()
{
	double x0=60,y0=120,x1=80,y1=20;
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin,ymin);
	glVertex2f(xmin,ymax);
	glVertex2f(xmax,ymax);
	glVertex2f(xmax,ymin);
	glEnd();

	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
	glVertex2d(x0,y0);
	glVertex2d(x1,y1);
	glEnd();

	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
	glVertex2d(x0,y1);
	glVertex2d(x1,y0);
	glEnd();

	cohensutherland(x0,y0,x1,y1);
	cohensutherland(x0,y1,x1,y0);

	glFlush();
}

void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,499,0,499);
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutCreateWindow("cohen");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}