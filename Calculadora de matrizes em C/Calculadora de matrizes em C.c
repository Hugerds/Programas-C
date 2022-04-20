#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#define lin 15
#define col 15

double vetGeral[lin][col];
int jaFoi = 0;

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


void trocaLinha(int qLinha, int qColuna, double vet[lin][col], int X, int Y) {
	double novoVet[qLinha][qColuna]; 
	int pX, pY, pLinha, pColuna, a1, a2;
	system("cls");
	gotoxy(1,2); printf ("Sua matriz com a linha %d trocada pela linha %d �:\n", X, Y);
	for(pLinha=0;pLinha<qLinha;pLinha++) {
        for(pColuna=0;pColuna<qColuna;pColuna++) {
                a1 = vet[Y][pColuna];
                a2 = vet[X][pColuna];
                vet[Y][pColuna] = a2;
                vet[X][pColuna] = a1;
        }
    }
    for(pY=4, pLinha=0;pLinha<qLinha;pY+=2, pLinha++) {
        for(pX=2, pColuna=0;pColuna<qColuna;pColuna++, pX+=3) {
            gotoxy(pX,pY);
            printf("%.0lf", vet[pLinha][pColuna]);
        }
    }
    printf ("\n\nAperte qualquer tecla para continuar\n");
    getch();
    system("cls");
    printf ("Resetando sistemas...\nAperte qualquer tecla para continuar\n");
    getch();
	system("cls");
	jaFoi = 0;
}

void trocaColuna(int qLinha, int qColuna, double vet[lin][col], int X, int Y) {
	double novoVet[qLinha][qColuna]; 
	int pX, pY, pLinha, pColuna, a1, a2;
	system("cls");
	gotoxy(1,2); printf ("Sua matriz com a coluna %d trocada pela coluna %d �:\n", X, Y);
	for(pLinha=0;pLinha<qLinha;pLinha++) {
        for(pColuna=0;pColuna<qColuna;pColuna++) {
            a1 = vet[pLinha][Y];
            a2 = vet[pLinha][X];
            vet[pLinha][Y] = a2;
            vet[pLinha][X] = a1;
        }
    }
    gotoxy(1,2); printf ("Sua matriz �:\n");
	for(pY=4, pLinha=0;pLinha<qLinha;pY+=2, pLinha++) {
        for(pX=2, pColuna=0;pColuna<qColuna;pColuna++, pX+=3) {
            gotoxy(pX,pY);
            printf("%.0lf", vet[pLinha][pColuna]);
        }
    }
    printf ("\n\nAperte qualquer tecla para continuar\n");
    getch();
    system("cls");
    printf ("Resetando sistemas...\nAperte qualquer tecla para continuar\n");
    getch();
	system("cls");
	jaFoi = 0;
	}
	
void trocaDiagonal(int qLinha, int qColuna, double vet[lin][col], int X, int Y) {
	int pX, pY, pLinha, pColuna, a1, a2;
	double novoVet[qLinha][qColuna];
	system("cls");
        for(pLinha=0;pLinha<qColuna;pLinha++) {
            a1 = vet[pLinha][pLinha];
            a2 = vet[pLinha][qColuna-1-pLinha];
            vet[pLinha][pLinha] = a2;
            vet[pLinha][qColuna-1-pLinha] = a1;
        }
        gotoxy(1,2); printf ("Sua matriz com a digonal prim�ria trocada pela digonal secund�ria �:\n");
		for(pY=4, pLinha=0;pLinha<qLinha;pY+=2, pLinha++) {
	        for(pX=2, pColuna=0;pColuna<qColuna;pColuna++, pX+=3) {
		        gotoxy(pX,pY);
		        printf("%.0lf", vet[pLinha][pColuna]);
		    }
	    }	
	getch();
	system("cls");
	printf ("Resetando sistemas...\nAperte qualquer tecla para continuar\n");
	getch();
	system("cls");
	jaFoi = 0;
	}
	
int ehSimetrica(int qLinha, int qColuna, double vet[lin][col]) {
	int pX, pY, pLinha, pColuna, a1, a2;
	int ehSimetrica = 1;
	system("cls");
		for (pLinha=0; pLinha<qColuna ; pLinha++) {
			for (pColuna=pLinha+1; pColuna<qColuna ; pColuna++) {
				if (vet[pLinha][pColuna] != vet[pColuna][pLinha]) {
					ehSimetrica = 0;
				}
			}
		}
		if (ehSimetrica == 0) {
			return ehSimetrica;
		}
		if (ehSimetrica == 1) {
			return ehSimetrica;
		}
	}
	
