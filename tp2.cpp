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
#include "insetos.h"

float virar=0.0, cor=0, descer=0, tamTeia=0;
int abaixa=0, music=0, gira=0, cont=0,cont2=0, light0Ligada=1; 
struct botoes play, pause;
GLuint texturaQuadrado1,texturaQuadrado2,texturaQuadrado3,texturaQuadrado4,texturaQuadrado5,texturaFloresta,texturaPlaca,texturaArvores;
Aranha a;
Insetos i, m;
Posicao tamTela;
sf::Music musicaInicio,musicaAranha;

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
		gluLookAt(0-gira, 0, 7.0-gira, 0.0+virar+gira, 0.0-down, 0.0-gira, 0.0, 1.0, 0.0);
	else if(gira<0)
		gluLookAt(0-gira, 0, 7.0+gira, 0.0+virar+gira, 0.0-down, 0.0+gira, 0.0, 1.0, 0.0);
		else
        	gluLookAt(0, 0.0, 7.0, 0.0+virar, 0-down, 0, 0.0, 1.0, 0.0);

    glEnable(GL_DEPTH_TEST);

	Floresta(texturaFloresta, texturaArvores);
	Paredes(texturaQuadrado1, texturaQuadrado2, texturaQuadrado3, texturaQuadrado4, texturaQuadrado5);
	Placa(texturaPlaca);
	Botoes(play.textura, pause.textura);
	animaAranha(&a, &cont, &cont2, &tamTeia, &descer, &musicaAranha, &musicaInicio);	
	desenhaAranha(a, cor);
	desenhaInsetos(i,cor);
	animaMoscas(&m);

	glDisable(GL_DEPTH_TEST);
    glutSwapBuffers();
}

void init(){
    glClearColor (1, 1, 1, 0);
    texturaQuadrado1 = carregar_textura("imagens/quadrado1.png");    texturaQuadrado2 = carregar_textura("imagens/quadrado2.png");
    texturaQuadrado3 = carregar_textura("imagens/quadrado3.png");    texturaQuadrado4 = carregar_textura("imagens/quadrado4.png");
	texturaQuadrado5 = carregar_textura("imagens/quadrado5.jpg");
	texturaFloresta  = carregar_textura("imagens/chao.jpg");		 texturaArvores = carregar_textura("imagens/floresta.jpg");
	texturaPlaca     = carregar_textura("imagens/placa2.png");
	play.textura     = carregar_textura("imagens/play.png");         pause.textura = carregar_textura("imagens/pause.png");

    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	musicaInicio.openFromFile("audios/casa.ogg"); 	musicaInicio.setVolume(75);
	musicaAranha.openFromFile("audios/aranha.ogg"); musicaAranha.setVolume(75); 
	musicaInicio.setLoop(true);
	musicaInicio.play();
	
	a.angulosPatas = anguloPatasAbertas; a.anguloCima = angCabecaCima;
	a.est= ativo;	a.p.x=0; 	a.p.y=5;	a.p.z=-5;	a.colide.raio = 0.5;
	i.angulosPatas = anguloPatasAbertas; i.anguloCima = angCabecaCima;
	i.p.centro.x=0;	i.p.centro.y=-6; i.p.centro.z=-5; i.p.raio=0.5;
	m.est= ativo; m.p.centro.x=3;	m.p.centro.y=-3; m.p.centro.z=-3; m.p.raio=0.3;
	play.coordenadas.x=-2; 	play.coordenadas.y=-10;
	play.tamanho.x=4;	  	play.tamanho.y=4;
	pause.coordenadas.x=2;	pause.coordenadas.y=-10;
	pause.tamanho.x=4;		pause.tamanho.y=4;

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

void mouseClicks(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON ){
		Posicao mause;
		converteCoordenadas(x,y,&mause, tamTela);
		if(clique(mause, play)==true){
			musicaInicio.stop();
			musicaAranha.setLoop(true);
			musicaAranha.play();
		}
		else if(clique(mause, pause)==true){
			musicaAranha.stop();
			musicaInicio.setLoop(true);
			musicaInicio.play();
		}
	}
}

void teclaEspecial(int key, int x, int y){
	if(a.est==ativo){
		switch(key) {
			case GLUT_KEY_RIGHT:
				a.p.x++;
				break;
			case GLUT_KEY_LEFT:
				a.p.x--;
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
				descer=1;
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
   
   	init();
   	glutDisplayFunc(desenha);
   	glutReshapeFunc(redimensiona);
   	glutKeyboardFunc(teclado);
   	glutSpecialFunc(teclaEspecial);
   	glutPassiveMotionFunc(mouse);
   	glutMouseFunc(mouseClicks);
   	glutIdleFunc(idle);

   	glutMainLoop();
   	return 0;
}