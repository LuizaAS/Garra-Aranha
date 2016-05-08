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

float virar=0.0, cor=0, descer=0, tamTeia=0;
int abaixa=0, music=0, gira=0, cont[4]={0}, light0Ligada=1;
GLuint texturaQuadrado1,texturaQuadrado2,texturaQuadrado3,texturaQuadrado4,texturaQuadrado5,texturaFloresta,texturaArvores,texturaTeia;
Aranha a;
Insetos i[qntInsetos];
Posicao tamTela;
sf::Music musicaInicio,musicaAranha, musicaInseto;

void redimensiona(int w, int h){
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -5.0);
   tamTela.x=w;
   tamTela.y=h;
}

void desenha(){
	glColor3f(1,1,1);
	float down=0;
	if(abaixa>0)
		down=3.5;
	if(virar>=3.5)
		virar--;
	else if(virar<=-5)
		virar++;
    glLoadIdentity();
	if(gira>0)
		gluLookAt(0-gira, 1, 7.0-gira, 0.0+virar+gira, 0.0-down, 0.0-gira, 0.0, 1.0, 0.0);
	else if(gira<0)
		gluLookAt(0-gira, 1, 7.0+gira, 0.0+virar+gira, 0.0-down, 0.0+gira, 0.0, 1.0, 0.0);
		else
        	gluLookAt(0, 1.0, 7.0, 0.0+virar, 0-down, 0, 0.0, 1.0, 0.0);

  glEnable(GL_DEPTH_TEST);

	Floresta(texturaFloresta, texturaArvores);
	Paredes(texturaQuadrado1, texturaQuadrado2, texturaQuadrado3, texturaQuadrado4, texturaQuadrado5);
	Teia(texturaTeia);
	animaAranha(&a, cont, &tamTeia, &descer, &musicaAranha, &musicaInicio);
	desenhaAranha(a, cor);
	animaInsetos(&a,i, &musicaInseto);

	glDisable(GL_DEPTH_TEST);
    glutSwapBuffers();
}

void init(){
    int b;
    glClearColor (1, 1, 1, 0);
    texturaQuadrado1 = carregar_textura("imagens/quadrado1.png");    texturaQuadrado2 = carregar_textura("imagens/quadrado2.png");
    texturaQuadrado3 = carregar_textura("imagens/quadrado3.png");    texturaQuadrado4 = carregar_textura("imagens/quadrado4.png");
	  texturaQuadrado5 = carregar_textura("imagens/quadrado5.jpg");
	  texturaFloresta  = carregar_textura("imagens/chao.jpg");		 texturaArvores = carregar_textura("imagens/floresta.jpg");
	  texturaTeia = carregar_textura("imagens/teia.png");
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

  	musicaInicio.openFromFile("audios/casa.ogg"); 	musicaInicio.setVolume(75);
  	musicaAranha.openFromFile("audios/aranha.ogg"); musicaAranha.setVolume(75);
  	musicaInseto.openFromFile("audios/grito.ogg"); musicaInseto.setVolume(75);
  	musicaInicio.setLoop(true);
  	musicaInicio.play();

  	a.angulosPatas = anguloPatasAbertas; a.anguloCima = angCabecaBaixo;
  	a.est = ativo;
  	for(b=0;b<qntInsetos/2;b++){
  		i[b].est=inativo; i[b+(qntInsetos/2)].est=inativo;
  		criaMosca(&i[b]);	criaArainha(&i[b+(qntInsetos/2)]);
  	}
  	a.est= ativo;	a.p.x=0; 	a.p.y=5;	a.p.z=-5;	a.colide.raio = 3; a.anda=0;

   	glClearColor(1,1,1,1);
   	glEnable(GL_CULL_FACE);
   	glCullFace(GL_BACK);

   	glDepthFunc(GL_LESS);

   	glEnable(GL_LIGHT0);
   	glEnable(GL_NORMALIZE);
   	glEnable(GL_COLOR_MATERIAL);
   	glEnable(GL_LIGHTING);

   	glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
   	glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
   	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
   	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   	glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
   	glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
   	glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
   	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void mouse ( int x, int y) {
	if(x>=790)
		virar++;
	else if(x<=10)
		virar--;
	if(y>=585)
		abaixa++;
	else if(y<=15)
		abaixa--;
}

void teclaEspecial(int key, int x, int y){
	if(a.est==ativo){
		switch(key) {
			case GLUT_KEY_RIGHT:
				a.p.x++;
				a.anda++;
				break;
			case GLUT_KEY_LEFT:
				a.p.x--;
				a.anda--;
				break;
			case GLUT_KEY_UP:
				a.p.z--;
				break;
			case GLUT_KEY_DOWN:
				a.p.z++;
				break;
		}
		if(a.p.z>=5)
			a.p.z--;
		else if(a.p.z<=-7)
				a.p.z++;
		if(a.p.x>=6)
			a.p.x--;
		else if(a.p.x<=-6)
				a.p.x++;
	}
	glutPostRedisplay();
}

static void teclado(unsigned char key, int x, int y){
    switch (key){
        case 27 :
            exit(0);
            break;
        case '.':
            virar++;
            break;
		case ',':
	    	virar--;
	    	break;
      	case 'p':
	  		abaixa++;
	    	break;
		case 'd':
			gira=-8;
			break;
		case 'a':
			gira=8;
			break;
		case 's':
			gira=0;
			virar=0;
			abaixa=0;
			break;
		case ' ':
			if(a.est==ativo){
				a.est=colide;
				musicaInicio.stop();
				musicaAranha.setLoop(true);
				musicaAranha.play();
			}
			break;
		case '+':
			cor+=0.1;
			break;
		case 'l':
			light0Ligada=0;
			break;
    }
    glutPostRedisplay();
}

static void idle(void){
   	glutPostRedisplay();
}

int main(int argc, char** argv){
   	glutInit(&argc, argv);
   	glutInitContextVersion(1,1);
   	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
   	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   	glutInitWindowSize (800, 600);
   	glutInitWindowPosition (100, 100);
   	glutCreateWindow ("Tp2 Luiza e Marcela");
    srand(time(NULL));

   	init();
   	glutDisplayFunc(desenha);
   	glutReshapeFunc(redimensiona);
   	glutKeyboardFunc(teclado);
   	glutSpecialFunc(teclaEspecial);
   	glutPassiveMotionFunc(mouse);
   	glutIdleFunc(idle);

   	glutMainLoop();
   	return 0;
}
