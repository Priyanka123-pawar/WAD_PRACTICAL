#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
float x1,x2,Y1,y2;

void show()
{
	float dx,dy,e;
	float x,y;
	dx=abs(x2-x1);
	dy=abs(y2-Y1);
	
	x=x1;
	y=Y1;
	
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	
	e=2*dy-dx;
	
	for(int i=1;i<=dx;i++)
	{
		if(e>=0)
		{
			y=y+1;
			e=e-2*dx;
		}
		x=x+1;
		e=e+2*dy;
		glVertex2i(x,y);
	
	}
	glEnd();
	glFlush();
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
    
}

int main(int argc,char**argv)
{
    cout<<"Enter the value of x1:";
    cin>>x1;
    cout<<"Enter the value of Y1:";
    cin>>Y1;
    cout<<"Enter the value of x2:";
    cin>>x2;
    cout<<"Enter the value of y2:";
    cin>>y2;
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(500,500);
    glutCreateWindow("Bresnhams Line Drawing Algo");
    init();
    glutDisplayFunc(show);
    glutMainLoop();
    
    return 0;
}  
	
	
	
