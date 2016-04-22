struct botoes {
	struct posicao coordenadas;
	struct posicao tamanho;
  	GLuint textura;
};

bool clique(struct posicao mouse, struct botoes botao);
void desenhaBotoes(struct botoes botao);
void Botoes(GLuint texturaPlay, GLuint texturaPause);