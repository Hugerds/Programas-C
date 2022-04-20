#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

void gotoxy(int x, int y) {
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void carregamento() {
	setlocale(LC_ALL, "C");
	int i, j;
   system ("cls");
   gotoxy(15,8);printf ("\n\nCarregando: \n\n");          
   for (i = 0; i <= 100; i++) {
      printf ("  %d%%\r", i);
      fflush (stdout);                      
      for (j = 0; j < i; j++) {
         if (!j)
           printf ("  ");
         printf ("%c", 219);
         Sleep(0.9999999999999995);
      }
   }
   printf ("\n\nAguarde...");
   Sleep (1000);
   gotoxy(15,17);printf ("APERTE QUALQUE TECLA PARA CONTINUAR\n\n\n");
   getch();
   fflush (stdin);
   fflush (stdout);
   setlocale(LC_ALL, "Portuguese");
}

void hexaBinario(char num[]) {
	int numNovo[200], numOrdenado[200];
	char numCharOrdem[200], numChar[200];
	long int numFinal;
	int a, b, c;
	printf("%s(16) = ",num);
	for(a=0;a<=16;a++) {
		if (num[a]=='\0') {
			b=a;
			break;
		}
	}
	for(a=0;a<=b;a++) {
		if (num[a]=='0') {
			printf("0000");
		}
		else if(num[a]=='1') {
			printf("0001");
		}
		else if(num[a]=='2') {
			printf("0010");
		}
		else if(num[a]=='3') {
			printf("0011");
		}
		else if(num[a]=='4') {
			printf("0100");
		}
		else if(num[a]=='5') {
			printf("0101");
		}
		else if(num[a]=='6') {
			printf("0110");
		}
		else if(num[a]=='7') {
			printf("0111");
		}
		else if(num[a]=='8') {
			printf("1000");
		}
		else if(num[a]=='9') {
			printf("1001");
		}
		else if(toupper(num[a])=='A') {
			printf("1010");
		}
		else if(toupper(num[a])=='B') {
			printf("1011");
		}
		else if(toupper(num[a])=='C') {
			printf("1100");
		}
		else if(toupper(num[a])=='D') {
			printf("1101");
		}
		else if(toupper(num[a])=='E') {
			printf("1110");
		}
		else if(toupper(num[a])=='F') {
			printf("1111");
		}
	}
	printf("(02)");
}

void hexaOctal(char num[]) {
	long long int a,tam, novoNum=0, octal=0;
	char salvaNum[20];
	strcpy(salvaNum, num);
	for(tam=0; num[tam]!='\0'; tam++);
	for(a=0; num[a]!='\0'; a++,tam--) {
		if(num[a]>='0' && num[a]<='9') {
			novoNum+=(num[a]-'0')*pow(16,tam-1);
		}
		if(num[a]>='A' && num[a]<='F') {
			novoNum+=(num[a]-55)*pow(16,tam-1);
		}
		if(num[a]>='a' && num[a]<='f') {
			novoNum+=(num[a]-87)*pow(16,tam-1);
		}
	}
	a=1;
	while(novoNum!=0) {
		octal+=(novoNum%8)*a;
		novoNum/=8;
		a*=10;
	}
	printf("%s(16) = %lld(08)", salvaNum, octal);
}

void hexaDecimal(char num[]) {
	long long int numNovo[200], potencia2[200], numOrdenado[200], potencia2ordenado[200], vetMult[200], numInt[16];
	long int numFinal;
	int a, b=16, c;
	for(a=0;a<=b;a++) {
		if(num[a]=='0') {
			numInt[a]=0;
		}
		else if(num[a]=='1') {
			numInt[a]=1;
		}
		else if(num[a]=='2') {
			numInt[a]=2;
		}
		else if(num[a]=='3') {
			numInt[a]=3;
		}
		else if(num[a]=='4') {
			numInt[a]=4;
		}
		else if(num[a]=='5') {
			numInt[a]=5;
		}
		else if(num[a]=='6') {
			numInt[a]=6;
		}
		else if(num[a]=='7') {
			numInt[a]=7;
		}
		else if(num[a]=='8') {
			numInt[a]=8;
		}
		else if(num[a]=='9') {
			numInt[a]=9;
		}
		else if(toupper(num[a])=='A') {
			numInt[a]=10;
		}
		else if(toupper(num[a])=='B') {
			numInt[a]=11;
		}
		else if(toupper(num[a])=='C') {
			numInt[a]=12;
		}
		else if(toupper(num[a])=='D') {
			numInt[a]=13;
		}
		else if(toupper(num[a])=='E') {
			numInt[a]=14;
		}
		else if(toupper(num[a])=='F') {
			numInt[a]=15;
		}
		if(num[a]=='\0') {
			b=a;
			break;
		}
	}
	for(a=0;a<=b;a++) {
		potencia2[a] = pow(16, a);
	}
	for(a=b-1, c=0;a>=0;a--, c++) {
		potencia2ordenado[c]=potencia2[a];
	}
	for(a=0;a<b;a++) {
		vetMult[a] = potencia2ordenado[a]*numInt[a];
	}
	for(a=0;a<b;a++) {
		numFinal+=vetMult[a];
	}
	printf("%s(16) = %ld(10)", num, numFinal);
}

void binarioHexa(long long int num) {
	int numHexpossiveis[] = {0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111};
    long long int salvaNum;
    char novoNum[20];
    int aux, i, numSolo;
    salvaNum = num;
    aux = 0;
    while(salvaNum!=0) {
        numSolo = salvaNum % 10000;
        for(i=0; i<16; i++) {
            if(numHexpossiveis[i] == numSolo) {
                if(i<10) {
                    novoNum[aux] = (char)(i + 48);
                }
                else {
                    novoNum[aux] = (char)((i-10) + 65);
                }
                aux++;
                break;
            }
        }
        salvaNum/=10000;
    }
    novoNum[aux] = '\0';
    strrev(novoNum);

    printf("%lld(02) = %s(16)", num, novoNum);
}

void binarioOctal(long long int num) {
	long long int pNum = 0, c1 = 0, resto, numSalvo=num, numFinal = 0, c2 = 1;
    while (num != 0) {
        resto=num%10;
        num/=10;
        pNum+=resto*pow(2, c1);
        ++c1;
    }
    while (pNum!=0) {
        numFinal += (pNum % 8) * c2;
        pNum /= 8;
        c2 *= 10;
    }
    
	printf("%lld(02) = %lld(08)",numSalvo, numFinal);
}

void binarioDecimal(long long int num) {
	int numNovo[200], potencia2[200], numOrdenado[200], potencia2ordenado[200], vetMult[200];
	long int numFinal;
	long long int numSalvo=num;
	int a, b, c;
	for(a=0;num>0;a++) {
		numNovo[a] = num%10;
		num/=10;
		b=a;
	}
	for(a=0;a<=b;a++) {
		potencia2[a] = pow(2, a);
	}
	for(a=b, c=0;a>=0;a--, c++) {
		numOrdenado[c]=numNovo[a];
	}
	for(a=b, c=0;a>=0;a--, c++) {
		potencia2ordenado[c]=potencia2[a];
	}
	for(a=0;a<=b;a++) {
		vetMult[a] = potencia2ordenado[a]*numOrdenado[a];
	}
	for(a=0;a<=b;a++) {
		numFinal+=vetMult[a];
	}
	printf("%lld(02) = %ld(10)",numSalvo, numFinal);
}

void octalHexa(long long int num) {
	int numOctpossiveis[] = {0, 1, 10, 11, 100, 101, 110, 111}, aux;
    long long int salvaNum=num, numBin=0, a = 1;
    char hex[65] = "";
    while(salvaNum > 0) {
        aux=salvaNum%10;
        numBin = (numOctpossiveis[aux] * a) + numBin;
        salvaNum /= 10;
        a*=1000;
    }
    while(numBin > 0) {
        aux = numBin % 10000;
        switch(aux) {
            case 0:
                strcat(hex, "0");
                break;
            case 1:
                strcat(hex, "1");
                break;
            case 10:
                strcat(hex, "2");
                break;
            case 11:
                strcat(hex, "3");
                break;
            case 100:
                strcat(hex, "4");
                break;
            case 101:
                strcat(hex, "5");
                break;
            case 110:
                strcat(hex, "6");
                break;
            case 111:
                strcat(hex, "7");
                break;
            case 1000:
                strcat(hex, "8");
                break;
            case 1001:
                strcat(hex, "9");
                break;
            case 1010:
                strcat(hex, "A");
                break;
            case 1011:
                strcat(hex, "B");
                break;
            case 1100:
                strcat(hex, "C");
                break;
            case 1101:
                strcat(hex, "D");
                break;
            case 1110:
                strcat(hex, "E");
                break;
            case 1111:
                strcat(hex, "F");
            break;
        }

        numBin/=10000;
    }
    strrev(hex);
    printf("%lld(08) = %s(16)", num, hex);
}

void octalBinario(long long int num) {
	int numNovo[200], numOrdenado[200];
	char numCharOrdem[200];
	long long int numFinal, numSalvo=num;
	int a, b, c;
	for(a=0;num>0;a++) {
		numNovo[a] = num%10;
		num/=10;
		b=a;
	}
	for(a=b, c=0;a>=0;a--, c++) {
		numOrdenado[c]=numNovo[a];
		numCharOrdem[c]=numNovo[a];
	}
	printf("%lld(08) = ",numSalvo);
	for(a=0;a<=b;a++) {
		if (numOrdenado[a]==0) {
			printf("000");
		}
		else if(numOrdenado[a]==1) {
			printf("001");
		}
		else if(numOrdenado[a]==2) {
			printf("010");
		}
		else if(numOrdenado[a]==3) {
			printf("011");
		}
		else if(numOrdenado[a]==4) {
			printf("100");
		}
		else if(numOrdenado[a]==5) {
			printf("101");
		}
		else if(numOrdenado[a]==6) {
			printf("110");
		}
		else if(numOrdenado[a]==7) {
			printf("111");
		}
	}
	printf("(02)");
}

void octalDecimal(long long int num) {
	long long int numNovo[200], potencia2[200], numOrdenado[200], potencia2ordenado[200], vetMult[200];
	long long int numFinal, numSalvo=num;
	int a, b, c;
	for(a=0;num>0;a++) {
		numNovo[a] = num%10;
		num/=10;
		b=a;
	}
	for(a=0;a<=b;a++) {
		potencia2[a] = pow(8, a);
	}
	for(a=b, c=0;a>=0;a--, c++) {
		numOrdenado[c]=numNovo[a];
	}
	for(a=b, c=0;a>=0;a--, c++) {
		potencia2ordenado[c]=potencia2[a];
	}
	for(a=0;a<=b;a++) {
		vetMult[a] = potencia2ordenado[a]*numOrdenado[a];
	}
	for(a=0;a<=b;a++) {
		numFinal+=vetMult[a];
	}
	if (numFinal<10) {
		printf("%lld(08) = 0%lld(10)",numSalvo, numFinal);
	}
	else {
		printf("%lld(08) = %lld(10)",numSalvo, numFinal);
	}	
}

void decimalOctal(long long int num) {
	long long int novoNum=0, a=1, salvaNum=num;
    while (num!=0) {
        novoNum+=(num%8)*a;
        num/=8;
        a*=10;
    }
    printf("%lld(10) = ", salvaNum);
    printf("%lld", novoNum);
    printf("(08)");
}

void decimalBinario(long long int num) {
	int a, ehDivisivel=0, deuZero=0, b;
	long long int salvaNum=num, aux;
	int numNovo[50];
	for(a=0;a<1000 || deuZero==1;a++) {
		if (num%2==0) {
			numNovo[a]=0;
		}
		else if(num%2==1) {
			numNovo[a]=1;
		}
		if(num==1) {
			deuZero==1;
			aux = a;
			break;
		}
		num/=2;
	}
	printf("%lld(10) = ", salvaNum);
	for(a=aux;a>=0;a--) {
		printf("%d", numNovo[a]);
	}
	printf("(02)");
}

void decimalHexa(long long int num) {
	long long int novoNum=0, a=1, b=0, c=0, salvaNum=num;
	int numOrdenado[20], numNovo[20], vetOrdenado[20];
	char numFinal[20];
	for(a=0;num>0;a++) {
		//printf("%lld\n", (num%16));
		numNovo[a] = (num%16);
		num/=16;
		b=a;
	}
    for(a=b, c=0;a>=0;a--, c++) {
		vetOrdenado[c]=numNovo[a];
	}
	printf("%lld(10) = ", salvaNum);
	for(a=0;a<=b;a++) {
		if(vetOrdenado[a]==0) {
			printf("%d", vetOrdenado[a]);
		}
		else if(vetOrdenado[a]==1) {
			printf("%d", vetOrdenado[a]);
		}
		else if(vetOrdenado[a]==2) {
			printf("%d", vetOrdenado[a]);
		}
		else if(vetOrdenado[a]==3) {
			printf("%d", vetOrdenado[a]);
		}
		else if(vetOrdenado[a]==4) {
			printf("%d", vetOrdenado[a]);
		}
		else if(vetOrdenado[a]==5) {
			printf("%d", vetOrdenado[a]);
		}
		else if(vetOrdenado[a]==6) {
			printf("%d", vetOrdenado[a]);
		}
		else if(vetOrdenado[a]==7) {
			printf("%d", vetOrdenado[a]);
		}
		else if(vetOrdenado[a]==8) {
			printf("%d", vetOrdenado[a]);
		}
		else if(vetOrdenado[a]==9) {
			printf("%d", vetOrdenado[a]);
		}
		else if(vetOrdenado[a]==10) {
			printf("A");
		}
		else if(vetOrdenado[a]==11) {
			printf("B");
		}
		else if(vetOrdenado[a]==12) {
			printf("C");
		}
		else if(vetOrdenado[a]==13) {
			printf("D");
		}
		else if(vetOrdenado[a]==14) {
			printf("E");
		}
		else if(vetOrdenado[a]==15) {
			printf("F");
		}
	}
	printf("(16)");
}

int confereHexa(char num[]) {
	int a, b, res;
	int numInt[20];
	for(a=0;a<=16;a++) {
		if (num[a]=='\0') {
			b=a;
			break;
		}
	}
	for(a=0;a<=b;a++) {
		if(num[a]=='0') {
			numInt[a]=0;
		}
		else if(num[a]=='1') {
			numInt[a]=1;
		}
		else if(num[a]=='2') {
			numInt[a]=2;
		}
		else if(num[a]=='3') {
			numInt[a]=3;
		}
		else if(num[a]=='4') {
			numInt[a]=4;
		}
		else if(num[a]=='5') {
			numInt[a]=5;
		}
		else if(num[a]=='6') {
			numInt[a]=6;
		}
		else if(num[a]=='7') {
			numInt[a]=7;
		}
		else if(num[a]=='8') {
			numInt[a]=8;
		}
		else if(num[a]=='9') {
			numInt[a]=9;
		}
		else if(toupper(num[a])=='A') {
			numInt[a]=10;
		}
		else if(toupper(num[a])=='B') {
			numInt[a]=11;
		}
		else if(toupper(num[a])=='C') {
			numInt[a]=12;
		}
		else if(toupper(num[a])=='D') {
			numInt[a]=13;
		}
		else if(toupper(num[a])=='E') {
			numInt[a]=14;
		}
		else if(toupper(num[a])=='F') {
			numInt[a]=15;
		}
	}
	for(a=b;a<=b;a++) {
		if (numInt[a]=='0') {
			res=1;
		}
		else if(numInt[a]==1) {
			res=1;
		}
		else if(numInt[a]==2) {
			res=1;
		}
		else if(numInt[a]==3) {
			res=1;
		}
		else if(numInt[a]==4) {
			res=1;
		}
		else if(numInt[a]==5) {
			res=1;
		}
		else if(numInt[a]==6) {
			res=1;
		}
		else if(numInt[a]==7) {
			res=1;
		}
		else if(numInt[a]==8) {
			res=1;
		}
		else if(numInt[a]==9) {
			res=1;
		}
		else if(numInt[a]==10) {
			res=1;
		}
		else if(numInt[a]==11) {
			res=1;
		}
		else if(numInt[a]==12) {
			res=1;
		}
		else if(numInt[a]==13) {
			res=1;
		}
		else if(numInt[a]==14) {
			res=1;
		}
		else if(numInt[a]==15) {
			res=1;
		}
		else {
			res=0;
			break;
		}
	}
	return res;
}

int confereZeros(long long int num) {
	int numNovo[200];
	int a, b, res;
	for(a=0;num>0;a++) {
		numNovo[a] = num%10;
		num/=10;
		b=a;
	}
	for(a=b;a>=0;a--) {
		if(numNovo[a] < 0 || numNovo[a] > 1) {
			res=0;
		}
		else if (numNovo[a]==0 || numNovo[a]==1){
			res=1;
		}
	}
	return res;
}

int confereOito(long long int num) {
	int numNovo[200];
	int a, b, res;
	if (num>777777777777777) {
		res=0;
	}
	for(a=0;num>0;a++) {
		numNovo[a] = num%10;
		num/=10;
		b=a;
	}
	for(a=b;a>=0;a--) {
		if(numNovo[a] <= -1|| numNovo[a] >= 8) {
			res=0;
		}
		else if (numNovo[a]>=0 || numNovo[a]<=7){
			res=1;
		}
	}
	return res;
}

void montaQuadrado() {
	int a, x, y; // 45 LADO // 10 ALTURA
	for(a=0, y=6;a<=7;a++,y++) {
		gotoxy(17, y);
		printf("|");
	}
	for(a=0, y=6;a<=7;a++,y++) {
		gotoxy(59, y);
		printf("|");
	}
	for(a=0, x=18;a<=40;a++,x++) {
		gotoxy(x, 5);
		printf("_");
	}
	for(a=0, x=18;a<=40;a++,x++) {
		gotoxy(x, 13);
		printf("_");
	}
}

void montaMenu() {
	int a, x, y; // 45 LADO // 10 ALTURA
	for(a=0, y=1;a<17;a++,y++) {
		gotoxy(17, y);
		printf("|");
	}
	for(a=0, y=1;a<17;a++,y++) {
		gotoxy(90, y);
		printf("|");
	}
	for(a=0, x=18;a<=71;a++,x++) {
		gotoxy(x, 0);
		printf("_");
	}
	for(a=0, x=18;a<=71;a++,x++) {
		gotoxy(x, 17);
		printf("_");
	}
	gotoxy(20,3); printf("CONVERSOR DE BASES NUM�RICAS");
	gotoxy(20,5);  printf("Menu Principal");
    gotoxy(20,7);  printf("1 - N�MERO OCTAL PARA TODAS AS BASES");
    gotoxy(20,8);  printf("2 - N�MERO BIN�RIO PARA TODAS AS BASES");
    gotoxy(20,9);  printf("3 - N�MERO DECIMAL PARA TODAS AS BASES");
    gotoxy(20,10); printf("4 - N�MERO HEXADECIMAL PARA TODAS AS BASES");
    gotoxy(20,20); printf("Desenvolvido por Hugo Esteves");
}

void menu() {
	int op, op2;
	long long int num;
	char numChar[16];
	system("cls");
	montaMenu();
	do {
		fflush(stdin);
		gotoxy(20,12); printf("SUA OP��O: ");
		scanf("%d", &op);
		fflush(stdout);
		gotoxy(20,12); printf("SUA OP��O:       ");
	} while(op<0 || op>4);
	do {
		if(op==4) {
			fflush(stdin);
			gotoxy(20, 13); printf("Insira o n�mero que voc� deseja converter: ");
			gets(numChar);
			fflush(stdout);
			gotoxy(20, 14); printf("Seu n�mero escolhido foi o %s", numChar);
			gotoxy(20, 15); system("pause");
		}
		else {
			fflush(stdin);
			gotoxy(20, 13); printf("Insira o n�mero que voc� deseja converter (MAX 999999999999999): ");
			gotoxy(20, 14); printf("Sua op��o: "); scanf("%lld", &num);
			fflush(stdout);
			gotoxy(20, 15); printf("Seu n�mero escolhido foi o %lld", num);
			gotoxy(20, 16); system("pause");
		}
	} while (num<0 || num>999999999999999);
	if (op==1) {
		int res8 = confereOito(num);
		if(res8==0) {
			carregamento();
			system("cls");
			printf("\nVoc� inseriu um n�mero octal inv�lido, voltando ao menu principal...\n");
			system("pause");
			menu();
		}
		else if(res8==1){
			carregamento();
			system("cls");
			montaQuadrado();
			gotoxy(20,7); printf("%lld(08) = %lld(08)", num, num);
			gotoxy(20,8); octalBinario(num);
			gotoxy(20,9); octalDecimal(num);
			gotoxy(20,10); octalHexa(num);
			gotoxy(20,12); system("pause");
			do {
				system("cls");
				montaQuadrado();
				gotoxy(20,7); printf("Deseja usar o programa novamente?");
				gotoxy(20,8); printf("1- Sim");
				gotoxy(20,9); printf("2- N�o");
				gotoxy(20,10); printf("Sua op��o: ");
				gotoxy(31,10); scanf("%d", &op2);
				getchar();
			} while(op2<=0 || op2>2);
			if(op2==1) {
				menu();
			}
			else {
				system("exit");
			}
		}
	}
	else if (op==2) {
		int res0 = confereZeros(num);
		if(res0==0) {
			carregamento();
			system("cls");
			printf("\nVoc� inseriu um n�mero bin�rio inv�lido, voltando ao menu principal...\n");
			system("pause");
			menu();
		}
		else if(res0==1){
			carregamento();
			system("cls");
			montaQuadrado();
			gotoxy(20,7); printf("%lld(02) = %lld(02)", num, num);
			gotoxy(20,8); binarioOctal(num);
			gotoxy(20,9); binarioDecimal(num);
			gotoxy(20,10); binarioHexa(num);
			gotoxy(20,11); system("pause");
			do {
				system("cls");
				gotoxy(20,7); printf("Deseja usar o programa novamente?");
				gotoxy(20,8); printf("1- Sim");
				gotoxy(20,9); printf("2- N�o");
				gotoxy(20,10); printf("Sua op��o: ");
				gotoxy(31,10); scanf("%d", &op2);
				getchar();
			} while(op2<=0 || op2>2);
			if(op2==1) {
				menu();
			}
			else {
				system("exit");
			}
		}
	}
	else if (op==3) {
		carregamento();
		system("cls");
		montaQuadrado();
		gotoxy(20,7); printf("%lld(10) = %lld(10)", num, num);
		gotoxy(20,8); decimalOctal(num);
		gotoxy(20,9); decimalBinario(num);
		gotoxy(20,10); decimalHexa(num);
		gotoxy(20,11); system("pause");
		do {
			system("cls");
			gotoxy(20,7); printf("Deseja usar o programa novamente?");
			gotoxy(20,8); printf("1- Sim");
			gotoxy(20,9); printf("2- N�o");
			gotoxy(20,10); printf("Sua op��o: ");
			gotoxy(31,10); scanf("%d", &op2);
			getchar();
			} while(op2<=0 || op2>2);
		if(op2==1) {
			menu();
		}
		else {
			system("exit");
		}
	}
	else if(op==4){
		//int res16 = confereHexa(numChar);
		carregamento();
		system("cls");
		montaQuadrado();
		gotoxy(20,7); printf("%s(16) = %s(16)", numChar, numChar);
		gotoxy(20,8); hexaDecimal(numChar);
		gotoxy(20,9); hexaOctal(numChar);
		gotoxy(20,10); hexaBinario(numChar);
		gotoxy(20,11); system("pause");
		do {
			system("cls");
			gotoxy(20,7); printf("Deseja usar o programa novamente?");
			gotoxy(20,8); printf("1- Sim");
			gotoxy(20,9); printf("2- N�o");
			gotoxy(20,10); printf("Sua op��o: ");
			gotoxy(31,10); scanf("%d", &op2);
			getchar();
		} while(op2<=0 || op2>2);
		if(op2==1) {
			menu();
		}
	}
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	menu();
}