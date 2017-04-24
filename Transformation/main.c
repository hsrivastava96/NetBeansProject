#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>

int ax, ay, sx, sy, ang, wid;
float P1[3][3], P2[3][3], T[3][3];

void draw(float d[3][3])
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,1.0,0.0);
	int i=0;
	for(i=0; i<3; i++)
	{
		glBegin(GL_LINES);
		glVertex2i(d[i][0], d[i][1]);
		glVertex2i(d[(i+1)%3][0], d[(i+1)%3][1]);
		glEnd();		
		glFlush();
	}
}

void translate()
{
	T[0][0]=1;  T[0][1]=0;  T[0][2]=0;
	T[1][0]=0;  T[1][1]=1;  T[1][2]=0;
	T[2][0]=sx; T[2][1]=sy; T[2][2]=1;	
}

void scale()
{
	T[0][0]=sx; T[0][1]=0;  T[0][2]=0;
	T[1][0]=0;  T[1][1]=sy; T[1][2]=0;
	T[2][0]=0;  T[2][1]=0;  T[2][2]=1;	
}

void rotate(float angl)
{
	int check;
	if(angl<0)
		check=-1;
	else
		check=1;
	T[0][0]=cos(angl);  	  T[0][1]=check*sin(angl); T[0][2]=0;
	T[1][0]=-check*sin(angl); T[1][1]=cos(angl); 	   T[1][2]=0;
	T[2][0]=0; 		  T[2][1]=0; 		   T[2][2]=1;	
}

void matpro()
{
	int i=0, j=0, k=0;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			P2[i][j]=0;
			for(k=0; k<3; k++)
			P2[i][j]+=P1[i][k]*T[k][j];
		}
	}
}

int main(int argc, char **argv)
{
	float angl=0;
	int choice, bx, by, cx, cy, mx, my, height;
	printf("\nPlease enter coordinates of vertx 1 --> ");
	scanf("%d", &ax);
	scanf("%d", &ay);
	printf("\nPlease enter width of the triangle --> ");
	scanf("%d", &wid);
	bx=ax+wid;
        by=ay;
        height=(sqrt(3)*wid )/2;
        mx=(ax+bx)/2;
        my=ay;
        cx=mx;
        cy=my+height;
	P1[0][0]=ax; P1[0][1]=ay; P1[0][2]=1;	
	P1[1][0]=bx; P1[1][1]=by; P1[1][2]=1;	
	P1[2][0]=cx; P1[2][1]=cy; P1[2][2]=1;	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Transformation");
	glClearColor(0, 0, 0, 0);
	gluOrtho2D(-600, 600, -600, 600);
	glClear(GL_COLOR_BUFFER_BIT);
	draw(P1);
	while(1)
	{
		printf("\n\tMENU\n1. Translate\n2. Rotate\n3. Scale\n4. Exit\nYour choice --> ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: printf("\nEnter tx and ty\n");
				scanf("%d", &sx);
				scanf("%d", &sy);
				translate();
				matpro();
				draw(P2);
				break;
			case 2: printf("\nEnter angle\n");
				scanf("%d", &ang);
				angl=ang*3.14/180;
				rotate(angl);
				matpro();
				draw(P2);
				break;
			case 3: printf("\nEnter sx and sy\n");
				scanf("%d", &sx);
				scanf("%d", &sy);
				scale();
				matpro();
				draw(P2);
				break;
			case 4: exit(0);
		}
	}
	glFlush();
	glutMainLoop();
	return 0;
}