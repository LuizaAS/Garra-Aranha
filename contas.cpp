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

void converteCoordenadas(int x, int y, struct posicao *mouse, struct posicao tamanhoTela){
	mouse->y=-1*y/tamanhoTela.y*12;
	mouse->x=((+(GLfloat)x/tamanhoTela.x)-(GLfloat)x/(tamanhoTela.x/2.0))*8;
}

int distanciaEntrePontos(Posicao p, Posicao q){
    int resultado = sqrt((p.x - q.x)*(p.x - q.x)+(p.y - q.y)*(p.y - q.y)+(p.z - q.z)*(p.z - q.z));
    return resultado;
}

bool esferaDentroDaOutra(Colisao aranha, Colisao obj){
	int d = distanciaEntrePontos(aranha.centro, obj.centro);
	if(aranha.raio>(d+obj.raio))
		return true;
	else
		return false;
}

bool esferaEncostaNaOutra(Colisao aranha, Colisao obj){
	int d = distanciaEntrePontos(aranha.centro, obj.centro);
	if(aranha.raio>(d+obj.raio))
		return true;
	else
		return false;
}
