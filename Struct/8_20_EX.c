#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
 /*Declare uma estrutura chamada TipoReg contendo os seguintes campos: Nome, RG,
Salario, Idade, Sexo, DataNascimento; onde Nome e RG são strings, Salario é real, Idade é inteiro, Sexo é char e DataNascimento
 é uma estrutura contendo três inteiros,
dia, mês e ano. Declare uma estrutura chamada TipoCadastro que contém dois campos: um campo funcionário, contendo um vetor com 100 posições do tipo TipoReg e
outro campo inteiro, Quant, que indica a quantidade de funcionários no cadastro.
*/
typedef struct {
	int dia;
	int mes;
	int ano;
} data;

struct TipoReg{
	char nome[20];
	char rg[20];
	float salario;
	char sexo[20];
	int idade;
	data nasc;
};

struct tipoCadastro{
	struct TipoReg funcionario[100];
	int quant;
	float v1, v2;
} TipoCadastro;

void organizaDados(int a, int b) {
	char auxNome[20], copiaDoc[20], copiaSexo[20], copiaEnd[20];
	int auxDatdia, auxDatmes, auxDatano, auxIdade;
	float auxSalario;
	// Nome
	strcpy(auxNome, TipoCadastro.funcionario[a].nome);
	strcpy(TipoCadastro.funcionario[a].nome, TipoCadastro.funcionario[b].nome);
	strcpy(TipoCadastro.funcionario[b].nome, auxNome);
	// Ano Nasc Func
	auxDatano = TipoCadastro.funcionario[a].nasc.ano;
	TipoCadastro.funcionario[a].nasc.ano = TipoCadastro.funcionario[b].nasc.ano;
	TipoCadastro.funcionario[b].nasc.ano = auxDatano;
	// Mes Nasc Func
	auxDatmes = TipoCadastro.funcionario[a].nasc.mes;
	TipoCadastro.funcionario[a].nasc.mes = TipoCadastro.funcionario[b].nasc.mes;
	TipoCadastro.funcionario[b].nasc.mes = auxDatmes;
	// Dia Nasc Func
	auxDatdia = TipoCadastro.funcionario[a].nasc.dia;
	TipoCadastro.funcionario[a].nasc.dia = TipoCadastro.funcionario[b].nasc.dia;
	TipoCadastro.funcionario[b].nasc.dia = auxDatdia;
	// RG
	strcpy(copiaDoc, TipoCadastro.funcionario[a].rg);
	strcpy(TipoCadastro.funcionario[a].rg, TipoCadastro.funcionario[b].rg);
	strcpy(TipoCadastro.funcionario[b].rg, copiaDoc);
	// Sexo
	strcpy(copiaSexo, TipoCadastro.funcionario[a].sexo);
	strcpy(TipoCadastro.funcionario[a].sexo, TipoCadastro.funcionario[b].sexo);
	strcpy(TipoCadastro.funcionario[b].sexo, copiaSexo);
	// Ano Nasc Func
	auxIdade = TipoCadastro.funcionario[a].nasc.ano;
	TipoCadastro.funcionario[a].nasc.ano = TipoCadastro.funcionario[b].nasc.ano;
	TipoCadastro.funcionario[b].nasc.ano = auxIdade;
	// Salario Funcionário
	auxSalario = TipoCadastro.funcionario[a].salario;
	TipoCadastro.funcionario[a].salario = TipoCadastro.funcionario[b].salario;
	TipoCadastro.funcionario[b].salario = auxSalario;
}

void mostrarFuncionarios(int a) {
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("Nome do funcionário: %s\n", TipoCadastro.funcionario[a].nome);
	printf("RG do funcionário: %s\n",TipoCadastro.funcionario[a].rg);
	printf("Salário do funcionário: %.4f\n", TipoCadastro.funcionario[a].salario);
	printf("Idade do funcionário: %d anos\n", TipoCadastro.funcionario[a].idade);
	printf("Sexo do funcionário: %s\n", TipoCadastro.funcionario[a].sexo);
	printf("Data de nascimento do funcionário(DD MM AAAA): %d/%d/%d\n", TipoCadastro.funcionario[a].nasc.dia, TipoCadastro.funcionario[a].nasc.mes, TipoCadastro.funcionario[a].nasc.ano);
}

void mostrarFuncionariosImposto(int a, float s) {
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("Nome do funcionário: %s\n", TipoCadastro.funcionario[a].nome);
	printf("RG do funcionário: %s\n",TipoCadastro.funcionario[a].rg);
	printf("Salário do funcionário: %.4f\n", TipoCadastro.funcionario[a].salario);
	printf("Idade do funcionário: %d anos\n", TipoCadastro.funcionario[a].idade);
	printf("Sexo do funcionário: %s\n", TipoCadastro.funcionario[a].sexo);
	printf("Data de nascimento do funcionário(DD MM AAAA): %d/%d/%d\n", TipoCadastro.funcionario[a].nasc.dia, TipoCadastro.funcionario[a].nasc.mes, TipoCadastro.funcionario[a].nasc.ano);
	printf("Imposto retido: %f\n", s);
}

