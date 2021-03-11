#include<stdio.h>
#include<stdlib.h>

int peao = 0, bispo = 0, torre = 0, rei = 0, rainha = 0, cavalo = 0;
int escolha, linha, coluna, linhadestino, colunadestino, peca = 0;
#define LINHAS 8
#define COLUNAS 8

void menu() //menu de opcoes
{
    printf("**********   Jogo Xadrez   **********\n");
    printf("1 - Peoes\n");
    printf("2 - Cavalos\n");
    printf("3 - Torres\n");
    printf("0 - Ausencia de pecas\n");
    printf("5 - Reis\n");
    printf("6 - Rainhas\n");
    printf("4 - Bispos\n\n");
}

void contapecas(int tabuleiro[LINHAS][COLUNAS]) //contabiliza a quantidade de peças que tem no tabuleiro
{
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            if (tabuleiro[i][j] == 1)
            {
                peao++;
            }
            if (tabuleiro[i][j] == 2)
            {
                cavalo++;
            }
            if (tabuleiro[i][j] == 3)
            {
                torre++;
            }
            if (tabuleiro[i][j] == 4)
            {
                bispo++;
            }
            if (tabuleiro[i][j] == 5)
            {
                rei++;
            }
            if (tabuleiro[i][j] == 6)
            {
                rainha++;
            }
        }
    }
}

void zeraposicao(int linha, int coluna, int tabuleiro[LINHAS][LINHAS]) //zera a posicao da casa quando uma peça é deslocada
{
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            tabuleiro[linha][coluna] = 0;
        }
    }
    printf("\n");
}

void exibequantidadedepecas() //mostra a quantidade de peças
{
    printf("\nQuantidade de Peoes = %i\n", peao);
    printf("Quantidade de Cavalos = %i\n", cavalo);
    printf("Quantidade de Bispos = %i\n", bispo);
    printf("Quantidade de Torres = %i\n", torre);
    printf("Quantidade de Rei = %i\n", rei);
    printf("Quantidade de Rainha = %i\n", rainha);
}

void digitapeca() //função para o usuario digitar a peça que deseja mover
{
    printf("Qual peca deseja movimentar? digite a linha e a coluna dessa peca! ");
    scanf_s("%i %i", &linha, &coluna);
    
    printf("Para onde deseja movimentar? digite a linha e a coluna de destino! ");
    scanf_s("%i %i", &linhadestino, &colunadestino);
}

void exibetabuleiro(int tabuleiro[LINHAS][COLUNAS]) //exibe na taela o tabuleiro
{
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            printf("%i \t", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void validanovaposicaodapeca(int tabuleiro[LINHAS][COLUNAS]) //faz o cauculo na matriz para o deslocamento da peça
{
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            peca = tabuleiro[linha][coluna];
            tabuleiro[linhadestino][colunadestino] = peca;
        }
    }
}

int main()
{
    
    int tabuleiro[8][8] = {
                          {1, 3, 0, 5, 4, 0, 2, 1},
                          {1, 0, 1, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 1, 0, 6, 0},
                          {1, 0, 0, 1, 1, 0, 0, 1},
                          {0, 1, 0, 4, 0, 0, 1 ,0},
                          {0, 0, 3, 1, 0, 0, 1, 1},
                          {1, 0, 6, 6, 0, 0, 1, 0},
                          {1, 0, 5, 0, 1, 1, 0, 6},
    };

    menu();
    exibetabuleiro(tabuleiro);
    digitapeca();
    validanovaposicaodapeca(tabuleiro);
    zeraposicao(linha, coluna, tabuleiro);
    exibetabuleiro(tabuleiro);
    contapecas(tabuleiro);
    exibequantidadedepecas();

    printf("Deseja mover outra peca? Sim(8) Nao(9)\n");
    scanf_s("%i", &escolha);
    
    while (escolha != 9)
    {
        digitapeca();
        validanovaposicaodapeca(tabuleiro);
        zeraposicao(linha, coluna, tabuleiro);
        exibetabuleiro(tabuleiro);

        printf("Deseja mover outra peca? Sim(8) Nao(9)\n");
        scanf_s("%i", &escolha);
    }

    contapecas(tabuleiro);
    exibequantidadedepecas();

    return 0;
}