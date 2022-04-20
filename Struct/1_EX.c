#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAX 50

struct pBandas {
	char nome[20];
	char tipo[20];
	int pos;
} banda[MAX];

void mostraDados(int tam, int a) {
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("Nome da banda: %s\n", banda[a].nome);
	printf("Tipo de música que %s toca: %s\n", banda[a].nome, banda[a].tipo);
	printf("Posição no ranking: %d\n", banda[a].pos);
}

void mostraFav(int tam, char nome[]) {
	system("cls");
	int a;
	for (a=0;a<tam;a++) {
		if(banda[a].nome==nome && banda[a].pos>0) {
			mostraDados(tam, a);
		}
		else {
			
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
}

void buscaTipo(int tam, char tipo[]) {
	system("cls");
	int a;
	for(a=0;a<tam;a++) {
		if(banda[a].tipo==tipo) {
			mostraDados(tam, a);
		}
		else {
			
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
}

void buscaRanking(int tam, int busca) {
	system("cls");
	int a;
	for (a=0;a<tam;a++) {
		if(banda[a].pos==busca) {
			mostraDados(tam, a);
		}
		else {
			
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
}

void leDados(int tam) {
	int a;
	for (a=0;a<tam;a++) {
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("Nome da banda: ");
		fflush(stdin);
		gets(banda[a].nome);
		fflush(stdout);
		printf("Tipo de música que %s toca: ", banda[a].nome);
		fflush(stdin);
		gets(banda[a].tipo);
		fflush(stdout);
		do {
			printf("Posição no ranking (0-5): ");
			scanf("%d", &banda[a].pos);
		} while(banda[a].pos<0 || banda[a].pos>5);
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
}

void menuRep() {
	int qtd, op, op2, op3;
	char tipo[20], nome[20];
	system("cls");
	do {
		printf("Você deseja:\n1- Buscar uma banda de acordo com seu ranking\n2- Buscar uma banda de acordo com o tipo de música\n3- Mostrar se determinada banda está entre suas favoritas\n4- Sair\nSua opção: ");
		scanf("%d", &op);
	} while(op<=0 || op>4);
	if (op==1) {
		system("cls");
		do {
			printf("Qual ranking você deseja filtrar?\nSua opção: ");
			scanf("%d", &op2);
		} while(op2<0 || op2>5);
		buscaRanking(qtd, op2);
		system("cls");
		do {
			printf("Você deseja:\n1- Reutilizar o programa com os mesmos dados \n2- Inserir novos dados?\nSua opção: ");
			scanf("%d", &op3);
		} while(op3<=0 || op3>2);
		if (op3==1) {
			menuRep();
		}
		else if(op3==2) {
			main();
		}
	}
	else if(op==2) {
		system("cls");
		printf("Qual tipo de música deseja buscar?\nSua opção: ");
		fflush(stdin);
		gets(tipo);
		fflush(stdout);
		buscaTipo(qtd, tipo);
		system("cls");
		do {
			printf("Você deseja:\n1- Reutilizar o programa com os mesmos dados \n2- Inserir novos dados?\nSua opção: ");
			scanf("%d", &op3);
		} while(op3<=0 || op3>2);
		if (op3==1) {
			menuRep();
		}
		else if(op3==2) {
			main();
		}
	}
	else if(op==3) {
		system("cls");
		printf("Qual nome da banda que deseja buscar?\nSua opção: ");
		fflush(stdin);
		gets(nome);
		fflush(stdout);
		mostraFav(qtd, nome);
		system("cls");
		do {
			printf("Você deseja:\n1- Reutilizar o programa com os mesmos dados \n2- Inserir novos dados?\nSua opção: ");
			scanf("%d", &op3);
		} while(op3<=0 || op3>2);
		if (op3==1) {
			menuRep();
		}
		else if(op3==2) {
			main();
		}
	}
}

void menu() {
	int qtd, op, op2, op3;
	char tipo[20], nome[20];
	system("cls");
	do {
		printf("Quantas bandas deseja cadastrar?\nSua opção: ");
		scanf("%d", &qtd);
	} while(qtd<=0 || qtd>50);
	system("cls");
	leDados(qtd);
	system("cls");
	do {
		printf("Você deseja:\n1- Buscar uma banda de acordo com seu ranking\n2- Buscar uma banda de acordo com o tipo de música\n3- Mostrar se determinada banda está entre suas favoritas\n4- Sair\nSua opção: ");
		scanf("%d", &op);
	} while(op<=0 || op>4);
	if (op==1) {
		system("cls");
		do {
			printf("Qual ranking você deseja filtrar?\nSua opção: ");
			scanf("%d", &op2);
		} while(op2<0 || op2>5);
		buscaRanking(qtd, op2);
		system("cls");
		do {
			printf("Você deseja:\n1- Reutilizar o programa com os mesmos dados \n2- Inserir novos dados?\nSua opção: ");
			scanf("%d", &op3);
		} while(op3<=0 || op3>2);
		if (op3==1) {
			menuRep();
		}
		else if(op3==2) {
			main();
		}
	}
	else if(op==2) {
		system("cls");
		printf("Qual tipo de música deseja buscar?\nSua opção: ");
		fflush(stdin);
		gets(tipo);
		fflush(stdout);
		buscaTipo(qtd, tipo);
		system("cls");
		do {
			printf("Você deseja:\n1- Reutilizar o programa com os mesmos dados \n2- Inserir novos dados?\nSua opção: ");
			scanf("%d", &op3);
		} while(op3<=0 || op3>2);
		if (op3==1) {
			menuRep();
		}
		else if(op3==2) {
			main();
		}
	}
	else if(op==3) {
		system("cls");
		printf("Qual nome da banda que deseja buscar?\nSua opção: ");
		fflush(stdin);
		gets(nome);
		fflush(stdout);
		mostraFav(qtd, nome);
		system("cls");
		do {
			printf("Você deseja:\n1- Reutilizar o programa com os mesmos dados \n2- Inserir novos dados?\nSua opção: ");
			scanf("%d", &op3);
		} while(op3<=0 || op3>2);
		if (op3==1) {
			menuRep();
		}
		else if(op3==2) {
			main();
		}
	}	
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	menu();
}