int quadradoMagico(int qLinha, int qColuna, double vet[lin][col]) {
	int somaD1=0, somaD2=0, somaL[qColuna], somaC[qLinha], pLinha, pColuna, pX, pY;
		carregamento();
		fflush (stdout);
		fflush (stdin);
		int ret;
		system("cls");
		for(pLinha=0; pLinha<qLinha-1; pLinha++) {
       		for(pColuna=0; pColuna<qColuna; pColuna++) {
            	somaL[pLinha]+=vet[pLinha][pColuna];
       	 	}
    	}
    	for(pLinha=0; pLinha<qColuna-1; pLinha++) {
        	for(pColuna=0; pColuna<qLinha; pColuna++){
           		somaC[pLinha]+=vet[pLinha][pColuna];
        	}
   	 	}
    	for(pLinha=0; pLinha<qLinha; pLinha++) {
      	 	somaD1+=vet[pLinha][pLinha];
   	 	}
    	for(pLinha=0;pLinha<qLinha;pLinha++) {
       		for(pColuna=0;pColuna<qLinha;pColuna++){
            	if(pColuna==(qLinha-1)-pLinha){
                	somaD2+=vet[pLinha][pColuna];
            	}
       	 	}
    	}
    	somaC[2]=somaC[1];
    	somaL[2]=somaL[1];
    	ret = 1;
    	if (somaD1 != somaD2){
        	ret = 0;
    	}
    	for (pLinha=0; pLinha<qLinha; pLinha++){
        	if (somaL[pLinha] != somaC[pLinha]){
            	ret = 0;
        	}
    	}
    	for (pLinha=0; pLinha<qLinha-1; pLinha++){
        	if (somaL[pLinha] != somaL[pLinha+1] || somaC[pLinha] != somaC[pLinha+1]){
            	ret = 0;
        	}
    	}
    	if (somaL[0] != somaD1){
       		ret = 0;
    	}
    	return ret;
}

int quadradoLatino(int qLinha, int qColuna, double vet[lin][col]) {
	int pLinha, pColuna, somaL[qColuna], somaC[qLinha], somaT=0, qL, i, ehQuad = 1, pX, pY;
	carregamento();
	fflush (stdout);
	fflush (stdin);
	system("cls");
	for(i=1; i<=qColuna; i++) {
		somaT+=i;
	}
	// Teste para Linhas //
	for(pColuna=0; pColuna<qColuna; pColuna++) {
		for(pLinha=0; pLinha<qLinha; pLinha++) {
			somaL[pColuna]+=vet[pLinha][pColuna];
		}
	}
	// Teste para Colunas //
	for(pLinha=0; pLinha<qLinha; pLinha++) {
		for(pColuna=0; pColuna<qColuna; pColuna++) {
			somaC[pLinha]+=vet[pLinha][pColuna];
		}
	}
	somaL[2]=somaL[0];
	somaC[2]=somaC[0];
	// Teste Final Linhas //
	for(pColuna=0; pColuna<qLinha && ehQuad == 1; pColuna++) {
		if(somaL[pColuna]!=somaT) {
			ehQuad = 0;
			qL = 0;
			break;
		}
		else 
			qL=1;
	}
	// Teste Final Colunas //
	if (ehQuad == 1) {
		for(pLinha=0; pLinha<qLinha && ehQuad == 1; pLinha++) {
			if(somaC[pLinha]!=somaT) {
				ehQuad = 0;
				qL = 0;
				break;
			}
			else 
				qL=1;
		}
	}
	if(qL==1) {
		ehQuad = 1;
	}
	return ehQuad;
}

int ehPerm(int qLinha, int qColuna, double vet[lin][col]) {
	int pLinha, pColuna, somaL[col], somaC[lin], qL, ehCerta = 1, pX, pY, s;
	carregamento();
	system("cls");
	for (pLinha = 0; pLinha < qColuna; pLinha++) {
    	somaC[pLinha] = 0;
	}
	for (pLinha = 0; pLinha < qColuna && ehCerta == 1; pLinha++) {
    s = 0;
    for (pColuna = 0; pColuna < qColuna && ehCerta == 1; pColuna++) {
      if (vet[pLinha][pColuna] != 1 && vet[pLinha][pColuna] != 0) {
		ehCerta = 0;
	}
      else {
			somaC[pColuna] += vet[pLinha][pColuna];
			s += vet[pLinha][pColuna];
		}
    }
    if(s != 1) {
		ehCerta = 0;
	}
  }

  for(pLinha = 0; pLinha < qColuna && ehCerta == 1; pLinha++) {
    if(somaC[pLinha] != 1)
      ehCerta = 0;
  }
    return ehCerta;
}
	

