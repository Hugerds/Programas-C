// Hugo Esteves Rezende de Deus Santos - BSI - ALG 1.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <conio.h>

int main () {
	system ("color 0E"); // cor de fundo preta e letras azuis brilhantes
    //Aceitar acentos.
    setlocale(LC_ALL, "Portuguese");
	// Declarar as vari�veis, double para precis�o.
	int a, radianoougrau;
	double opmenu, conta, containversa, reprocessar, seno, cosseno, tangente, secante, cossecante, cotangente, arcoseno, arcocosseno, arcotangente, angulo, radianos, reprocessamento = 1, arcs, arcc, arct;
	//Reprocessamento Falso
	while (reprocessamento!=1) {
		system("cls");
		printf ("\nFechando o programa.");
		exit;
		}
	//Reprocessamento Verdadeiro
	while (reprocessamento==1) {
		//Limpar a tela.
		system("cls");
		//Menu Principal.
		printf ("Menu Principal\n\nEscolha o n�mero correspondente a op��o que deseja calcular\n\n1. Seno\n2. Cosseno\n3. Tangente\n4. Secante\n5. Cossecante\n6. Cotangente\n7. Arco Seno\n8. Arco Cosseno\n9. Arco Tangente\n\n");
		//Op��o do menu.
		printf ("Digite sua op��o: ");
		scanf ("%d", &a);
		getchar ();
		//IF Com todas as op��es do Menu
			if (a==1) {
				//Escolha Seno
				system ("cls"); // Limpa Tela
				printf ("Voc� escolheu a op��o Seno, deseja saber o c�lculo em graus ou em radianos?\n\n1. Graus\n2. Radianos\n\n"); // Rad ou Grau para Seno
				printf ("Digite sua op��o: "); 
				scanf ("%d", &radianoougrau);
				getchar ();
				// Caso n�o escolha uma op��o v�lida, volta para o menu de reprocessamento
					if (radianoougrau<1 || radianoougrau>2) {
						while (radianoougrau<1 || radianoougrau>2) {
							printf ("\n\nOp��o inv�lida\n\n");
							printf ("Digite a op��o desejada: ");
							scanf ("%d", &radianoougrau);
							getchar ();
								} 
							}
						//Switch p/ escolher a op��o grau.
				if (radianoougrau==1) {
					system ("cls");
					printf ("Voc� escolheu a op��o Graus, digite em graus o valor que deseja calcular o seno:\n\n");
					printf ("Digite o valor: ");
					scanf("%lf", &angulo);
					getchar ();
					system ("cls");
					containversa=angulo*M_PI/180; printf ("Sua op��o: %lf� equivale a %f radianos.\n", angulo, containversa);
					printf ("O seno de %lf� � igual a %lf", angulo, sin(angulo*M_PI/180));
					printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
					printf ("Digite a op��o desejada: ");
					scanf ("%lf", &reprocessamento);
					}
					//Se escolher Radianos
				if (radianoougrau==2) {
					system ("cls");
					printf ("Voc� escolheu a op��o Radianos, digite em radianos o valor que deseja calcular o seno:\n\n");
					printf ("Digite o valor: ");
					scanf("%lf", &radianos);
					getchar ();
					system ("cls");
					conta=radianos*180/M_PI; printf ("Sua op��o: %lf radianos equivale a %lf�\n", radianos, conta);
					printf ("O seno de %lf � igual a %lf", radianos, sin(radianos));
					printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
					printf ("Digite a op��o desejada: ");
					scanf ("%lf", &reprocessamento);	
					}
					}
			if (a==2) {
				system ("cls");
				printf ("Voc� escolheu a op��o Cosseno, deseja saber o c�lculo em graus ou em radianos?\n\n1. Graus\n2. Radianos\n\n");
				printf ("Digite sua op��o: ");
				scanf("%d", &radianoougrau);
				getchar ();
					if (radianoougrau<1 || radianoougrau>2) {
						while (radianoougrau<1 || radianoougrau>2) {
							printf ("\n\nOp��o inv�lida\n\n");
							printf ("Digite a op��o desejada: ");
							scanf ("%d", &radianoougrau); getchar ();
							}
						}
					//Switch p/ escolher a op��o grau.
					if (radianoougrau==1) {
						system ("cls");
						printf ("Voc� escolheu a op��o Graus, digite em graus o valor que deseja calcular o coseno:\n\n");
						printf ("Digite o valor: ");
						scanf("%lf", &angulo); getchar ();
						system ("cls");
						containversa=angulo*M_PI/180; printf ("Sua op��o: %lf� equivale a %f radianos.\n", angulo, containversa);
						printf ("O cosseno de %lf� � igual a %lf", angulo, cos(angulo*M_PI/180));
						printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
						printf ("Digite a op��o desejada: ");
						scanf ("%lf", &reprocessamento);
						}	
						//Switch p/ escolher radianos
					if (radianoougrau==2) {
						system ("cls");
						printf ("Voc� escolheu a op��o Radianos, digite em radianos o valor que deseja calcular o cosseno:\n\n");
						printf ("Digite o valor: ");
						scanf("%lf", &radianos); getchar (); 
						system ("cls");
						conta=radianos*180/M_PI; printf ("Sua op��o: %lf radianos equivale a %lf�\n", radianos, conta);
						printf ("O cosseno de %lf � igual a %lf", radianos, cos(radianos));
						printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
						printf ("Digite a op��o desejada: ");
						scanf ("%lf", &reprocessamento);
							}
						}
			if (a==3) {
				system ("cls");
				printf ("Voc� escolheu a op��o Tangente, deseja saber o c�lculo em graus ou em radianos?\n\n1. Graus\n2. Radianos\n\n");
				printf ("Digite sua op��o: ");
				scanf ("%d", &radianoougrau); getchar ();
					if (radianoougrau<1 || radianoougrau>2) {
						while (radianoougrau<1 || radianoougrau>2) {
							printf ("\n\nOp��o inv�lida\n\n");
							printf ("Digite a op��o desejada: ");
							scanf ("%d", &radianoougrau);
							} 
						}
					//Switch p/ escolher a op��o grau.
					if (radianoougrau==1) {
						system ("cls");
						printf ("Voc� escolheu a op��o Graus, digite em graus o valor que deseja calcular a tangente:\n\n");
						printf ("Digite o valor: ");
						scanf("%lf", &angulo); getchar ();
						system ("cls");
					if	(angulo==90 || angulo==270)
            			printf("A tangente de %f� n�o existe.", angulo);
					else {
						containversa=angulo*M_PI/180; printf ("Sua op��o: %lf� equivale a %f radianos.\n", angulo, containversa);
						printf ("A tangente de %lf� � igual a %lf", angulo, tan(angulo*M_PI/180)); }
						printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
						printf ("Digite a op��o desejada: ");
						scanf ("%lf", &reprocessamento);
						}
					//Switch p/ escolher radianos
					if (radianoougrau==2) {
						system ("cls");
						printf ("Voc� escolheu a op��o Radianos, digite em radianos o valor que deseja calcular a tangente:\n\n");
						printf ("Digite o valor: ");
						scanf("%lf", &radianos); getchar ();
						system ("cls");
					if	(radianos==1.5708 || radianos==4.71239)
            			printf("A tangente de %f radianos n�o existe.", radianos);
					else {
						conta=radianos*180/M_PI; printf ("Sua op��o: %lf radianos equivale a %lf�\n", radianos, conta);
						printf ("A tangente de %lf � igual a %lf", radianos, tan(radianos)); }
						printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
						printf ("Digite a op��o desejada: ");
						scanf ("%lf", &reprocessamento);
						}
						}
			if (a==4) {
				system ("cls");
				printf ("Voc� escolheu a op��o Secante, deseja saber o c�lculo em graus ou em radianos?\n\n1. Graus\n2. Radianos\n\n");
				printf ("Digite sua op��o: ");
				scanf("%d", &radianoougrau); getchar ();
					if (radianoougrau<1 || radianoougrau>2) {
						while (radianoougrau<1 || radianoougrau>2) {
							printf ("\n\nOp��o inv�lida\n\n");
							printf ("Digite a op��o desejada: ");
							scanf ("%d", &radianoougrau);
							} 
						}
					if (radianoougrau==1) {
						system ("cls");
						printf ("Voc� escolheu a op��o Graus, digite em graus o valor que deseja calcular a secante:\n\n");
						printf ("Digite o valor: ");
						scanf("%lf", &angulo); getchar ();
						system ("cls");
					if	(angulo==90 || angulo==270)
           				printf("A secante de %f� n�o existe", angulo);
					else {
						containversa=angulo*M_PI/180; printf ("Sua op��o: %lf� equivale a %f radianos.\n", angulo, containversa);
						printf ("A secante de %lf� � igual a %lf", angulo, 1/cos(angulo*M_PI/180)); }
						printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
						printf ("Digite a op��o desejada: ");
						scanf ("%lf", &reprocessamento);
						}
					//Switch p/ escolher radianos
					if (radianoougrau==2) {
						system ("cls");
						printf ("Voc� escolheu a op��o Radianos, digite em radianos o valor que deseja calcular a secante:\n\n");
						printf ("Digite o valor: ");
						scanf("%lf", &radianos); getchar ();
						system ("cls");
					if	(radianos==1.5708 || radianos==4.71239)
           				printf("A secante de %f radianos n�o existe", radianos);
					else {
						conta=radianos*180/M_PI; printf ("Sua op��o: %lf radianos equivale a %lf�\n", radianos, conta);
						printf ("A secante de %lf � igual a %lf", radianos, 1/cos(radianos)); }
						printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
						printf ("Digite a op��o desejada: ");
						scanf ("%lf", &reprocessamento);
						}
						}
			if (a==5) {
				system ("cls");
				printf ("Voc� escolheu a op��o Cossecante, deseja saber o c�lculo em graus ou em radianos?\n\n1. Graus\n2. Radianos\n\n");
				printf ("Digite sua op��o: ");
				scanf("%d", &radianoougrau); getchar ();
					if (radianoougrau<1 || radianoougrau>2) {
						while (radianoougrau<1 || radianoougrau>2) {
							printf ("\n\nOp��o inv�lida\n\n");
							printf ("Digite a op��o desejada: ");
							scanf ("%d", &radianoougrau);
							} 
						}
					//Switch p/ escolher a op��o grau.
					if (radianoougrau==1) {
						system ("cls");
						printf ("Voc� escolheu a op��o Graus, digite em graus o valor que deseja calcular a cossecante:\n\n");
						printf ("Digite o valor: ");
						scanf("%lf", &angulo); getchar ();
						system ("cls");
					if	(angulo==0 || angulo==180 || angulo==360)
            			printf ("A cossecante de %f� n�o existe", angulo);
					else {
						containversa=angulo*M_PI/180; printf ("Sua op��o: %lf� equivale a %f radianos.\n", angulo, containversa);
						printf ("A cossecante de %lf� � igual a %lf", angulo, 1/sin(angulo*M_PI/180)); }
						printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
						printf ("Digite a op��o desejada: ");
						scanf ("%lf", &reprocessamento);
						}		
					//Switch p/ escolher radianos
					if (radianoougrau==2) {
						system ("cls");
						printf ("Voc� escolheu a op��o Radianos, digite em radianos o valor que deseja calcular a cossecante:\n\n");
						printf ("Digite o valor: ");
						scanf("%lf", &radianos); getchar ();
						system ("cls");
					if	(radianos==0 || radianos==3.14159 || radianos==6.28319)
            			printf("A cossecante de %f n�o existe", radianos);
					else {
						conta=radianos*180/M_PI; printf ("Sua op��o: %lf radianos equivale a %lf�\n", radianos, conta); }
						printf ("A cossecante de %lf � igual a %lf", radianos, 1/sin(radianos));
						printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
						printf ("Digite a op��o desejada: ");
						scanf ("%lf", &reprocessamento);
						}
						}
			if (a==6) {
				system ("cls");
				printf ("Voc� escolheu a op��o Cotangente, deseja saber o c�lculo em graus ou em radianos?\n\n1. Graus\n2. Radianos\n\n");
				printf ("Digite sua op��o: ");
				scanf("%d", &radianoougrau); getchar ();
					if (radianoougrau<1 || radianoougrau>2) {
						while (radianoougrau<1 || radianoougrau>2) {
							printf ("\n\nOp��o inv�lida\n\n");
							printf ("Digite a op��o desejada: ");
							scanf ("%d", &radianoougrau);
							} 
						}
					//Switch p/ escolher a op��o grau.
					if (radianoougrau==1) {
						system ("cls");
						printf ("Voc� escolheu a op��o Graus, digite em graus o valor que deseja calcular a cotangente:\n\n");
						printf ("Digite o valor: ");
						scanf("%lf", &angulo); getchar ();
						system ("cls");
					if	(angulo==0 || angulo==180 || angulo==360)
            			printf("A cotangente de %f n�o existe", angulo);
					else {
						containversa=angulo*M_PI/180; printf ("Sua op��o: %lf� equivale a %f radianos.\n", angulo, containversa);
						printf ("A cotangente de %lf� � igual a %lf", angulo, 1/tan(angulo*M_PI/180)); }
						printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
						printf ("Digite a op��o desejada: ");
						scanf ("%lf", &reprocessamento);
						}		
						//Switch p/ escolher radianos
						if (radianoougrau==2) {
							system ("cls");
							printf ("Voc� escolheu a op��o Radianos, digite em radianos o valor que deseja calcular a cotangente:\n\n");
							printf ("Digite o valor: ");
							scanf("%lf", &radianos); getchar ();
							system ("cls");
						if	(radianos==0 || radianos==3.14159 || radianos==6.28319)
            				printf("A cotangente de %f� n�o existe", radianos);
						else {
							conta=radianos*180/M_PI; printf ("Sua op��o: %lf radianos equivale a %lf�\n", radianos, conta);
							printf ("A cotangente de %lf � igual a %lf", radianos, 1/tan(radianos)); }
							printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
							printf ("Digite a op��o desejada: ");
							scanf ("%lf", &reprocessamento);
							}
						}
			if (a==7) {
				system ("cls");
				printf ("Voc� escolheu a op��o Arco Seno, deseja saber o arco correspondente em graus ou em radianos?\n\n1. Graus\n2. Radianos\n\n");
				printf ("Digite sua op��o: ");
				scanf("%d", &radianoougrau); getchar ();
				if (radianoougrau<1 || radianoougrau>2) {
					while (radianoougrau<1 || radianoougrau>2) {
						printf ("\n\nOp��o inv�lida\n\n");
						printf ("Digite a op��o desejada: ");
						scanf ("%d", &radianoougrau);
							} 
						}
				//Switch p/ escolher a op��o grau.
				if (radianoougrau==1) {
					system ("cls");
					printf ("Voc� escolheu a op��o Graus, digite o valor do seno para calcular o Arco Seno:\n\n");
					printf ("Digite o valor: ");
					scanf("%lf", &angulo); getchar ();
						if (angulo>1 || angulo<-1) {
							while (angulo>1 || angulo<-1) {
								printf ("Valor inv�lido, digite novamente: "); scanf ("%lf", &angulo); getchar ();
								}
							}
				if (angulo<=1 || angulo >=-1) {
				system ("cls");
				conta=angulo*180/M_PI; containversa=angulo*M_PI/180; printf ("Sua op��o: %lf equivale a %lf�\n", angulo, conta);
				arcs=asin(angulo);
				printf ("O arco seno de %lf � igual a %lf�", angulo, arcs*180/M_PI);
				printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
				printf ("Digite a op��o desejada: ");
				scanf ("%lf", &reprocessamento);
					}
				}
				//Switch p/ escolher radianos
				if (radianoougrau==2) {		
					system ("cls");
					printf ("Voc� escolheu a op��o Radianos, digite o valor do cosseno para calcular o arco seno:\n\n");
					printf ("Digite o valor: ");
					scanf("%lf", &radianos); getchar ();
						if (radianos>1 || radianos<-1) {
							while (radianos>1 || radianos<-1) {
								printf ("Valor inv�lido, digite novamente: "); scanf ("%lf", &radianos); getchar ();
							}
						}
					system ("cls");
					conta=radianos*180/M_PI; printf ("Sua op��o: %lf equivale a %lf�\n", radianos, conta);
					printf ("O arco seno de %lf � igual a %lf", radianos, asin(radianos));
					printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
					printf ("Digite a op��o desejada: ");
					scanf ("%lf", &reprocessamento);
						}
					}
			if (a==8) {
				system ("cls");
				printf ("Voc� escolheu a op��o Arco Cosseno, deseja saber o arco correspondente em graus ou em radianos?\n\n1. Graus\n2. Radianos\n\n");
				printf ("Digite sua op��o: ");
				scanf("%d", &radianoougrau); getchar ();
					if (radianoougrau<1 || radianoougrau>2) {
						while (radianoougrau<1 || radianoougrau>2) {
							printf ("\n\nOp��o inv�lida\n\n");
							printf ("Digite a op��o desejada: "); getchar ();
							scanf ("%d", &radianoougrau); 
							}  
						}
					//Switch p/ escolher a op��o grau.
					if (radianoougrau==1) {
							system ("cls");
							printf ("Voc� escolheu a op��o Graus, digite o valor do cosseno para calcular o Arco Cosseno:\n\n");
							printf ("Digite o valor: ");
							scanf("%lf", &angulo); getchar ();
							if (angulo>1 || angulo<-1) {
									while (angulo>1 || angulo<-1) {
									printf ("Valor inv�lido, digite novamente: "); scanf ("%lf", &angulo);
									} 
								}
							if (angulo<=1 || angulo >=-1) {
								system ("cls");
								conta=angulo*180/M_PI; containversa=angulo*M_PI/180; printf ("Sua op��o: %lf equivale a %lf�\n", angulo, conta);
								arcs=acos(angulo);
								printf ("O arco cosseno de %lf � igual a %lf�", angulo, arcs*180/M_PI);
								printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
								printf ("Digite a op��o desejada: ");
								scanf ("%lf", &reprocessamento); getchar ();
								}
							}			
					//Switch p/ escolher radianos
					if (radianoougrau==2) {
						system ("cls");
						printf ("Voc� escolheu a op��o Radianos, digite o valor do cosseno para calcular o Arco Cosseno:\n\n");
						printf ("Digite o valor: ");
						scanf("%lf", &radianos); getchar ();
							if (radianos>1 || radianos<-1) {
									while (radianos>1 || radianos<-1) {
										printf ("Valor inv�lido, digite novamente: "); scanf ("%lf", &radianos); getchar ();
									}
								}
						system ("cls");
						conta=radianos*180/M_PI; printf ("Sua op��o: %lf equivale a %lf�\n", radianos, conta);
						printf ("O arco cosseno de %lf � igual a %lf", radianos, acos(radianos));
						printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
						printf ("Digite a op��o desejada: ");
						scanf ("%lf", &reprocessamento); 
						}
						}
			if (a==9) {
				system ("cls");
				printf ("Voc� escolheu a op��o Arco Tangente, deseja saber o c�lculo em graus ou em radianos?\n\n1. Graus\n2. Radianos\n\n");
				printf ("Digite sua op��o: ");
				scanf("%d", &radianoougrau);
				getchar ();
					if (radianoougrau<1 || radianoougrau>2) {
						while (radianoougrau<1 || radianoougrau>2) {
							printf ("\n\nOp��o inv�lida\n\n");
							printf ("Digite a op��o desejada: ");
							scanf ("%d", &radianoougrau);
							} 
						}
				//Switch p/ escolher a op��o grau.
				if (radianoougrau==1) {
						system ("cls");
						printf ("Voc� escolheu a op��o Graus, digite o valor da tangente para calcular o Arco Tangente:\n\n");
						printf ("Digite o valor: ");
						scanf("%lf", &angulo);
						getchar ();
						arct=atan(angulo);
						system ("cls");
						conta=angulo*180/M_PI; containversa=angulo*M_PI/180; printf ("Sua op��o: %lf equivale a %f�\n", angulo, conta);
						printf ("o arco tangente de %lf � igual a %lf�", angulo, arct*180/M_PI);
						printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
						printf ("Digite a op��o desejada: ");
						scanf ("%lf", &reprocessamento);
						}
					//Switch p/ escolher radianos
					if (radianoougrau==2) {
						system ("cls");
						printf ("Voc� escolheu a op��o Radianos, digite o valor da tangente para calcular o Arco Tangente:\n\n");
						printf ("Digite o valor: ");
						scanf("%lf", &radianos);
						getchar ();
						system ("cls");
						conta=radianos*180/M_PI; printf ("Sua op��o: %lf equivale a %lf�\n", radianos, conta);
						printf ("o arco tangente de %lf � igual a %lf", radianos, atan(radianos));
						printf ("\n\nDeseja Reiniciar o programa?\n\n1 para Sim\nQualquer outro n�mero para N�o\n\n");
						printf ("Digite a op��o desejada: ");
						scanf ("%lf", &reprocessamento);
						}
						}
			else reprocessamento==1;								
}
}