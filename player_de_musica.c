#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int menu();
void ExibirMusicas();
void AdicionarMusicas();
void LimparMusicas();
void AdicionarFinal();

struct Player_De_Musica
{
    char dado1[20]; //nome do artista
    char dado2[20]; //nome da musica
    float dado3;  //tempo da musica
    struct Player_De_Musica* prox;

}*Head, *Limpeza;

int main()
{
    int op, c;

    while (1)
    {
        op = menu();
        switch (op)
        {
        case 1:
            AdicionarMusicas();
            system("pause");
            break;
        case 2:
            AdicionarFinal();
            system("pause");
            break;
        case 3:
            ExibirMusicas();
            system("pause");
            break;
        case 4:
            LimparMusicas();
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
    while ((c = getchar()) != '\n' && c != EOF) {}
    system("Cls");
    return opcao;
}

void ExibirMusicas()
{
    struct Player_De_Musica* Listagem = (struct Player_De_Musica*)malloc(sizeof(struct Player_De_Musica));
    Listagem = Head;

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

    struct Player_De_Musica* NovoElemento;
    NovoElemento = (struct Player_De_Musica*)malloc(sizeof(struct Player_De_Musica));

    printf("Digite o nome do artista: ");
    fgets(NovoElemento->dado1, 19, stdin);
   
    printf("Digite o nome da musica: ");
    fgets(NovoElemento->dado2, 19, stdin);

    printf("Digite a Duracao da musica: ");
    scanf_s("%f", &NovoElemento->dado3);
    while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer

    NovoElemento->prox = NULL;

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

    struct Player_De_Musica* NovoElemento;
    NovoElemento = (struct Player_De_Musica*)malloc(sizeof(struct Player_De_Musica));
    struct Player_De_Musica* ElementoVarredura;
    ElementoVarredura = (struct Player_De_Musica*)malloc(sizeof(struct Player_De_Musica));

    printf("Digite o nome do artista: ");
    fgets(NovoElemento->dado1, 19, stdin);

    printf("Digite o nome da musica: ");
    fgets(NovoElemento->dado2, 19, stdin);

    printf("Digite a Duracao da musica: ");
    scanf_s("%f", &NovoElemento->dado3);
    while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer

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
