/*EXERCÍCIO PROPOSTO*/
/*Declare uma estrutura que contenha as seguintes informações: NÚMERO DA CONTA,
NOME DO CLIENTE, SALDO e DATA DA ÚLTIMA OPERAÇÃO.
Utilizando a estrutura, faça um programa que permita a entrada de, no máximo, 50 clientes
e, imprima-os em ordem alfabética. O programa também deve permitir a consulta de clientes
fornecendo a data da última operação e, também a consulta de clientes com saldo negativo.
Faça um menu, que permita o reprocessamento, oferecendo as opções de cadastro
e consulta de clientes por data da última operação e saldo.*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define max 50

typedef struct {
	int dia;
	int mes;
	int ano;
} data;

struct empEmpresa {
	char nome[20];
	char numConta[20];
	data nasc;
	float salario;
} Empregados[max];

void leituraStruct(tam) {
	system("cls");
	int a;
	for (a=0;a<tam;a++) {
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf ("Digite o nome do(a) %d cliente\n", a+1);
		fflush(stdin);
		gets(Empregados[a].nome);
		printf ("Digite o numero da conta de %s\n", Empregados[a].nome);
		fflush(stdin);
		gets(Empregados[a].numConta);
		printf ("Digite a data da ultima operacao de %s\n", Empregados[a].nome);
		fflush(stdin);
		scanf("%d %d %d", &Empregados[a].nasc.dia,&Empregados[a].nasc.mes,&Empregados[a].nasc.ano);
		printf ("Digite o saldo da conta de %s\n", Empregados[a].nome);
		fflush(stdin);
		scanf ("%f", &Empregados[a].salario);
	}
}

void saldoNeg(tam) {
	int i, j;
	system("cls");
	char copia[100];
	for (i=0;i<(tam-1);i++) {
		for(j=i+1;j<tam;j++) {
			if (strcmp(Empregados[i].nome, Empregados[j].nome)>0) {
				strcpy (copia, Empregados[i].nome);
        		strcpy(Empregados[i].nome, Empregados[j].nome);
        		strcpy(Empregados[j].nome, copia);
			}
		}
	}
	int a;
	for (a=0;a<tam;a++) {
		if (Empregados[a].salario<0) {
			printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
			printf("Nome do cliente: %s\n", Empregados[a].nome);
			printf("Numero da conta de %s: %s\n", Empregados[a].nome, Empregados[a].numConta);
			printf("Saldo do cliente: %f\n", Empregados[a].salario);
			printf ("Data da ultima operacao: %d/%d/%d\n", Empregados[a].nasc.dia,Empregados[a].nasc.mes,Empregados[a].nasc.ano);
		}
	}
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void ordem(tam) {
	int i, j;
	system("cls");
	char copia[100];
	for (i=0;i<(tam-1);i++) {
		for(j=i+1;j<tam;j++) {
			if (strcmp(Empregados[i].nome, Empregados[j].nome)>0) {
				strcpy (copia, Empregados[i].nome);
        		strcpy(Empregados[i].nome, Empregados[j].nome);
        		strcpy(Empregados[j].nome, copia);
			}
		}
	}
	int a;
	for (a=0;a<tam;a++) {
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("Nome do(a) cliente: %s\n", Empregados[a].nome);
		printf("Numero da conta de %s: %s\n", Empregados[a].nome, Empregados[a].numConta);
		printf("Saldo do cliente: %f\n", Empregados[a].salario);
		printf ("Data da ultima operacao: %d/%d/%d\n", Empregados[a].nasc.dia,Empregados[a].nasc.mes,Empregados[a].nasc.ano);
	}
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void dataOp(tam) {
	char ope[20]; int a, dia, mes, ano;
	printf ("Qual data de ultima operacao voce quer buscar?\n");
	printf("Sua opcao: "); fflush(stdin); scanf("%d %d %d", &dia, &mes, &ano);
	for (a=0;a<tam;a++) {
		if (dia==Empregados[a].nasc.dia && mes==Empregados[a].nasc.mes && ano==Empregados[a].nasc.ano) {
			printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
			printf("Nome do(a) cliente: %s\n", Empregados[a].nome);
			printf("Numero da conta de %s: %s\n", Empregados[a].nome, Empregados[a].numConta);
			printf("Saldo do cliente: %f\n", Empregados[a].salario);
			printf ("Data da ultima operacao: %d/%d/%d\n", Empregados[a].nasc.dia,Empregados[a].nasc.mes,Empregados[a].nasc.ano);
		}
	}
}

void numConta(tam) {
	float sal; int a;
	printf ("Qual data de ultima operacao voce quer buscar?\n");
	printf("Sua opcao: "); fflush(stdin); scanf("%f", &sal);
	for (a=0;a<tam;a++) {
		if (sal==Empregados[a].salario) {
			printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
			printf("Nome do(a) cliente: %s\n", Empregados[a].nome);
			printf("Numero da conta de %s: %s\n", Empregados[a].nome, Empregados[a].numConta);
			printf("Saldo do cliente: %f\n", Empregados[a].salario);
			printf ("Data da ultima operacao: %d/%d/%d\n", Empregados[a].nasc.dia,Empregados[a].nasc.mes,Empregados[a].nasc.ano);
		}
	}
}

int main () {
	system("cls");
	int tam, opcao, opmenu2, rep, repI;
	do {
		printf ("Quantos clientes voce quer cadastrar?(MAX 50)\nSua opcao: ");
		scanf ("%d", &tam);
	} while(tam<=0 || tam >50);
	printf ("\n\n\nVoce deseja\n\n1 - INSERIR DADOS\n\nSua opcao: ");
	scanf ("%d", &opcao);
	if (opcao == 1) {
		leituraStruct(tam);
		system("cls");
		printf ("O QUE DESEJA REALIZAR AGORA?\n\n1 - MOSTRAR DADOS EM ORDEM ALFAETICA\n2 - MOSTRAR CLIENTES COM SALDO NEGATIVO\n3 - PROCURAR CLIENTE PELA DATA DA ULTIMA OPERACAO\n4 - PROCURAR CLIENTE PELO SALDO DO(A) CLIENTE\n\nSua opcao: ");
		scanf("%d", &opmenu2);
		if (opmenu2==1) {
			ordem(tam);
			printf("\nDeseja usar o programa novamente com outros dados?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
			if (rep==1) {
				main();
			}
			else {
				system("cls");
				printf ("1 - MOSTRAR DADOS EM ORDEM ALFABETICA\n2 - MOSTRAR CLIENTES COM SALDO NEGATIVO\n3 - PROCURAR CLIENTE PELA DATA DA ULTIMA OPERACAO\n4 - PROCURAR CLIENTE PELO SALDO DO(A) CLIENTE\n\nSua opcao: ");
				scanf("%d", &repI);
				if (repI==1) {
					ordem(tam);
					printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
					if (rep==1) {
						main();
					}
					if(rep!=1) {
						exit;
					}
				}
				if (repI==2) {
					saldoNeg(tam);
					printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
					if (rep==1) {
						main();
					}
					if(rep!=1) {
						exit;
					}
				}
				if (repI==3) {
					dataOp(tam);
					printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
					if (rep==1) {
						main();
					}
					if(rep!=1) {
						exit;
					}
				}
				if (repI==4) {
					numConta(tam);
				}
			}
		}
		if (opmenu2==2) {
			saldoNeg(tam);
			printf("\nDeseja usar o programa novamente com outros dados?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
			if (rep==1) {
				main();
			}
			else {
				system("cls");
				printf ("1 - MOSTRAR DADOS EM ORDEM ALFABETICA\n2 - MOSTRAR CLIENTES COM SALDO NEGATIVO\n3 - PROCURAR CLIENTE PELA DATA DA ULTIMA OPERACAO\n4 - PROCURAR CLIENTE PELO SALDO DO(A) CLIENTE\n\nSua opcao: ");
				scanf("%d", &repI);
				if (repI==1) {
					ordem(tam);
					printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
					if (rep==1) {
						main();
					}
					if(rep!=1) {
						exit;
					}
				}
				if (repI==2) {
					saldoNeg(tam);
					printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
					if (rep==1) {
						main();
					}
					if(rep!=1) {
						exit;
					}
				}
				if (repI==3) {
					dataOp(tam);
					printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
					if (rep==1) {
						main();
					}
					if(rep!=1) {
						exit;
					}
				}
				if (repI==4) {
					numConta(tam);
					printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
					if (rep==1) {
						main();
					}
					if(rep!=1) {
						exit;
					}
				}
			}
		}
		if(opmenu2==3) {
			dataOp(tam);
			printf("\nDeseja usar o programa novamente com outros dados?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
			if (rep==1) {
				main();
			}
			else {
				system("cls");
				printf ("1 - MOSTRAR DADOS EM ORDEM ALFABETICA\n2 - MOSTRAR CLIENTES COM SALDO NEGATIVO\n3 - PROCURAR CLIENTE PELA DATA DA ULTIMA OPERACAO\n4 - PROCURAR CLIENTE PELO SALDO DO(A) CLIENTE\n\nSua opcao: ");
				scanf("%d", &repI);
				if (repI==1) {
					ordem(tam);
					printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
					if (rep==1) {
						main();
					}
					if(rep!=1) {
						exit;
					}
				}
				if (repI==2) {
					saldoNeg(tam);
					printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
					if (rep==1) {
						main();
					}
					if(rep!=1) {
						exit;
					}
				}
				if (repI==3) {
					dataOp(tam);
					printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
					if (rep==1) {
						main();
					}
					if(rep!=1) {
						exit;
					}
				}
				if (repI==4) {
					numConta(tam);
					printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
					if (rep==1) {
						main();
					}
					if(rep!=1) {
						exit;
					}
				}
			}
		}
		if (opmenu2==4) {
			numConta(tam);
			printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
			if (rep==1) {
				main();
			}
			else {
				system("cls");
				printf ("1 - MOSTRAR DADOS EM ORDEM ALFABETICA\n2 - MOSTRAR CLIENTES COM SALDO NEGATIVO\n3 - PROCURAR CLIENTE PELA DATA DA ULTIMA OPERACAO\n4 - PROCURAR CLIENTE PELO SALDO DO(A) CLIENTE\n\nSua opcao: ");
				scanf("%d", &repI);
				if (repI==1) {
					ordem(tam);
					printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
					if (rep==1) {
						main();
					}
					if(rep!=1) {
						exit;
					}
				}
				if (repI==2) {
					saldoNeg(tam);
					printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
					if (rep==1) {
						main();
					}
					if(rep!=1) {
						exit;
					}
				}
				if (repI==3) {
					dataOp(tam);
					printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
					if (rep==1) {
						main();
					}
					if(rep!=1) {
						exit;
					}
				}
				if (repI==4) {
					numConta(tam);
					printf("Deseja usar o programa novamente?(1-S|!=1N)\nSua opcao: "); scanf ("%d", &rep);
					if (rep==1) {
						main();
					}
					if(rep!=1) {
						exit;
					}
				}
			}
		}
	}
	else {
		exit;
	}
	return 0;
}
