# CG - Trabalho Prático 02

<h2>A Aranha</h2>

[![A Aranha](images/aranha.gif)][a-aranha-youtube]

[a-aranha-youtube]: https://www.youtube.com/watch?v=IWcU_Qsk-4A

Ajude uma pobre e terrivel aranha a conquistar suas refeições diarias.


<img align="center" src="https://github.com/LuizaAS/Garra-Aranha/tree/master/screenshots/Captura de tela de 2016-05-12 00:55:41.png?raw=true" width="250" height="300"/>
<img align="center" src="https://github.com/LuizaAS/Garra-Aranha/tree/master/screenshots/Captura de tela de 2016-05-12 00:55:54.png?raw=true" width="250" height="300"/>
<img align="center" src="https://github.com/LuizaAS/Garra-Aranha/tree/master/screenshots/Captura de tela de 2016-05-12 00:55:58.png?raw=true" width="250" height="300"/>

<h3>SISTEMA SUPORTADO: LINUX</h3>

<h3>BLIBLIOTECAS E COMO RODAR EM LINUX:</h3>

<h4>COMPILANDO E RODANDO (LINUX):</h4>

FORAM USADAS AS BIBLIOTECAS GLEW,FREEGLUT,SOIL,SFML(AUDIO).
<h4>PARA ADQUIRIR AS BIBLIOTECAS (LINUX):</h4>
	
	sudo apt-get install build-essential
	sudo apt-get install freeglut3-dev
	sudo apt-get install libglew1.6-dev
	sudo apt-get install libsfml-dev
	sudo apt-get install libsoil-dev

OU USE 

	make install -->instala todas bibliotecas acima

PARA RODAR O JOGO EM LINUX BASTA SEGUIR OS SEGUINTE PASSOS:
	
	1- sudo apt-get install git
	2- git clone https://github.com/LuizaAS/Garra-Aranha.git
	3- cd Garra-Aranha/
	4- make install
	5- make run

CASO DESEJE COMPILAR O PROGAMA TAMBÉM USE OS COMANDOS DENTRO DA PASTA Makefile/:

	1- make        --> compila o jogo
	2- make clean  --> limpa arquivo .o
	3- make run    --> compila e roda o jogo

<h3>COMO JOGAR:</h3>
FUNCIONALIDADES:
	<p>USE <kbd>←</kbd><kbd>↑</kbd><kbd>→</kbd><kbd>↓</kbd> NO TECLADO PARA MOVIMENTAR A ARANHA.</p>
	E <kbd>Backspace</kbd> PARA TENTAR PEGAR UM INSETO</p>
	<p>USE <kbd>a</kbd><kbd>w</kbd><kbd>d</kbd><kbd>s</kbd> PARA MOVER A CAMERA</p>
	<p>O MOUSE PODE SER USADO PARA MOVIMENTAR SUTILMETE A CAMERA E NAVEGAR NO MENU INICIAL</p>
	<p><kbd>ESC</kbd> PARA SAIR DO JOGO</p>
	<p>E PRESSIONE QUALQUER TECLA PARA SAIR DAS TELAS DE GANHOU, PERDEU E TURORIAL</p>

<img align="center" src="https://github.com/LuizaAS/Garra-Aranha/tree/master/imagens/tutorial2.png?raw=true" width="250" height="300"/>

<h3>CREDITOS:</h3>
Desenvolvido por: Luiza && Marcela para a disciplina de computação gráfica 2016/01.
Grande parte das imagens e audios foram retiradas do google e youtube.
DEMO: https://www.youtube.com/watch?v=q2L8nsqD320





