enum Tipo{arainha, mosca};
typedef struct insetos{
   Colisao p;
   Angulo angulosPatas;
   Angulo anguloCima;
   Estado est;
   Tipo tipo;
}Insetos;
#define qntInsetos 10


void desenhaInsetos(Insetos i);
	
void desenhaMosca(Insetos i);

void moveMoscas(Aranha *a, Insetos *m, sf::Music *musicaInseto);

void moveArainha(Aranha *a, Insetos *m, sf::Music *musicaInseto );

void criaMoscas(Insetos *m);

void criaArainha(Insetos *a,Insetos *m);

void animaInsetos(Aranha *a,Insetos m[qntInsetos], sf::Music *musicaInseto);