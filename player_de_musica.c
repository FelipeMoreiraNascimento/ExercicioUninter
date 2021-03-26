#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int menu();
void ExibirMusicas(); //função que exibe a playlist de musicas
void AdicionarMusicas(); //função que adiciona as musicas
void LimparMusicas(); //fução que limpa a playlist
void AdicionarFinal(); //funçaõ que adiciona musicas no final da playlist

struct Player_De_Musica 
{
    char dado1[20]; //nome do artista
    char dado2[20]; //nome da musica
    float dado3;  //tempo da musica
    struct Player_De_Musica* prox;

}*Head, *Limpeza; //variavel head do inicio da lista e varial limpeza, usada na função de limpeza da lista

int main()
{
    int op, c;

    while (1)
    {
        op = menu(); //chama a função menu, com as informações na tela e opções de escolha
        switch (op)
        {
        case 1:
            AdicionarMusicas(); //chamada de função
            system("pause");
            break;
        case 2:
            AdicionarFinal(); //chamada de função
            system("pause");
            break;
        case 3:
            ExibirMusicas(); //chamada de função
            system("pause");
            break;
        case 4:
            LimparMusicas(); //chamada de função
            system("pause");
            break;
        case 5:
            return 0;
            break;
        default:
            printf("opcao incorreta\n");
            system("pause");
            break;
        }
    }

    
    return 0;
}


int menu() 
{
    int opcao, c;
    system("Cls");
    printf("**********Tocador de Musica**********\n");
    printf("[1] Inserir musicas no inicio da playlist\n");
    printf("[2] Inserir musicas no final da playlist\n");
    printf("[3] Exibir playlist\n");
    printf("[4] Limpar playlist\n");
    printf("[5] Sair\n");
    scanf_s("%d", &opcao);
    while ((c = getchar()) != '\n' && c != EOF) {}  //limpeza de buffer do teclado
    system("Cls");
    return opcao;
}

void ExibirMusicas()
{
    struct Player_De_Musica* Listagem = (struct Player_De_Musica*)malloc(sizeof(struct Player_De_Musica)); //foi preciso criar uma variavel auxiliar para a estrutura de dados heterogenea
    Listagem = Head; //listagem recebe o primeiro elemento da lista

    if (Head == NULL)
    {
        printf("A lista esta vazia!!!\n");
    }
    else
    {
        while (Listagem != NULL)
        {
            printf("%s", Listagem->dado1);
            printf("%s", Listagem->dado2);
            printf("%.2f\n\n", Listagem->dado3);
            Listagem = Listagem->prox;
        }
    }
}

void AdicionarMusicas()
{  
    int c;

    struct Player_De_Musica* NovoElemento; //novo elemento auxiliar para exibir as musicas
    NovoElemento = (struct Player_De_Musica*)malloc(sizeof(struct Player_De_Musica));

    printf("Digite o nome do artista: "); //entrada de dados
    fgets(NovoElemento->dado1, 19, stdin);
   
    printf("Digite o nome da musica: "); //entrada de dados
    fgets(NovoElemento->dado2, 19, stdin);

    printf("Digite a Duracao da musica: "); //entrada de dados
    scanf_s("%f", &NovoElemento->dado3);
    while ((c = getchar()) != '\n' && c != EOF) {} //limpeza de buffer

    NovoElemento->prox = NULL; //esvazia o proximo espaço da lista

    if (Head == NULL)
    {
        Head = NovoElemento;
    }
    else
    {
        NovoElemento->prox = Head;
        Head = NovoElemento;
    }
}

void LimparMusicas()
{
    char escolha;

    if (Head == NULL)
    {
        printf("A playlist esta vazia!\n");
    }
    else
    {
        printf("Tem certeza que deseja esvaziar a playlist? (s/n): ");
        escolha = getchar();
        if (escolha == 's' || escolha == 'S')
        {
            while (Head != NULL)
            {
                Limpeza = Head;
                Head = Head->prox;
                free(Limpeza); //libera espaço na memoria
            }
            printf("Playlist esvaziada com sucesso! \n");
        }
        else
        {
            printf("Playlist não esvaziada!\n");
        }
    }
}

void AdicionarFinal()
{
    int c;

    struct Player_De_Musica* NovoElemento; //novo elemento auxiliar para limpeza da playlist
    NovoElemento = (struct Player_De_Musica*)malloc(sizeof(struct Player_De_Musica));
    struct Player_De_Musica* ElementoVarredura;//novo elementovarredura auxiliar para limpeza da playlist
    ElementoVarredura = (struct Player_De_Musica*)malloc(sizeof(struct Player_De_Musica));

    printf("Digite o nome do artista: "); //entrada de dados
    fgets(NovoElemento->dado1, 19, stdin);

    printf("Digite o nome da musica: "); //entrada de dados
    fgets(NovoElemento->dado2, 19, stdin);

    printf("Digite a Duracao da musica: "); //entrada de dados
    scanf_s("%f", &NovoElemento->dado3);
    while ((c = getchar()) != '\n' && c != EOF) {} //limpeza de buffer

    if (Head == NULL)
    {
        Head = NovoElemento;
        Head->prox = NULL;
    }
    else
    {
        ElementoVarredura = Head;
        while (ElementoVarredura->prox != NULL)
        {
            ElementoVarredura = ElementoVarredura->prox;
        }
        ElementoVarredura->prox = NovoElemento;
        NovoElemento->prox = NULL;
    }
}
