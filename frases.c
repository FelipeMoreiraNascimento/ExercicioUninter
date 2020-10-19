#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char frase1 [50];
   

    printf("Adicione a  frase\n");
    gets(frase1);

    for (int i = 0; i < strlen(frase1); i++)
    {
        printf("%c", toupper(frase1[i]));
    }

    
    
   

   
}