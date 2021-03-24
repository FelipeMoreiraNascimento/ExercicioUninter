#include<stdio.h>
#include<stdlib.h>

int menu();
void InserirInicio(int num);
void Listar();
void InserirFim(int num);
void InserirMeio(int num, int posicao);
int Remover(int num);

struct ElementoDaLista_Simples
{
	int dado;
	ElementoDaLista_Simples* prox;
} *Head;

int main()
{
	int op, num, pos, c;
	while (1)
	{
		op = menu();
		switch (op)
		{
		case 1: //inserir no inicio da lista
			printf("Digite o numero desejado: ");
			scanf_s("%d", & num);
			InserirInicio(num);
			break;
		case 2: //inserir no fim da lista
			printf("Digite o numero desejado: ");
			scanf_s("%d", &num);
			InserirFim(num);
			break;
		case 3: //insrir no meio da lista
			printf("Digite o numero desejado: ");
			scanf_s("%i", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // limpeza do buffer
			printf("Digite a posicao desejado: ");
			scanf_s("%i", &pos);
			InserirMeio(num, pos);
			break;
		case 4: //remover da lista
			int res;
			printf("Digite o numero a ser removido: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			res = Remover(num);
			if (res == 1)
				printf("Numero removido.");
			else
				printf("Numero nao encontrado.");
			break;
			break;
		case 5: //mostrar toda a lista
			Listar();
			break;
		case 6:
			return 0;
		default:
			printf("Invalido\n");
		}
	}
	return 0;
}

int menu()
{
	int op, c;
	system("Cls");

	printf("1.Inserir no inicio da lista encadeada simples \n");
	printf("2.Inserir no fim da lista encadeada simples \n");
	printf("3.Inserir no meio da lista encadeada simples \n");
	printf("4.Remover da lista encadeada simples \n");
	printf("5.Mostrar a lista encadeada simples \n");
	printf("6.Sair \n");
	printf("Digite sua escolha: ");

	scanf_s("%i", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} // limpeza do buffer

	system("Cls");
	return op;

}

void InserirInicio(int num)
{
	ElementoDaLista_Simples* NovoElemento;
	//alocar o elemento na memoria
	NovoElemento = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	NovoElemento->dado = num;

	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		NovoElemento->prox = Head;
		Head = NovoElemento;
	}
}

void Listar()
{
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head;
	if (ElementoVarredura == NULL) {
		return;
	}
	while (ElementoVarredura != NULL) {
		printf("%d ", ElementoVarredura->dado);
		ElementoVarredura = ElementoVarredura->prox;
	}
	printf("\n");

	system("pause");
	return;
}

void InserirFim(int num)
{
	ElementoDaLista_Simples* NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	NovoElemento->dado = num;

	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		ElementoVarredura = Head;
		while (ElementoVarredura->prox != NULL)
			ElementoVarredura = ElementoVarredura->prox;

		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = NULL;
	}
}

void InserirMeio(int num, int posicao)
{
	ElementoDaLista_Simples* NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples* ElementoAuxiliar;
	ElementoAuxiliar = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	NovoElemento->dado = num;

	if (posicao == 0)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		ElementoVarredura = Head;
		for (int i = 0; i < posicao - 1; i++)
			ElementoVarredura = ElementoVarredura->prox;

		ElementoAuxiliar = ElementoVarredura->prox;
		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = ElementoAuxiliar;
	}
}

int Remover(int num)
{
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples* Anterior;
	Anterior = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head;
	while (ElementoVarredura != NULL) {
		if (ElementoVarredura->dado == num) {
			if (ElementoVarredura == Head) {
				Head = ElementoVarredura->prox;
				free(ElementoVarredura);
				return 1;
			}
			else {
				Anterior->prox = ElementoVarredura->prox;
				free(ElementoVarredura);
				return 1;
			}
		}
		else {
			Anterior = ElementoVarredura;
			ElementoVarredura = ElementoVarredura->prox;
		}
	}
	return 0;
}