int main() {
	int qLinha, qColuna, pX, pY, pLinha, pColuna;
	//char op = {"1 - LER MATRIZ", "2 - MOSTRAR MATRIZ", "3 - TROCAR LINHA X/Y", "4 - "};
	setlocale(LC_ALL, "Portuguese");
    int opcao = 1, x = 7;
    bool sair = true;
    double vet[lin][col];

    system("cls");
    system("color 0F");
    gotoxy(18,5); printf("Menu Principal");
    gotoxy(18,7); printf("->");

    while(sair){
    	gotoxy(18,5);  printf("Menu Principal");
        gotoxy(20,7);  printf("1 - LER MATRIZ");
        gotoxy(20,8);  printf("2 - MOSTRAR MATRIZ");
        gotoxy(20,9);  printf("3 - TROCAR LINHA X/Y");
        gotoxy(20,10); printf("4 - TROCAR COLUNA X/Y");
        gotoxy(20,11); printf("5 - TROCAR DIAGONAL PRINCIPAL POR SECUND�RIA");
        gotoxy(20,12); printf("6 - VERIFICAR SE A MATRIZ � SIM�TRICA");
        gotoxy(20,13); printf("7 - VERIFICAR SE A MATRIZ � UM QUADRADO M�GICO");
        gotoxy(20,14); printf("8 - VERIFICAR SE A MATRIZ � UM QUADRADO LATINO");
        gotoxy(20,15); printf("9 - VERIFICAR SE A MATRIZ � UMA MATRIZ DE PERMUTA��O");
        gotoxy(20,16); printf("10 - SAIR");
        

        system("pause>nul");

		if(GetAsyncKeyState(VK_DOWN) && x != 16) {
            gotoxy(18,x); printf("  ");
            x++;
            gotoxy(18,x); printf("->");
            opcao++;
            continue;
        }

		if(GetAsyncKeyState(VK_UP) && x != 7){
            gotoxy(18,x); printf("  ");
            x--;
            gotoxy(18,x); printf("->");
            opcao--;
            continue;
        }

		if(GetAsyncKeyState(VK_RETURN)){
            if (opcao == 1) {
            	if (jaFoi == 1) {
					gotoxy(20,16);
                	printf("\n");
				}
				if (jaFoi == 0) {
                	gotoxy(20,16);
                	printf("OP 1\n");
                	carregamento();
					system("cls");
					do {
						printf ("Quantas linhas ter� sua matriz: "); scanf ("%d", &qLinha);
						printf ("Quntas colunas ter� sua matriz: "); scanf ("%d", &qColuna);
					} while (qLinha > 15 || qLinha < 1 || qColuna < 1 || qColuna > 15);
					system("cls");
					gotoxy(2,1); printf ("Digite os n�meros da matriz desejada...\n");
                    for(pY=4, pLinha=0;pLinha<qLinha;pY+=2, pLinha++) {
                        for(pX=2, pColuna=0;pColuna<qColuna;pColuna++, pX+=3) {
                            gotoxy(pX,pY);
                            scanf("%lf",&vet[pLinha][pColuna]);
                        }
                    }
					Sleep(500);
					system("cls");
					jaFoi = 1;
                	}
            	}
            if (opcao == 2) {
            	if (jaFoi == 0) {
					gotoxy(20,16);
                	printf("\n");
                }
                else {
                	gotoxy(20,16);
                	printf("OP 2\n");
                	carregamento();
                	system("cls");
                	gotoxy(1,2); printf ("Sua matriz �:\n");
					for(pY=4, pLinha=0;pLinha<qLinha;pY+=2, pLinha++) {
                        for(pX=2, pColuna=0;pColuna<qColuna;pColuna++, pX+=3) {
                            gotoxy(pX,pY);
                            printf("%.0lf", vet[pLinha][pColuna]);
                        }
                    }
					getch();
					system("cls");
	            }
	        }
            if (opcao == 3) {
            	int X, Y;
            	if (jaFoi == 0) {
					gotoxy(20,16);
                	printf("\n");
                }
                if (jaFoi == 1) {
                	gotoxy(20,16);
                	carregamento();
                	system("cls");
                	printf("Digite a linha X:"); scanf ("%d", &X);
                	printf("Digite a linha Y:"); scanf ("%d", &Y);
                	trocaLinha(qLinha, qColuna, vet, X, Y);
            	}
            }
            if (opcao == 4) {
            	int X, Y;
            	if (jaFoi == 0) {
					gotoxy(20,16);
                	printf("\n");
                }
                if (jaFoi == 1) {
                	gotoxy(20,16);
                	carregamento();
                	system("cls");
                	printf("Digite a coluna X:"); scanf ("%d", &X);
                	printf("Digite a coluna Y:"); scanf ("%d", &Y);
                	trocaColuna(qLinha, qColuna, vet, X, Y);
            	}
            }
            if (opcao == 5) {
            	int X, Y;
            	if (jaFoi == 0) {
					gotoxy(20,16);
                	printf("\n");
                }
                if (jaFoi == 1) {
                	gotoxy(20,16);
                	carregamento();
                	trocaDiagonal(qLinha, qColuna, vet, X, Y);
            	}
            }
            if (opcao == 6) {
            	int ehS;
            	if (jaFoi == 0) {
					gotoxy(20,16);
                	printf("\n");
                }
                if (jaFoi == 1) {
                	gotoxy(20,16);
                	carregamento();
                	ehS = ehSimetrica(qLinha, qColuna, vet);
                	if (ehS == 1) {
                		printf ("Sua matriz � sim�trica\n\n");
                	}
                	if (ehS == 0) {
                		printf ("Sua matriz n�o � sim�trica\n\n");
					}
					printf ("\n\nAperte qualquer tecla para continuar\n");
					getch();
					system("cls");
					printf ("Resetando sistemas...\nAperte qualquer tecla para continuar\n");
					getch();
					system("cls");
					jaFoi = 0;
            	}
            }
            if (opcao == 7) {
            	if (jaFoi == 0) {
					gotoxy(20,16);
                	printf("\n");
                }
                if (jaFoi == 1) {
                	if(qLinha!=qColuna){
                		carregamento();
                		system("cls");
						printf("A matriz n�o � quadrada.\n");
						printf ("\n\nAperte qualquer tecla para continuar\n");
						getch();
						system("cls");
						printf ("Resetando sistemas...\nAperte qualquer tecla para continuar\n");
						getch();
						system("cls");
						jaFoi = 0;
					}
					if (qLinha == qColuna) {
		                gotoxy(20,16);
		                int ehQm;
		                ehQm = quadradoMagico(qLinha, qColuna, vet);
		                if (ehQm == 1) {
		                	printf ("Sua matriz � um quadrado m�gico\n");
		            	}
		            	if (ehQm == 0) {
		                	printf ("Sua matriz n�o � um quadrado m�gico\n");
		            	}
						printf ("\n\nAperte qualquer tecla para continuar\n");
						getch();
						system("cls");
						printf ("Resetando sistemas...\nAperte qualquer tecla para continuar\n");
						getch();
						system("cls");
						jaFoi = 0;
		            }
	            }
            }
            if (opcao == 8) {
            	int ehQl;
            	if (jaFoi == 0) {
					gotoxy(20,16);
                	printf("\n");
                }
                if (jaFoi == 1) {
                	if(qLinha!=qColuna){
                		carregamento();
                		system("cls");
						printf("A matriz n�o � quadrada.\n");
						printf ("\n\nAperte qualquer tecla para continuar\n");
						getch();
						system("cls");
						printf ("Resetando sistemas...\nAperte qualquer tecla para continuar\n");
						getch();
						system("cls");
						jaFoi = 0;
					}
					if (qLinha == qColuna) {
		                gotoxy(20,16);
		                ehQl = quadradoLatino(qLinha, qColuna, vet);
		                if (ehQl == 1) {
		                	printf ("Sua matriz � um quadrado m�gico\n");
						}
						if (ehQl == 0) {
							printf ("Sua matriz n�o � um quadrado m�gico\n");
						}
						printf ("\n\nAperte qualquer tecla para continuar\n");
						getch();
						system("cls");
						printf ("Resetando sistemas...\nAperte qualquer tecla para continuar\n");
						getch();
						system("cls");
						jaFoi = 0;
		            }
            	}
            }
            if (opcao == 9) {
            	int ehPm;
            	if (jaFoi == 0) {
					gotoxy(20,16);
                	printf("\n");
                }
                if (jaFoi == 1) {
	                gotoxy(20,16);
	                printf("OP 9\n");
	                ehPm = ehPerm(qLinha, qColuna, vet);
	                if (ehPm == 1) {
	                	printf ("Sua matriz � uma matriz de permuta��o\n");
					}
					if (ehPm == 0) {
	                	printf ("Sua matriz n�o � uma matriz de permuta��o\n");
					}
	                printf ("\n\nAperte qualquer tecla para continuar\n");
					getch();
					system("cls");
					printf ("Resetando sistemas...\nAperte qualquer tecla para continuar\n");
					getch();
					system("cls");
					jaFoi = 0;
	            }
        	}
        	if (opcao == 10) {
        		break;
			}
    	}
    }
    gotoxy(20,21);
	return 0;
}
