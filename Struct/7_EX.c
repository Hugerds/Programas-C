#include <stdio.h>
#include <locale.h>
#include <string.h>

struct vetores{
	float x;
	float y;
	float z;
} vetor;

struct vetores2{
	float x;
	float y;
	float z;
} vetor2;



int main () {
	setlocale(LC_ALL, "Portuguese");
	printf("Escreva os três números do primeiro vetor que deseja somar: ");
	scanf("%f %f %f", &vetor.x, &vetor.y, &vetor.z);
	printf("(%.3f, %.3f, %.3f)\n", vetor.x, vetor.y, vetor.z);
	printf("Agora escreva o outro vetor que deseja somar com este: ");
	scanf("%f %f %f", &vetor2.x, &vetor2.y, &vetor2.z);
	printf("\n\n");
	printf("A soma entre (%.3f, %.3f, %.3f) e (%.3f, %.3f, %.3f) resulta no vetor: (%.3f, %.3f, %.3f)\n", vetor.x, vetor.y, vetor.z, vetor2.x, vetor2.y, vetor2.z, vetor.x+vetor2.x, vetor.y+vetor2.y, vetor.z+vetor2.z);
}
