#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

char nome[50];
float salario;
float aliquota = 0;
float imposto = 0;
float salariofinal = 0;

void menu()
{
    printf("Base de calculo mensal em R$ | Aliquota\n");
    printf("Ate 1.637,11                 | -\n");
    printf("De 1.637,12 ate 2453,50      | 7,5\n");
    printf("De 2.453,51 ate 3271,38      | 15,0\n");
    printf("De 3.271,39 ate 4.087,65     | 22,5\n");
    printf("Acima de 4.087,65            | 27,5\n\n");
}

void entradadedados()
{
    printf("Digite seu nome: ");
    scanf("%s", &nome);
    printf("Digite o seu salario: ");
    scanf("%f", &salario);
    printf("\n\n");
}

void validaimposto()
{
    if (salario <= 1637.11)
    {
        aliquota = 0.0;
        salariofinal = salario;

    }else if (salario >= 1637.12 && salario <= 2453.50)
    {
        aliquota = 7.5;
        imposto = ((salario *aliquota)/100);
        salariofinal = salario - imposto;
    }else if (salario >= 2453.51 && salario <= 3271.38)
    {
        aliquota = 15.0;
        imposto = ((salario * aliquota)/100);
        salariofinal = salario - imposto;
    }else if (salario >= 3271.39 && salario <= 4087.65)
    {
        aliquota = 22.5;
        imposto = ((salario * aliquota)/100);
        salariofinal = salario - imposto;
    }else
    {
        aliquota = 27.5;
        imposto = ((salario * aliquota)/100);
        salariofinal = salario - imposto;
    }
}

void imprimedados()
{
    printf("Nome: %s \n", nome);
    printf("Salario: %.2f \n", salario);
    printf("Aliquota: %.1f \n", aliquota);
    printf("Imposto: %.2f \n", imposto);
    printf("Salario Final: %.2f \n\n", salariofinal);
}

int main()
{
    menu(); //chama a função menu, com os dados dos impostos
    entradadedados(); //chama a função entrada de dados, para receber nome e salario
    validaimposto(); //chama a função que valida o imposto, aliquota e salario final
    imprimedados(); //chama a função que exibe o salario, nome, aliquota, imposto e salario final
}