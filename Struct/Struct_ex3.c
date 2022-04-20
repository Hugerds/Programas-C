/* 3) Utilizando uma estrutura, desenvolva um programa que permita a entrada do nome, 
endereço e telefone de, no máximo, 30 pessoas e, os imprima em ordem alfabética. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 40

struct dados {
	char nome[20];
	char endereco[50];
	char tel[15];
} info[max];

void leituraStruct(tam) {
	int a;
	for (a=0;a<tam;a++) {
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf ("Digite o nome do %d funcionario\n", a+1);
		fflush(stdin);
		gets(info[a].nome);
		printf ("Digite o endereco do %s\n", info[a].nome);
		fflush(stdin);
		gets(info[a].endereco);
		printf ("Digite o numero do telefone do %s\n", info[a].nome);
		fflush(stdin);
		gets(info[a].tel);
	}
}

void mostraStruct(tam) {
	int a;
	system("cls");
	for (a=0;a<tam;a++) {
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("Nome: %s\n", info[a].nome);
		printf ("Endereco: %s\n", info[a].endereco);
		printf ("Telefone: %s\n", info[a].tel);
	}
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void ordem(tam) {
	int i, j; 
	char copia[100];
	for (i=0;i<(tam-1);i++) {
		for(j=i+1;j<tam;j++) {
			if (strcmp(info[i].nome, info[j].nome)>0) {
				strcpy (copia, info[i].nome);
        		strcpy(info[i].nome, info[j].nome);
        		strcpy(info[j].nome, copia);
			}
		}
	}
	for (i=0;i<tam;i++) {
		printf ("%s\n", info[i].nome);
	}
}

int main() {
	int tam;
	do {
		printf ("Quantos funcionarios tem sua empresa?(MAX 40)\nSua opcao: ");
		scanf ("%d", &tam);
	} while(tam<=0 || tam >40);
	leituraStruct(tam);
	mostraStruct(tam);
	ordem(tam);
	system("pause");
}
