#include<GL/glut.h>

int c=0;


void drawsq(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{

	if(c==0)
	{
		glColor3f(1, 1, 1);
		c=1;
	}
	else
	{
		glColor3f(0, 0, 0);
		c=0;
	}	

	glBegin(GL_POLYGON);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glVertex2i(x4, y4);
	glFlush();
	glEnd();
}

void rotate(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	int P_old[4][3], P_new[4][3], Trans[3][3];
	int i=0, j=0, k=0;

	P_old[0][0]=x1;
	P_old[0][1]=y1;
	P_old[0][2]=1;
	P_old[1][0]=x2;
	P_old[1][1]=y2;
	P_old[1][2]=1;
	P_old[2][0]=x3;
	P_old[2][1]=y3;
	P_old[2][2]=1;
	P_old[3][0]=x4;
	P_old[3][1]=y4;
	P_old[3][2]=1;

	Trans[0][0]=1;
	Trans[0][1]=0;
	Trans[0][2]=0;
	Trans[1][0]=0;
	Trans[1][1]=1;
	Trans[1][2]=0;
	Trans[2][0]=0;
	Trans[2][1]=0;
	Trans[2][2]=1;

	for(i=0; i<4; i++)
	{
		for(j=0; j<3; j++)
		{
			P_new[i][j]=0;
			for(k=0; k<3; k++)
			P_new[i][j]+=P_old[i][k]*Trans[k][j];
		}
	}
	
	for(i=0; i<2; i++)
	drawsq(P_new[0][0]+300, P_new[0][1]-100, P_new[1][0]+300, P_new[1][1]-100, P_new[2][0]+300, P_new[2][1]-100, P_new[3][0]+300, P_new[3][1]-100);
	
	if(c==0)
		c=1;
	else
		c=0;
}


void chessboard()
{
	glClear(GL_COLOR_BUFFER_BIT);
	int x, y;
	for(x=100; x<550; x+=75)
	{
		for(y=100; y<550; y+=75)
		rotate(x, y+75, x+75, y+75, x+75, y, x, y);
		if(c==0)
			c=1;
		else
			c=0;
	}
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Chess_Board");
	glClearColor(0, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1024, 0, 768);
	glutDisplayFunc(chessboard);
	glutMainLoop();
}