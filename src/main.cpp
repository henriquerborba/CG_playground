#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "matrix/matrix.h"
#include "canvas/gl_canvas2d.h"
#include "Vector2.h"

using namespace std;

int screenWidth = 800, screenHeight = 800; // largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int mouseX, mouseY;                        // variaveis globais do mouse para poder exibir dentro da render().

vector<Vector2> squarePoints = {
    Vector2(100, 100),
    Vector2(100, 200),
    Vector2(200, 200),
    Vector2(200, 100)};

vector<Vector2> squarePoints2 = {
    Vector2(100, 100),
    Vector2(100, 200),
    Vector2(200, 200),
    Vector2(200, 100)};

void drawPoligon(vector<Vector2> points)
{
   for (int i = 0; i < points.size(); i++)
   {
      CV::line(points[i], points[i == points.size() - 1 ? 0 : i + 1]);
   }
}

void translate(float x, float y)
{
   Matrix m = Matrix::translate(x, y);
   for (int i = 0; i < squarePoints.size(); i++)
   {
      squarePoints[i] = m * squarePoints[i];
   }
}

// funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis globais
// Todos os comandos para desenho na canvas devem ser chamados dentro da render().
// Deve-se manter essa fun��o com poucas linhas de codigo.
void render()
{
   // translada o eixo da tela para o centro da tela
   CV::translate(screenWidth / 2, screenHeight / 2);
   // desenha os eixos x e y
   CV::line(0, -screenWidth / 2, 0, screenWidth / 2);
   CV::line(-screenHeight / 2, 0, screenHeight / 2, 0);
   CV::color(0);

   drawPoligon(squarePoints);
   drawPoligon(squarePoints2);
}

// funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
   printf("\nTecla: %d", key);
   switch (key)
   {
   // seta para esquerda
   case 200:
      translate(-100, -100);
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

   CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
   CV::run();
}
