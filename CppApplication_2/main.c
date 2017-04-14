#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<stdlib.h>

struct Point {
    int x;
    int y;
};
typedef struct Point p;

void drawline(int x1, int x2, int y1, int y2) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    int m = 0, dx = 0, dy = 0, length = 0, x = 0, y = 0;
    int i = 0;
    dx = x2 - x1;
    dy = y2 - y1;
    m = dy / dx;
    if (dx >= dy) {
        length = abs(dx);
        x = round(x1);
        y = round(y1);
        while (i < length) {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
            glFlush();
            x = x + 1;
            y = y + m;
            y = round(y);
            i++;
        }
    } else {
        length = abs(dy);
        x = round(x1);
        y = round(y1);
        while (i < length) {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
            glFlush();
            x = x + (1 / m);
            y = y + 1;
            x = round(x);
            i++;
        }
    }

}

void display() {
    p pt[40];
    int i = 0, n;
    printf("Number of vertices --> ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coordinates of %d point --> ", i + 1);
        scanf("%d", &pt[i].x);
        scanf("%d", &pt[i].y);
    }
    for (i = 0; i < n; i++)
        drawline(pt[i].x, pt[i + 1].x, pt[i].y, pt[i + 1].y);
}

void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line");
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glFlush();
    glutMainLoop();
}