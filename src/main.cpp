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
#include <vector>

#include "gl_canvas2d.h"
#include "Vector2.h"

using namespace std;

// variavel global para selecao do que sera exibido na canvas.
int opcao = 50;
int screenWidth = 500, screenHeight = 500; // largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int mouseX, mouseY;                        // variaveis globais do mouse para poder exibir dentro da render().

vector<Vector2> points;

int factorial(int number)
{
    int fact = 1;
    for (int i = 1; i <= number; i++)
    {
        fact *= i;
    }

    return fact;
}

// função que desenha uma curva de bezier dado um vetor de pontos.
void bezierCurve(vector<Vector2> pontos)
{
    CV::color(0, 0, 0);
    int n = pontos.size() - 1;
    int nFatorial = factorial(n);
    for (float t = 0; t < 1; t += 0.001)
    {
        Vector2 p = Vector2(0, 0);
        for (int i = 0; i <= n; i++)
        {
            p += pontos[i] * pow(t, i) * pow(1 - t, n - i) * (nFatorial / (factorial(i) * factorial(n - i)));
        }
        CV::point(p);
    }
}

void blendingFunction()
{
    CV::color(0, 0, 255);
    float b0, b1, b2, b3;
    for (float t = 0; t < 1; t += 0.0001)
    {
        b0 = pow(1 - t, 3);
        b1 = 3 * t * pow(1 - t, 2);
        b2 = 3 * pow(t, 2) * (1 - t);
        b3 = pow(t, 3);
        CV::point(t * 100, b0 * 100);
        CV::point(t * 100, b1 * 100);
        CV::point(t * 100, b2 * 100);
        CV::point(t * 100, b3 * 100);
    }
}

// funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis globais
// Todos os comandos para desenho na canvas devem ser chamados dentro da render().
// Deve-se manter essa fun��o com poucas linhas de codigo.
void render()
{
    CV::text(20, 500, "Programa Demo Canvas2D");
    bezierCurve(points);
}

// funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
    printf("\nTecla: %d", key);
    if (key < 200)
    {
        opcao = key;
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

    if (button == 0 && state == 1)
    {
        points.push_back(Vector2(x, y));
    }

    printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction, x, y);
}

int main(void)
{

    CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
    CV::run();
}
