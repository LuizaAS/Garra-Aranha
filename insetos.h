typedef struct insetos{
   Colisao p;
   Angulo angulosPatas;
   Angulo anguloCima;
   Estado est;
}Insetos;

void desenhaInsetos(Insetos i, float cor);
void desenhaMosca(Insetos i);
void animaMoscas(Insetos *m);