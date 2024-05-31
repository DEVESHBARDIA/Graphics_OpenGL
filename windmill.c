#include <GL/glut.h>
#include <stdio.h>

void myinit() {
    gluOrtho2D(0, 500, 0, 500);
}

void triangle() {
    glBegin(GL_TRIANGLES);
        glVertex2f(0, 0);
        glVertex2f(50, 0);
        glVertex2f(25, 25);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);

    // Draw the windmill base
    glPushMatrix();
        glTranslated(250, 0, 0);
        glScaled(1, 10, 1);
        triangle();
    glPopMatrix();

    // Draw the first blade
    glPushMatrix();
        glTranslated(275, 230, 0);
        glScaled(1, 4, 1);
        glRotated(0, 0, 0, 1);
        triangle();
    glPopMatrix();

    // Draw the second blade
    glPushMatrix();
        glTranslated(275, 230, 0);
        glScaled(1, 4, 1);
        glRotated(90, 0, 0, 1);
        triangle();
    glPopMatrix();

    // Draw the third blade
    glPushMatrix();
        glTranslated(275, 230, 0);
        glScaled(1, 4, 1);
        glRotated(180, 0, 0, 1);
        triangle();
    glPopMatrix();

    // Draw the fourth blade
    glPushMatrix();
        glTranslated(275, 230, 0);
        glScaled(1, 4, 1);
        glRotated(270, 0, 0, 1);
        triangle();
    glPopMatrix();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Transformation");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

