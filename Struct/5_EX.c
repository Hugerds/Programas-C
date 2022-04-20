#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAX 100

typedef struct {
	int dia;
	int mes;
	int ano;
} data;

struct guardaC {
	int c;
} guarda;

struct escola {
	char nome[20];
	data nasc;
	char doc[10];
	char sexo[20];
	char end[50];
	int ra;
	float cr;
}aluno[MAX];

struct escola2 {
	char nome[20];
	data nasc;
	char doc[10];
	char sexo[20];
	char end[50];
	int ra;
	float cr;
}aluno2[MAX];

void mostraOriginal() {
	int a;
	for(a=0;a<guarda.c;a++) {
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("Nome do aluno: %s\n", aluno2[a].nome);
		printf("Data de nascimento de %s: %d/%d/%d\n", aluno2[a].nome, aluno2[a].nasc.dia, aluno2[a].nasc.mes, aluno2[a].nasc.ano);
		printf("Documento de %s: %s\n", aluno2[a].nome, aluno2[a].doc);
		printf("Sexo de %s (M/F): %s\n", aluno2[a].nome, aluno2[a].sexo);
		printf("Endereço de %s: %s\n", aluno2[a].nome, aluno2[a].end);
		printf("RA de %s: %d", aluno2[a].nome, aluno2[a].ra);
		printf("Coeficiente de rendimento de %s: %.3f\n", aluno2[a].nome, aluno2[a].cr);
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void mostraDados(int a) {
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("Nome do aluno: %s\n", aluno[a].nome);
	printf("Data de nascimento de %s: %d/%d/%d\n", aluno[a].nome, aluno[a].nasc.dia, aluno[a].nasc.mes, aluno[a].nasc.ano);
	printf("Documento de %s: %s\n", aluno[a].nome, aluno[a].doc);
	printf("Sexo de %s (M/F): %s\n", aluno[a].nome, aluno[a].sexo);
	printf("Endereço de %s: %s\n", aluno[a].nome, aluno[a].end);
	printf("RA de %s: %d", aluno[a].nome, aluno[a].ra);
	printf("Coeficiente de rendimento de %s: %.3f\n", aluno[a].nome, aluno[a].cr);
}

void organizaDados(int a, int b) {
	char auxNome[20], copiaDoc[20], copiaSexo[20], copiaEnd[20];
	int auxDatdia, auxDatmes, auxDatano, copiaRa;
	float copiaCr;
	// Nome
	strcpy(auxNome, aluno[a].nome);
	strcpy(aluno[a].nome, aluno[b].nome);
	strcpy(aluno[b].nome, auxNome);
	// Ano Nasc Aluno
	auxDatano = aluno[a].nasc.ano;
	aluno[a].nasc.ano = aluno[b].nasc.ano;
	aluno[b].nasc.ano = auxDatano;
	// Mes Nasc Aluno
	auxDatmes = aluno[a].nasc.mes;
	aluno[a].nasc.mes = aluno[b].nasc.mes;
	aluno[b].nasc.mes = auxDatmes;
	// Dia Nasc Aluno
	auxDatdia = aluno[a].nasc.dia;
	aluno[a].nasc.dia = aluno[b].nasc.dia;
	aluno[b].nasc.dia = auxDatdia;
	// Documento
	strcpy(copiaDoc, aluno[a].doc);
	strcpy(aluno[a].doc, aluno[b].doc);
	strcpy(aluno[b].doc, copiaDoc);
	// Sexo
	strcpy(copiaSexo, aluno[a].sexo);
	strcpy(aluno[a].sexo, aluno[b].sexo);
	strcpy(aluno[b].sexo, copiaSexo);
	// End
	strcpy(copiaEnd, aluno[a].end);
	strcpy(aluno[a].end, aluno[b].end);
	strcpy(aluno[b].end, copiaEnd);
	// CR
	copiaCr = aluno[a].cr;
	aluno[a].cr = aluno[b].cr;
	aluno[b].cr = copiaCr;
	// RA
	copiaRa = aluno[a].ra;
	aluno[a].ra = aluno[b].ra;
	aluno[b].ra = copiaRa;
}

void imprimeRa(int ra) {
	system("cls");
	int a, b, tam=guarda.c;
	for(a=0;a<tam;a++) {
		if(aluno[a].ra==ra) {
			mostraDados(a);
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void organizaCr() {
	system("cls");
	int a, b, tam=guarda.c;
	for (a=0;a<(tam-1);a++) {
		for(b=a+1;b<tam;b++) {
			if(aluno[a].cr>aluno[b].cr) {
				organizaDados(a, b);
			}
		}
	}
	for(a=0;a<tam;a++) {
		mostraDados(a);
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void organizaAlfa() {
	system("cls");
	int a, b, tam=guarda.c;
	for (a=0;a<(tam-1);a++) {
		for(b=a+1;b<tam;b++) {
			if(strcmp(aluno[a].nome, aluno[b].nome)==1) {
				organizaDados(a, b);
			}
		}
	}
	for(a=0;a<tam;a++) {
		mostraDados(a);
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void leDados() {
	system("cls");
	int a, op, c;
		for(a=0;a<MAX, op!=2;a++) {
			if(op==2) {
				guarda.c = a;
				break;
			}
			printf("Qual o nome do aluno %d: ", a);
			fflush(stdin);
			gets(aluno[a].nome);
			fflush(stdout);
			printf("Qual a data de nascimento de %s (DD MM AAAA): ", aluno[a].nome);
			scanf("%d %d %d", &aluno[a].nasc.dia, &aluno[a].nasc.mes, &aluno[a].nasc.ano);
			printf("Insira o documento de %s: ", aluno[a].nome);
			fflush(stdin);
			gets(aluno[a].doc);
			fflush(stdout);
			printf("Insira o sexo de %s (M/F): ", aluno[a].nome);
			fflush(stdin);
			gets(aluno[a].sexo);
			fflush(stdout);
			printf("Insira o endereço de %s: ", aluno[a].nome);
			fflush(stdin);
			gets(aluno[a].end);
			fflush(stdout);
			do {
				printf("Insira o coeficiente de rendimento de %s: ", aluno[a].nome);
				fflush(stdin);
				scanf("%f", &aluno[a].cr);
				fflush(stdout);
			}while(aluno[a].cr<0 || aluno[a].cr>1);
			printf("Insira o RA de %s: ", aluno[a].nome);
			fflush(stdin);
			scanf("%d", &aluno[a].ra);
			fflush(stdout);
			printf("Deseja registrar outro aluno?(1/2): ");
			fflush(stdin);
			scanf("%d", &op);
			fflush(stdout);
			strcpy(aluno2[a].nome, aluno[a].nome);
			aluno[a].nasc.dia = aluno2[a].nasc.dia;
			aluno[a].nasc.mes = aluno2[a].nasc.mes;
			aluno[a].nasc.ano = aluno2[a].nasc.ano;
			strcpy(aluno[a].doc, aluno[2].doc);
			strcpy(aluno[a].end, aluno2[a].end);
			strcpy(aluno[a].sexo, aluno2[a].sexo);
			aluno[a].cr = aluno2[a].cr;
			aluno[a].ra = aluno2[a].ra;
		}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}
	
void menuRep() {
	system("cls");
	int op, op2, op3, ra;
	system("cls");
	do {
		printf("Você deseja:\n1- Ordenar por CR\n2- Imprimir em ordem alfabética\n3- Ler um valor de RA e encontrar o aluno correspondente\n4- Imprimir na ordem em que foi escrita\nSua opção: ");
		scanf("%d", &op);
	}while(op<=0 || op>4);
	if(op==1) {
		system("cls");
		organizaAlfa();
		do {
			printf("Deseja usar o programa novamente?\n1- Sim\n2- Não\nSua opção: ");
			scanf("%d", &op2);
		}while(op2<=0 || op2>2);
		if(op2==1) {
			system("cls");
			do {
				printf("1- Utilizar o programa com os mesmos dados\n2- Utilizar o programa com dados diferentes\nSua opção: ");
				scanf("%d", &op3);
			}while(op3<=0 || op3>2);
			if(op3==1) {
				menuRep();
			}
			else {
				main();
			}
		}
		else {
			system("exit");
		}
	}
	else if(op==2) {
		system("cls");
		organizaCr();
		do {
			printf("Deseja usar o programa novamente?\n1- Sim\n2- Não\nSua opção: ");
			scanf("%d", &op2);
		}while(op2<=0 || op2>2);
		if(op2==1) {
			system("cls");
			do {
				printf("1- Utilizar o programa com os mesmos dados\n2- Utilizar o programa com dados diferentes\nSua opção: ");
				scanf("%d", &op3);
			}while(op3<=0 || op3>2);
			if(op3==1) {
				menuRep();
			}
			else {
				main();
			}
		}
		else {
			system("exit");
		}
	}
	else if(op==3) {
		system("cls");
		printf("Digite o RA que deseja buscar: "); scanf("%d", &ra);
		system("pause");
		system("cls");
		imprimeRa(ra);
		do {
			printf("Deseja usar o programa novamente?\n1- Sim\n2- Não\nSua opção: ");
			scanf("%d", &op2);
		}while(op2<=0 || op2>2);
		if(op2==1) {
			system("cls");
			do {
				printf("1- Utilizar o programa com os mesmos dados\n2- Utilizar o programa com dados diferentes\nSua opção: ");
				scanf("%d", &op3);
			}while(op3<=0 || op3>2);
			if(op3==1) {
				menuRep();
			}
			else {
				main();
			}
		}
		else {
			system("exit");
		}
	}
	else {
		system("cls");
		mostraOriginal();
		do {
			printf("Deseja usar o programa novamente?\n1- Sim\n2- Não\nSua opção: ");
			scanf("%d", &op2);
		}while(op2<=0 || op2>2);
		if(op2==1) {
			system("cls");
			do {
				printf("1- Utilizar o programa com os mesmos dados\n2- Utilizar o programa com dados diferentes\nSua opção: ");
				scanf("%d", &op3);
			}while(op3<=0 || op3>2);
			if(op3==1) {
				menuRep();
			}
			else {
				main();
			}
		}
		else {
			system("exit");
		}
	}
}	

void menu() {
	system("cls");
	int op, op2, op3, ra;
	leDados();
	system("pause");
	system("cls");
	do {
		printf("Você deseja:\n1- Ordenar por CR\n2- Imprimir em ordem alfabética\n3- Ler um valor de RA e encontrar o aluno correspondente\n4- Imprimir na ordem em que foi escrita\nSua opção: ");
		scanf("%d", &op);
	}while(op<=0 || op>4);
	if(op==1) {
		system("cls");
		organizaAlfa();
		do {
			printf("Deseja usar o programa novamente?\n1- Sim\n2- Não\nSua opção: ");
			scanf("%d", &op2);
		}while(op2<=0 || op2>2);
		if(op2==1) {
			system("cls");
			do {
				printf("1- Utilizar o programa com os mesmos dados\n2- Utilizar o programa com dados diferentes\nSua opção: ");
				scanf("%d", &op3);
			}while(op3<=0 || op3>2);
			if(op3==1) {
				menuRep();
			}
			else {
				main();
			}
		}
		else {
			system("exit");
		}
	}
	else if(op==2) {
		system("cls");
		organizaCr();
		do {
			printf("Deseja usar o programa novamente?\n1- Sim\n2- Não\nSua opção: ");
			scanf("%d", &op2);
		}while(op2<=0 || op2>2);
		if(op2==1) {
			system("cls");
			do {
				printf("1- Utilizar o programa com os mesmos dados\n2- Utilizar o programa com dados diferentes\nSua opção: ");
				scanf("%d", &op3);
			}while(op3<=0 || op3>2);
			if(op3==1) {
				menuRep();
			}
			else {
				main();
			}
		}
		else {
			system("exit");
		}
	}
	else if(op==3) {
		system("cls");
		printf("Digite o RA que deseja buscar: "); scanf("%d", &ra);
		system("pause");
		system("cls");
		imprimeRa(ra);
		do {
			printf("Deseja usar o programa novamente?\n1- Sim\n2- Não\nSua opção: ");
			scanf("%d", &op2);
		}while(op2<=0 || op2>2);
		if(op2==1) {
			system("cls");
			do {
				printf("1- Utilizar o programa com os mesmos dados\n2- Utilizar o programa com dados diferentes\nSua opção: ");
				scanf("%d", &op3);
			}while(op3<=0 || op3>2);
			if(op3==1) {
				menuRep();
			}
			else {
				main();
			}
		}
		else {
			system("exit");
		}
	}
	else {
		system("cls");
		mostraOriginal();
		do {
			printf("Deseja usar o programa novamente?\n1- Sim\n2- Não\nSua opção: ");
			scanf("%d", &op2);
		}while(op2<=0 || op2>2);
		if(op2==1) {
			system("cls");
			do {
				printf("1- Utilizar o programa com os mesmos dados\n2- Utilizar o programa com dados diferentes\nSua opção: ");
				scanf("%d", &op3);
			}while(op3<=0 || op3>2);
			if(op3==1) {
				menuRep();
			}
			else {
				main();
			}
		}
		else {
			system("exit");
		}
	}
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	menu();
}
