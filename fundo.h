// 2 5 5 configura alguns parâmetros do modelo de iluminação: FONTE DE LUZ
const GLfloat light_ambient[]  = { 0.3f, 0.3f,  0.3f, 1.0f };
const GLfloat light_diffuse[]  = { 0.5f, 0.5f,  0.5f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f,  1.0f, 1.0f };
const GLfloat light_position[] = { 5.0f, 5.0f, 10.0f, 0.0f };
// configura alguns parâmetros do modelo de iluminação: MATERIAL
const GLfloat mat_ambient[]    = { 0.2f, 0.2f, 0.2f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.3f, 0.3f, 0.3f, 1.0f };
const GLfloat mat_specular[]   = { 0.1f, 0.1f, 0.1f, 1.0f };
const GLfloat high_shininess[] = { 100.0f};

int carregar_textura(char const nome[40]);
void Paredes( GLuint texturaQuadrado1, GLuint texturaQuadrado2, GLuint texturaQuadrado3, GLuint texturaQuadrado4, GLuint texturaQuadrado5);
void Floresta( GLuint texturaFloresta, GLuint texturaArvores);
void Placa(GLuint texturaPlaca);