#include<GL/glut.h>

void edgedetect(float x1,float y1,float x2,float y2,int *le,int *re)
{
	float mx,temp,x;
	int i;
	
	if((y2-y1)<0)
	{
		temp=y2;y2=y1;y1=temp;
		temp=x2;x2=x1;x1=temp;
	}
	if((y2-y1)!=0)
		mx=(x2-x1)/(y2-y1);
	else
		mx=x2-x1;
	x=x1;

	for(i=y1;i<=y2;i++)
	{
		if(x<(float)le[i])
			le[i]=(int)x;
		if(x>(float)re[i])
			re[i]=(int)x;

		x+=mx;
	}
}

void drawpixel(float x, float y)
{
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}

void scanfil(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
	int le[500],re[500];
	int i,j;
	for(i=0;i<500;i++)
	{
		le[i]=500;
		re[i]=0;
	}
	edgedetect(x1,y1,x2,y2,le,re);
	edgedetect(x2,y2,x3,y3,le,re);
	edgedetect(x3,y3,x4,y4,le,re);
	edgedetect(x4,y4,x1,y1,le,re);

	for(i=0;i<500;i++)
		if(le[i]<=re[i])
			for(j=le[i];j<re[i];j++)
				drawpixel(i,j);
}

void display()
{
	float x1=200,y1=100,x2=100,y2=200,x3=200,y3=300,x4=300,y4=200;
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glVertex2f(x4,y4);
	glEnd();
	scanfil(x1,y1,x2,y2,x3,y3,x4,y4);
	glFlush();
}
void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glPointSize(1.0);
	glLoadIdentity();
	gluOrtho2D(0,499,0,499);
}
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("scanfil");
	glutDisplayFunc(display);
	myinit();

	glutMainLoop();
}
