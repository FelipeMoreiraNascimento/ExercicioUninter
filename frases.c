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


        FILE * f;

        f = fopen("frases.txt", "r+");
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);

        fprintf(f, "\n%s", frase1);

        fclose(f);
    

    
    
   

   
}