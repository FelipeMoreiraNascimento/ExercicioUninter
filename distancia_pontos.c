#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main() 
{
    struct ponto2d
    {
    float x1, x2, y1, y2,distancia;
    
    };
    struct ponto2d ponto_inicial;
    struct ponto2d ponto_final;
    struct ponto2d resultado;

    printf("\n[1]Digitar os valores do primeiro ponto\n");
    scanf("%f", ponto_inicial.x1);
    scanf("%f", ponto_inicial.y1);
    printf("[2]Digitar os valores do segundo ponto\n");
    scanf("%f", ponto_final.x2);
    scanf("%f", ponto_final.y2);
    printf("[3]Mostrar a distancia entre os pontos\n");
    
    resultado.distancia = sqrt((pow((ponto_inicial.x1 - ponto_final.x2),2)) + pow((ponto_inicial.y1-ponto_final.y2),2));
 
    printf("distancia = %.2f", resultado.distancia);
}