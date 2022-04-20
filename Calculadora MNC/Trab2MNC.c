#include <stdio.h>
#include <math.h>

#define MAX 15

double calcSomatorio(double vet[MAX], int size);
void RotinaAjusteReta();
void AjusteReta(int size, double vetTable[MAX][MAX], double res1[MAX], double res2[MAX], double ajusteReta[MAX], double coeficienteDeterminacao);
double RotinaCoefDeterminacao(double vetTable[MAX][MAX], int size, double vetAjustado[MAX]);


double calcSomatorio(double vet[MAX], int size) {
	int a;
	double sum=0;
	for(a=0;a<size;a++)
	{
		sum+=vet[a];
	}
	return sum;
}

void RotinaAjusteReta() {
	double vetTable[MAX][MAX], res[MAX];
	int size, a;
	double grau, xFuncao;
	do {
		printf("Insira o valor maximo de pontos da tabela: ");
		scanf("%d", &size);
	} while(size<1 || size>15);
	
	printf("\n\nInsira os pontos X:\n");
	for(a=0;a<size;a++) {
		scanf("%lf", &vetTable[0][a]);
	}
	
	printf("\n\nInsira os pontos Y:\n");
	for(a=0;a<size;a++) {
		scanf("%lf", &vetTable[1][a]);
	}
	double res1[1], res2[1], ajusteReta[MAX], coeficienteDeterminacao;
	AjusteReta(size, vetTable, res1, res2, ajusteReta, coeficienteDeterminacao);
	
	printf("\n\n");
	
	res1[0] > 0? printf("%.4lf + %.4lfx\n", res2[0], res1[0]) : printf("%.4lf - %.4lfx\n", res2[0], -res1[0]);
	printf("\nReta ajustada:\n");
	for(a=0;a<size;a++) {
		printf("^Y%d: %.4lf\n", a+1, ajusteReta[a]);
	}
	
	printf("\nCoeficiente de Determinacao: %.4lf", RotinaCoefDeterminacao(vetTable, size, ajusteReta));
	
	printf("\n\nPressione qualquer tecla para continuar\n\n");
	getch();
}

void AjusteReta(int size, double vetTable[MAX][MAX], double res1[MAX], double res2[MAX], double ajusteReta[MAX], double coeficienteDeterminacao) {
	double vetX[MAX], vetY[MAX], vetXQuadrado[MAX], vetXY[MAX];
	int a;
	for(a=0; a<size; a++) {
		vetXQuadrado[a] = vetTable[0][a]*vetTable[0][a];
		vetXY[a] = vetTable[0][a] * vetTable[1][a];
		vetX[a] = vetTable[0][a];
		vetY[a] = vetTable[1][a];
	}
	double sumXQuadrado = calcSomatorio(vetXQuadrado, size);
	double sumX = calcSomatorio(vetX, size);
	for(a=0;a<size;a++) {
	}
	double sumY = calcSomatorio(vetY, size);
	double sumXY = calcSomatorio(vetXY, size);
	res1[0] = ((size*sumXY-(sumX*sumY))/(size*sumXQuadrado-(sumX*sumX)));
	res2[0] = (sumY - (res1[0]*sumX))/(size);
	for(a=0;a<size;a++) {
		ajusteReta[a] = res2[0] + (res1[0]*vetX[a]);
	}
	
}

void RotinaAjusteExponencial(int size, double vetTable[MAX][MAX], double res1[MAX], double res2[MAX], double vetAjustado[MAX], double auxCoeficienteDet[MAX]) {
    double a0, a1;
    int a;
    for (a = 0; a < size; a++) {
        vetTable[1][a] = log(vetTable[1][a]);
    }
    AjusteReta(size, vetTable, res1, res2, vetAjustado, 1.0);
    res1[0] = pow(M_E, res1[0]);
    res2[0] = pow(M_E, res2[0]);
}

void AjusteExponencial() {
	double vetTable[MAX][MAX], res[MAX];
	int size, a;
	double grau, xFuncao;
	do {
		printf("Insira o valor maximo de pontos da tabela: ");
		scanf("%d", &size);
	} while(size<1 || size>15);
	
	printf("\n\nInsira os pontos X:\n");
	for(a=0;a<size;a++) {
		scanf("%lf", &vetTable[0][a]);
	}
	
	printf("\n\nInsira os pontos Y:\n");
	for(a=0;a<size;a++) {
		scanf("%lf", &vetTable[1][a]);
	}
	double res1[1], res2[1], ajusteReta[MAX], coeficienteDeterminacao[1];
	RotinaAjusteExponencial(size, vetTable, res1, res2, ajusteReta, coeficienteDeterminacao);
	
	printf("\nResultado:\n");
	res1[0] > 0? printf("%.4lf + %.4lfx\n", res2[0], res1[0]) : printf("%.4lf - %.4lfx\n", res2[0], -res1[0]);
	
	printf("\nCoeficiente de Determinacao: %.4lf", RotinaCoefDeterminacao(vetTable, size, ajusteReta));
	
	printf("\n\nPressione qualquer tecla para continuar\n\n");
	getch();
}

