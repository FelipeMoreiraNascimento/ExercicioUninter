#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

char maiusculas [5][50];
char frase1 [5][50];

void adicionafrase()
{
    for (int i = 1; i <= 5 ; i++)
    {
        printf("Adicione a frase [%i] \n", i);
        gets(frase1[i]);
    }
}

void convertemaiusculas()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            maiusculas[i][j] = toupper(frase1[i][j]);
        }    
    }
}

void imprimepalavras()
{
     for (int i = 1; i <=5 ; i++)
    {
        printf("frase maiuscula [%i] = %s \n", i, maiusculas[i]);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    char nomearquivo[15];
    printf("Digite o nome do arquivo: ");
    gets(nomearquivo);
    strcat(nomearquivo, ".txt");

    adicionafrase();
    convertemaiusculas();
    
    printf("\n");

    FILE * f;
    f = fopen(nomearquivo, "w");

    for (int i = 1; i <= 5 ; i++)
    {
        fprintf(f, "\n%s", maiusculas[i]);
    }
    fclose(f);

    system("cls");

    imprimepalavras();
    
}

