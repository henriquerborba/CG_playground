/*********************************************************************
// Canvas para desenho, criada sobre a API OpenGL. Nao eh necessario conhecimentos de OpenGL para usar.
//  Autor: Cesar Tadeu Pozzer
//         05/2020
//
//  Pode ser utilizada para fazer desenhos, animacoes, e jogos simples.
//  Tem tratamento de mouse e teclado
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp
//
//  Versao 2.0
//
//  Instru��es:
//	  Para alterar a animacao, digite numeros entre 1 e 3
// *********************************************************************/

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"
#include "Vector2.h"


//variavel global para selecao do que sera exibido na canvas.
int opcao  = 50;
int screenWidth = 500, screenHeight = 500; //largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int mouseX, mouseY; //variaveis globais do mouse para poder exibir dentro da render().

Vector2 p1 = Vector2(0, 0);
Vector2 p2 = Vector2(0, 100);
Vector2 p3 = Vector2(100, 100);
Vector2 p4 = Vector2(100, 0);

void renderCurva(Vector2 p1, Vector2 p2, Vector2 p3)
{
    CV::color(255, 0, 0);
    for(float t = 0; t < 1; t+=0.001)
    {
            float xt = p1.x * (1 - t) * (1 - t) + p2.x * (2 * t * (1-t))  + p3.x * t * t;
            float yt = p1.y * (1 - t) * (1 - t) + p2.y * (2 * t * (1 - t)) + p3.y * t * t;
            CV::point(xt, yt);
    }

}

void renderCurva2(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4)
{
    CV::color(0, 0, 0);
    for(float t = 0; t < 1; t+= 0.001)
    {
        Vector2 p = p1 * pow(1 - t, 3) + p2 * 3 * t * pow(1 - t, 2) + p3 * pow(t, 2) * (1 - t) + p4 * pow(t, 3);

        CV::point(p);

    }

}

void blendingFunction()
{
    CV::color(0, 0, 255);
    float b0, b1, b2, b3;
    for(float t = 0; t < 1; t += 0.0001)
    {
        b0 = pow(1-t,3);
        b1 = 3 * t * pow(1-t, 2);
        b2 = 3 * pow(t, 2) * (1 - t);
        b3 = pow(t, 3);
        CV::point(t * 100,  b0 * 100);
        CV::point(t * 100,  b1 * 100);
        CV::point(t * 100,  b2 * 100);
        CV::point(t * 100,  b3 * 100);

    }



}




//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis globais
//Todos os comandos para desenho na canvas devem ser chamados dentro da render().
//Deve-se manter essa fun��o com poucas linhas de codigo.
void render()
{
   CV::text(20,500,"Programa Demo Canvas2D");
   blendingFunction();

}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
   printf("\nTecla: %d" , key);
   if( key < 200 )
   {
      opcao = key;
   }

}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   printf("\nLiberou: %d" , key);
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   mouseX = x; //guarda as coordenadas do mouse para exibir dentro da render()
   mouseY = y;
   p3.set(x, y);

   printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);
}

int main(void)
{


   CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
   CV::run();
}