double RotinaCoefDeterminacao(double vetTable[MAX][MAX], int size, double vetAjustado[MAX]) {
    double sum = 0, auxDivide1 = 0, auxQuad = 0, auxDivide2 = 0;
    int a;

    for (a = 0; a < size; a++) {
        sum += vetTable[1][a];
    }

    for (a = 0; a < size; a++) {
        auxDivide2 += pow((vetTable[1][a] - vetAjustado[a]), 2.0);
    }

    for (a = 0; a < size; a++) {
        auxQuad += pow(vetTable[1][a], (double)2);
    }
    auxDivide1 = ((double)size * auxQuad) - (pow(sum, 2.0));
    double res = 1.0 - (size * auxDivide2 / auxDivide1);
    return res;
}

void CoeficienteDeterminacao() {
	double vetTable[MAX][MAX], res[MAX], vetAjustado[MAX];
	int size, a;
	double grau, xFuncao;
	do {
		printf("Insira o valor maximo de pontos da tabela: ");
		scanf("%d", &size);
	} while(size<1 || size>15);
	
	printf("\n\nInsira os pontos X:\n");
	for(a=0;a<size;a++) {
		scanf("%lf", &vetTable[0][a]);
	}
	
	printf("\n\nInsira os pontos Y:\n");
	for(a=0;a<size;a++) {
		scanf("%lf", &vetTable[1][a]);
	}
	
	printf("\n\nInsira os pontos ajustados:\n");
	for(a=0;a<size;a++) {
		scanf("%lf", &vetAjustado[a]);
	}
	
	printf("\n\n");
	
	printf("Resultado do Coeficiente de Determinacao: %.4lf\n", RotinaCoefDeterminacao(vetTable, size, vetAjustado));
	
	printf("\n\nPressione qualquer tecla para continuar\n\n");
	getch();
}

double RotinaNewtonGregory(double xFuncao, int size, double vetTable[][MAX]) {
    int a, b, auxFatorial = 1;
    double vetAux[MAX], vetRes[MAX], sum = 0, res, h;

    h = vetTable[0][1] - vetTable[0][0];

    for (a = 0; a < size; a++)
        vetAux[a] = vetTable[1][a];
    for (a = 0; a < size - 1; a++)
        for (b = 0; b < size - a; b++)
        {
            vetAux[b] = (vetAux[b + 1] - vetAux[b]);
            if (b == 0)
                vetRes[a] = vetAux[b];
        }
    res = vetTable[1][0];
    for (a = 0; a < size - 1; a++)
    {
        if (a == 0)
            sum += (xFuncao - vetTable[0][a]);
        else
            sum *= (xFuncao - vetTable[0][a]);
        res += sum * vetRes[a] / (auxFatorial * pow(h, a + 1));
        auxFatorial *= a + 2;
    }
    return res;
}

double RotinaNewton(double xFuncao, int size, double vetTable[MAX][MAX]) {
    int a, b;
    double vetAux[MAX], vetRes[MAX], soma = 0, res;

    for (a = 0; a < size; a++)
        vetAux[a] = vetTable[1][a];
    for (a = 0; a < size - 1; a++)
        for (b = 0; b < size - a; b++) {
            vetAux[b] = (vetAux[b + 1] - vetAux[b]) / (vetTable[0][b + a + 1] - vetTable[0][b]);
            if (b == 0)
                vetRes[a] = vetAux[b];
        }
    res = vetTable[1][0];
    for (a = 0; a < size - 1; a++) {
        if (a == 0)
            soma += (xFuncao - vetTable[0][a]);
        else
            soma *= (xFuncao - vetTable[0][a]);
        res += soma * vetRes[a];
    }
    return res;
}

