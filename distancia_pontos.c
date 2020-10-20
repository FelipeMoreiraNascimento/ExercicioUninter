#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int opcao;

struct ponto2d //criação da struct e suas variaveis
{
    float x1, x2, y1, y2, distancia; 
};
struct ponto2d ponto_inicial, resultado, ponto_final; //criação das estruturas

void menu()
{
    printf("[1]Digitar os valores do primeiro ponto\n");
    printf("[2]Digitar os valores do segundo ponto\n");
    printf("[3]Mostrar a distancia entre os pontos\n");
    printf("[4]Sair\n\n");
}

void escolha()
{
    printf("Selecione uma opcao: ");
    scanf_s("%i", &opcao);

    while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4) //valida uma opcao correta, caso contrario usuario fica preso no loop
    {
        printf("Selecione uma opcao valida!!!\n");
        printf("Selecione uma opcao: ");
        scanf_s("%i", &opcao);
    }

    while (opcao != 4) //validação de preenchimento dos pontos, e definição da resposta
    {
        if (opcao == 1)
        {
            printf("Digite o valor do ponto A1: ");
            scanf_s("%f", &ponto_inicial.x1);
            printf("Digite o valor do ponto A2 ");
            scanf_s("%f", &ponto_inicial.y1);
        }
        if (opcao == 2)
        {
            printf("Digite o valor do ponto B1: ");
            scanf_s("%f", &ponto_final.x2);
            printf("Digite o valor do ponto B2: ");
            scanf_s("%f", &ponto_final.y2);
        }
        if (opcao == 3)
        {
            resultado.distancia = sqrt((pow((ponto_inicial.x1 - ponto_final.x2), 2)) + pow((ponto_inicial.y1 - ponto_final.y2), 2));
            printf("distancia = %.3f\n", resultado.distancia);
        }
        printf("Selecione uma opcao: ");
        scanf_s("%i", &opcao); 
    }
}
int main()
{
    menu(); //menu de opcoes
    escolha(); //chama a funcão com toda estrutura de codigo das validações
}