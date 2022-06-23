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

// 1.	Elabore um algoritmo para fazer um veículo, representado por uma seta com 3 linhas (figura), andar no espaço 2D com o uso de setas direcionais (direita e esquerda).

vector<Vector2> seta = {Vector2(0, 0), Vector2(200, 200), Vector2(200, 150), Vector2(150, 200)};

void renderseta()
{
   CV::line(seta[0], seta[1]);
   CV::line(seta[1], seta[3]);
   CV::line(seta[1], seta[2]);
}
// funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis globais
// Todos os comandos para desenho na canvas devem ser chamados dentro da render().
// Deve-se manter essa fun��o com poucas linhas de codigo.
void render()
{
   CV::text(20, 500, "Programa Demo Canvas2D");
   CV::color(0, 0, 0);
   renderseta();
}

// funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
   printf("\nTecla: %d", key);
   switch (key)
   {
   case 200:
      for (int i = 0; i < seta.size(); i++)
      {
         seta[i].x -= 1;
      }
      break;
   case 201:
      for (int i = 0; i < seta.size(); i++)
      {
         seta[i].y += 1;
      }
      break;
   case 202:
      for (int i = 0; i < seta.size(); i++)
      {
         seta[i].x += 1;
      }
      break;
   case 203:
      for (int i = 0; i < seta.size(); i++)
      {
         seta[i].y -= 1;
      }
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
