#include<GL/glut.h>
#include<stdbool.h>
#define outcode int
double xmin=50,ymin=50,xmax=100,ymax=100;
double xvmin=200,yvmin=200,xvmax=300,yvmax=300;
#define RIGHT 8
#define LEFT 2
#define TOP 4
#define BOTTOM 1

outcode computecode(double x,double y)
{
	outcode code=0;
	if(x>xmax)
		code |=RIGHT;
	if(x<xmin)
		code |=LEFT;
	if(y>ymax) 
		code |=TOP;
	if(y<ymin) 
		code |=BOTTOM;
	return code;
}
void cohensutherland(double x0,double y0,double x1,double y1)
{
	outcode o1,o2,out;
	bool accept=false,done=false;
	o1=computecode(x0,y0);
	o2=computecode(x1,y1);

	do
	{
		if(!(o1|o2))
		{
			accept=true;
			done=true;
		}
		else
			if(o1&o2)
				done=true;
			else
			{
				double x,y;
				out=o1?o1:o2;

				if(out&TOP)
				{
					x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
					y=ymax;
				}
				else if(out&BOTTOM)
				{
					x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
					y=ymin;
				}
				else if(out&RIGHT)
				{
					x=xmax;
					y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
				}
				else
				{
					x=xmin;
					y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
				}
				 if(out==o1)
					{
						x0=x;
						y0=y;
						o1=computecode(x0,y0);
					}
					else
						{
						x1=x;
						y1=y;
						o2=computecode(x1,y1);
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
		glVertex2d(60,20);
		glVertex2d(80,120);
		glEnd();

		cohensutherland(x0,y0,x1,y1);
		cohensutherland(60,20,80,120);
		
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





