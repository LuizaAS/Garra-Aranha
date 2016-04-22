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

int carregar_textura(char const nome[40]){
    int textura;
    textura = SOIL_load_OGL_texture( nome ,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
        if (textura == 0 ) { printf("Erro: %s %s'\n", nome, SOIL_last_result()); }  
    return textura;
}

void Paredes( GLuint texturaQuadrado1, GLuint texturaQuadrado2, GLuint texturaQuadrado3, GLuint texturaQuadrado4, GLuint texturaQuadrado5){
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texturaQuadrado1);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-8, -8,  -10);
            glTexCoord2f(1, 0); glVertex3f( 8, -8,  -10);
            glTexCoord2f(1, 1); glVertex3f( 8, 8, -10);
            glTexCoord2f(0, 1); glVertex3f( -8, 8,  -10);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, texturaQuadrado2);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(8, -8,  -10);
            glTexCoord2f(1, 0); glVertex3f( 8, -8, 0);
            glTexCoord2f(1, 1); glVertex3f( 8, 8,  0);
            glTexCoord2f(0, 1); glVertex3f( 8, 8,  -10);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, texturaQuadrado3);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-8, -8, 0);
            glTexCoord2f(1, 0); glVertex3f( -8, -8,  -10);
            glTexCoord2f(1, 1); glVertex3f( -8, 8,  -10);
            glTexCoord2f(0, 1); glVertex3f( -8, 8,  0);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, texturaQuadrado4);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-8, -8, 0);
            glTexCoord2f(1, 0); glVertex3f( 8, -8, 0);
            glTexCoord2f(1, 1); glVertex3f( 8, -8,  -10);
            glTexCoord2f(0, 1); glVertex3f( -8, -8,  -10);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, texturaQuadrado5);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-8, 8,  -10);
            glTexCoord2f(1, 0); glVertex3f( 8, 8,  -10);
            glTexCoord2f(1, 1); glVertex3f( 8, 8,  0);
            glTexCoord2f(0, 1); glVertex3f( -8, 8,  0);
        glEnd();

    glDisable(GL_TEXTURE_2D);
}

void Floresta( GLuint texturaFloresta, GLuint texturaArvores){
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texturaFloresta);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-10, -8, 6);
            glTexCoord2f(1, 0); glVertex3f( 10, -8, 6);
            glTexCoord2f(1, 1); glVertex3f( 10, -8,  -10);
            glTexCoord2f(0, 1); glVertex3f( -10, -8,  -10);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, texturaArvores);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(10, -8, -10);
            glTexCoord2f(1, 0); glVertex3f( 10, -8, 6);
            glTexCoord2f(1, 1); glVertex3f( 10, 12,  6);
            glTexCoord2f(0, 1); glVertex3f( 10, 12,  -10);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, texturaArvores);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex3f(-10, -8, 6);
            glTexCoord2f(1, 0); glVertex3f( -10, -8, -10);
            glTexCoord2f(1, 1); glVertex3f( -10, 12,  -10);
            glTexCoord2f(0, 1); glVertex3f( -10, 12,  6);
        glEnd();
    glDisable(GL_TEXTURE_2D);
}
void Placa(GLuint texturaPlaca){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaPlaca);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-6, -11.5,  0);
        glTexCoord2f(1, 0); glVertex3f( 6, -11.5,  0);
        glTexCoord2f(1, 1); glVertex3f( 6, -6,  0);
        glTexCoord2f(0, 1); glVertex3f( -6, -6,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}