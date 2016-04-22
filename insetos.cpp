#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <SFML/Audio.hpp>
#include "contas.h"
#include "aranha.h"
#include "botao.h"
#include "fundo.h"
#include "insetos.h"

void desenhaInsetos(Insetos i,float cor)
{
	int a;	 
	glPushMatrix();
		glRotatef((GLfloat)i.anguloCima.x,(GLfloat)i.anguloCima.y,(GLfloat)i.anguloCima.z,1.0);
		glTranslatef(0,0,10);
		//corpo
		 glPushMatrix();
         		glColor3f(cor,cor,cor);
         		glTranslatef(i.p.x,i.p.y,i.p.z+0.5);
	 		glScalef (0.5, 0.5, 0.5);
      	 		glutSolidSphere(1,10,10);
		glPopMatrix();
		//olhos
		 glPushMatrix();
			glColor3f(0.3,0.1,0.2);
         		glTranslatef(i.p.x+0.2,i.p.y+0.3,i.p.z+0.3);
	 		glScalef (0.3, 0.3, 0.3);
      	 		glutSolidSphere(0.5,10,10);
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.3,0.1,0.2);
         		glTranslatef(i.p.x-0.2,i.p.y+0.1,i.p.z+0.3);
	 		glScalef (0.3, 0.3, 0.3);
      	 		glutSolidSphere(0.5,10,10);
		glPopMatrix();
		//patas
		for (int a = 0; a < 2 ; a++)
		{
			glPushMatrix();
				glColor3f(cor,cor,cor);
				glTranslatef(i.p.x,i.p.y,i.p.z+0.5);
				glRotatef((GLfloat)360/12*a,0.0,0.0,1.0);
				glScalef (0.5, 0.5, 0.5);
				desenhaPata(i.angulosPatas);
			glPopMatrix();

			glPushMatrix();
				glColor3f(cor,cor,cor);
				glTranslatef(i.p.x,i.p.y,i.p.z+0.5);
				glRotatef((GLfloat)((360/12*a)-180),0.0,0.0,1.0);
				glScalef (0.5, 0.5, 0.5);
				desenhaPata(i.angulosPatas);
			glPopMatrix();
		}
	 glPopMatrix();

}

