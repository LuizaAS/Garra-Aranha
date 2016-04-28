#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <SFML/Audio.hpp>
#include "contas.h"
#include "aranha.h"
#include "fundo.h"
#include "insetos.h"

void desenhaInsetos(Insetos i){
	glPushMatrix();
		glRotatef((GLfloat)i.anguloCima.x,(GLfloat)i.anguloCima.y,(GLfloat)i.anguloCima.z,1.0);
		//corpo
		 glPushMatrix();
         		glColor3f(0,0,0);
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
				glColor3f(0,0,0);
				glTranslatef(i.p.centro.x,i.p.centro.y,i.p.centro.z+0.5);
				glRotatef((GLfloat)360/12*a,0.0,0.0,1.0);
				glScalef (0.5, 0.5, 0.5);
				desenhaPata(i.angulosPatas);
			glPopMatrix();

			glPushMatrix();
				glColor3f(0,0,0);
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
	glColor3f(0,0,0);
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

void moveMoscas(Aranha *a, Insetos *m, sf::Music *musicaInseto){
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
	else if(m->p.centro.z<=-6)
			m->p.centro.z++;
	if(m->p.centro.x>=6)
		m->p.centro.x--;
	else if(m->p.centro.x<=-6)
			m->p.centro.x++;
	if(m->p.centro.y>=6)
		m->p.centro.y--;
	else if(m->p.centro.y<=-6)
			m->p.centro.y++;
	if(esferaEncostaNaOutra(a->colide,m->p)&&a->est==colide){
		printf("ok\n");
		musicaInseto->play();
		m->est=colide;
		a->est=inativo;
		a->angulosPatas=anguloPatasFechadas;
	}
}

void moveArainha(Aranha *a, Insetos *m, sf::Music *musicaInseto ){
	int b = rand()%3;
	if(b==2){b=-1;}
	m->p.centro.x+=(b*0.01);
	b = rand()%3;
	if(b==2){b=-1;}
	m->p.centro.z+=(b*0.01);
	if(m->p.centro.z>=5)
		m->p.centro.z--;
	else if(m->p.centro.z<=-6)
			m->p.centro.z++;
	if(m->p.centro.x>=6)
		m->p.centro.x--;
	else if(m->p.centro.x<=-6)
			m->p.centro.x++;
	if(esferaEncostaNaOutra(a->colide,m->p)&&a->est==colide){
		printf("ook\n");
		musicaInseto->play();
		m->est=colide;
		a->est=inativo;
		a->angulosPatas=anguloPatasFechadas;
	}
}

void criaMoscas(Insetos *m){
	printf("1\n");
	m->est= ativo;
	m->p.centro.x=rand()%7;
	if(rand()%2==1)
		m->p.centro.x*=-1;
	m->p.centro.y=rand()%7;
	if(rand()%2==1)
		m->p.centro.y*=-1;
	m->p.centro.z=rand()%6;
	if(rand()%2==1)
		m->p.centro.z*=-1;
	m->p.raio=0.3; 
	m->tipo=mosca;
}

void criaArainha(Insetos *a,Insetos *m){
	m->est= ativo;
	m->p.centro.y= -6;
	m->p.centro.x=rand()%7;
	if(rand()%2==1)
		m->p.centro.x*=-1;
	m->p.centro.z=rand()%6;
	if(rand()%2==1)
		m->p.centro.z*=-1;
	m->p.raio=0.5; 
	m->tipo=arainha;
	m->angulosPatas = anguloPatasAbertas;
	m->anguloCima = angCabecaCima;
}

void animaInsetos(Aranha *a,Insetos m[qntInsetos], sf::Music *musicaInseto){
	glColor3f(0,0,0);
	for(int i=0; i<qntInsetos;i++){
		if(m[i].est==inativo){
/*			if(rand()%2==0)
				criaMoscas(&m[i]);
			else
				criaArainha(&m[i]);*/
		}
		else{
			if(m[i].est==ativo){
				if(m[i].tipo==mosca)
					moveMoscas(a, &m[i],musicaInseto);
				else
					moveArainha(a, &m[i],musicaInseto);
			}
			else if(m[i].est==colide){
				m[i].p.centro=a->p;
				m[i].p.centro.y-=0.5;
				if(a->est==ativo)
					m[i].est=inativo;
			}
			if(m[i].tipo==mosca)
				desenhaMosca(m[i]);
			else
				desenhaInsetos(m[i]);
		}
	}
}
