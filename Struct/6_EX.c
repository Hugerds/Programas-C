#include <stdio.h>
#include <locale.h>
#include <string.h>

struct dma1 {
int dia;
int mes;
int ano;
} data1;

struct dma2 {
int dia;
int mes;
int ano;
} data2;

int main () {
	int dmes, qmes, ddia, dano, qano;
	setlocale(LC_ALL, "Portuguese");
	printf("Insira a primeira de duas datas para haver uma comparação entre estas(DD MM AAAA): ");
	scanf("%d %d %d", &data1.dia, &data1.mes, &data1.ano);
	printf("Insira a segunda de duas datas para haver uma comparação entre estas(DD MM AAAA): ");
	scanf("%d %d %d", &data2.dia, &data2.mes, &data2.ano);
	system("pause");
	system("cls");
	if(data1.ano==data2.ano) {
		if(data1.mes==data2.mes) {
			if(data1.dia==data2.dia) {
				printf("As datas são iguais\n");
			}
			else if(data1.dia>data2.dia){
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", data1.dia-data2.dia, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
			else if(data1.dia<data2.dia){
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", data2.dia-data1.dia, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
		}
		else if(data1.mes>data2.mes) {
			dmes=data1.mes-data2.mes;
			qmes=dmes*30;
			if(data1.dia==data2.dia) {
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", qmes, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
			else if(data1.dia>data2.dia) {
				ddia =  data1.dia-data2.dia;
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", qmes+ddia, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
			else if(data1.dia<data2.dia) {
				ddia =  data2.dia-data1.dia;
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", qmes+ddia, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
		}
		else if(data1.mes<data2.mes) {
			dmes=data2.mes-data1.mes;
			qmes=dmes*30;
			if(data1.dia==data2.dia) {
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", qmes, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
			else if(data1.dia>data2.dia) {
				ddia =  data1.dia-data2.dia;
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", qmes+ddia, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
			else if(data1.dia<data2.dia) {
				ddia =  data2.dia-data1.dia;
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", qmes+ddia, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
		}
	}
	else if(data1.ano>data2.ano) {
		printf("Data incompatível\n");
	}
	else if(data1.ano<data2.ano) {
		dano=data2.ano-data1.ano;
		qano=dano*365;
		if(data1.mes==data2.mes) {
			if(data1.dia==data2.dia) {
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", qano, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
			else if(data1.dia>data2.dia){
				ddia=data1.dia-data2.dia;
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", qano+ddia, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
			else if(data1.dia<data2.dia){
				ddia=data2.dia-data1.dia;
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", qano+ddia, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
		}
		else if(data1.mes>data2.mes) {
			dmes=data1.mes-data2.mes;
			qmes=dmes*30;
			if(data1.dia==data2.dia) {
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", qmes+qano, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
			else if(data1.dia>data2.dia) {
				ddia =  data1.dia-data2.dia;
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", qmes+ddia+qano, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
			else if(data1.dia<data2.dia) {
				ddia =  data2.dia-data1.dia;
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", qmes+ddia+qano, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
		}
		else if(data1.mes<data2.mes) {
			dmes=data2.mes-data1.mes;
			qmes=dmes*30;
			if(data1.dia==data2.dia) {
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", qmes+qano, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
			else if(data1.dia>data2.dia) {
				ddia =  data1.dia-data2.dia;
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", qmes+ddia+qano, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
			else if(data1.dia<data2.dia) {
				ddia =  data2.dia-data1.dia;
				printf("Decorreram %d dias entre %d/%d/%d e %d/%d/%d", qmes+ddia+qano, data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
			}
		}
	}
}