void InterpolacaoNewtonOrNewtonGregory(int enumNewtonGregory) {
	int a, b, size;
	double vetTable[MAX][MAX], res[MAX];
	double grau, xFuncao;
	
	do {
		printf("Insira o valor maximo de pontos da tabela: ");
		scanf("%d", &size);
	} while(size<1 || size>15);
	
	printf("\n\nInsira os pontos X:\n");
	for(a=0;a<size;a++) {
		scanf("%lf", &vetTable[0][a]);
	}
	
	printf("\n\nInsira os pontos Y:\n");
	for(a=0;a<size;a++) {
		scanf("%lf", &vetTable[1][a]);
	}
	
	printf("\n\nInsira o ponto X a ser calculado: ");
	scanf("%lf", &xFuncao);
	enumNewtonGregory == 1? printf("\n\nO ponto %.4lf calculado atraves do polinomio de Newton tem o resultado: %.4lf\n\n", xFuncao, RotinaNewton(xFuncao, size, vetTable)): printf("\n\nO ponto %lf calculado atraves do polinomio de Newton Gregory tem o resultado: %lf\n\n", xFuncao, RotinaNewtonGregory(xFuncao, size, vetTable)); 
	
	printf("\n\nPressione qualquer tecla para continuar\n\n");
	getch();
}

// Fun��es //
float f1(float x) { 
    return x*(x+8)-(x-1);
}

float f2(float x) { 
    return (x+6*sin(x));
}

float f3(float x) { 
    return (x+pow(x,2)+x-9);
}

void rotinaTrapezio() {
    int i, n, option;
    double a, b, soma = 0, h, integral, y, x;

    // Inputs //
    printf("Selecione a funcao que deseja:\n\n1-f(x)=x*(x+8)-(x-1)\n\n2-f(x)=(x+6*sin(x))\n\n3-f(x)=(x+pow(x,2)+x-9)\n\nSua opcao: "); 
    scanf("%d", &option);

    printf("\nDigite o numero de sub-intervalos: ");
    scanf("%d", &n);

    printf("\nDigite o limite inferior: ");
    scanf("%lf", &a);

    printf("\nDigite o limite superior: ");
    scanf("%lf", &b);

    switch (option) {
    case 1:
        //* fun��o 1 *//
        h = fabs(b - a) / n; // C�lculo do h //

        for(i = 1; i < n; i++) { // M�todo do Trap�zio //
            x = a + i * h;
            soma = soma + f1(x);
        }
        integral = (h/2) * (f1(a) + f1(b) + 2 * soma);
        
        break;
    case 2:
        //* fun��o 2 *//
        h = fabs(b - a) / n; // C�lculo do h //

        for(i = 1; i < n; i++) { // M�todo do Trap�zio //
            x = a + i * h;
            soma = soma + f2(x);
        }
        integral = (h/2) * (f2(a) + f2(b) + 2 * soma);
        
        break;
    case 3:
        //* fun��o 3 *//
        h = fabs(b - a) / n; // C�lculo do h //

        for(i = 1; i < n; i++) { // M�todo do Trap�zio //
            x = a + i * h;
            soma = soma + f3(x);
        }
        integral = (h/2) * (f3(a) + f3(b) + 2 * soma);
        
        break;
    }
    
    printf("\nA integral eh: %.4lf\n", integral);
	printf("\n\nPressione qualquer tecla para continuar\n\n");
    getch();
    
}

void RotinaSimpson13() {
    int i, n, option;
    double a, b, soma = 0, h, integral, y, x;

    // Inputs //
    printf("Selecione a funcao que deseja:\n\n1-f(x)=x*(x+8)-(x-1)\n\n2-f(x)=(x+6*sin(x))\n\n3-f(x)=(x+x^2+x-9)\n\nSua opcao: "); 
    scanf("%d", &option);

    printf("\nDigite o numero de sub-intervalos: ");
    scanf("%d", &n);

    printf("\nDigite o limite inferior: ");
    scanf("%lf", &a);

    printf("\nDigite o limite superior: ");
    scanf("%lf", &b);

    switch (option) {
        case 1:
            h = fabs(b - a) / n;
            for(i = 1; i < n; i++) {
                x = a + i * h;

                if(i % 2 == 0) {
                    soma = soma + 2 * f1(x);
                }
                else {
                    soma = soma + 4 * f1(x);
                }
            }
            integral = (h/3) * (f1(a) + f1(b) + soma);

            printf("\nO valor da integral eh: %.3lf\n", integral);
            break;
        case 2:
            h = fabs(b - a) / n;
            for(i = 1; i < n; i++) {
                x = a + i * h;

                if(i % 2 == 0) {
                    soma = soma + 2 * f2(x);
                }
                else {
                    soma = soma + 4 * f2(x);
                }
            }
            integral = (h/3) * (f2(a) + f2(b) + soma);

            printf("\nO valor da integral eh: %.3lf\n", integral);
            break;
        case 3:
            h = fabs(b - a) / n;
            for(i = 1; i < n; i++) {
                x = a + i * h;

                if(i % 2 == 0) {
                    soma = soma + 2 * f3(x);
                }
                else {
                    soma = soma + 4 * f3(x);
                }
            }
            integral = (h/3) * (f3(a) + f3(b) + soma);

            printf("\nO valor da integral eh: %.3lf\n", integral);
        break;
    }
	printf("\n\nPressione qualquer tecla para continuar\n\n");
	getch();
}

