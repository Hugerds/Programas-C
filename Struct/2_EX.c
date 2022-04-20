#include <stdio.h>
#include <locale.h>

#define MAX 50

struct Ponto{
	int x;
	int y;
} ponto;

void menu() {
	int p, rep;
	system("cls");
	printf("Insira o primeiro valor do retângulo: ");
	scanf("%d", &ponto.x);
	printf("%d e ", ponto.x);
	scanf("%d", &ponto.y);
	system("cls");
	printf("Você digitou %d e %d\n", ponto.x, ponto.y);
	printf("Digite agora o ponto que você deseja saber se está dentro ou fora do triângulo: ");
	scanf("%d", &p);
	if(p<=(ponto.x*ponto.y)) {
		printf("O ponto %d está localizado dentro do retângulo %dx%d", p, ponto.x, ponto.y);
	}
	else {
		printf("O ponto %d está localizado fora do retângulo %dx%d", p, ponto.x, ponto.y);
	}
	do {
		printf("\n\nDeseja reutilizar o programa?\n1- Sim\n2- Não\nSua opção: ");
		scanf("%d", &rep);
	} while(rep<=0 || rep>2);
	if (rep==1) {
		menu();
	}
	else {
		system("exit");
	}
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	menu();
}
