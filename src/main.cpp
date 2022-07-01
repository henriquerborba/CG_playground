#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "canvas/gl_canvas2d.h"
#include "Matrix/matrix.h"
#include "Vector2.h"
#include "Vector3.h"

using namespace std;

int screenWidth = 800, screenHeight = 800; // largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int mouseX, mouseY;                        // variaveis globais do mouse para poder exibir dentro da render().

vector<Vector3> cubo = {
    Vector3(-100, -100, -100), // 0
    Vector3(-100, 100, -100),  // 1
    Vector3(100, -100, -100),  // 2
    Vector3(100, 100, -100),   // 3
    Vector3(100, -100, 100),   // 4
    Vector3(100, 100, 100),    // 5
    Vector3(-100, -100, 100),  // 6
    Vector3(-100, 100, 100)    // 7
};

Vector2 projeta(Vector3 v, float d)
{
   Vector2 p;
   p.x = (v.x * d) / v.z;
   p.y = (v.y * d) / v.z;
   return p;
}

void desenha(vector<Vector2> vertices)
{
   for (int i = 0; i < vertices.size(); i++)
   {
      auto v1 = vertices[i];
      auto v2 = vertices[i + 1 < vertices.size() ? i + 1 : (i + 1) % vertices.size()];
      auto v3 = vertices[i + 2 < vertices.size() ? i + 2 : (i + 2) % vertices.size()];
      CV::line(v1, v2);
      CV::line(v2, v3);
      CV::line(v3, v1);
   }
}

float ang = 0;

// funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis globais
// Todos os comandos para desenho na canvas devem ser chamados dentro da render().
// Deve-se manter essa fun��o com poucas linhas de codigo.
void render()
{
   CV::translate(screenWidth / 2, screenHeight / 2);
   CV::color(0, 0, 0);
   Vector3 p;
   vector<Vector2> saida(8);
   for (int i = 0; i < 8; i++)
   {
      p = cubo[i];
      p = Matrix::rotateY(ang) * p;
      p = Matrix::translate3d(0, 0, 300) * p;
      saida[i] = projeta(p, 300);
   }
   desenha(saida);
   ang += 0.01;
}

// funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
   printf("\nTecla: %d", key);
   switch (key)
   {
   // seta para esquerda
   case 200:
      break;
   // seta para cima
   case 201:
      break;
   // seta para direita
   case 202:
      break;
   // seta para baixo
   case 203:
      break;
   }
}

// funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   printf("\nLiberou: %d", key);
}

// funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   mouseX = x; // guarda as coordenadas do mouse para exibir dentro da render()
   mouseY = y;

   printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction, x, y);
}

int main(void)
{

   CV::init(&screenWidth, &screenHeight, "Playground");
   CV::run();
}