typedef double(*Funcao)(double);

double F1(double x){
  return x*x;
}

double F2(double x){
  return 1/x;
}

double F3(double x){
	return (x*x*x) - (2*x) + 1;
}

Funcao EscolherFuncao(int *f){
	int op;
	while(op > 3 || op < 1){
		system("cls");
		printf("\nFuncoes disponiveis: \n");
		printf("1-f(x) = x*x\n");
		printf("2-f(x) = 1/x\n");
		printf("3-f(x) = x^3 - 2x + 1");
		printf("\nDigite o numero da funcao que deseja: ");
		scanf("%d", &op);
	}
	
	*f = op;
	switch(op){
		case 1:
			return F1;
			break;
		case 2:
			return F2;
			break;
		case 3:
			return F3;
			break;
	}
}

double Calcular(Funcao *f, double a, double b, int n){
    double h, x, resultado;
    double somatorio = 0;
    int i;
    
	h = fabs(b-a) / n;
  
    for(i = 1; i < n; i++){
    	
    x = a + i * h;
    if(i % 3 == 0){
      somatorio = somatorio + 2*(*f)(x);
    }
    else{
      somatorio = somatorio + 3*(*f)(x);
    }
  }
  resultado = (3*h/8)*((*f)(a)+(*f)(b)+ somatorio);
  return resultado;	
}

void RotinaSimpson38() {
	int f, input, n;
	double resultado, a, b;
	Funcao op;
	
	op = EscolherFuncao(&f);
	printf("\nInforme o limite inferior: ");
	scanf("%lf", &a);
	printf("\nInforme o limite superior: ");
	scanf("%lf", &b);
	printf("\nInforme o numero de intervalos(divisivel por 3): ");
	scanf("%d", &n);
	resultado = Calcular(&op, a, b, n);
	printf("\nResultado de f(%d) = %5.4lf", f, resultado);
	
	
	printf("\n\nPressione qualquer tecla para continuar\n\n");
	input = getch();

}

// vet[0] para X
// vet[1] para Y

int main() {
	int op;
	system("cls");
	printf("CALCULADORA MNC -- Desenvolvido por: Bryan Dias, Edmar Andre, Hugo Esteves e Pedro Braga\n");
	printf("1- Calcular interpolacao de Newton\n");
	printf("2- Calcular interpolacao de Newton Gregory\n");
	printf("3- Calcular coeficiente de determinacao\n");
	printf("4- Calcular ajuste de reta\n");
	printf("5- Calcular ajuste de polinomio\n");
	printf("6- Calcular ajuste exponencial\n");
	printf("7- Calcular regra dos trapezios\n");
	printf("8- Calcular 1/3 de Simpson\n");
	printf("9- Calcular 3/8 de Simpson\n");
	printf("10 - Sair\n");
	do {
		printf("\n\nInsira a opcao: ");
		scanf("%d", &op);
	} while(op < 1 || op > 10);
	if(op==1) {
		system("cls");
		//enum == 1 para Newton
		InterpolacaoNewtonOrNewtonGregory(1);
		main();
	}
	else if(op==2) {
		system("cls");
		//enum == 2 para Newton Gregory
		InterpolacaoNewtonOrNewtonGregory(2);
		main();
	}
	else if(op==3) {
		system("cls");
		CoeficienteDeterminacao();
		main();
	}
	else if(op==4) {
		system("cls");
		RotinaAjusteReta();
		main();
	}
	else if(op==5) {
		system("cls");
		//Faltando
		main();
	}
	else if(op==6) {
		system("cls");
		AjusteExponencial();
		main();
	}
	else if(op==7) {
		system("cls");
		rotinaTrapezio();
		main();
	}
	else if(op==8) {
		system("cls");
		RotinaSimpson13();
		main();
	}
	else if(op==9) {
		system("cls");
		RotinaSimpson38();
		main();
	}
	else if(op==10){
		system("exit");
	}
	else {
		main();
	}
}