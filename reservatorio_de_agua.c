#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i, qtdMax, calc = 0;
	int chuvaMeses[12]; //variavel para calcular o
	int mmchuvaMes[12]; //quantidade de agua mensal
	int mmResevatorioGasto[12]; //agua do reservatorio consumida
	int reservatorioRestante[12]; // variavel do 
	
	char meses[11][4]; //declaraçao dos meses para exibir em seguida no FOR
	strcpy(meses[0], "Jan");
	strcpy(meses[1], "Fev");
	strcpy(meses[2], "Mar");
	strcpy(meses[3], "Abr");
	strcpy(meses[4], "Mai");
	strcpy(meses[5], "Jun");
	strcpy(meses[6], "Jul");
	strcpy(meses[7], "Ago");
	strcpy(meses[8], "Set");
	strcpy(meses[9], "Out");
	strcpy(meses[10], "Nov");
	strcpy(meses[11], "Dez");


	printf("Informe a Quantidade maxima do reservatorio: ");
	scanf_s("%i", &qtdMax);

	printf("Informe a quantidade de chuva em cada mes\n");
	for (i = 0; i < 12; i++)
	{
		printf("%s ", meses[i]);
		scanf_s("%i", &mmchuvaMes[i]);
		chuvaMeses[i] = mmchuvaMes[i];
		calc += chuvaMeses[i];
	}
	
	if (calc > qtdMax) // condicional reservatorio cheio
	{
		printf("Reservatorio cheio!\n");
		system("pause");
		return 0;
	}

	calc = 0;
	printf("Informe a quantidade de agua gasta por mes\n");
	for (i = 0; i < 12; i++)
	{
		printf("%s ", meses[i]);
		scanf_s("%i", &mmResevatorioGasto[i]);
		chuvaMeses[i] -= mmResevatorioGasto[i];
		calc += chuvaMeses[i];
	}

	if (calc < 0)
	{
		printf("Reservatorio Vazio!!\n");
		system("pause");
		return 0;
	}

	printf("Quantidade de agua restante: \n");
	for (i = 0; i < 12; i++)
	{
		printf("%s ", meses[i]);
		printf("%i mm\n", chuvaMeses[i]);
	}

	system("pause");
	return 0;
}