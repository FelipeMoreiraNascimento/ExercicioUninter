#include<stdlib.h>
#include<stdio.h>
#include<math.h>


void calc_hexa(float l, float* area, float* perimetro)
{
    *area = (3 * ((pow(l, 2)) * (sqrt(3)))) / 2;
    *perimetro = 6 * l;
}

int main()
{
    float l;
    float area;
    float perimetro;

    printf("Digite o lado do Hexagono: ");
    scanf("%f", &l);

    while (l < 0) //valida para ver se o lado é positivo
    {
        printf("Valor invalido, digite um numero positivo: ");
        scanf("%f", &l);
    }
   
    calc_hexa(l, &area, &perimetro); //chama a função, chamando a area e o perimetro com o incremento &

    printf("Area = %.2f\n", area);
    printf("Perimetro = %.2f\n", perimetro);

}