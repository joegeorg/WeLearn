#include<GL/glut.h>
#include<math.h>

void draw_pixel(int x,int y)
{
	glColor3f(0.0,1.0,0.5);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void plot_pixels(int h,int k, int x, int y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(x+h,-y+k);

	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(-y+h,-x+k);
	draw_pixel(y+h,-x+k);
}

void draw_circle(GLint h,GLint k,GLint r)
{
	GLint x=0,y=r,d=1-r;
	while(y>x)
	{
		plot_pixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plot_pixels(h,k,x,y);
}

void draw_cylinder()
{
	int x=100,y=100,r=50,n=50,i;
	for(i=0;i<n;i+=3)
		draw_circle(x,y+i,r);
}

void draw_quadrilateral(int x1,int y1,int x2,int y2)
{
	glColor3f(1.0,0.0,0.5);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x1,y1);
	glVertex2i(x1,y2);
	glVertex2i(x2,y2);
	glVertex2i(x2,y1);
	glEnd();
}

void draw_parallelepiped()
{
	int x1=200,y1=100,x2=300,y2=200;
	int i;
	for(i=0;i<40;i+=2)
		draw_quadrilateral(x1+i,y1+i,x2+i,y2+i);	
}

void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glPointSize(2.0);
	gluOrtho2D(0,499,0,499);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw_cylinder();
	draw_parallelepiped();
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("cylinder");	
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}