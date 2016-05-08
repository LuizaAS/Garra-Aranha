typedef struct posicao{
   float x, y, z;
} Posicao, Direcao;

typedef struct colisao{
   int raio;
   Posicao centro;
} Colisao;

void converteCoordenadas(int x, int y, struct posicao *mouse, struct posicao tamanhoTela);
int distanciaEntrePontos(Posicao p, Posicao q);
bool esferaDentroDaOutra(Colisao aranha, Colisao obj);
bool esferaEncostaNaOutra(Colisao aranha, Colisao obj);