void listaNiversexo(int dia, int mes, int ano, char sexo[]) {
	int a, b=0, tam;
	float s=0;
	tam = TipoCadastro.quant;
	for (a=0;a<tam;a++) {
		if(TipoCadastro.funcionario[a].nasc.mes==mes && TipoCadastro.funcionario[a].nasc.dia==dia && TipoCadastro.funcionario[a].nasc.ano==ano && TipoCadastro.funcionario[a].sexo==sexo) {
			mostrarFuncionarios(a);
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void listaNivermes(int mes) {
	int a, b=0, tam;
	float s=0;
	tam = TipoCadastro.quant;
	for (a=0;a<tam;a++) {
		if(TipoCadastro.funcionario[a].nasc.mes==mes) {
			mostrarFuncionarios(a);
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void removeFuncionario(char rg[]) {
	int a, b, tam, pos;
	tam = TipoCadastro.quant;
	for (a=0;a<tam;a++) {
		if(TipoCadastro.funcionario[a].rg==rg) {
			pos = a;
		}
		else {
			
		}
	}
	for(a=pos;a<tam-1;a++) {
		organizaDados(a, a+1);
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void listaMaraja() {
	int a, b, tam;
	tam = TipoCadastro.quant;
	for (a=0;a<(tam-1);a++) {
		for(b=a+1;b<tam;b++) {
			if(TipoCadastro.funcionario[a].salario>TipoCadastro.funcionario[b].salario) {
				organizaDados(a, b);
			}
		}
	}
	for(a=0;a<50;a++) {
		if (a==tam) {
			break;
		}
		mostrarFuncionarios(a);
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void atualizarSalario(char rg[]) {
	int a, b=0, tam;
	float s=0;
	tam = TipoCadastro.quant;
	for (a=0;a<tam;a++) {
		if(TipoCadastro.funcionario[a].rg==rg) {
			printf("Insira o novo salário que deseja inserir para %s: ", TipoCadastro.funcionario[a].nome);
			TipoCadastro.funcionario[a].salario=(float)0;
			scanf("%f", &TipoCadastro.funcionario[a].salario);
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void buscaNome(char nome[]) {
	int a, b=0, tam;
	float s=0;
	tam = TipoCadastro.quant;
	for (a=0;a<tam;a++) {
		if(TipoCadastro.funcionario[a].nome==nome) {
			mostrarFuncionarios(a);
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("Média dos salários listados: %f", s/b);
	system("pause");
	system("cls");
}

void imposto() {
	int a, b=0, tam;
	float sP, s;
	tam = TipoCadastro.quant;
	for (a=0;a<tam;a++) {
		if(TipoCadastro.funcionario[a].salario>=(float)1000) {
			s = TipoCadastro.funcionario[a].salario;
			mostrarFuncionariosImposto(a, s);
		}
		else if(TipoCadastro.funcionario[a].salario>(float)1000 && TipoCadastro.funcionario[a].salario<=(float)2000) {
			sP = TipoCadastro.funcionario[a].salario/0.10;
			s=TipoCadastro.funcionario[a].salario-sP;
			mostrarFuncionariosImposto(a, s);
		}
		else if(TipoCadastro.funcionario[a].salario>(float)2000 && TipoCadastro.funcionario[a].salario<=(float)3500) {
			sP = TipoCadastro.funcionario[a].salario/0.15;
			s=TipoCadastro.funcionario[a].salario-sP;
			mostrarFuncionariosImposto(a, s);
		}
		else if(TipoCadastro.funcionario[a].salario>(float)3500) {
			sP = TipoCadastro.funcionario[a].salario/0.25;
			s=TipoCadastro.funcionario[a].salario-sP;
			mostrarFuncionariosImposto(a, s);
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void salarioIntervalo(float v1, float v2) {
	int a, b=0, tam;
	float s=0;
	tam = TipoCadastro.quant;
	for (a=0;a<tam;a++) {
		if(TipoCadastro.funcionario[a].salario>= v1 && TipoCadastro.funcionario[a].salario<=v2) {
			s+=TipoCadastro.funcionario[a].salario;
			b++;
			mostrarFuncionarios(a);
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("Média dos salários listados: %f", s/b);
	system("pause");
	system("cls");
}

void ordenaSalario() {
	int a, b, tam;
	tam = TipoCadastro.quant;
	for (a=0;a<(tam-1);a++) {
		for(b=a+1;b<tam;b++) {
			if(TipoCadastro.funcionario[a].salario>TipoCadastro.funcionario[b].salario) {
				organizaDados(a, b);
			}
		}
	}
	for(a=0;a<tam;a++) {
		mostrarFuncionarios(a);
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void ordenaNome() {
	int a, b, tam;
	tam = TipoCadastro.quant;
	for (a=0;a<(tam-1);a++) {
		for(b=a+1;b<tam;b++) {
			if(strcmp(TipoCadastro.funcionario[a].nome, TipoCadastro.funcionario[b].nome)==1) {
				organizaDados(a, b);
			}
		}
	}
	for(a=0;a<tam;a++) {
		mostrarFuncionarios(a);
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void listaFuncionarios() {
	int a, c;
	c = TipoCadastro.quant;
	for(a=0;a<c;a++) {
		mostrarFuncionarios(a);
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void leFuncionarios() {
	int a, op;
	do {
		for(a=0;a<100;a++) {
			if (op==2) {
				TipoCadastro.quant = a;
				break;
			}
			printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
			printf("Insira o nome do funcionário: ");
			fflush(stdin);
			gets(TipoCadastro.funcionario[a].nome);
			fflush(stdout);
			printf("Insira o RG do funcionário: ");
			fflush(stdin);
			gets(TipoCadastro.funcionario[a].rg);
			fflush(stdout);
			printf("Insira o salário do funcionário: ");
			scanf("%f", &TipoCadastro.funcionario[a].salario);
			printf("Insira a idade do funcionário: ");
			scanf("%d", &TipoCadastro.funcionario[a].idade);
			printf("Insira o sexo do funcionário(M/F): ");
			fflush(stdin);
			gets(TipoCadastro.funcionario[a].sexo);
			fflush(stdout);
			printf("Insira a data de nascimento do funcionário(DD MM AAAA): ");
			scanf("%d %d %d", &TipoCadastro.funcionario[a].nasc.dia, &TipoCadastro.funcionario[a].nasc.mes, &TipoCadastro.funcionario[a].nasc.ano);
			printf("Deseja registrar outro funcionário?(1/2)\nSua opção: ");
			do {
         		scanf("%d", &op);
     		} while (op != 1 && op != 2);
		}
	} while (op == 1);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void iniciaCadastro() {
	TipoCadastro.quant=0; int op;
	leFuncionarios();
	system("cls");
	do {
		printf("O que você deseja fazer?\n1- Listar os funcionários\n2- Ordenar pelo nome\n3- Ordenar pelo salário\n4- Mostrar um salário de acordo com um intervalo\n5- Mostrar o quanto é descontado de imposto\n6- Buscar pelo nome\n7- Atualizar o salário de alguém\n8- Mostrar os maiores salários(TOP 50)\n 9- Remover um funcionário\n10- Mostrar quem faz de acordo com o mês inserido\n11- Listar a data de aniversário e o sexo inserido\nSua opção: ");
		scanf("%d", &op);
	}while(op<=0 || op>11);
	if(op==1) {
		system("cls");
		listaFuncionarios();
	}
	else if(op==2) {
		ordenaNome();
	}
	else if(op==3) {
		ordenaSalario();
	}
	else if(op==4) {
		printf("Insira o intervalo que deseja, dois números: ");
		scanf("%f %f", &TipoCadastro.v1, &TipoCadastro.v2);
		ordenaNome(TipoCadastro.v1, TipoCadastro.v2);
	}
	else if(op==5) {
		imposto();
	}
	else if(op==6) {
		char nome[20];
		printf("Insira o nome que deseja buscar: ");
		fflush(stdin);
		gets(nome);
		fflush(stdout);
		ordenaSalario(nome);
	}
	else if(op==7) {
		char rg[20];
		printf("Insira o rg que deseja buscar para alterar salário: ");
		fflush(stdin);
		gets(rg);
		fflush(stdout);
		atualizarSalario(rg);
	}
	else if(op==8) {
		listaMaraja();
	}
	else if(op==9) {
		char rg[20];
		printf("Insira o rg que deseja buscar para removê-lo: ");
		fflush(stdin);
		gets(rg);
		fflush(stdout);
		removeFuncionario(rg);
	}
	else if(op==10) {
		int mes;
		printf("Insira o mês para buscar os aniversariantes correspondentes: ");
		fflush(stdin);
		scanf("%d", &mes);	
		fflush(stdout);
		removeFuncionario(mes);
	}
	else if(op==11) {
		int dia, mes, ano;
		char sexo[20];
		printf("Insira o dia, mes, ano e sexo para buscar os aniversariantes do sexo correspondentes: ");
		fflush(stdin);
		scanf("%d %d %d", &dia, &mes, &ano);
		gets(sexo);	
		fflush(stdout);
		listaNiversexo(dia, mes, ano, sexo);
	}
	
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	iniciaCadastro();
	
}
