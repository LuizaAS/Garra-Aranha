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
         		glTranslatef(i.p.centro.x,i.p.centro.y,i.p.centro.z+0.5);
	 		glScalef (0.5, 0.5, 0.5);
      	 		glutSolidSphere(1,10,10);
		glPopMatrix();
		//olhos
		 glPushMatrix();
			glColor3f(0.3,0.1,0.2);
         		glTranslatef(i.p.centro.x+0.2,i.p.centro.y+0.3,i.p.centro.z+0.3);
	 		glScalef (0.3, 0.3, 0.3);
      	 		glutSolidSphere(0.5,10,10);
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.3,0.1,0.2);
         		glTranslatef(i.p.centro.x-0.2,i.p.centro.y+0.1,i.p.centro.z+0.3);
	 		glScalef (0.3, 0.3, 0.3);
      	 		glutSolidSphere(0.5,10,10);
		glPopMatrix();
		//patas
		for (int a = 0; a < 2 ; a++)
		{
			glPushMatrix();
				glColor3f(cor,cor,cor);
				glTranslatef(i.p.centro.x,i.p.centro.y,i.p.centro.z+0.5);
				glRotatef((GLfloat)360/12*a,0.0,0.0,1.0);
				glScalef (0.5, 0.5, 0.5);
				desenhaPata(i.angulosPatas);
			glPopMatrix();

			glPushMatrix();
				glColor3f(cor,cor,cor);
				glTranslatef(i.p.centro.x,i.p.centro.y,i.p.centro.z+0.5);
				glRotatef((GLfloat)((360/12*a)-180),0.0,0.0,1.0);
				glScalef (0.5, 0.5, 0.5);
				desenhaPata(i.angulosPatas);
			glPopMatrix();
		}
	 glPopMatrix();
	
}

void desenhaMosca(Insetos i){
	glTranslatef(i.p.centro.x,i.p.centro.y,i.p.centro.z);
	glutSolidSphere(0.3,10,10);
	glColor3f(1,1,1);
	glPushMatrix();
		glTranslatef(0,0,0.3);
		glRotatef( (GLfloat)-90,45,0.0,1.0);
		glutSolidCylinder((GLdouble) 0.2, (GLdouble) 0.1, (GLint) 10, (GLint) 1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0,0,-0.3);
		glRotatef( (GLfloat)-90,45,0.0,1.0);
		glutSolidCylinder((GLdouble) 0.2, (GLdouble) 0.1, (GLint) 10, (GLint) 1);
	glPopMatrix();
}

void animaMoscas(Insetos *m){
	if(m->est==inativo){}
	else{
		if(m->est==ativo){
			int b = rand()%3;
			if(b==2){b=-1;}
			m->p.centro.x+=(b*0.1);
			b = rand()%3;
			if(b==2){b=-1;}
			m->p.centro.y+=(b*0.1);
			b = rand()%3;
			if(b==2){b=-1;}
			m->p.centro.z+=(b*0.1);
			if(m->p.centro.z>=5)
				m->p.centro.z--;
			else if(m->p.centro.z<=-7)
					m->p.centro.z++;
			if(m->p.centro.x>=6)
				m->p.centro.x--;
			else if(m->p.centro.x<=-6)
						m->p.centro.x++;
		}
		desenhaMosca(*m);
	}
}


