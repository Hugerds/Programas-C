/*Defina um registro empregado para guardar os dados 
(nome, sobrenome, data de nascimento, RG, data de admissão, salário) 
de um empregado de sua empresa. Defina um vetor de empregados para armazenar 
todos os empregados de sua empresa.*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

#define max 40

typedef struct {
	int dia;
	int mes;
	int ano;
} data;

struct empEmpresa {
	char nome[20];
	char sobrenome[20];
	data nasc, ads;
	int rg;
	float salario;
} Empregados[max];

void leituraStruct(tam) {
	int a;
	for (a=0;a<tam;a++) {
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf ("Digite o nome do %d funcionario\n", a+1);
		fflush(stdin);
		gets(Empregados[a].nome);
		printf ("Digite o sobrenome do %s\n", Empregados[a].nome);
		fflush(stdin);
		gets(Empregados[a].sobrenome);
		printf ("Digite a data de nascimento do %s\n", Empregados[a].nome);
		fflush(stdin);
		scanf("%d %d %d", &Empregados[a].nasc.dia,&Empregados[a].nasc.mes,&Empregados[a].nasc.ano);
		printf ("Digite o RG do %s\n", Empregados[a].nome);
		fflush(stdin);
		scanf("%d", &Empregados[a].rg);
		printf ("Digite a data de admissao do %s\n", Empregados[a].nome);
		fflush(stdin);
		scanf("%d %d %d", &Empregados[a].ads.dia,&Empregados[a].ads.mes,&Empregados[a].ads.ano);
		printf ("Digite o salario do %s\n", Empregados[a].nome);
		scanf ("%f", &Empregados[a].salario);
	}
}

void mostraStruct(tam) {
	int a;
	system("cls");
	for (a=0;a<tam;a++) {
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("Nome do empregado: %s", Empregados[a].nome); printf (" %s\n", Empregados[a].sobrenome);
		printf ("Data de nascimento: %d/%d/%d\n", Empregados[a].nasc.dia,Empregados[a].nasc.mes,Empregados[a].nasc.ano);
		printf ("RG: %d\n", Empregados[a].rg); 
		printf ("Data de admissao: %d/%d/%d\n", Empregados[a].ads.dia,Empregados[a].ads.mes,Empregados[a].ads.ano);
		printf ("Salario: %.3f\n", Empregados[a].salario);
	}
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

int main () {
	int tam;
	do {
		printf ("Quantos funcionarios tem sua empresa?(MAX 40)\nSua opcao: ");
		scanf ("%d", &tam);
	} while(tam<=0 || tam >40);
	leituraStruct(tam);
	mostraStruct(tam);
	system("pause");
	
}
