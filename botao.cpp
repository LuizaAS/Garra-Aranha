#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <SFML/Audio.hpp>
#include "contas.h"
#include "botao.h"
#include "aranha.h"
#include "fundo.h"

/*bool clique(struct posicao mouse, struct botoes botao){
	if ((mouse.y>=(botao.coordenadas.y-botao.tamanho.y))&&(mouse.y<=(botao.coordenadas.y+botao.tamanho.y))&&(mouse.x>=(botao.coordenadas.x-botao.tamanho.x))&&(mouse.x<=(botao.coordenadas.x+botao.tamanho.x))){    
		printf("ok\n");
		return true;
	}
	return false;
}*/

void desenhaBotoes(struct botoes botao){
  	glPushMatrix();
	  	glTranslatef(botao.coordenadas.x, botao.coordenadas.y, 0);
	  	glEnable(GL_BLEND);
		    glEnable(GL_TEXTURE_2D);
			    glBindTexture(GL_TEXTURE_2D, botao.textura);
			    glBegin(GL_QUADS);
			        glTexCoord2f(0, 0); glVertex3f(-botao.tamanho.x/2, -botao.tamanho.y/2,  0);
			        glTexCoord2f(1, 0); glVertex3f( botao.tamanho.x/2, -botao.tamanho.y/2,  0);
			        glTexCoord2f(1, 1); glVertex3f( botao.tamanho.x/2,  botao.tamanho.y/2,  0);
			        glTexCoord2f(0, 1); glVertex3f(-botao.tamanho.x/2,  botao.tamanho.y/2,  0);
			    glEnd();
		    glDisable(GL_TEXTURE_2D);
	    glDisable(GL_BLEND);
   	glPopMatrix();
}

// void Botoes(GLuint texturaPlay, GLuint texturaPause){
//     glEnable(GL_TEXTURE_2D);
// 	    glBindTexture(GL_TEXTURE_2D, texturaPlay);
// 	    glBegin(GL_QUADS);
// 	        glTexCoord2f(0, 0); glVertex3f(-3, -11,  0);
// 	        glTexCoord2f(1, 0); glVertex3f( -1, -11,  0);
// 	        glTexCoord2f(1, 1); glVertex3f( -1, -9,  0);
// 	        glTexCoord2f(0, 1); glVertex3f( -3, -9,  0);
// 	    glEnd();

// 	    glBindTexture(GL_TEXTURE_2D, texturaPause);
// 	    glBegin(GL_QUADS);
// 	        glTexCoord2f(0, 0); glVertex3f(1, -11,  0);
// 	        glTexCoord2f(1, 0); glVertex3f( 3, -11,  0);
// 	        glTexCoord2f(1, 1); glVertex3f( 3, -9,  0);
// 	        glTexCoord2f(0, 1); glVertex3f( 1, -9,  0);
// 	    glEnd();
//     glDisable(GL_TEXTURE_2D);
// }
