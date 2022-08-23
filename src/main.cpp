#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

#include "canvas/gl_canvas2d.h"
#include "Vector.h"

#define KD 1

using namespace std;

int screenWidth = 800, screenHeight = 800; // largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int mouseX, mouseY;                        // variaveis globais do mouse para poder exibir dentro da render().
float ang = 0;
int cont = 0;

// funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis globais
// Todos os comandos para desenho na canvas devem ser chamados dentro da render().
// Deve-se manter essa fun��o com poucas linhas de codigo.

Vector normal, light, viewer;

float ilumina_difusa(Vector pos, int flag)
{
   float shift_x = cos(pos.x / 2.0);

   Vector tmp = light - pos;
   tmp.normalize();

   // bump mapping
   Vector bump = normal;
   bump.x += shift_x;
   bump.normalize();

   if (flag == 1)
      return KD * bump.dot(tmp);
   else
      return KD * normal.dot(tmp);
}

void render()
{
   // cont++;
   // int flag = 0;
   // if (cont < 100)
   //    flag = 1;
   // else if (cont < 200)
   //    flag = 0;
   // else
   //    cont = 0;

   for (int x = 100; x < 300; x++)
      for (int z = 100; z < 300; z++)
      {
         float cor = ilumina_difusa(Vector(x, 0, z), 1);
         CV::color(cor, cor, cor);
         CV::point(x, z);
      }

   // // move a fonte luminosa
   float x, z;
   x = 100 * cos(ang);
   z = 100 * sin(ang);
   light.x = x + 200;
   light.z = z + 200;
   ang += 0.03;
   std::cout << "x:" << light.x << " z:" << light.z << std::endl;
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
}

int main(void)
{
   normal.x = 0;
   normal.y = 1;
   normal.z = 0;

   light.x = 200;
   light.y = 100;
   light.z = 200;

   CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
   CV::run();
}
