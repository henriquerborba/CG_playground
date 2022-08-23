#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "canvas/gl_canvas2d.h"
#include "Vector2.h"

using namespace std;

int screenWidth = 800, screenHeight = 800; // largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int mouseX, mouseY;                        // variaveis globais do mouse para poder exibir dentro da render().
bool direita = true;
int x1 = 0, x2 = 100;
int d = 20;

// funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis globais
// Todos os comandos para desenho na canvas devem ser chamados dentro da render().
// Deve-se manter essa fun��o com poucas linhas de codigo.
void render()
{
   CV::color(0);
   if (direita)
   {

      CV::line(x1, screenHeight / 2, x2, screenHeight / 2);
      CV::line(x2 - 10, screenHeight / 2 + d, x2, screenHeight / 2);
      CV::line(x2 - 10, screenHeight / 2 - d, x2, screenHeight / 2);
   }
   else
   {
      CV::line(x2, screenHeight / 2, x1, screenHeight / 2);
      CV::line(x1 + 10, screenHeight / 2 + d, x1, screenHeight / 2);
      CV::line(x1 + 10, screenHeight / 2 - d, x1, screenHeight / 2);
   }
}

// funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
   printf("\nTecla: %d", key);
   switch (key)
   {
   // seta para esquerda
   case 200:
      direita = false;
      x1--;
      x2--;
      break;
   // seta para cima
   case 201:
      break;
   // seta para direita
   case 202:
      direita = true;
      x1++;
      x2++;
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

   CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
   CV::run();
}
