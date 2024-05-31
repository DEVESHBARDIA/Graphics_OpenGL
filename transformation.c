#include<GL/glut.h>
#include<stdio.h>
void myinit()
{
	gluOrtho2D(0,500,0,500);
}
void triangle()
{
	glBegin(GL_TRIANGLES);
		glVertex2f(100,100);
		glVertex2f(200,100);
		glVertex2f(150,150);
	glEnd();
}
void translate()
{
	glPushMatrix();
		glTranslated(100,0,0);
		triangle();
	glPopMatrix();
}
void rotate_triangle()
{
	glPushMatrix();
		glRotated(45,0,0,1);
		triangle();
	glPopMatrix();
}
void pivot_point_rotate()
{
	glPushMatrix();
		glTranslated(100,100,0);
		glRotated(45,0,0,1);
		glTranslated(-100,-100,0);
		triangle();
	glPopMatrix();
}

void scale_triangle()
{
	glPushMatrix();
		glScaled(2,2,1);
		triangle();
	glPopMatrix();
}
void pivot_point_scale()
{
	glColor3f(1,0,0);
	glPushMatrix();
	glTranslated(100,100,0);
	glScaled(2,2,1);
	glTranslated(-100,-100,0);
	triangle();
	glPopMatrix();
}

void menu(int ch){
	switch(ch){
		case 1:
			triangle();
			break;
		case 2:
			translate();
			break;
		case 3:
			rotate_triangle();
			break;
		case 4:
			pivot_point_rotate();
			break;
		case 5:
			scale_triangle();
			break;
		case 6:
			pivot_point_scale();
			break;
		default:
			exit(0); 
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1,0,0);
	glFlush();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutCreateWindow("Transformation");
	myinit();
	glutCreateMenu(menu);
		glutAddMenuEntry("Draw Triangle",1);
		glutAddMenuEntry("Translate Triangle",2);
		glutAddMenuEntry("Rotate About Origin",3);
		glutAddMenuEntry("Rotate About Fixed Point",4);
		glutAddMenuEntry("Scale About Origin",5);
		glutAddMenuEntry("Scale About Fixed Point",6);
		glutAddMenuEntry("EXIT",7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
