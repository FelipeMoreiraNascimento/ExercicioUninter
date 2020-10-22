#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

char maiusculas [5][50]; //vetor para salvar as frases convertidas para letra maiuscula
char frases [5][50]; //vetor para adicionar as frases

void adicionafrases() //função que adiciona as frases digitadas
{
    for (int i = 1; i <= 5 ; i++)
    {
        printf("Adicione a frase [%i] \n", i);
        gets(frases[i]);
    }
}

void converteparamaiusculas() //função que converte para letras maiusculas, foi preciso utilizar loop
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            maiusculas[i][j] = toupper(frases[i][j]);
        }    
    }
}

void imprimepalavras() //função para imprimir as palavras
{
     for (int i = 1; i <=5 ; i++)
    {
        printf("frase maiuscula [%i] = %s \n", i, maiusculas[i]);
    }
}

void gravapalavrasnoarquivo(char arquivo[15]) //função que grava as palavras no arquivo, utilizando w como tipo de gravação, foi preciso usar um loop
{
    FILE * f;
    f = fopen(arquivo, "w");

    for (int i = 1; i <= 5 ; i++)
    {
        fprintf(f, "\n%s", maiusculas[i]);
    }
    fclose(f);
}

void crianomedoarquivo(char nome[15]) //função para criar nome do arquivo, solicitado ao usuario
{
    printf("Digite o nome do arquivo: ");
    gets(nome);
    strcat(nome, ".txt");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char nomearquivo[15];
    
    crianomedoarquivo(nomearquivo);
    adicionafrases();
    converteparamaiusculas();
    printf("\n");
    gravapalavrasnoarquivo(nomearquivo);
    system("cls");
    imprimepalavras();
    
    return 0;
}

