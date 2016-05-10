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
int posicaoX = 0,mudaDirecao=0;
void desenhaArainha(Insetos* i){
	glPushMatrix();
		glTranslatef(i->p.centro.x,i->p.centro.y,i->p.centro.z);
		glRotatef((GLfloat)i->anguloCima.x,(GLfloat)i->anguloCima.y,(GLfloat)i->anguloCima.z,1.0);
		//corpo
		 glPushMatrix();
         		glColor3f(0,0,0);
         		glTranslatef(0,0,0.5);
	 		glScalef (0.5, 0.5, 0.5);
      	 		glutSolidSphere(1,10,10);
		glPopMatrix();
		//olhos
		glPushMatrix();
			glColor3f(0.3,0.1,0.2);
         		glTranslatef(-0.2,0.1,0.3);
	 		glScalef (0.3, 0.3, 0.3);
      	 		glutSolidSphere(0.5,10,10);
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.3,0.1,0.2);
         		glTranslatef(0.2,0.1,0.3);
	 		glScalef (0.3, 0.3, 0.3);
      	 		glutSolidSphere(0.5,10,10);
		glPopMatrix();
		//patas
		for (int a = 0; a < 2 ; a++){
			glPushMatrix();
				glColor3f(0,0,0);
				glTranslatef(0,0,0.5);
				glRotatef((GLfloat)360/12*a,0.0,0.0,1.0);
				glScalef (0.5, 0.5, 0.5);
				desenhaPata(i->angulosPatas);
			glPopMatrix();

			glPushMatrix();
				glColor3f(0,0,0);
				glTranslatef(0,0,0.5);
				glRotatef((GLfloat)((360/12*a)-180),0.0,0.0,1.0);
				glScalef (0.5, 0.5, 0.5);
				desenhaPata(i->angulosPatas);
			glPopMatrix();
		}
	glPopMatrix();
}

void desenhaMosca(Insetos* i){
		glPushMatrix();
				glTranslatef(i->p.centro.x,i->p.centro.y,i->p.centro.z);
				glColor3f(0,0,0);
				glutSolidSphere(0.3,10,10);
				glColor3f(0.4,0.4,0.4);
				glPushMatrix();
						glTranslatef(0.4,0,0);
						glRotatef( (GLfloat)90,45,-45.0,1.0);
						glutSolidCylinder((GLdouble) 0.2, (GLdouble) 0.02, (GLint) 10, (GLint) 1);
				glPopMatrix();
				glPushMatrix();
						glTranslatef(-0.4,0,0);
						glRotatef( (GLfloat)90,45,45.0,1.0);
						glutSolidCylinder((GLdouble) 0.2, (GLdouble) 0.02, (GLint) 10, (GLint) 1);
				glPopMatrix();
		glPopMatrix();
}


void moveInseto(Aranha *a, Insetos *m, sf::Music *musicaInseto, int indiceDoInseto ) {
		srand(time(NULL) + indiceDoInseto*500);

		float direcaoSorteadaX = ((float)rand()/(float)RAND_MAX)*3 - 1;
		float direcaoSorteadaY = ((float)rand()/(float)RAND_MAX)*3 - 1;
		float direcaoSorteadaZ = ((float)rand()/(float)RAND_MAX)*3 - 1;
		if(mudaDirecao == 1)
		{
			m->p.centro.x -= (direcaoSorteadaX*0.01);
			m->p.centro.y -= (m->tipo == mosca ? 1 : 0 ) * (direcaoSorteadaY*0.01);
			m->p.centro.z -= (direcaoSorteadaZ*0.01);
		}
		else{
			// printf("rand: x,y,z = (%.5f, %.5f, %.5f)", direcaoSorteadaX, direcaoSorteadaY, direcaoSorteadaZ);
			m->p.centro.x += (direcaoSorteadaX*0.01);
			// operador ternário para condicionais em linha: "? :"
			// ideia: variavel == TRUE ? retorna isto : retorna este outro;
			m->p.centro.y += (m->tipo == mosca ? 1 : 0 ) * (direcaoSorteadaY*0.01);
			m->p.centro.z += (direcaoSorteadaZ*0.01);
		}

		if(m->p.centro.z >= 0)
				m->p.centro.z--;
		else if(m->p.centro.z <= -8)
				m->p.centro.z++;
		if(m->p.centro.x >= 6){
				m->p.centro.x--;
				mudaDirecao=1;
		}
		else if(m->p.centro.x <=- 6){
				m->p.centro.x++;
				mudaDirecao=0;
		}
		if(m->p.centro.y  >= 6)
				m->p.centro.y--;
		else if(m->p.centro.y <= -6)
				m->p.centro.y++;
		if(esferaEncostaNaOutra(a->colide,m->p)&&a->est==colide){
				//printf("ook\n");
				musicaInseto->play();
				m->est=colide;
				a->est=inativo;
				a->angulosPatas=anguloPatasFechadas;
		}
}

void criaMosca(Insetos *m){
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

void criaArainha(Insetos *m){
	m->est= ativo;
	m->p.centro.y= -6;
	m->p.centro.x=-5 + posicaoX;
	posicaoX+=2;
	m->p.centro.z=-5;
	m->p.raio=0.5;
	m->tipo=arainha;
	m->angulosPatas = anguloPatasAbertas;
	m->anguloCima = angCabecaCima;
}

void animaInsetos(Aranha *a,Insetos m[qntInsetos], sf::Music *musicaInseto){
	glColor3f(0,0,0);
	for(int i=0; i<qntInsetos;i++){
		if(m[i].est==inativo){}
		else{
			if(m[i].est==ativo){
				moveInseto(a, &m[i], musicaInseto, i);
			}
			else if(m[i].est==colide){
				m[i].p.centro=a->p;
				m[i].p.centro.y-=0.5;
				if(a->est==ativo)
					m[i].est=inativo;
			}
			if(m[i].tipo==mosca)
				desenhaMosca(&(m[i]));
			else
				desenhaArainha(&(m[i]));

		}
	}
}
