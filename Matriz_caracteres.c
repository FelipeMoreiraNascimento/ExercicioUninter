#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

void PrimeiraLetra();

char matriz[10][10];
int i, j, c;
float pletra, result;
int main()
{
	int linhas, colunas;

	printf("Digite o numero de linhas: "); //define as linhas
	scanf_s("%i", &linhas);
	while ((c = getchar()) != '\n' && c != EOF) {} //limpa buffer de techado
	while ((linhas < 1) || (linhas > 10)) //validaçaõ caso o usuario digite valor inválido
	{
		printf("Tamanho invalido!!!!\n");
		printf("Digite o numero de linhas: ");
		scanf_s("%i", &linhas);
		while ((c = getchar()) != '\n' && c != EOF) {} //limpa buffer de techado
	}

	printf("Digite o numero de colunas: "); //define as colunas
	scanf_s("%i", &colunas);
	while ((c = getchar()) != '\n' && c != EOF) {} //limpa buffer de techado
	while ((colunas < 1) || (colunas > 10)) //validaçaõ caso o usuario digite valor inválido
	{
		printf("Tamanho invalido!!!!\n");
		printf("Digite o numero de colunas: ");
		scanf_s("%i", &colunas);
		while ((c = getchar()) != '\n' && c != EOF) {}//limpa buffer de techado
	}


	for (i = 0; i < linhas; i++) //coleta os caracteres
	{
		for (j = 0; j < colunas; j++)
		{
			printf("Digite o caracter [%d] [%d]: ", i, j);
			scanf_s("%c", &matriz[i][j]);
			while ((c = getchar()) != '\n' && c != EOF) {} //limpa buffer de techado
		}
	}

	for (i = 0; i < linhas; i++) //exibe os caracteres
	{
		for (j = 0; j < colunas; j++)
		{
			printf("%c\t", matriz[i][j]);
		}
		printf("\n");
	}

	PrimeiraLetra(); //retorna o calculo da letra maiuscula/minuscula
	return 0;
}

void PrimeiraLetra()
{
	pletra = matriz[0][0];
	if (isupper(pletra)) //condicional para definir se é maiuscula ou minuscula
	{
		
		printf("Eh maiuscula, valor: %.2f", pletra / 10);
	}
	else
	{
		printf("Nao eh maiuscula, valor: %.2f ", pletra * 2);
	}
}
